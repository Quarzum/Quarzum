#pragma once
#include "../Quarzum.h"
class Parser {
    
public:

    Parser(TokenList input): m_input(input){}

    StatementList parse() {
        output.push_back({});
        Statement buffer;
        for(; m_index < m_input.size(); ++m_index){

            TokenType t = m_input[m_index].type;

            if(t == TokenType::Endl){ ++m_line; continue; }

            if(t == TokenType::RightCurlyBracket) {
                if(m_ident == 0) {
                    // err
                    continue;
                }
                buffer.children = output[m_ident].getAll();
                output.pop_back();
                --m_ident;
                addStmt(buffer);
                buffer = {};
            }

            if(isDataType(t)) {
                bool isConst = getType(-1) == TokenType::Const;
                if(getType(1) == TokenType::Identifier) {
                    string varName = m_input[m_index + 1].value;
                    if(getType(2) == TokenType::Equal) {
                        m_index += 3;
                        
                        Expr e = parseExpr(getExprValids());
                        if(matchTypes(e.type, t)){
                            if(getType(0) != TokenType::Semicolon) { 
                                // err
                                continue;
                             }
                            addVarDecl(varName, t, e.value, isConst);
                            continue;
                        }
                        // err
                        continue;
                    }   
                    if(getType(2) == TokenType::Semicolon) {
                        if(isConst){
                            // err
                            continue; }
                        addVarDecl(varName, t);
                        continue;
                    } 
                    // err
                    continue;
                }
                // err
                continue;
            }

            if(t == TokenType::Module) {
                if(getType(1) == TokenType::Identifier) {

                    continue;
                }
                // err
                continue;
            }

            if(t == TokenType::Exit) {
                ++m_index;
                Expr e = parseExpr(getExprValids());
                if(e.type == INT) {
                    if(getType(0) != TokenType::Semicolon) {
                        // err
                        continue; 
                        }
                    addStmt({exit_stmt, {e.value}, NULL});
                    continue;
                }
                // err
                continue;
            }

            if(t == TokenType::Return) {
                ++m_index;
                if(getType(0) == TokenType::Semicolon) {
                    // addreturn(null);
                    continue;
                }
                Expr e = parseExpr(getExprValids());
                if(getType(0) != TokenType::Semicolon) { 
                    // err
                    continue; }
                // addreturn(expr);
                continue;
            }

            if(t == TokenType::Identifier) {
                
                string varName = m_input[m_index].value; 

                if(getType(1) == TokenType::Equal) {
                    m_index += 2;
                    Expr e = parseExpr(getExprValids());
                    if(getType(0) != TokenType::Semicolon) { 
                        // err
                        continue; }
                    addVarModification(varName, e.value);
                    continue;
                }

                if(getType(1) == TokenType::PlusEq || getType(1) == TokenType::MinusEq) {
                    TokenType symbol = getType(1);
                    m_index += 2;
                    Expr e = parseExpr(getExprValids());
                    if(getType(0) != TokenType::Semicolon) {// err
                    continue; }
                    addStmt( Statement{ (symbol == TokenType::PlusEq ? inc_stmt : dec_stmt) , {varName, e.value}, NULL });
                    continue;
                }
            }

            if(t == TokenType::Function) {
                if(getType(1) == TokenType::Identifier) {
                    if(getType(2) == TokenType::LeftPar) {
                        m_index += 3;
                        getArgs(false);
                        if(getType(0) == TokenType::RigthPar) {
                            if(getType(1) == TokenType::LeftCurlyBracket){
                                addIdent();
                                buffer = {func_stmt, {}};
                                continue;
                            }
                            // err
                    continue;
                        }
                        // err
                    continue;
                    }
                    // err
                    continue;
                }
                // err
                    continue;
            }

            if(t == TokenType::If) {
                if(getType(1) == TokenType::LeftPar) {
                    m_index += 2;
                    Expr e = parseExpr(getExprValids());
                    if(e.type != BOOL) {
                       // err
                    continue;
                    }
                    if(getType(0) == TokenType::RigthPar) {
                        if(getType(1) == TokenType::LeftCurlyBracket){
                            addIdent();
                            buffer = {if_stmt, {e.value}};
                            continue;
                        }
                        // err
                    continue;
                    }
                   // err
                    continue;
                }
               // err
                    continue;
            }

            if(t == TokenType::While) {
                if(getType(1) == TokenType::LeftPar) {
                    m_index += 2;
                    Expr e = parseExpr(getExprValids());
                    if(e.type != BOOL) { // err
                    continue; }
                    if(getType(0) == TokenType::RigthPar) {
                        if(getType(1) == TokenType::LeftCurlyBracket){
                            addIdent();
                            buffer = {while_stmt, {e.value}};
                            continue;
                        }
                       // err
                    continue;
                    }
                    // err
                    continue;
                }
               // err
                    continue;
            }

        }
        return output[0];
    }
private:
    size_t m_index { 0 };
    int m_ident { 0 };
    size_t m_line { 0 };
    deque<StatementList> output;
    TokenList m_input;

    bool isDataType(TokenType t) const { return ((unsigned char)(t) >= 1 && (unsigned char)t <= 8); }

    TokenType getType(size_t n) {
        if(m_index + n >= m_input.size()){
            return TokenType::Error;
        }
        if(m_input.get(m_index + n).type == TokenType::Endl){
            ++m_line;
        }
        return m_input.get(m_index + n).type;
    }

    TokenList getExprValids() {
        TokenList exprValids;
        while(isExprValid(m_input[m_index].type)){
            exprValids.addToken(m_input[m_index]);
            ++m_index; 
        }
        return exprValids;
    }

    void getArgs(bool mandatory) {
        if(isDataType(getType(0))){
            if(getType(1) == TokenType::Identifier) {
                m_index += 2;
            }
            else {
               // err
                  
                return;
            }
        }
        else if(mandatory) {
            // err
                   
            return;
        }
        if(getType(0) == TokenType::Comma) {
            ++m_index;
            getArgs(true);
        }

    }

    bool matchTypes(exprType e, TokenType t);
    Expr parseExpr(TokenList list); // in parseexpr.cpp

    string typeToString(TokenType t){
        const unordered_map<TokenType, string> types = {
            {TokenType::Integer, "int"},
            {TokenType::String, "string"},
            {TokenType::Bool, "byte"},
            {TokenType::Byte, "byte"},
            {TokenType::Char, "byte"},
            {TokenType::Uint, "int"},
            {TokenType::Number, "long"}
        };
        auto it = types.find(t);
        return it->second;
    }

    void addStmt(Statement s) { 
        output[m_ident].add(s);
    }

    void addIdent() {output.push_back({}); m_ident = output.size() - 1;}

    void addVarDecl(string name, TokenType type, string value = "0", bool isConst = false){
        if(symbolTable.find(name).name != ""){
            
            return;
        }
        symbolTable.add({name, typeToString(type), value, isConst});
    }

    void addVarModification(string name, string value) {
        if(symbolTable.find(name).name == ""){
            
            return;
        }
        output[m_ident].add({redec_stmt, {name, value}, NULL});
    }
};