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
            TokenType t = input.get(i).type;
            switch (t)
            {
            case function_k:
                if(followSyntax({id, left_par, right_par, left_cb, right_cb}))
                {
                    cout << "f: " + input.get(i+1).value << endl;

                    output.push_back({func_stmt, {input.get(i+1).value}});
                }
                break;
            case exit_k:
                if(followSyntax({int_lit, semicolon})){
                    output.push_back({exit_stmt, {input.get(i+1).value}});
                }
                if(followSyntax({id, semicolon}) and varlist.getVariable(input.get(i+1).value).name != ""){
                    output.push_back({exit_stmt, {varlist.getVariable(input.get(i+1).value).value}});
                }
                break;
        
            case out_k:
                if(followSyntax({left_par, str_lit, right_par, semicolon}))
                {
                    output.push_back({out_stmt, {input.get(i+2).value}});
                }
                break;
            case int_k:
                if(followSyntax({id, eq, int_lit, semicolon}))
                {
                    varlist.addVariable({
                        .name = input.get(i+1).value, 
                        .type = input.get(i).value, 
                        .value = input.get(i+3).value 
                    });
                    output.push_back({var_stmt, {input.get(i).value,input.get(i+1).value, input.get(i+3).value}});
                    break;
                }
                else if(followSyntax({id, semicolon}))
                {
                    varlist.addVariable({
                        .name = input.get(i+1).value, 
                        .type = input.get(i).value, 
                        .value = ZERO
                    });
                    output.push_back({var_stmt, {input.get(i).value,input.get(i+1).value, ZERO}});
                    break;
                }
            case str_k:
                if(followSyntax({id, eq, str_lit, semicolon}))
                {
                    output.push_back({var_stmt, {input.get(i).value,input.get(i+1).value, input.get(i+3).value}});
                    break;
                }
                else if(followSyntax({id, semicolon}))
                {
                    output.push_back({var_stmt, {input.get(i).value,input.get(i+1).value, ZERO}});
                    break;
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
