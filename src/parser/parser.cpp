#pragma once
#include "../Quarzum.h"
using tokens::Token;
using tokens::TokenType;
using tokens::TokenList;
class Parser: public QComponent{
public:
    Parser(TokenList input){
        this -> input = input;
    }
    // Converts a list of Tokens into a list of Statements
    vector<Statement> parse(){
        for(; i < input.size(); i++){
            TokenType t = input.get(i).type;
            Expr e;
            switch (t)
            {
            default:
                break;
            case TokenType::function_k:
                if(followSyntax({TokenType::id, TokenType::left_par, TokenType::right_par, TokenType::left_cb, TokenType::right_cb}))
                {
                    output.push_back({func_stmt, {input.get(i+1).value.value}});
                }
                break;
            case TokenType::exit_k:
                i++;
                e = parseExpr(getExprValids());
                if(e.type != INT){
                    errorHandler.err({syntax_err,0,"Exit statement should have an integer exit code"});
                    break;
                }               
                if(input.get(i).type != TokenType::semicolon){
                    errorHandler.err({syntax_err,0,"Expected semicolon"});
                    break;
                } 
                output.push_back({exit_stmt, {e.value}});
                break;
        
            case TokenType::out_k:
                if(followSyntax({TokenType::left_par, TokenType::str_lit, TokenType::right_par, TokenType::semicolon}))
                {
                    output.push_back({out_stmt, {input.get(i+2).value}});
                }
                break;
            case TokenType::int_k:
                if(followSyntax({TokenType::id, TokenType::eq, TokenType::int_lit, TokenType::semicolon}))
                {
                    varlist.addVariable({
                        .name = input.get(i+1).value, 
                        .type = input.get(i).value, 
                        .value = input.get(i+3).value
                    });
                    output.push_back({var_stmt, {input.get(i).value,input.get(i+1).value, input.get(i+3).value}});
                    break;
                }
                if(followSyntax({TokenType::id, TokenType::semicolon}))
                {
                    varlist.addVariable({
                        .name = input.get(i+1).value, 
                        .type = input.get(i).value, 
                        .value = ZERO
                    });
                    output.push_back({var_stmt, {input.get(i).value,input.get(i+1).value, ZERO}});
                    break;
                }
                break;
            case TokenType::str_k:
                if(followSyntax({TokenType::id, TokenType::eq, TokenType::str_lit, TokenType::semicolon}))
                {
                    output.push_back({var_stmt, {input.get(i).value,input.get(i+1).value, input.get(i+3).value}});
                    break;
                }
                if(followSyntax({TokenType::id, TokenType::semicolon}))
                {
                    output.push_back({var_stmt, {input.get(i).value,input.get(i+1).value, ZERO}});
                    break;
                }
                break;
            case TokenType::id:
                qstring name = input.get(i).value;
                if(followSyntax({TokenType::eq})){
                    i++;
                    e = parseExpr(getExprValids());
                    // if(input.get(i).type != semicolon){
                    //     errorHandler.err({syntax_err,0,"Expected semicolon"});
                    //     break;
                    // }
                    output.push_back({redec_stmt, {varlist.getVariable(name), e.value} });
                }
                break;
            
            }
        }
        errorHandler.run();
        return output;
    }
private:
    size_t i;
    vector<Statement> output;
    TokenList input;
    bool isType(uint a, TokenType b){
        return input.get(i + a).type == b;
    }
    bool followSyntax(vector<TokenType> t){
        for (size_t j = 0; j < t.size(); j++)
        {
            if(not isType(j + 1, t.at(j))){
                return false;
            }
        }
        return true;
    }

    TokenList getExprValids(){

        TokenList exprValids;
        // 1. Get every possible expression token - FINISHED
        while(isExprValid(input.get(i).type)){
            exprValids.addToken(input.get(i));
            cout << input.get(i).value.value << "t - ";
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

        return {INT, Token{TokenType::int_lit, "7"}};
    }
};
