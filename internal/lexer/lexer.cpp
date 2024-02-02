#include "../Quarzum.h"
#pragma once

const char KEYWORD_COUNT = 1;
string keywords[KEYWORD_COUNT] = {
    "int"
};
// Searchs if a determined input is a keyword. If not, returns an id Token,
Token searchForKeyword(string input){
    for (size_t i = 0; i < KEYWORD_COUNT; i++)
    {
        if(input == keywords[i]){
            return {TokenType(0x000 + i),input};
        }
    }
    return {id, input};
}

const char SYMBOL_COUNT = 1;
string symbols[SYMBOL_COUNT]={
    "="
};
Token searchForSymbol(string input){
    for (size_t i = 0; i < SYMBOL_COUNT; i++)
    {
        if(input == symbols[i]){
            return {TokenType(0x200 + i),input};
        }
    }
    // TO-DO: throw an error "unexpected token"
    return {id, input};
}

// Converts an input string into a list of Tokens
deque<Token> tokenize(string input){
    string buffer;
    deque<Token> output;
    int lineno = 1;
    for(size_t i = 0; i < input.length(); i++){
        char c = input[i];
        char next = NULL;
        if(i + 1 < input.length()){
            next = input[i + 1];
        }

        if(c == '\n'){
            lineno++;
        }
        else if(isspace(c)){
            continue;
        }

        if(isalpha(c)){
            buffer += c;
            
            if(!isalnum(next)){
                cout << buffer << endl;

                output.push_back(searchForKeyword(buffer));
                buffer.clear();
            }
        }

        if(isdigit(c)){
            buffer += c;
            if(!isdigit(next)){
                cout << buffer << endl;

                output.push_back({int_lit, buffer});
                buffer.clear();
            }
        }

        if(ispunct(c)){
            cout << c << endl;
            output.push_back(searchForSymbol(buffer));
        }

    }
    return output;
}