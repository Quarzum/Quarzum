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
            Expr expr;
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
                expr = parse_expr();
                // Add an int assign with value
                debug("EXIT -> code: " + expr.literal.value);
                addStatement(Exit{expr}, 2);
                break;

            case RETURN:
                expr = parse_expr();
                // Add an int assign with value
                debug("RETURN -> value: " + expr.literal.value);
                addStatement(Return{expr}, 2);
                break;

            case INT_KEYWORD:

                if (followSyntax({IDENTIFIER, EQUAL}))
                {
                    expr = parse_expr(3);

                    // Add an int assign with value
                    debug("INT_INIT -> id: " + next().value + ", value: " + expr.literal.value);
                    addStatement(Assign{INT_LITERAL, next(), expr}, 4);
                    break;
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
                    expr = parse_expr(2);

                    // Add an int assign with value
                    debug("REASSIGN -> id: " + next(0).value + ", new value: " + expr.literal.value);
                    addStatement(ReAssign{next(), expr}, 3);
                    break;
                }

                else if (followSyntax({OPERATOR, EQUAL}))
                {

                    expr = parse_expr(3);
                    // Add an int assign with value
                    debug("REASSIGN -> id: " + next(0).value + ", new value: " + next(0).value + next().value + expr.literal.value);
                    addStatement(ReAssign{next(), expr}, 4);
                    break;
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
    bool isTerm(TokenType t)
    {
        return isLiteral(t) || t == IDENTIFIER;
    }
    /* Expr parsing procedure */
    Expr parse_expr(unsigned short int d = 1)
    {
        if (isTerm(next(d).type))
        {
            return Expr{next(d).type, next(d).value};
        }
        throwError(EXPECTED_EXPR);
    }
};
