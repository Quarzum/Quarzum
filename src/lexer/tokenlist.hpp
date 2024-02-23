#pragma once
// An object that stores a list of inmutable Tokens.
class TokenList{
public:
    // Adds a new Token to the TokenList
    void addToken(Token t) noexcept{ m_tokens.push_back(t); }

    // Returns the nth token. If that token doesn't exist, returns a null token.
    Token get(const size_t n) const noexcept{
        if(n > size()){
            return {};
        }
        return m_tokens.at(n);
    }

    // The size of the TokenList
    size_t size() const noexcept { return m_tokens.size(); }

    // Creates a TokenList that is a fragment of the original.
    TokenList divide(const size_t from = 0, const size_t to = 1) noexcept{
        TokenList result;
        for (size_t i = from; i < to; i++)
        {
            result.addToken(get(i));
        }
        return result;
    }
private:
    vector<Token> m_tokens;
};