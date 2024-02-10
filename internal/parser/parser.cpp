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
        case function_k:
            if(i+5<=input.size() 
                and input.get(i + 1).type == id
                and input.get(i + 2).type == left_par
                and input.get(i + 3).type == rigth_par
                and input.get(i + 4).type == left_cb
                and input.get(i + 5).type == rigth_cb)
            {
                cout << "f: " + input.get(i+1).value << endl;

                output.push_back({func_stmt, {input.get(i+1).value}});
            }
            break;
        case exit_k:
            if(i+1<= input.size() and input.get(i + 1).type == int_lit){
                output.push_back({exit_stmt, {input.get(i+1).value}});
            }
            break;
        
        case out_k:
            if(i+3<=input.size() 
                and input.get(i + 1).type == left_par
                and input.get(i + 2).type == str_lit
                and input.get(i + 3).type == rigth_par)
            {
                output.push_back({out_stmt, {input.get(i+2).value}});
            }
            break;
        case int_k:
            if(i+3<=input.size() 
                and input.get(i + 1).type == id
                and input.get(i + 2).type == eq
                and input.get(i + 3).type == int_lit)
            {
                output.push_back({var_stmt, {input.get(i+1).value, input.get(i+3).value}});
            }
        }
    }
    return output;
}