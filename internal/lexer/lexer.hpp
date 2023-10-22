#define SYMBOLS_I EQUAL

/* Lexer complexity time: O(n)*/
class Lexer
{
public:
    Lexer(string source) : m_src(move(source)) {}
    TokenList tokenize()
    {
        // Divides the string into tokens
        size_t size = m_src.length();
        i = 0;

        for (i; i < size; i++)
        {
            char c = m_src.at(i);

            if (c == '\n')
            {
                line++;
                if (isComment == "single")
                {
                    isComment = "none";
                }
                continue;
            }

            if (c == '/' && m_src.at(i + 1) == '*')
            {
                isComment = "multi";
                i++;
                continue;
            }
            if (c == '*' && m_src.at(i + 1) == '/' && isComment == "multi")
            {
                isComment = "none";
                i++;
                continue;
            }
            if (c == '/' && m_src.at(i + 1) == '/' && isComment != "multi")
            {
                isComment = "single";
                i++;
                continue;
            }

            if (!isspace(c) && isComment == "none")
            {

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

    string keywords[6] = {"int", "num", "string", "bool", "any", "null"};
    string symbols = "=+";

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

    string toStr(char c)
    {
        string s(1, c);
        return s;
    }
};