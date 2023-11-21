#pragma once
#define nextc m_src.at(i + 1)
// Lexer complexity time: O(n)
class Lexer
{
#define advance \
    i++;        \
    continue
public:
    Lexer(string source) : m_src(move(source)) {}
    TokenList tokenize()
    {
        // Iterates through the source code characters to find patterns
        i = 0;
        line = 1;
        for (i; i < m_src.length(); i++)
        {
            char c = m_src.at(i);

            // Adds a new line
            if (c == '\n')
            {
                line++;
                if (isComment == "single")
                {
                    isComment = "none";
                }
                continue;
            }
            // Initiates a multiline comment
            else if (c == '/' and nextc == '*')
            {
                isComment = "multi";
                advance;
            }
            // Closes a multilne comment
            else if (c == '*' and nextc == '/' and isComment == "multi")
            {
                isComment = "none";
                advance;
            }
            // Adds a sngle line comment
            else if (c == '/' and nextc == '/' and isComment != "multi")
            {
                isComment = "single";
                advance;
            }
            else if (c == '"')
            {
                buffer.add(c);
                if (buffer.isFirstElement('"') and isStr == true)
                {

                    isStr = false;
                    tokens.addToken(STR, buffer.read());
                    buffer.clear();
                    continue;
                }
                isStr = true;
                continue;
            }
            else if (isStr == true)
            {
                buffer.add(c);
                continue;
            }
            else if (c == '\'')
            {
                buffer.add(c);
                if (buffer.isFirstElement('\'') and isChar == true)
                {

                    isChar = false;
                    tokens.addToken(CHAR, buffer.read());
                    buffer.clear();
                    continue;
                }
                isChar = true;
                continue;
            }
            else if (isChar == true)
            {
                buffer.add(c);
                continue;
            }
            else if (c == ';')
            {
                Debug.warn("Semicolon are not required.");
                continue;
            }
            else if (!isspace(c) and isComment == "none")
            {

                // If follows the pattern [a-zA-Z][a-zA-Z0-9]*
                if (isalpha(c))
                {
                    buffer.add(c);
                    if (not isalpha(nextc))
                    {
                        if (keywords.find(buffer.read()) == true)
                        {
                            tokens.addToken(TokenType(keywords.index(buffer.read())), buffer.read());
                        }
                        else
                        {
                            tokens.addToken(ID, buffer.read());
                        }
                        buffer.clear();
                        continue;
                    }
                    continue;
                }
                // If follows the pattern [0-9]+(.[0-9]*)?
                else if (isdigit(c) or c == '.')
                {
                    buffer.add(c);
                    if (c == '.')
                    {
                        isNum = true;
                    }
                    if (not isdigit(nextc) and nextc != '.')
                    {
                        if (isNum == true)
                        {
                            tokens.addToken(NUM, buffer.read());
                            isNum = false;
                        }
                        else
                        {
                            tokens.addToken(INT, buffer.read());
                        }
                        buffer.clear();
                    }
                    continue;
                }
                // If it is a recognized symbol
                else if (symbols.find(toStr(c)) == true)
                {
                    string composed = toStr(c) + toStr(nextc);
                    if (composedSymbols.find(composed) == true)
                    {
                        tokens.addToken(TokenType(composedSymbols.index(composed)), composed);
                        advance;
                    }
                    tokens.addToken(TokenType(symbols.index(toStr(c))), toStr(c));
                    continue;
                }
                Debug.err("Unexpected token \"" + toStr(c) + "\" at line " + to_string(line) + ".", "LexicalError");
            }
        }
        Debug.print();
        tokens.debug();

        return tokens;
    }

private:
    string m_src;
    TokenList tokens;
    size_t line, i;

    Buffer buffer;

    string isComment = "none";
    bool isNum, isStr, isChar;

    // Converts a char into str
    string toStr(char c)
    {
        string s(1, c);
        return s;
    }
};