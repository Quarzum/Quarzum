#pragma once
#include "../Quarzum.h"

class Tokenizer: public QComponent{

public:

    Tokenizer(const string input) : m_input(input) {}

    TokenList tokenize() {
        
        bool isComment = false;
        bool isSingleComment = false;
        bool isStringLiteral = false;

        for(; m_index < m_input.length(); ++m_index){

            char c = get(0);
            char next = get(1);

            if(c == '\n'){
                isSingleComment = false;
                m_line++;
                continue;
            }

            if(c == '"' && !isStringLiteral){
                isStringLiteral = true;
                consume();
                continue;
            }

            if(isStringLiteral){
                consume();
                if(next == '"'){
                    ++m_index;
                    consume();
                    isStringLiteral = false;
                    addToken(str_lit);
                }
                continue;
            }

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

            if(c == '/' && next == '/'){isSingleComment = true; ++m_index; continue;}

            if(not (isspace(c) || isComment || isSingleComment)){
                
                if(isalpha(c)){
                    consume();
                    if(not isalnum(next)){
                        addToken(TokenType(search(m_buff)));
                    }
                    continue;
                }
                
                if(isdigit(c)){
                    consume();
                    if(not isdigit(next)){
                        addToken(int_lit);
                    }
                    continue;
                }
                
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

    char get(const size_t n) const {
        if(n + m_index < m_input.size()){
            return m_input[m_index+n];
        }
        return 0;
    }

    void addToken(const TokenType t) {
        m_output.addToken({type: t, value: m_buff});
        m_buff.clear();
    }

    void consume() {
        m_buff += get(0);
    }

    bool opensComment(const char a, const char b) const {
        return a == '/' && b == '*';
    }

    bool closesComment(const char a, const char b) const {
        return a == '*' && b == '/';
    }
};