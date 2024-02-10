#include "../Quarzum.h"
#pragma once
class Tokenizer{
public:
    inline Tokenizer(const string src){
        this-> src = src;
    }
    /** 
     *   Converts an input string into a list of Tokens.
     *   @return A deque of tokens.
    */
    const TokenList tokenize() noexcept{
        for (index = 0; index <= src.length(); index++)
        {
            char c = get(0);
            char next = get(1);
            if(c == '\n'){
                line++;
                isSingleComment = false;
                continue;
            }
            if(c == '/'){
                if(next == '/'){
                    isSingleComment = true;
                    index++;
                    continue;
                }
                if(next == '*'){
                    isComment = true;
                    index++;
                    continue;
                }
            }
            if(c == '*' and next == '/'){
                isComment = false;
                index++;
                continue;
            }
            if(c == '"' && isStringLiteral == false){
                isStringLiteral = true;
                consume();
                continue;
            }
            else if(isStringLiteral == true){
                consume();
                if(next == '\"'){
                    consume(1);
                    index++;
                    isStringLiteral = false;
                    addToken(TokenType::str_lit);
                }
                continue;
            }
            if(not (isspace(c) || isComment || isSingleComment)){

                if(isalpha(c)){
                    consume();
                    if(!isalnum(next)){
                        addToken(TokenType(search(buffer, keywords, 36) + 1));
                    }
                    continue;
                }

                else if(isdigit(c)){
                    consume();
                    if(!isdigit(next)){
                        addToken(TokenType::int_lit);
                    }
                    continue;
                }

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
    string src, buffer;
    uint line = 1;
    uint index;
    TokenList output;
    bool isSingleComment, isComment, isStringLiteral;
    /**
     * Gets a character of the input
     * @param n The position distance between actual index and the desired character index
     * @return The [input + n] character
    */
    const char get(uint n) noexcept{
        if(index + n > src.length()){
            return '\0';
        }
        return src[index + n];
    }
    /**
     * Adds a new Token in the output Tokenlist and consumes the buffer.
     * @param t The new Token type
    */
    void addToken(TokenType t){
        output.addToken({t, buffer});
        buffer.clear();
    }
    /**
     * Adds a new character to the buffer
     * @param n The position distance between actual index and the desired character index
    */
    void consume(uint n = 0) noexcept{
        if(index + n > src.length()) return;
        buffer += get(n);
    }
};