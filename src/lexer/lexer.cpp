#pragma once
#include "../Quarzum.h"
class Tokenizer: public QComponent{
public:
    // Constructor
    Tokenizer(const string input) : m_input(input) {}

    // Converts an input string into a list of Tokens.
    TokenList tokenize() noexcept{
        
        bool isComment = false;
        bool isSingleComment = false;
        bool isStringLiteral = false;

        for(; m_index < m_input.length(); ++m_index){
            // The actual character
            char c = get();
            // The next character (null if c is the last character)
            char next = get(1);

            // If there is a new m_line, sum 1 to the m_line number
            if(c == '\n'){
                isSingleComment = false;
                m_line++;
                continue;
            }
            if(c == '"' and not isStringLiteral){
                isStringLiteral = true;
                consume();
                continue;
            }
            if(isStringLiteral){
                consume();
                if(next == '"'){
                    consume(1);
                    isStringLiteral = false;
                    addToken(str_lit);
                }
                continue;
            }
            // Multim_line and single m_line comments
            if(opensComment(c, next)){
                isComment = true; 
                ++m_index; 
                continue;
            }
            if(closesComment(c, next)){
                isComment = false; 
                ++m_index;
                continue;
            }
            if(c == '/' and next == '/'){isSingleComment = true; ++m_index; continue;}

            if(not (isspace(c) or isComment or isSingleComment)){
                // [a-zA-Z][a-zA-Z0-9]+
                if(isalpha(c)){
                    consume();
                    if(not isalnum(next)){
                        addToken(TokenType(search(m_buff)));
                    }
                    continue;
                }
                // [0-9]+
                if(isdigit(c)){
                    consume();
                    if(not isdigit(next)){
                        addToken(int_lit);
                    }
                    continue;
                }
                // Punctuation
                if(search(c) > 0){
                    consume();
                    addToken(TokenType(search(c) + 512));
                    continue;
                }
                errorHandler.err({lexical_err, m_line, "Unexpected token " + c});
            }        
        }
        errorHandler.run();
        return m_output;
    }
private:
    size_t m_index { 0 };
    size_t m_line  { 1 };
    string m_input, m_buff;
    TokenList m_output;

    // Returns the char at the (n + i) position. If the index is out of range, returns a null character.
    char get(const size_t n = 0) const noexcept{
        if(n + m_index < m_input.size()){
            return m_input[m_index+n];
        }
        return 0;
    }

    // Adds a new Token to the TokenList and clears the buffer.
    void addToken(const TokenType t) noexcept{
        m_output.addToken({t,m_buff});
        m_buff.clear();
    }

    // The buffer will consume the character, advancing the index.
    void consume(const size_t n = 0) noexcept{
        m_buff += get(n);
        m_index += n;
    }
    bool opensComment(const char a, const char b) const noexcept {
        return a == '/' and b == '*';
    }
    bool closesComment(const char a, const char b) const noexcept {
        return a == '*' and b == '/';
    }
};