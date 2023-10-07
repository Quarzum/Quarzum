struct AST
{
    deque<Statement> statements;
};

class Parser
{
public:
    Parser(TokenList tokens) : m_tokens(move(tokens)) {}

    /* String parsing procedure */
    optional<string> parse_string(unsigned short int d = 1) {}

    AST parse()
    {
        i = 0;
        debug("Statements\n-------------");
        /* Converts tokens into an AST */
        while (i < m_tokens.size())
        {
            Token t = m_tokens.get(i);
            switch (t.type)
            {
            case OUT:
                if (followSyntax({PAR_OPEN, STRING_LITERAL, PAR_CLOSE}))
                {
                    // Add a print instruction
                    debug("OUT -> content: " + next(2).value);
                    i += 4;
                    // addStatement(Exit{}, 4);
                    break;
                }
                throwError(EXPECTED_EXPR);

            case EXIT:

                if (auto expr = parse_expr())
                {
                    // Add an int assign with value
                    debug("EXIT -> code: " + expr.value().literal.value);
                    addStatement(Exit{expr.value()}, 2);
                    break;
                }
                throwError(EXPECTED_EXPR);
            case RETURN:

                if (auto expr = parse_expr())
                {
                    // Add an int assign with value
                    debug("RETURN -> value: " + expr.value().literal.value);
                    addStatement(Return{expr.value()}, 2);
                    break;
                }

                throwError(EXPECTED_EXPR);

            case INT_KEYWORD:

                if (followSyntax({IDENTIFIER, EQUAL}))
                {
                    if (auto expr = parse_expr(3))
                    {
                        // Add an int assign with value
                        debug("INT_INIT -> id: " + next().value + ", value: " + expr.value().literal.value);
                        addStatement(Assign{INT_LITERAL, next(), expr.value()}, 4);

                        break;
                    }

                    throwError(EXPECTED_EXPR);
                }

                else if (followSyntax({IDENTIFIER}))
                {
                    // Add an int assign without value
                    debug("INT_INIT -> id: " + next().value + ", value: null");
                    addStatement(Assign{INT_LITERAL, next(), {NULL_KEYWORD, "null"}}, 2);
                    break;
                }

                throwError(SYNTAX_ERROR);

            case IDENTIFIER:

                if (followSyntax({EQUAL}))
                {
                    if (auto expr = parse_expr(2))
                    {
                        // Add an int assign with value
                        debug("REASSIGN -> id: " + next(0).value + ", new value: " + expr.value().literal.value);
                        addStatement(ReAssign{next(), expr.value()}, 3);
                        break;
                    }

                    throwError(EXPECTED_EXPR);
                }

                else if (followSyntax({OPERATOR, EQUAL}))
                {

                    if (auto expr = parse_expr(3))
                    {
                        // Add an int assign with value
                        debug("REASSIGN -> id: " + next(0).value + ", new value: " + next(0).value + next().value + expr.value().literal.value);
                        addStatement(ReAssign{next(), expr.value()}, 4);
                        break;
                    }

                    throwError(EXPECTED_EXPR);
                }

                throwError(SYNTAX_ERROR);

            default:
                i++;
                break;
            }
        }
        return ast;
    }

private:
    TokenList m_tokens;
    unsigned int i;
    AST ast;

    Token next(short unsigned int distance = 1)
    {
        /* Returns the next token in the TokenList */
        return m_tokens.get(i + distance);
    }
    void addStatement(Statement stat, short unsigned int size = 1)
    {
        /* Adds a new statement and increments i by the number of elements of the stat */
        ast.statements.push_back(stat);
        i += size;
    }
    bool followSyntax(deque<TokenType> syntax)
    {
        /* Comproves that a sentence follows a defined syntax step by step */
        bool result = true;
        for (int n = 0; n < syntax.size(); n++)
        {
            if (next(1 + n).type != syntax.at(n))
            {
                result = false;
            }
        }
        return result;
    }
    bool isTerm(unsigned short int d = 1)
    {
        return isLiteral(next(d).type) || next(d).type == IDENTIFIER;
    }
    /* Expr parsing procedure */
    optional<Expr> parse_expr(unsigned short int d = 1)
    {
        if (isTerm(d))
        {
            return Expr{next(d).type, next(d).value};
        }
        return {};
    }
};
