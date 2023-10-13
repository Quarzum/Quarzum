class TokenList
{
public:
    deque<Token> getItems()
    {
        /*

        Returns all the tokens

        */
        return items;
    }

    unsigned int size()
    {
        /*

        Returns the amount of elements of the list

        */
        return getItems().size();
    }
    Token get(uint16_t index = 1)
    {
        /*

        If the token index exists, return that token

        */
        if (index < size())
        {
            return items.at(index);
        }
        return {};
    }
    void addToken(TokenType type, string value)
    {
        /*

        Adds a new token to the list

        */
        items.push_back({type, value});
    }

private:
    deque<Token> items;
};