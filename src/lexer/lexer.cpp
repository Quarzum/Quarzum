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
     *   Algorithm time complexity: O(n).
     *   @return A deque of tokens.
    */
    const TokenList tokenize(){
        bool isComment = false;
        bool isSingleComment = false;
        bool isStringLiteral = false;

        for(i = 0; i < input.length(); i++){
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
            // Multiline and single line comments
            if(opensComment(c, next)){
                isComment = true; 
                i++; 
                continue;
            }
            if(closesComment(c, next)){
                isComment = false; 
                i++;
                continue;
            }
            if(c == '/' and next == '/'){isSingleComment = true; i++; continue;}

            if(not (isspace(c) or isComment or isSingleComment)){
                // [a-zA-Z][a-zA-Z0-9]+
                if(isalpha(c)){
                    consume();
                    if(not isalnum(next)){
                        addToken(TokenType(search(buffer)));
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
                wcerr << "Lexical Error: Unexpected token " << charToString(c) << " at line " << to_wstring(line) << ".\n";
            }        
        }
        return output;
    }
private:
    uint i, line;
    string input, buffer;
    TokenList output;
    /**
     * Returns the char at the (n + i) position. 
     * If the index is out of range, returns a null character.
    */
    char get(uint n = 0) const{
        if(n + i < input.size()){
            return input[i+n];
        }
        return 0;
    }
    /**
     * Adds a new Token to the TokenList and clears the buffer.
    */
    void addToken(TokenType t){
        output.addToken({t, buffer});
        buffer.clear();
    }
    /**
     * The buffer will consume the character, advancing the index.
    */
    void consume(uint n = 0){
        buffer += get(n);
        i += n;
    }
    bool opensComment(char a, char b){
        return a == '/' and b == '*';
    }
    bool closesComment(char a, char b){
        return a == '*' and b == '/';
    }
};