#pragma once
#include "../Quarzum.h"

class Parser: public QComponent{
    
public:

    Parser(TokenList input): m_input(input){}

    vector<Statement> parse() {

        for(; m_index < m_input.size(); ++m_index){

            TokenType t = m_input.get(m_index).type;

            if(isDataType(t)) {
                if(getType(1) == id) {
                    string varName = m_input.get(m_index + 1).value;
                    if(getType(2) == eq) {
                        m_index += 3;
                        Expr e = parseExpr(getExprValids());
                        if(e.type == INT && t == int_k){
                            if(getType(0) != semicolon) {
                                errorHandler.err({syntax_err, 0, "Expected semicolon"});
                                continue;
                            }
                            addVarDecl(varName, t, any_cast<Token>(e.value).value);
                            cout << "Valid INT expression.\n";
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

            if(t == exit_k) {
                ++m_index;
                Expr e = parseExpr(getExprValids());
                if(e.type == INT) {
                    if(getType(0) != semicolon) {
                        errorHandler.err({syntax_err, 0, "Expected semicolon"});
                        continue;
                    }
                    //addVarDecl();
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

                if(getType(1) == plus_eq) {
                    m_index += 2;
                    Expr e = parseExpr(getExprValids());
                    if(getType(0) != semicolon) {
                        errorHandler.err({syntax_err, 0, "Expected semicolon"});
                        continue;
                    }
                    addIncrement(varName, any_cast<Token>(e.value).value);
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

    Expr parseExpr(TokenList list){
        
        // 2. Iterate the TokenList. If finds a "+" divide into a binary expr. If not, push a single expr.

        if(list.size() == 1){
            return Expr{
                .type = exprType::INT,
                .value = Token{ int_lit, "7"}
            };
        }

        /*

        Operator Precedence Level 0

        */
        // for (size_t n = list.size(); n > 0; n--)
        // {
        //     if (list.get(n).type == TokenType::plus)
        //     {
        //         Expr a = parseExpr( list.divide(0, n) );
        //         Expr b = parseExpr(list.divide(n, list.size()));

        //         return Expr{
        //             exprType::INT,
        //             BinaryExpr{a, b, TokenType::plus}
        //         };
        //     }
        // }
        Token v = {int_lit, "7"};
        return Expr {
            .type = exprType::INT,
            .value = v
        };
    }

    void addVarDecl(string name, TokenType type, string value = "0"){
        symbolTable.add({name, "int", value});
    }

    void addIncrement(string name, string value){
    }
};
