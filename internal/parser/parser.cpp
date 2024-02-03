#pragma once
#include "../Quarzum.h"

// Converts a list of Tokens into a list of Statements
deque<Statement> parse(deque<Token> input){
    deque<Statement> output;
    for (size_t i = 0; i < input.size(); i++)
    {
        Token t = input.at(i);
        switch (t.type)
        {
        case exit_k:
            if(i+1<= input.size() and input.at(i + 1).type == int_lit){
                output.push_back({exit_stmt, {input.at(i+1).value}});
            }
            break;
        
        case out_k:
            if(i+3<=input.size() 
                and input.at(i + 1).type == left_par
                and input.at(i + 2).type == int_lit
                and input.at(i + 3).type == rigth_par)
            {
                output.push_back({out_stmt, {input.at(i+2).value}});
            }
            break;
        }
    }
    return output;
}