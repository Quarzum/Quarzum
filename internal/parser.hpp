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
            Expr expr;

            Token t = m_tokens.get(i);
            switch (t.type)
            {
            case MODULE_KEYWORD:
                if (followSyntax({IDENTIFIER, C_BRACKET_OPEN}))
                {
                    ast.addModule(next().value);
                    advance(3);
                    break;
                }
                Error.exit(SYNTAX_ERROR, "Expected module name");
            case OUT:
                if (followSyntax({PAR_OPEN}))
                {
                    expr = parse_expr(2);
                    // Add a print instruction
                    if (next(3).type == PAR_CLOSE)
                    {
                        debug("OUT -> content: " + expr.literal.value);
                        advance(expr.size);
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
                        debug("INPUT -> content: " + expr.literal.value);
                        advance(expr.size);
                        break;
                    }
                }
                Error.exit(SYNTAX_ERROR, "Expected string");
            // Add an exit expression
            case EXIT:
                expr = parse_expr();
                ast.addExit(expr);
                advance(1 + expr.size);
                break;
            // Add a return expression
            case RETURN:
                expr = parse_expr();
                ast.addReturn(expr);
                advance(1 + expr.size);
                break;
            // Removes an existing variable
            case DELETE:
                if (followSyntax({IDENTIFIER}))
                {
                    ast.addDelete(next().value);
                    advance(2);
                    break;
                }
                Error.exit(SYNTAX_ERROR);

            // Add a BOOL assign
            case BOOL_KEYWORD:
                addAssignation(BOOL);
                break;

            // Add an INT assign
            case INT_KEYWORD:
                addAssignation(INT);
                break;

            // Add a NUMBER assign
            case NUMBER_KEYWORD:
                addAssignation(NUMBER);
                break;

            // Add a STRING assign
            case STRING_KEYWORD:
                addAssignation(STRING);
                break;

            // Add a ANY assign
            case ANY_KEYWORD:
                addAssignation(ANY);
                break;

            case IDENTIFIER:

                if (followSyntax({EQUAL}))
                {
                    expr = parse_expr(2);
                    // Add a reassign with value
                    ast.addAssign(next(0).value, expr);
                    advance(2 + expr.size);
                    break;
                }

                else if (followSyntax({OPERATOR, EQUAL}))
                {
                    expr = parse_expr(3);
                    // Add a reassign with value
                    ast.addAssign(next(0).value, Expr{{.type = expr.literal.type, .value = next(0).value + next().value + expr.literal.value}, expr.size + 2});
                    advance(3 + expr.size);
                    break;
                }

                else if ((next().value + next(2).value) == "++")
                {

                    ast.addUnaryPlus(next(0).value);
                    advance(3);
                    break;
                }

                else if ((next().value + next(2).value) == "--")
                {
                    ast.addUnaryMinus(next(0).value);
                    advance(3);
                    break;
                }

                Error.exit(SYNTAX_ERROR, "Expected assignation");

            case FUNCTION_KEYWORD:
                if (followSyntax({IDENTIFIER, PAR_OPEN, PAR_CLOSE, C_BRACKET_OPEN}))
                {
                    ast.addFunction(ANY, next().value);
                    advance(5);
                    break;
                }
                Error.exit(SYNTAX_ERROR, "Expected function initialization");
            case C_BRACKET_CLOSE:
                ast.closeLastIdent();
                advance();
                break;
            default:
                advance();
                break;
            }
        }
        VariableStack.debug();
    }
    unsigned short i;

private:
    TokenList m_tokens;
    void advance(short d = 1)
    {
        i += d;
    }
    // Returns the next token in the TokenList
    Token next(short distance = 1)
    {
        return m_tokens.get(i + distance);
    }
    // Adds a new statement and increments i by the number of elements of the stat
    void addStatement(Statement stat, short size = 1)
    {
        ast.nodes.push_back(stat);
        advance(size);
    }
    // Checks that a sentence follows a defined syntax step by step
    bool followSyntax(deque<TokenType> syntax)
    {
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
    // Expression parsing procedure
    Cond parse_cond(short d = 1)
    {
        TokenType t = next(d).type;
        if (isBool(t))
        {
            if (isComparator(next(d + 1).value[0]))
            {
                Cond expr = parse_cond(d + 2);
                // If the expression exists, it is (actually) a sum
                return Cond{{t, next(d).value + " " + next(d + 1).value[0] + " " + expr.literal.value}, 1 + expr.size};
            }
            return Cond{{t, next(d).value}, 1};
        }
        Error.exit(SYNTAX_ERROR, "Invalid expression");
        return {};
    }

    // Adds a new assignation depending on the type
    void addAssignation(TokenType type)
    {
        string var = next().value;
        if (followSyntax({IDENTIFIER, EQUAL}))
        {
            if (type == BOOL)
            {
                Cond cond = parse_cond(3);
                ast.addCond(var, cond);
                advance(3 + cond.size);
            }
            else
            {
                // Add an assign with value
                Expr expr = parse_expr(3);
                ast.addInit(type, var, expr);
                advance(3 + expr.size);
            }
        }
        else if (followSyntax({IDENTIFIER, PAR_OPEN, PAR_CLOSE, C_BRACKET_OPEN}))
        {
            ast.addFunction(type, var);
            advance(5);
        }
        else if (followSyntax({IDENTIFIER}))
        {
            // Add an assign without value
            ast.addInit(type, var);
            advance(2);
        }
        else
        {
            Error.exit(SYNTAX_ERROR, "Expected an initializer");
        }
    }
};