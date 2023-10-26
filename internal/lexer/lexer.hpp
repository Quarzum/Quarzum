// Lexer complexity time: O(n)
class Lexer
{
public:
    Lexer(string source) : m_src(move(source)) {}
    TokenList tokenize()
    {
        // Iterates through the source code characters to find patterns
        size_t size = m_src.length();
        i = 0;
        line = 1;
        for (i; i < size; i++)
        {
            char c = m_src.at(i);

            // Adds a new line
            if (c == '\n')
            {
                line++;
                if (isComment == "single")
                {
                    isComment = "none";
                }
                continue;
            }
            // Initiates a multiline comment
            if (c == '/' and m_src.at(i + 1) == '*')
            {
                isComment = "multi";
                i++;
                continue;
            }
            // Closes a multilne comment
            if (c == '*' and m_src.at(i + 1) == '/' and isComment == "multi")
            {
                isComment = "none";
                i++;
                continue;
            }
            // Adds a sngle line comment
            if (c == '/' and m_src.at(i + 1) == '/' and isComment != "multi")
            {
                isComment = "single";
                i++;
                continue;
            }
            if (c == '"')
            {
                buffer += c;
                if (buffer[0] == '"' and isStr == true)
                {

                    isStr = false;
                    tokens.addToken(STR, buffer);
                    buffer.clear();
                    continue;
                }
                isStr = true;
                continue;
            }
            if (isStr == true)
            {
                buffer += c;
                continue;
            }
            if (c == '\'')
            {
                buffer += c;
                if (buffer[0] == '\'' and isChar == true)
                {

                    isChar = false;
                    tokens.addToken(CHAR, buffer);
                    buffer.clear();
                    continue;
                }
                isChar = true;
                continue;
            }
            if (isChar == true)
            {
                buffer += c;
                continue;
            }
            if (!isspace(c) and isComment == "none")
            {

                // If follows the pattern [a-zA-Z][a-zA-Z0-9]*
                if (isalpha(c))
                {
                    buffer += c;
                    if (!isalpha(m_src.at(i + 1)))
                    {
                        if (buffer == "true" or buffer == "false")
                        {
                            tokens.addToken(BOOL, buffer);
                        }
                        else if (keywords.find(buffer) != keywords.end())
                        {
                            tokens.addToken(TokenType(keywords.at(buffer)), buffer);
                        }
                        else
                        {
                            tokens.addToken(ID, buffer);
                        }
                        buffer.clear();
                        continue;
                    }
                    continue;
                }
                // If follows the pattern [0-9]+(.[0-9]*)?
                else if (isdigit(c) or c == '.')
                {
                    buffer += c;
                    if (c == '.')
                    {
                        isNum = true;
                    }
                    if (!isdigit(m_src.at(i + 1)) and m_src.at(i + 1) != '.')
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
                        buffer.clear();
                    }
                    continue;
                }
                // If it is a recognized symbol
                else if (symbols.find(toStr(c)) != symbols.end())
                {
                    tokens.addToken(TokenType(symbols.at(toStr(c))), toStr(c));
                    continue;
                }
                Error.exit(LEXICAL_ERROR, "Unexpected token \"" + toStr(c) + "\" at line " + to_string(line));
            }
        }
        return tokens;
    }

private:
    string m_src, buffer;
    TokenList tokens;
    size_t line, i;

    string isComment = "none";
    bool isNum, isStr, isChar;

    // Converts a char into string
    string toStr(char c)
    {
        string s(1, c);
        return s;
    }
};