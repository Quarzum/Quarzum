class Lexer
{
public:
    Lexer(string source) : m_src(move(source)) {}
    TokenList tokenize()
    {
        // Divides the string into tokens
        size_t size = m_src.length();
        i = 0;

        while (i < size)
        {
            for (auto rule : rules)
            {
                regex r(rule.first);
                if (createRule(r, rule.second))
                {
                    break;
                }
            }
            i++;
        }
        return tokens;
    }

private:
    string m_src;
    TokenList tokens;
    size_t line, i;

    map<string, TokenType> rules = {
        {"(-)?[1-9]*[0-9][\\.][0-9]+", NUMBER},
        {"0|(-)?[1-9][0-9]*", INT},
        {"int", INT_KEYWORD},
        {"\"[.]*\"", STRING},
        {"string", STRING_KEYWORD},
        {"num", NUMBER_KEYWORD},
        {"bool", BOOL_KEYWORD},
        {"any", ANY_KEYWORD},
        {"null", NULL_KEYWORD},
        {"function", FUNCTION_KEYWORD},
        {"return", RETURN},
        {"import", IMPORT},
        {"from", FROM},
        {"exit", EXIT},
        {"true|false", BOOL},
        {"struct", STRUCT_KEYWORD},
        {"enum", ENUM_KEYWORD},
        {"class", CLASS_KEYWORD},
        {"public", PUBLIC_KEYWORD},
        {"private", PRIVATE_KEYWORD},
        {"module", MODULE_KEYWORD},
        {"&&|and", AND},
        {"\\|\\||or", OR},
        {"!|not", NOT},
        {",", COMMA},
        {"\\.", POINT},
        {"\\(", PAR_OPEN},
        {"\\)", PAR_CLOSE},
        {"\\{", C_BRACKET_OPEN},
        {"\\}", C_BRACKET_CLOSE},
        {"\\[", S_BRACKET_OPEN},
        {"\\]", S_BRACKET_CLOSE},
        {"const", CONST},
        {"unsigned", UNSIGNED},
        {"short", SHORT},
        {"long", LONG},
        {"this", THIS},
        {"static", STATIC},
        {"delete", DELETE},
        {"if", IF},
        {"for", FOR},
        {"else", ELSE},
        {"while", WHILE},
        {"\\/\\/.*\n", COMMENT},
        {"\\/\\*(.|\n)*\\*\\/", COMMENT},
        {"=", EQUAL},
        {"[a-zA-Z]+", IDENTIFIER},

    };
    bool createRule(regex r, TokenType t)
    {
        string s = m_src.substr(i);
        smatch m;

        if (regex_search(s, m, r) && s.find(m.str(0)) == 0)
        {

            string value = m.str(0);
            if (t != COMMENT)
            {
                if (rules.find(value) != rules.end())
                {
                    tokens.addToken(rules.at(value), value);
                }
                else
                {
                    tokens.addToken(t, value);
                }
            }

            i += value.length() - 1;
            return 1;
        }
        return 0;
    }
};