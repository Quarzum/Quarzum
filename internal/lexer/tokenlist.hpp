class TokenList
{
public:
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

    deque<Token> items;
};