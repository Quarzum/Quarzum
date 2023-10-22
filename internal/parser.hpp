class Parser
{
public:
    Parser(TokenList tokens) : m_tokens(move(tokens)) {}
    void parse()
    {

        i = 0;
        debug("Statements\n-------------");
        // Converts tokens into an AST
        while (i < m_tokens.size())
        {
            Token t = m_tokens.get(i);

            // <type> id
            if (isType(t.type) && next().type == IDENTIFIER)
            {
                // <type> id = <Expressionession>
                if (next(2).type == EQUAL)
                {
                    Expression e = parseExpr(3);
                    ast.addInit(t.type, next().value, e);
                    i += 3 + e.size;
                    continue;
                }
                // <type> id (= null)
                ast.addInit(t.type, next().value);
                i += 2;
                continue;
            }

            i++;
        }
    }
    size_t i;

private:
    TokenList m_tokens;
    // Returns the next token in the TokenList
    Token next(__int8 distance = 1)
    {
        return m_tokens.get(i + distance);
    }

    // Expression parsing procedure
    Expression parseExpr(__int8 num)
    {

        if (isTerm(next(num).type))
        {
            cout << "Is a valid term" << endl;

            return nullExpr;
        }

        Error.exit(SYNTAX_ERROR, "Expected expression");
        return nullExpr;
    }
};