#pragma once
#include "../Quarzum.h"

// Converts a list of Tokens into a list of Statements
deque<Statement> parse(TokenList input){
    deque<Statement> output;
    print("Parsing...");
    for (size_t i = 0; i < input.size(); i++)
    {
        Token t = input.get(i);
        switch (t.type)
        {
        case TokenType::exit_k:
            if(i+1<= input.size() and input.get(i + 1).type == TokenType::int_lit){
                output.push_back({exit_stmt, {input.get(i+1).value}});
            }
            break;
        
        case TokenType::out_k:
            if(i+3<=input.size() 
                and input.get(i + 1).type == TokenType::left_par
                and input.get(i + 2).type == TokenType::str_lit
                and input.get(i + 3).type == TokenType::rigth_par)
            {
                output.push_back({out_stmt, {input.get(i+2).value}});
            }
            break;
        }
    }
    return output;
}