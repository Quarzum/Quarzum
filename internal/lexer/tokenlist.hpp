class TokenList
{
public:
    TokenList(deque<Token> tokens = {})
    {
        items = tokens;
    }
    // Returns the amount of elements of the list
    size_t size()
    {
        return items.size();
    }
    // If the token index exists, return that token
    Token get(size_t index = 1)
    {
        if (index < size())
        {
            return items.at(index);
        }
        return {};
    }
    // Adds a new token to the list
    void addToken(TokenType type, string value)
    {
        items.push_back({type, value});
    }
    // Shows in console the result of Lexer (list of tokens)
    void debug(string title = "Token Stack")
    {
        if (SHOW_COMPILER_DEBUG)
        {
            cout << GRAY << "\n"
                 << title << "\n---------------------------\n"
                 << NC;
            int maxNameLength = 16;
            for (size_t i = 0; i < items.size(); i++)
            {
                string name = items[i].value;
                for (size_t j = 0; j < maxNameLength - items[i].value.length(); j++)
                {
                    name += " ";
                }
                string num = to_string(i);
                for (size_t n = 0; n < 4 - to_string(i).length(); n++)
                {
                    num += " ";
                }

                cout << GRAY << "| " << num << " | " << YELLOW << name << GRAY << " |\n]-------------------------[" << NC << endl;
            }
            cout << "\n";
        }
    }

    deque<Token> divide(int index, bool first)
    {
        deque<Token> result;
        if (first == true)
        {
            for (size_t i = 0; i < index; i++)
            {
                result.push_back(get(i));
            }
        }
        else
        {
            for (size_t i = index + 1; i < size(); i++)
            {
                result.push_back(get(i));
            }
        }
        return result;
    }

    void clear()
    {
        items.clear();
    }

    deque<Token> items;
};