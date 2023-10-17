class Lexer
{
public:
    Lexer(string source) : m_src(move(source)) {}
    TokenList tokenize()
    {
        /*

        Divides the string into tokens

        */
        size = m_src.length();
        while (i < size)
        {
            c = m_src.at(i);
            if (c == '\n')
            {
                isSingleComment = false;
                line++;
            }
            else if (c == '"')
            {
                addToBuffer();
                if (isException() && buffer.length() > 1)
                {
                    addToken(STRING, buffer);
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
                    addToken(isNum ? NUMBER : INT, buffer);
                    isNum = false;
                }
            }
            else if (ispunct(c))
            {

                if (isException())
                {
                    addToBuffer();
                }
                else if (c == '/' && next() == '/')
                {
                    isSingleComment = true;
                    i++;
                }
                else if (c == '/' && next() == '*')
                {
                    isComment = true;
                    i++;
                }
                else if (c == '*' && next() == '/')
                {
                    isComment = false;
                    i++;
                }
                else if (isOperator(c))
                {
                    addToken(OPERATOR, toString(c));
                }
                else if (isSymbol(c))
                {
                    addToken(TokenType(symbols.at(c)), toString(c));
                }
            }
            else if (!isException() && !isspace(c) && !isComment && !isSingleComment)
            {
                Error.exit(LEXICAL_ERROR, "Unexpected token " + toString(c) + " at line " + to_string(line));
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
    bool isEOF(unsigned short d)
    {
        /*

        Returns true if m_src[i] is the final character

        */
        return i + d > size;
    };
    char next(short distance = 1)
    {
        /*

        Returns the next character if it exists

        */
        if (!isEOF(distance))
        {
            return m_src.at(i + distance);
        }
        return {};
    }
    void addToken(TokenType type, string value)
    {
        /*

        Adds a new token to the deque

        */
        if (!isSingleComment && !isComment)
        {
            tokens.addToken(type, value);
            buffer.clear();
        }
    }
    bool isException()
    {
        /*

        Returns if the begin of the buffer is a quote

        */
        return buffer[0] == '"';
    }
    void addToBuffer()
    {
        if (!isSingleComment && !isComment)
        {
            buffer += c;
        }
    }
    bool isSingleComment = false;
    bool isComment = false;
};