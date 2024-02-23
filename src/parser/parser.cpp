#pragma once
#include "../Quarzum.h"

class Parser: public QComponent{
public:
    Parser(TokenList input): m_input(input){}
    // Converts a list of Tokens into a list of Statements
    vector<Statement> parse() noexcept {
        for(; m_index < m_input.size(); ++m_index){
            TokenType t = m_input.get(m_index).type;
            /**
             * [data-type] [id] [;]  
             *          and  
             * [data-type] [id] [=] [expression] [;]
            */
            if(isDataType(t)){
                if(getType(1) == id){
                    if(getType(2) == eq){
                        m_index += 3;
                        // get expr and semicolon
                        Expr e = parseExpr(getExprValids());

                        if(getType(0) == semicolon){
                            // good path (int i = 5;)
                            cout << "- (" << m_input.get(m_index).value << ") " << m_input.get(m_index + 1).value << " (= expr)\n";
                            ++m_index;
                        }
                        else{
                            errorHandler.err({syntax_err, 0, "Expected semicolon"});
                        }
                    }
                    else if(getType(2) == semicolon){
                        
                        cout << "- (" << m_input.get(m_index).value << ") " << m_input.get(m_index + 1).value << "\n";
                        m_index += 2;
                        // good path (int i;)
                        continue;
                    }
                    else{
                        m_index += 1;
                        errorHandler.err({syntax_err, 0, "Expected semicolon"});
                    }
                }
                else{
                    errorHandler.err({syntax_err, 0, "Invalid syntax"});
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
        return (t == int_k);
    }

    TokenType getType(int n) const noexcept{
        return m_input.get(m_index + n).type;
    }

    TokenList getExprValids(){

        TokenList exprValids;
        // 1. Get every possible expression token - FINISHED
        while(isExprValid(m_input.get(m_index).type)){
            exprValids.addToken(m_input.get(m_index));
            //cout << m_input.get(i).value << "t - ";
            m_index++; 
        }
        return exprValids;
    }

    Expr parseExpr(TokenList list){
        
        // 2. Iterate the TokenList. If finds a "+" divide into a binary expr. If not, push a single expr.

        if(list.size() == 1){
            return Expr{
                .type = exprType::INT,
                .value = list.get(0)
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

        return {INT, Token{int_lit, "7"}};
    }
};
