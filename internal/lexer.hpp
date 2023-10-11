class Lexer
{
public:
    Lexer(string source) : m_src(move(source)) {}
    TokenList tokenize()
    {
        /* Divides the string into single tokens */
        size = m_src.length();
        while (i < size)
        {
            c = m_src.at(i);
            if (c == '\n')
            {
                line++;
            }
            else if (c == '"')
            {
                addToBuffer();
                if (isException() && buffer.length() > 1)
                {
                    addToken(STRING_LITERAL, buffer);
                }
            }
            else if (isalpha(c))
            {
                addToBuffer();
                if (!isException() && !isalnum(next()))
                {
                    addToken(isKeyword(buffer) ? TokenType(findKeyword(buffer)) : IDENTIFIER, buffer);
                }
            }
            else if (isdigit(c) || c == '.')
            {
                addToBuffer();
                if (c == '.')
                {
                    isNum = true;
                }
                if (!isException() && !(isdigit(next()) || next() == '.'))
                {
                    if (isNum && buffer[buffer.length() - 1] == '.')
                    {
                        buffer += '0';
                    }
                    addToken(isNum ? NUMBER_LITERAL : INT_LITERAL, buffer);
                    isNum = false;
                }
            }
            else if (ispunct(c))
            {
                if (isException())
                {
                    addToBuffer();
                }
                else if (isOperator(c))
                {
                    addToken(OPERATOR, toString(c));
                }
                else if (isSymbol(c))
                {
                    addToken(TokenType(symbols.at(c)), toString(c));
                }
                else
                {
                    throwError(LEXICAL_ERROR, "Unexpected token " + c);
                }
            }
            else if (!isException() && !isspace(c))
            {
                throwError(LEXICAL_ERROR, "Unexpected token " + toString(c) + " at line " + to_string(line));
            }
            i++;
        }
        return tokens;
    }

private:
    string m_src, buffer;
    TokenList tokens;
    unsigned int size, line, i = 0;
    char c;
    bool isNum;
    bool isEOF(__int8 d)
    {
        /* Returns true if m_src[i] is the final character */
        return i + d > size;
    };
    char next(__int8 distance = 1)
    {
        /* Returns the next character if it exists*/
        if (!isEOF(distance))
        {
            return m_src.at(i + distance);
        }
        return {};
    }
    void addToken(TokenType type, string value)
    {
        /* Adds a new token to the deque */
        tokens.addToken(type, value);
        buffer.clear();
    }
    bool isException()
    {
        /* Returns if the begin of the buffer is a quote */
        return buffer[0] == '"';
    }
    void addToBuffer()
    {
        buffer += c;
    }
};