class Parser
{
public:
    Parser(TokenList tokens) : m_tokens(move(tokens)) {}
    void parse()
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
                if (followSyntax({PAR_OPEN}))
                {
                    expr = parse_expr(2);
                    // Add a print instruction
                    if (next(3).type == PAR_CLOSE)
                    {
                        debug("OUT -> content: " + expr.literal.value);
                        i += expr.size;
                        break;
                    }
                }
                Error.exit(SYNTAX_ERROR, "Expected string");

            case INPUT:
                if (followSyntax({PAR_OPEN}))
                {
                    expr = parse_expr(2);
                    // Add an input instruction
                    if (next(3).type == PAR_CLOSE)
                    {
                        debug("OUT -> content: " + expr.literal.value);
                        i += expr.size;
                        break;
                    }
                }
                Error.exit(SYNTAX_ERROR, "Expected string");

            case EXIT:
                expr = parse_expr();
                // Add an exit expression
                ast.addExit(expr);
                i += 1 + expr.size;
                break;

            case RETURN:
                expr = parse_expr();
                // Add a return expression
                ast.addReturn(expr);
                i += 1 + expr.size;
                break;

            case DELETE:
                if (followSyntax({IDENTIFIER}))
                {
                    // Removes an existing variable
                    VariableStack.remove(next().value);
                    debug("DELETE -> id: " + next().value);
                    i += 2;
                    break;
                }
                Error.exit(SYNTAX_ERROR);

            /*

            Add a new assignation based on the type

            */
            case BOOL_KEYWORD:
                addAssignation(BOOL);
                break;

            case INT_KEYWORD:
                addAssignation(INT);
                break;

            case NUMBER_KEYWORD:
                addAssignation(NUMBER);
                break;

            case STRING_KEYWORD:
                addAssignation(STRING);
                break;

            case ANY_KEYWORD:
                addAssignation(ANY);
                break;

            case IDENTIFIER:

                if (followSyntax({EQUAL}))
                {
                    expr = parse_expr(2);
                    // Add a reassign with value
                    ast.addAssign(next(0), expr);
                    i += 2 + expr.size;
                    break;
                }

                else if (followSyntax({OPERATOR, EQUAL}))
                {
                    expr = parse_expr(3);
                    // Add a reassign with value
                    debug("REASSIGN -> id: " + next(0).value + ", new value: " + next(0).value + next().value + expr.literal.value);
                    addStatement(ReAssign{next(), expr}, 3 + expr.size);
                    break;
                }

                else if ((next().value + next(2).value) == "++")
                {

                    ast.addUnaryPlus(next(0));
                    i += 3;
                    break;
                }

                else if ((next().value + next(2).value) == "--")
                {
                    ast.addUnaryMinus(next(0));
                    i += 3;
                    break;
                }

                Error.exit(SYNTAX_ERROR, "Expected assignation");

            default:
                i++;
                break;
            }
        }
        // debugVariables();
    }
    unsigned short i;

private:
    TokenList m_tokens;

    Token next(short distance = 1)
    {
        /*

        Returns the next token in the TokenList

        */
        return m_tokens.get(i + distance);
    }
    void addStatement(Statement stat, short size = 1)
    {
        /*

        Adds a new statement and increments i by the number of elements of the stat

        */
        ast.nodes.push_back(stat);
        i += size;
    }
    bool followSyntax(deque<TokenType> syntax)
    {
        /*

        Checks that a sentence follows a defined syntax step by step

        */
        bool result = true;
        for (unsigned short n = 0; n < syntax.size(); n++)
        {
            if (next(1 + n).type != syntax.at(n))
            {
                result = false;
            }
        }
        return result;
    }
    /*

    Expression parsing procedure

    */
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
    void addAssignation(TokenType type)
    {
        VariableStack.add(next().value);
        /*

        Adds a new assignation depending on the type

        */
        if (followSyntax({IDENTIFIER, EQUAL}))
        {
            // Add an assign with value
            Expr expr = parse_expr(3);
            ast.addInit(type, next(), expr);
            i += 3 + expr.size;
        }
        else if (followSyntax({IDENTIFIER}))
        {
            // Add an assign without value
            ast.addInit(type, next());
            i += 2;
        }
        else
        {
            Error.exit(SYNTAX_ERROR, "Expected an initializer");
        }
    }
};
