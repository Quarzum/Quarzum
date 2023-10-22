
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
                continue;
            }
            if (!isspace(c))
            {
                if (isalpha(c))
                {
                    buffer += c;
                    if (!isalnum(m_src.at(i + 1)))
                    {
                        cout << buffer;
                        if (keywords->find(buffer) > 0)
                        {
                        }
                        buffer.clear();
                        continue;
                    }
                    continue;
                }
                if (symbols.find(c) > 0)
                {
                    cout << "s";
                    continue;
                }
            }
        }
        return tokens;
    }

private:
    string m_src, buffer;
    TokenList tokens;
    size_t line, i;

    string keywords[2] = {"int", "num"};
    string symbols = "=";
};