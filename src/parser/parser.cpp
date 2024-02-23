#pragma once
#include "../Quarzum.h"

class Parser: public QComponent{
public:
    Parser(TokenList input): input(move(input)){}
    // Converts a list of Tokens into a list of Statements
    vector<Statement> parse(){
        for(i = 0; i< input.size(); i++){
            TokenType t = input.get(i).type;
            /**
             * [data-type] [id] [;]  
             *          and  
             * [data-type] [id] [=] [expression] [;]
            */
            if(isDataType(t)){
                if(getType(1) == id){
                    if(getType(2) == eq){
                        i += 3;
                        // get expr and semicolon
                        Expr e = parseExpr(getExprValids());

                        if(getType(0) == semicolon){
                            // good path (int i = 5;)
                            cout << "- (" << input.get(i).value << ") " << input.get(i + 1).value << " (= expr)\n";
                            i++;
                        }
                        else{
                            errorHandler.err({syntax_err, 0, "Expected semicolon"});
                        }
                    }
                    else if(getType(2) == semicolon){
                        
                        cout << "- (" << input.get(i).value << ") " << input.get(i + 1).value << "\n";
                        i += 2;
                        // good path (int i;)
                        continue;
                    }
                    else{
                        i += 1;
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
    size_t i;
    vector<Statement> output;
    TokenList input;

    bool isDataType(TokenType t){
        return (t == int_k);
    }

    TokenType getType(int n){
        return input.get(i+ n).type;
    }

    TokenList getExprValids(){

        TokenList exprValids;
        // 1. Get every possible expression token - FINISHED
        while(isExprValid(input.get(i).type)){
            exprValids.addToken(input.get(i));
            //cout << input.get(i).value << "t - ";
            i++; 
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
