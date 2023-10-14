class TokenList
{
public:
    // Returns all the tokens
    deque<Token> getItems()
    {
        return items;
    }

    // Returns the amount of elements of the list
    unsigned int size()
    {
        return getItems().size();
    }
    // If the token index exists, return that token
    Token get(unsigned short index = 1)
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

private:
    deque<Token> items;
};