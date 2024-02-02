#pragma once
#include "../Quarzum.h"

// Converts a list of Tokens into a list of Statements
void parse(deque<Token> input){
    deque<Statement> output;
    for (size_t i = 0; i < input.size(); i++)
    {
        Token t = input.at(i);
        switch (t.type)
        {
        case return_k:
            if(i+1<= input.size() and input.at(i + 1).type == int_lit){
                output.push_back({return_stmt, {input.at(i+1).value}});
            }
            break;
        }
    }
    
}