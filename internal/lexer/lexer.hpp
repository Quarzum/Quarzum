#define SYMBOLS_I EQUAL

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
            if (c == '/' && m_src.at(i + 1) == '*')
            {
                isComment = "multi";
                i++;
                continue;
            }
            // Closes a multilne comment
            if (c == '*' && m_src.at(i + 1) == '/' && isComment == "multi")
            {
                isComment = "none";
                i++;
                continue;
            }
            // Adds a sngle line comment
            if (c == '/' && m_src.at(i + 1) == '/' && isComment != "multi")
            {
                isComment = "single";
                i++;
                continue;
            }

            if (!isspace(c) && isComment == "none")
            {
                // If follows the pattern [a-zA-Z][a-zA-Z0-9]*
                if (isalpha(c))
                {
                    buffer += c;
                    if (!isalnum(m_src.at(i + 1)))
                    {
                        if (buffer == "true" || buffer == "false")
                        {
                            tokens.addToken(BOOL, buffer);
                        }
                        else if (findKeyword(buffer) >= 0)
                        {
                            tokens.addToken(TokenType(findKeyword(buffer)), buffer);
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
                if (isdigit(c) || (c == '.' && isNum == false))
                {
                    buffer += c;
                    if (c == '.')
                    {
                        isNum = true;
                    }
                    if (!isdigit(m_src.at(i + 1)) && m_src.at(i + 1) != '.')
                    {
                        if (isNum)
                        {
                            tokens.addToken(NUM, buffer);
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
                if (symbols.find(c) >= 0)
                {
                    tokens.addToken(TokenType(SYMBOLS_I + symbols.find(c)), toStr(c));
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
    bool isNum;

    string keywords[13] = {"int", "num", "string", "bool", "any", "null", "const", "module", "return", "function", "not", "and", "or"};
    string symbols = "=+-*/%.,(){}[]";

    // Finds the number of index of an element inside an array
    int findKeyword(string key)
    {
        for (__int8 i = 0; i < keywords->size(); i++)
        {
            if (keywords[i] == key)
            {
                return i;
            }
        }
        return -1;
    }

    // Converts a char into string
    string toStr(char c)
    {
        string s(1, c);
        return s;
    }
};