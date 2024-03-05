#pragma once
#include "../Quarzum.h"
class Tokenizer: public QComponent{

public:

    Tokenizer(const string input) : m_input(input) {}

    TokenList tokenize() { 

        for(m_index = 0; m_index < m_input.length(); ++m_index){

            if(get(0) == '\'' && isascii(get(1)) && get(2) == '\''){
                consume();
                consume();
                consume();
                --m_index;
                addToken(char_lit);
                continue;
            }

            if(get(0) == '"') {
                do {
                    consume();
                }
                while(get(0) != '"');
                consume();
                --m_index;
                addToken(str_lit);
                continue;
            }

            if(get(0) == '/' && get(1) == '*') {
                while(get(0) != '*' || get(1) != '/') ++m_index;
                ++m_index;
                continue;
            }

            if(get(0) == '/' && get(1) == '/') {
                while(get(0) != '\n') ++m_index;
                ++m_line; 
                continue;
            }

            if(isspace(get(0))) continue;
                
            if(isalpha(get(0))) {
                consume();
                while(isalpha(get(0)) || isdigit(get(0))) consume();
                TokenType t = TokenType(search(m_buff));
                if(m_buff == "true") m_buff = "1";
                if(m_buff == "false") m_buff = "0";
                addToken(t);
                --m_index;
                continue;
            }
            
            if(isdigit(get(0))) {
                bool isFloat = false;
                consume();
                while(isdigit(get(0)) || (get(0) == '.' && !isFloat)) {
                    if(get(0) == '.') { isFloat = true; }
                    consume();
                }
                addToken(isFloat? num_lit : int_lit);
                --m_index;
                continue;
            }
            
            if( isSymbol(get(0))) {
                consume();
                if(isSymbol(get(0))) {
                    consume();
                    --m_index;
                    if(search(m_buff) > 0) {
                        addToken(TokenType( search(m_buff) + 512));
                        continue;
                    }
                    else m_buff.pop_back();
                }
                --m_index;
                string s;
                s += get(0);
                addToken(TokenType( search(s) + 512 ));
                continue;
            }
            errorHandler.err({lexical_err, m_line, "Unexpected token " + get(0)});
                   
        }
        errorHandler.run();
        return m_output;
    }
private:

    size_t m_index;
    size_t m_line  { 1 };
    string m_input, m_buff;
    TokenList m_output;

    char get(const size_t n) const {
        if(n + m_index < m_input.size()) return m_input[m_index+n];
        return 0;
    }

    void addToken(const TokenType t) {
        m_output.addToken({type: t, value: m_buff});
        m_buff.clear();
    }

    void consume() {
        m_buff += get(0);
        ++m_index;
    }

};