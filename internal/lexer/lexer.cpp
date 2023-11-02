#pragma once
#define buff_cl buffer.clear()
#define buff_add(c) buffer.push_back(c)
#define nextc m_src.at(i + 1)
#define isKeyword keywords.find(buffer) != keywords.end()
#define isSymbol symbols.find(toStr(c)) != symbols.end()
// Lexer complexity time: O(n)
class Lexer
{
#define advance \
    i++;        \
    continue
public:
    Lexer(string source) : m_src(move(source)) {}
    TokenList tokenize()
    {
        // Iterates through the source code characters to find patterns
        i = 0;
        line = 1;
        for (i; i < m_src.length(); i++)
        {
            char c = m_src.at(i);

            switch (c)
            {
            // Adds a new line
            case '\n':
                line++;
                if (isComment == "single")
                {
                    isComment = "none";
                }
                break;

            case '/':
                // Initiates a multiline comment
                if (nextc == '*')
                {
                    isComment = "multi";
                    break;
                }
                // Adds a sngle line comment
                if (nextc == '/' and isComment != "multi")
                {
                    isComment = "single";
                    break;
                }
                // Adding a divide-equal token (/=)
                if (nextc == '=')
                {
                    tokens.addToken(DIVIDE_EQUAL, "/=");
                    break;
                }
                // Adding a divide token (/)
                tokens.addToken(DIVIDE, "/");
                break;

            case '"':

                buff_add(c);
                // Closes a string token
                if (buffer[0] == '"' and isStr == true)
                {

                    isStr = false;
                    tokens.addToken(STR, buffer);
                    buff_cl;
                    break;
                }
                // Adds a string token
                isStr = true;
                break;

            case '*':
                // Closes a multiline comment
                if (nextc == '/' and isComment == "multi")
                {
                    isComment = "none";
                    break;
                }
                // Adding a prod-equal token (*=)
                if (nextc == '=')
                {
                    tokens.addToken(PROD_EQUAL, "*=");
                    break;
                }
                // Adding a product token (*)
                tokens.addToken(PRODUCT, "*");
                break;

            case '\'':
                buff_add(c);
                // Closes char token
                if (buffer[0] == '\'' and isChar == true)
                {
                    isChar = false;
                    tokens.addToken(CHAR, buffer);
                    buff_cl;
                    break;
                }
                // Opens a char token
                isChar = true;
                break;

            default:
                if (isStr == true)
                {
                    buff_add(c);
                    break;
                }
                if (isChar == true)
                {
                    buff_add(c);
                    break;
                }
                if (!isspace(c) and isComment == "none")
                {
                    // If follows the pattern [a-zA-Z][a-zA-Z0-9]*
                    if (isalpha(c))
                    {
                        buff_add(c);
                        if (not isalpha(nextc))
                        {
                            if (isKeyword)
                            {
                                tokens.addToken(TokenType(keywords.at(buffer)), buffer);
                            }
                            else
                            {
                                tokens.addToken(ID, buffer);
                            }
                            buff_cl;
                        }
                        break;
                    }
                    // If follows the pattern [0-9]+(.[0-9]*)?
                    if (isdigit(c) or c == '.')
                    {
                        buff_add(c);
                        if (c == '.')
                        {
                            isNum = true;
                        }
                        if (not isdigit(nextc) and nextc != '.')
                        {
                            if (isNum == true)
                            {
                                tokens.addToken(NUM, buffer);
                                isNum = false;
                            }
                            else
                            {
                                tokens.addToken(INT, buffer);
                            }
                            buff_cl;
                        }
                        break;
                    }

                    if (isSymbol)
                    {
                        string composed = toStr(c) + toStr(nextc);
                        if (composedSymbols.find(composed) != composedSymbols.end())
                        {
                            tokens.addToken(TokenType(composedSymbols.at(composed)), composed);
                            advance;
                        }
                        tokens.addToken(TokenType(symbols.at(toStr(c))), toStr(c));
                        break;
                    }
                    Error.exit(LEXICAL_ERROR, "Unexpected token \"" + toStr(c) + "\" at line " + to_string(line));
                }
                break;
            }
        }

        tokens.debug();
        return tokens;
    }

private:
    string m_src, buffer;
    TokenList tokens;
    size_t line, i;

    string isComment = "none";
    bool isNum, isStr, isChar;

    // Converts a char into str
    string toStr(char c)
    {
        string s(1, c);
        return s;
    }
};