#pragma once
#include "../Quarzum.h"
#define SyntaxErr(c) errorHandler.err({syntax_err, m_line, c}); continue;
#define TypeErr(c) errorHandler.err({type_err, m_line, c}); continue;
class Parser: public QComponent{
    
public:

    Parser(TokenList input): m_input(input){}

    StatementList parse() {
        output.push_back({});
        Statement buffer;
        for(; m_index < m_input.size(); ++m_index){

            TokenType t = m_input[m_index].type;

            if(t == TokenType::endl){ ++m_line; continue; }

            if(t == right_cb) {
                if(m_ident == 0) {
                    SyntaxErr("Unexpected '}'");
                }
                buffer.children = output[m_ident].getAll();
                output.pop_back();
                --m_ident;
                addStmt(buffer);
                buffer = {};
            }

            if(isDataType(t)) {
                bool isConst = getType(-1) == const_k;
                if(getType(1) == id) {
                    string varName = m_input[m_index + 1].value;
                    if(getType(2) == eq) {
                        m_index += 3;
                        
                        Expr e = parseExpr(getExprValids());
                        if(matchTypes(e.type, t)){
                            if(getType(0) != semicolon) { SyntaxErr("Expected semicolon"); }
                            addVarDecl(varName, t, e.value, isConst);
                            continue;
                        }
                        TypeErr("Expected expression of type '" + m_input[0].value +"'");
                    }   
                    if(getType(2) == semicolon) {
                        if(isConst){ SyntaxErr("Variables marked as constant should be initialized"); }
                        addVarDecl(varName, t);
                        continue;
                    } 
                    SyntaxErr("Expected semicolon or assignment");
                }
                SyntaxErr("Expected identifier");
            }

            if(t == module_k) {
                if(getType(1) == id) {

                    continue;
                }
                SyntaxErr("Expected identifier");
            }

            if(t == exit_k) {
                ++m_index;
                Expr e = parseExpr(getExprValids());
                if(e.type == INT) {
                    if(getType(0) != semicolon) { SyntaxErr("Expected semicolon"); }
                    addStmt({exit_stmt, {e.value}, NULL});
                    continue;
                }
                TypeErr("Expected expression of type 'int'");
            }

            if(t == return_k) {
                ++m_index;
                if(getType(0) == semicolon) {
                    // addreturn(null);
                    continue;
                }
                Expr e = parseExpr(getExprValids());
                if(getType(0) != semicolon) { SyntaxErr("Expected semicolon"); }
                // addreturn(expr);
                continue;
            }

            if(t == id) {
                
                string varName = m_input[m_index].value; 

                if(getType(1) == eq) {
                    m_index += 2;
                    Expr e = parseExpr(getExprValids());
                    if(getType(0) != semicolon) { SyntaxErr("Expected semicolon"); }
                    addVarModification(varName, e.value);
                    continue;
                }

                if(getType(1) == plus_eq || getType(1) == minus_eq) {
                    TokenType symbol = getType(1);
                    m_index += 2;
                    Expr e = parseExpr(getExprValids());
                    if(getType(0) != semicolon) { SyntaxErr("Expected semicolon"); }
                    addStmt( Statement{ (symbol == plus_eq ? inc_stmt : dec_stmt) , {varName, e.value}, NULL });
                    continue;
                }
            }

            if(t == function_k) {
                if(getType(1) == id) {
                    if(getType(2) == left_par) {
                        m_index += 3;
                        getArgs(false);
                        if(getType(0) == right_par) {
                            if(getType(1) == left_cb){
                                continue;
                            }
                            SyntaxErr("Expected function body");
                        }
                        SyntaxErr("Expected ')'");
                    }
                    SyntaxErr("Expected function arguments");
                }
                SyntaxErr("Expected identifier");
            }

            if(t == if_k) {
                if(getType(1) == left_par) {
                    m_index += 2;
                    Expr e = parseExpr(getExprValids());
                    if(e.type != BOOL) {
                        TypeErr("Conditions must be of type 'bool'");
                    }
                    if(getType(0) == right_par) {
                        if(getType(1) == left_cb){
                            addIdent();
                            buffer = {if_stmt, {e.value}};
                            continue;
                        }
                        SyntaxErr("Expected 'if' body");
                    }
                    SyntaxErr("Expected ')'");
                }
                SyntaxErr("Expected identifier");
            }

            if(t == while_k) {
                if(getType(1) == left_par) {
                    m_index += 2;
                    Expr e = parseExpr(getExprValids());
                    if(e.type != BOOL) { TypeErr("Conditions must be of type 'bool'"); }
                    if(getType(0) == right_par) {
                        if(getType(1) == left_cb){
                            addIdent();
                            buffer = {while_stmt, {e.value}};
                            continue;
                        }
                        SyntaxErr("Expected 'while' body");
                    }
                    SyntaxErr("Expected ')'");
                }
                SyntaxErr("Expected identifier");
            }

        }
        errorHandler.run();
        return output[0];
    }
private:
    size_t m_index { 0 };
    int m_ident { 0 };
    size_t m_line { 0 };
    deque<StatementList> output;
    TokenList m_input;

    bool isDataType(TokenType t) const { return (t >= 1 && t <= 8); }

    TokenType getType(size_t n) {
        if(m_index + n >= m_input.size()){
            return err;
        }
        if(m_input.get(m_index + n).type == TokenType::endl){
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
            if(getType(1) == id) {
                m_index += 2;
            }
            else {
                errorHandler.err({syntax_err, m_line, "Expected identifier"});
                return;
            }
        }
        else if(mandatory) {
            errorHandler.err({syntax_err, m_line, "Expected function argument after comma"});
            return;
        }
        if(getType(0) == comma) {
            ++m_index;
            getArgs(true);
        }

    }

    bool matchTypes(exprType e, TokenType t);
    Expr parseExpr(TokenList list); // in parseexpr.cpp

    string typeToString(TokenType t){
        const unordered_map<TokenType, string> types = {
            {int_k, "int"},
            {str_k, "string"},
            {bool_k, "byte"},
            {byte_k, "byte"},
            {char_k, "byte"},
            {uint_k, "int"},
            {num_k, "long"}
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
            errorHandler.err({syntax_err, m_line, "Variable '" + name + "' already exists"});
            return;
        }
        symbolTable.add({name, typeToString(type), value, isConst});
    }

    void addVarModification(string name, string value) {
        if(symbolTable.find(name).name == ""){
            errorHandler.err({syntax_err, m_line, "Undefined reference to '" + name +"'"});
            return;
        }
        output[m_ident].add({redec_stmt, {name, value}, NULL});
    }
};