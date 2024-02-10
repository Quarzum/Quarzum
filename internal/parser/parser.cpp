#pragma once
#include "../Quarzum.h"

class Parser{
public:
    Parser(TokenList input){
        this -> input = input;
    }
    // Converts a list of Tokens into a list of Statements
    deque<Statement> parse(){
        repeat(i, input.size()){
            Token t = input.get(i);
            switch (t.type)
            {
            case function_k:
                if(followSyntax({id, left_par, right_par, left_cb, right_cb}))
                {
                    cout << "f: " + input.get(i+1).value << endl;

                    output.push_back({func_stmt, {input.get(i+1).value}});
                }
                break;
            case exit_k:
                if(followSyntax({int_lit})){
                    output.push_back({exit_stmt, {input.get(i+1).value}});
                }
                break;
        
            case out_k:
                if(followSyntax({left_par, str_lit, right_par}))
                {
                    output.push_back({out_stmt, {input.get(i+2).value}});
                }
                break;
            case int_k:
                if(followSyntax({id, eq, int_lit}))
                {
                    output.push_back({var_stmt, {input.get(i+1).value, input.get(i+3).value}});
                }
            }
        }
        return output;
    }
private:
    uint i;
    deque<Statement> output;
    TokenList input;
    bool isType(uint a, TokenType b){
        return input.get(i + a).type == b;
    }
    bool followSyntax(deque<TokenType> t){
        for (size_t j = 0; j < t.size(); j++)
        {
            if(not isType(j + 1, t.at(j))){
                return false;
            }
        }
        return true;
    }
};
