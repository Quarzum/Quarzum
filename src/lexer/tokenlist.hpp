#pragma once
// An object that stores a list of inmutable Tokens.
class TokenList {

public:

    void addToken(const Token t){ m_tokens.push_back(t); }

    Token get(const size_t n) const{
        if(n > size()){
            return {};
        }
        return m_tokens.at(n);
    }

    size_t size() const{ return m_tokens.size(); }

    // Creates a TokenList that is a fragment of the original.
    TokenList divide(const size_t from = 0, const size_t to = 1) {
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