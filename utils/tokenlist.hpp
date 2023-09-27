class TokenList
{
public:
    deque<Token> getItems()
    {
        return items;
    }

    unsigned int size()
    {
        return getItems().size();
    }
    Token get(unsigned short int index)
    {
        if (index < size())
        {
            return items.at(index);
        }
        return {};
    }
    void addToken(TokenType type, string value)
    {
        items.push_back({type, value});
    }

private:
    deque<Token> items;
};