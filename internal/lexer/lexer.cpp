#include "../Quarzum.h"
#pragma once

// Shows in console every token with its type (converted to decimal) and its value.
void debugTokens(deque<Token> list){
    for (size_t i = 0; i < list.size(); i++)
    {
        cout << list.at(i).type << " - " << list.at(i).value << endl;
    }
}

const unsigned char KEYWORD_COUNT = 12;
string keywords[KEYWORD_COUNT] = {
    "int",
    "number",
    "string",
    "char",
    "bool",
    "any",
    "return",
    "function",
    "enum",
    "const",
    "exit",
    "out"
};
// Searchs if a determined input is a keyword. If not, returns an id Token,
Token searchForKeyword(string input){
    for (size_t i = 0; i < KEYWORD_COUNT; i++)
    {
        if(input == keywords[i]){
            return {TokenType(0x001 + i),input};
        }
    }
    return {id, input};
}

const unsigned char SYMBOL_COUNT = 3;
string symbols[SYMBOL_COUNT]={
    "=",
    "(",
    ")"
};
Token searchForSymbol(string input){
    for (size_t i = 0; i < SYMBOL_COUNT; i++)
    {
        if(input == symbols[i]){
            return {TokenType(0x201 + i),input};
        }
    }
    // TO-DO: throw an error "unexpected token"
    return {id, input};
}

// Converts an input string into a list of Tokens
deque<Token> tokenize(string input){
    ErrorHandler errorHandler;
    string buffer;
    deque<Token> output;
    int lineno = 1;

    for(size_t i = 0; i <= input.length(); i++){

        char c = input[i];
        char next = '\0';
        if(i + 1 < input.length()){
            next = input[i + 1];
        }

        // If there is a new line, sum 1 to the line number
        if(c == '\n'){
            lineno++;
        }
        // Ignore spaces
        else if(isspace(c)){
            continue;
        }
        // [a-zA-Z][a-zA-Z0-9]+
        if(isalpha(c)){
            buffer += c;
            
            if(!isalnum(next)){
                output.push_back(searchForKeyword(buffer));
                buffer.clear();
            }
        }
        // [0-9]*
        if(isdigit(c)){
            buffer += c;
            if(!isdigit(next)){
                output.push_back({int_lit, buffer});
                buffer.clear();
            }
        }
        // Punctuation
        if(ispunct(c)){
            buffer +=c;
            output.push_back(searchForSymbol(buffer));
            buffer.clear();
        }

        else{
            errorHandler.err({{},lineno,"Unexpected token"});
        }
    }
    return output;
}