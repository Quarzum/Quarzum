#include "../Quarzum.h"
#pragma once

class Tokenizer{
public:
    // Constructor
    Tokenizer(const string input){
        this -> input = input;
        this -> output = TokenList();
        line = 1;
    }
    /** 
     *   Converts an input string into a list of Tokens.
     *   @return A deque of tokens.
    */
    const TokenList tokenize() noexcept{
        bool isComment = false;
        bool isSingleComment = false;
        bool isStringLiteral = false;

        repeat(i, input.length() + 1){
            // The actual character
            char c = get();
            // The next character (null if c is the last character)
            char next = get(1);

            // If there is a new line, sum 1 to the line number
            if(c == '\n'){
                isSingleComment = false;
                line++;
                continue;
            }
            else if(c == '"' and isStringLiteral == false){
                isStringLiteral = true;
                consume();
                continue;
            }
            else if(isStringLiteral == true){
                consume();
                if(next == '\"'){
                    consume(1);
                    isStringLiteral = false;
                    addToken(str_lit);
                }
                continue;
            }
            // Multiline and single line comments
            else if(c == '/' and next == '*'){isComment = true; i++; continue;}
            else if(c == '*' and next == '/'){isComment = false; i++; continue;}
            else if(c == '/' and next == '/'){isSingleComment = true; i++; continue;}


            else if(not (isspace(c) or isComment or isSingleComment)){
                // [a-zA-Z][a-zA-Z0-9]+
                if(isalpha(c)){
                    consume();
                    if(not isalnum(next)){
                        addToken(TokenType(search(buffer, keywords, 38) + 1));
                    }
                    continue;
                }
                // [0-9]*
                else if(isdigit(c)){
                    consume();
                    if(not isdigit(next)){
                        addToken(int_lit);
                    }
                    continue;
                }
                // Punctuation
                else if(isSymbol(c)){
                    consume();
                    addToken(TokenType(search(buffer, symbols, 28) + 0x201));
                    continue;
                }
                else{
                    wcerr << "Lexical Error: Unexpected token " << charToString(c) << " at line " << to_wstring(line) << ".\n";
                }
            }        
        }
        return output;
    }
private:
    uint i, line;
    string input, buffer;
    TokenList output;
    char get(uint n = 0){
        if(n + i < input.size()){
            return input[i+n];
        }
        return 0;
    }
    void addToken(TokenType t){
        output.addToken({t, buffer});
        buffer.clear();
    }
    void consume(uint n = 0){
        buffer += get(n);
        i += n;
    }
};
