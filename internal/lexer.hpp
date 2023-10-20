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
        i = 0;

        regex int_keyword("int");
        regex str_keyword("string");
        regex num_keyword("number");
        regex equal("=");
        regex int_literal("[0-9]+");

        while (i < size)
        {
            addRule(int_literal, INT);
            addRule(int_keyword, INT_KEYWORD);
            addRule(str_keyword, STRING_KEYWORD);
            addRule(equal, EQUAL);
            i++;
            /*
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
            */
        }
        return tokens;
    }

private:
    string m_src, buffer;
    TokenList tokens;
    unsigned int size, line, i;
    char c;
    bool isNum;

    char next(short distance = 1)
    {
        /*

        Returns the next character if it exists

        */
        if (i + distance < size)
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

    bool addRule(regex r, TokenType t)
    {
        string s = m_src.substr(i);
        cout << "------\n"
             << s << "--------\n";
        smatch m;

        if (regex_search(s, m, r) && s.find(m.str(0)) == 0)
        {
            cout << m.str(0) << endl;
            addToken(t, m.str(0));
            i += m.str(0).length();

            return 1;
        }
        return 0;
    }
};