#pragma once
#include "../Quarzum.h"

class Parser: public QComponent{
    
public:

    Parser(TokenList input): m_input(input){}

    vector<Statement> parse() {

        for(; m_index < m_input.size(); ++m_index){

            TokenType t = m_input.get(m_index).type;

            if(isDataType(t)) {
                bool isConst = getType(-1) == const_k;
                if(getType(1) == id) {
                    string varName = m_input.get(m_index + 1).value;
                    if(getType(2) == eq) {
                        m_index += 3;
                        Expr e = parseExpr(getExprValids());
                        if(e.type == STRING && t == str_k){
                            if(getType(0) != semicolon) {
                                errorHandler.err({syntax_err, 0, "Expected semicolon"});
                                continue;
                            }
                            addVarDecl(varName, t, any_cast<Token>(e.value).value, isConst);
                            cout << "Valid STRING expression.\n";
                            continue;
                        }
                        if(e.type == BOOL && t == bool_k){
                            if(getType(0) != semicolon) {
                                errorHandler.err({syntax_err, 0, "Expected semicolon"});
                                continue;
                            }
                            addVarDecl(varName, t,any_cast<Token>(e.value).value == "true" ? "1" : "0" , isConst);
                            cout << "Valid BOOL expression.\n";
                            continue;
                        }
                        if(e.type == INT && t == int_k){
                            if(getType(0) != semicolon) {
                                errorHandler.err({syntax_err, 0, "Expected semicolon"});
                                continue;
                            }
                            addVarDecl(varName, t, any_cast<Token>(e.value).value, isConst);
                            cout << "Valid INT expression.\n";
                            continue;
                        }
                        if(e.type == CHAR && t == char_k){
                            if(getType(0) != semicolon) {
                                errorHandler.err({syntax_err, 0, "Expected semicolon"});
                                continue;
                            }
                            addVarDecl(varName, t, any_cast<Token>(e.value).value, isConst);
                            cout << "Valid CHAR expression.\n";
                            continue;
                        }
                        if(e.type == NUMBER && t == num_k){
                            if(getType(0) != semicolon) {
                                errorHandler.err({syntax_err, 0, "Expected semicolon"});
                                continue;
                            }
                            addVarDecl(varName, t, any_cast<Token>(e.value).value, isConst);
                            cout << "Valid NUMBER expression.\n";
                            continue;
                        }
                        errorHandler.err({syntax_err, 0, "Expected expression of type " + m_input.get(0).value});
                        continue;
                    }   
                    if(getType(2) == semicolon) {
                        addVarDecl(varName, t);
                        continue;
                    } 
                    errorHandler.err({syntax_err, 0, "Expected semicolon or assignment"});
                    continue;
                }
                errorHandler.err({syntax_err, 0, "Expected identifier"});
                continue;
            }

            if(t == module_k) {
                if(getType(1) == id) {

                    continue;
                }
                errorHandler.err({syntax_err, 0, "Expected identifier"});
                continue;
            }

            if(t == exit_k) {
                ++m_index;
                Expr e = parseExpr(getExprValids());
                if(e.type == INT) {
                    if(getType(0) != semicolon) {
                        errorHandler.err({syntax_err, 0, "Expected semicolon"});
                        continue;
                    }
                    addExit(any_cast<Token>(e.value).value);
                    continue;
                }
                errorHandler.err({syntax_err, 0, "Expected expression of type int"});
                continue;
            }

            if(t == id) {

                string varName = m_input.get(m_index).value; 

                if(getType(1) == eq) {
                    m_index += 2;
                    Expr e = parseExpr(getExprValids());
                    if(getType(0) != semicolon) {
                        errorHandler.err({syntax_err, 0, "Expected semicolon"});
                        continue;
                    }
                    //addVarDecl();
                    continue;
                }

                if(getType(1) == plus_eq || getType(1) == minus_eq) {
                    m_index += 2;
                    Expr e = parseExpr(getExprValids());
                    if(getType(0) != semicolon) {
                        errorHandler.err({syntax_err, 0, "Expected semicolon"});
                        continue;
                    }
                    getType(1) == plus_eq ? 
                        addIncrement(varName, any_cast<Token>(e.value).value) : 
                        addDecrement(varName, any_cast<Token>(e.value).value);
                    
                    continue;
                }

            }

        }
        errorHandler.run();
        return output;
    }
private:
    size_t m_index { 0 };
    vector<Statement> output;
    TokenList m_input;

    bool isDataType(TokenType t) const noexcept {
        return (t >= 1 && t <= 8);
    }

    TokenType getType(size_t n) const {
        if(m_index + n >= m_input.size()){
            return err;
        }
        return m_input.get(m_index + n).type;
    }

    TokenList getExprValids() {

        TokenList exprValids;
        while(isExprValid(m_input.get(m_index).type)){
            exprValids.addToken(m_input.get(m_index));
            ++m_index; 
        }
        return exprValids;
    }

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

    void addVarDecl(string name, TokenType type, string value = "0", bool isConst = false){
        symbolTable.add({name, typeToString(type), value, isConst});
    }

    void addIncrement(string name, string value){
        output.push_back({inc_stmt, {name, value}});
    }

    void addDecrement(string name, string value){
        output.push_back({dec_stmt, {name, value}});
    }

    void addExit(string value) {
        output.push_back({exit_stmt, {value}});
    }
};