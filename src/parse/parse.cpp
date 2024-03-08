#pragma once
#include "parse.hpp"
using namespace Quarzum;
using namespace Quarzum::Lex;
using namespace Quarzum::Parse;
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

            if(t == Endl){ ++m_line; continue; }

            if(t == RightCurlyBracket) {
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
                bool isConst = getType(-1) == Const;
                if(getType(1) == Identifier) {
                    string varName = m_input[m_index + 1].value;
                    if(getType(2) == Equal) {
                        m_index += 3;
                        
                        Expr e = parseExpr(getExprValids());
                        if(matchTypes(e.type, t)){
                            if(getType(0) != Semicolon) { SyntaxErr("Expected semicolon"); }
                            addVarDecl(varName, t, e.value, isConst);
                            continue;
                        }
                        TypeErr("Expected expression of type '" + m_input[0].value +"'");
                    }   
                    if(getType(2) == Semicolon) {
                        if(isConst){ SyntaxErr("Variables marked as constant should be initialized"); }
                        addVarDecl(varName, t);
                        continue;
                    } 
                    SyntaxErr("Expected semicolon or assignment");
                }
                SyntaxErr("Expected identifier");
            }

            if(t == Module) {
                if(getType(1) == Identifier) {

                    continue;
                }
                SyntaxErr("Expected identifier");
            }

            if(t == Exit) {
                ++m_index;
                Expr e = parseExpr(getExprValids());
                if(e.type == INT) {
                    if(getType(0) != Semicolon) { SyntaxErr("Expected semicolon"); }
                    addStmt({exit_stmt, {e.value}, NULL});
                    continue;
                }
                TypeErr("Expected expression of type 'int'");
            }

            if(t == Return) {
                ++m_index;
                if(getType(0) == Semicolon) {
                    // addreturn(null);
                    continue;
                }
                Expr e = parseExpr(getExprValids());
                if(getType(0) != Semicolon) { SyntaxErr("Expected semicolon"); }
                // addreturn(expr);
                continue;
            }

            if(t == Identifier) {
                
                string varName = m_input[m_index].value; 

                if(getType(1) == Equal) {
                    m_index += 2;
                    Expr e = parseExpr(getExprValids());
                    if(getType(0) != Semicolon) { SyntaxErr("Expected semicolon"); }
                    addVarModification(varName, e.value);
                    continue;
                }

                if(getType(1) == PlusEq || getType(1) == MinusEq) {
                    TokenType symbol = getType(1);
                    m_index += 2;
                    Expr e = parseExpr(getExprValids());
                    if(getType(0) != Semicolon) { SyntaxErr("Expected semicolon"); }
                    addStmt( Statement{ (symbol == PlusEq ? inc_stmt : dec_stmt) , {varName, e.value}, NULL });
                    continue;
                }
            }

            if(t == Function) {
                if(getType(1) == Identifier) {
                    if(getType(2) == LeftPar) {
                        m_index += 3;
                        getArgs(false);
                        if(getType(0) == RigthPar) {
                            if(getType(1) == LeftCurlyBracket){
                                addIdent();
                                buffer = {func_stmt, {}};
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

            if(t == If) {
                if(getType(1) == LeftPar) {
                    m_index += 2;
                    Expr e = parseExpr(getExprValids());
                    if(e.type != BOOL) {
                        TypeErr("Conditions must be of type 'bool'");
                    }
                    if(getType(0) == RigthPar) {
                        if(getType(1) == LeftCurlyBracket){
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

            if(t == While) {
                if(getType(1) == LeftPar) {
                    m_index += 2;
                    Expr e = parseExpr(getExprValids());
                    if(e.type != BOOL) { TypeErr("Conditions must be of type 'bool'"); }
                    if(getType(0) == RigthPar) {
                        if(getType(1) == LeftCurlyBracket){
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
    unsigned long m_index { 0 };
    unsigned char m_ident { 0 };
    unsigned long m_line { 0 };
    deque<StatementList> output;
    TokenList m_input;

    TokenType getType(size_t n) {
        if(m_index + n >= m_input.size()){
            return TokenType::Error;
        }
        if(m_input.get(m_index + n).type == Endl){
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
            if(getType(1) == Identifier) {
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
        if(getType(0) == Comma) {
            ++m_index;
            getArgs(true);
        }

    }

    bool matchTypes(ExprType e, TokenType t);
    Expr parseExpr(TokenList list); // in parseexpr.cpp

    string typeToString(TokenType t){
        const unordered_map<TokenType, string> types = {
            {Integer, "int"},
            {String, "string"},
            {Bool, "byte"},
            {Byte, "byte"},
            {Char, "byte"},
            {Uint, "int"},
            {Number, "long"}
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