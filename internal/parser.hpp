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
                // <type> id = <expression>
                if (next(2).type == EQUAL)
                {
                    Expr e = parse_expr(3);
                    ast.addInit(t.type, next().value, e);
                }
                // <type> id (= null)
                else
                {
                    ast.addInit(t.type, next().value);
                }
            }

            i++;
        }
    }
    size_t i;

private:
    TokenList m_tokens;
    // Returns the next token in the TokenList
    Token next(short distance = 1)
    {
        return m_tokens.get(i + distance);
    }

    // Expression parsing procedure
    Expr parse_expr(short d = 1)
    {
        TokenType t = next(d).type;
        if (isTerm(t))
        {
            if (isOperator(next(d + 1).value[0]))
            {
                Expr expr = parse_expr(d + 2);
                // If the expression exists, it is (actually) a sum
                return Expr{{t, next(d).value + " " + next(d + 1).value[0] + " " + expr.literal.value}, 1 + expr.size};
            }
            return Expr{{t, next(d).value}, 1};
        }
        Error.exit(SYNTAX_ERROR, "Invalid expression");
        return {};
    }
};