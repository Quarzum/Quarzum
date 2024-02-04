#include "../Quarzum.h"
#pragma once

/** 
*   Converts an input string into a list of Tokens.
*   @param input The input string to tokenize.
*   @return A deque of tokens.
*/
const TokenList tokenize(string input) noexcept{
    ErrorHandler errorHandler;
    string buffer;
    TokenList output;
    int lineno = 1;
    bool isComment = false;
    bool isSingleComment = false;
    
    print("Tokenization...");

    for(uint i = 0; i <= input.length(); i++){

        // The actual character
        char c = input[i];

        // The next character (null if c is the last character)
        char next = '\0';
        if(i + 1 < input.length()){
            next = input[i + 1];
        }

        // If there is a new line, sum 1 to the line number
        if(c == '\n'){
            isSingleComment = false;
            lineno++;
        }

        // Ignore spaces
        else if(isspace(c)){continue;}

        // Multiline and single line comments
        if(c == '/' and next == '*'){isComment = true; i++; continue;}
        if(c == '*' and next == '/'){isComment = false; i++; continue;}
        if(c == '/' and next == '/'){isSingleComment = true; continue;}


        if(not (isComment || isSingleComment)){
            
            // [a-zA-Z][a-zA-Z0-9]+
            if(isalpha(c)){
                buffer += c;
                if(!isalnum(next)){
                    output.push_back({TokenType(search(buffer, keywords, 32) + 1),buffer});
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
                output.push_back({TokenType(search(buffer, symbols, 21) + 0x201), buffer});
                buffer.clear();
            }
            else{
                errorHandler.err({{},lineno,"Unexpected token"});
            }
        }        
    }
    return output;
}