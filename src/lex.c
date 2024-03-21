vector<Token> tokenize(const char* input) {

    size_t i;
    size_t len = strlen(input);
    size_t line = 1;
    string buffer;
    vector<Token> output;

    for(i = 0; i < len; ++i) {

        if(input[i] == '\'' && isascii(input[i + 1]) && input[i + 2] == '\'') {
            buffer += input[i++];
            buffer += input[i++];
            buffer += input[i];
            output.push_back(Token {
                .type = CharLit,
                .value = buffer
            });
            buffer.clear();
            continue;
        }

        if(input[i] == '"') {
            do {
                buffer.push_back(input[i++]);
            }
            while(input[i] != '"');
            buffer.push_back(input[i]);
            output.push_back(Token {
                .type = StringLit, 
                .value = buffer
            });
            buffer.clear();
            continue;
        } 

        if(input[i] == '/' && input[i + 1] == '*') {
            while(input[i] != '*' && input[i + 1] != '/') ++i;
            ++i;
            continue;
        }

        if(input[i] == '/' && input[i + 1] == '/') {
            while(input[i] != '\n') ++i;
            ++line;
            output.push_back(Token {
                .type = Endl,
                .value = "\n"
            });
            continue;
        }

        if(input[i] == '\n'){
            ++line;
            output.push_back(Token {
                .type = Endl,
                .value = "\n"
            });
            continue;
        }

        if(isspace(input[i])) continue;

        if(isalpha(input[i])) {
            buffer += input[i++];
            while(isalnum(input[i])) buffer += input[i++];
            TokenType t = TokenType(search(buffer));
            if(buffer == "true") buffer = "1";
            if(buffer == "false") buffer = "0";
            --i;
            printf("ID OR KEYWORD (%s) ", buffer.c_str());
            output.push_back(Token {
                .type = t,
                .value = buffer
            });
            buffer.clear();
            continue;
        }

        if(isdigit(input[i])){
            bool isFloat = false;
            buffer += input[i++];
            while (isdigit(input[i]) || (input[i] == '.' && !isFloat)) {
                if(input[i] == '.') {isFloat = true;}
                buffer += input[i++];
            }
            printf("NUMBER (%s) ", buffer.c_str());
            output.push_back(Token {
                .type = isFloat? NumberLit : IntegerLit,
                .value = buffer
            });
            buffer.clear();
            --i;
            continue;
        }

        if(isSymbol(input[i])) {
            buffer += input[i++];
            if(isSymbol(input[i])) {
                buffer += input[i];
                if(search(buffer) > 0) {
                    output.push_back(Token {
                        .type = TokenType(search(buffer)),
                        .value = buffer
                    });
                    buffer.clear();
                    continue;
                }
                buffer.pop_back();
            }
            --i;
            string s;
            s += input[i];
            printf("SYMBOL (%s) ", buffer.c_str());
            output.push_back(Token {
                .type = TokenType(search(s)),
                .value = buffer
            });
            buffer.clear();
            continue;
        }

        err("Unexpected token");

    }

    return output;
   
}