#include "../Quarzum.h"
#pragma once

/** 
 *   Converts an input string into a list of Tokens.
 *   @param input The input string to tokenize.
 *   @return A deque of tokens.
*/
const TokenList tokenize(const string input) noexcept{
    string buffer;
    TokenList output = TokenList();
    int lineno = 1;
    bool isComment = false;
    bool isSingleComment = false;
    bool isStringLiteral = false;
    
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
            continue;
        }
        else if(c == '"' && isStringLiteral == false){
            isStringLiteral = true;
            buffer +=c;
            continue;
        }
        else if(isStringLiteral == true){
            buffer += c;
            if(next == '\"'){
                buffer += next;
                i++;
                isStringLiteral = false;
                output.addToken({TokenType::str_lit, buffer});
                buffer.clear();
            }
            continue;
        }
        // Multiline and single line comments
        else if(c == '/' and next == '*'){isComment = true; i++; continue;}
        else if(c == '*' and next == '/'){isComment = false; i++; continue;}
        else if(c == '/' and next == '/'){isSingleComment = true; i++; continue;}


        else if(not (isspace(c) || isComment || isSingleComment)){
            // [a-zA-Z][a-zA-Z0-9]+
            if(isalpha(c)){
                buffer += c;
                if(!isalnum(next)){
                    output.addToken({TokenType(search(buffer, keywords, 36) + 1),buffer});
                    buffer.clear();
                }
                continue;
            }
            // [0-9]*
            else if(isdigit(c)){
                buffer += c;
                if(!isdigit(next)){
                    output.addToken({TokenType::int_lit, buffer});
                    buffer.clear();
                }
                continue;
            }
            // Punctuation
            else if(isSymbol(c)){
                buffer +=c;
                output.addToken({TokenType(search(buffer, symbols, 28) + 0x201), buffer});
                buffer.clear();
                continue;
            }
            else{
                wstring s;
                s += c;
                wcerr << "Lexical Error: Unexpected token " << s << " at line " << to_wstring(lineno) << ".\n";
            }
        }        
    }
    return output;
}