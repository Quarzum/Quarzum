#define buff_cl buffer.clear()
#define buff_add(c) buffer += c
#define nextc m_src.at(i + 1)
#define isKeyword keywords.find(buffer) != keywords.end()
#define isSymbol symbols.find(toStr(c)) != symbols.end()
// Lexer complexity time: O(n)
class Lexer
{
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
            if (c == '/' and nextc == '*')
            {
                isComment = "multi";
                i++;
                continue;
            }
            // Closes a multilne comment
            if (c == '*' and nextc == '/' and isComment == "multi")
            {
                isComment = "none";
                i++;
                continue;
            }
            // Adds a sngle line comment
            if (c == '/' and nextc == '/' and isComment != "multi")
            {
                isComment = "single";
                i++;
                continue;
            }
            if (c == '"')
            {
                buff_add(c);
                if (buffer[0] == '"' and isStr == true)
                {

                    isStr = false;
                    tokens.addToken(STR, buffer);
                    buff_cl;
                    continue;
                }
                isStr = true;
                continue;
            }
            if (isStr == true)
            {
                buff_add(c);
                continue;
            }
            if (c == '\'')
            {
                buff_add(c);
                if (buffer[0] == '\'' and isChar == true)
                {

                    isChar = false;
                    tokens.addToken(CHAR, buffer);
                    buff_cl;
                    continue;
                }
                isChar = true;
                continue;
            }
            if (isChar == true)
            {
                buff_add(c);
                continue;
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
                        continue;
                    }
                    continue;
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
                    continue;
                }
                // If it is a recognized symbol
                if (isSymbol)
                {
                    string composed = toStr(c) + toStr(nextc);
                    if (composedSymbols.find(composed) != composedSymbols.end())
                    {
                        tokens.addToken(TokenType(composedSymbols.at(composed)), composed);
                        i++;
                        continue;
                    }
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