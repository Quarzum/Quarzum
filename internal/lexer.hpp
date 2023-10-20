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
        regex bool_keyword("bool");
        regex null_keyword("null");
        regex any_keyword("any");
        regex equal("=");
        regex int_literal("[0-9]+");

        while (i < size)
        {
            addRule(int_literal, INT);
            addRule(int_keyword, INT_KEYWORD);
            addRule(str_keyword, STRING_KEYWORD);
            addRule(num_keyword, NUMBER_KEYWORD);
            addRule(bool_keyword, BOOL_KEYWORD);
            addRule(any_keyword, ANY_KEYWORD);
            addRule(equal, EQUAL);
            i++;
        }
        return tokens;
    }

private:
    string m_src;
    TokenList tokens;
    unsigned int size, line, i;

    void addRule(regex r, TokenType t)
    {
        string s = m_src.substr(i);
        smatch m;

        if (regex_search(s, m, r) && s.find(m.str(0)) == 0)
        {
            cout << m.str(0) << endl;
            tokens.addToken(t, m.str(0));
            i += m.str(0).length();
        }
    }
};