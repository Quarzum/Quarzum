struct AST
{
    deque<Statement> statements;
};

class Parser
{
public:
    Parser(TokenList tokens) : m_tokens(move(tokens)) {}

    /* String parsing procedure */
    optional<string> parse_string(__int8 d = 1) {}

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
                errorHandler.exit(SYNTAX_ERROR, "Expected string");
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
                errorHandler.exit(SYNTAX_ERROR, "Expected string");
            case EXIT:
                expr = parse_expr();
                // Add an int assign with value
                debug("EXIT -> code: " + expr.literal.value);
                addStatement(Exit{expr}, 1 + expr.size);
                break;

            case RETURN:
                expr = parse_expr();
                // Add an int assign with value
                debug("RETURN -> value: " + expr.literal.value);
                addStatement(Return{expr}, 1 + expr.size);
                break;

            case DELETE:
                if (followSyntax({IDENTIFIER}))
                {
                    // Removes an existing variable
                    variableStack.remove(next().value);
                    debug("DELETE -> id: " + next().value);
                    i += 2;
                    break;
                }
                errorHandler.exit(SYNTAX_ERROR);
            case BOOL_KEYWORD:
                addAssignation(BOOL, "BOOL");
                break;
            case INT_KEYWORD:
                addAssignation(INT, "INT");
                break;
            case NUMBER_KEYWORD:
                addAssignation(NUMBER, "NUM");
                break;
            case STRING_KEYWORD:
                addAssignation(STRING, "STR");
                break;
            case ANY_KEYWORD:
                addAssignation(ANY, "ANY");
                break;
            case IDENTIFIER:

                if (followSyntax({EQUAL}))
                {
                    expr = parse_expr(2);

                    // Add an int assign with value
                    debug("REASSIGN -> id: " + next(0).value + ", new value: " + expr.literal.value);
                    addStatement(ReAssign{next(), expr}, 2 + expr.size);
                    break;
                }

                else if (followSyntax({OPERATOR, EQUAL}))
                {

                    expr = parse_expr(3);
                    // Add an int assign with value
                    debug("REASSIGN -> id: " + next(0).value + ", new value: " + next(0).value + next().value + expr.literal.value);
                    addStatement(ReAssign{next(), expr}, 3 + expr.size);
                    break;
                }
                else if (next().value == "+" && next(2).value == "+")
                {
                    debug("REASSIGN -> id: " + next(0).value + ", new value: " + next(0).value + " + 1");
                    addStatement(ReAssign{next(), Expr{INT, next(0).value + " + 1"}}, 3);
                    break;
                }
                else if (next().value == "-" && next(2).value == "-")
                {
                    debug("REASSIGN -> id: " + next(0).value + ", new value: " + next(0).value + " - 1");
                    addStatement(ReAssign{next(), Expr{INT, next(0).value + " - 1"}}, 3);
                    break;
                }
                errorHandler.exit(SYNTAX_ERROR, "Expected assignation");

            default:
                i++;
                break;
            }
        }
        // debugVariables();
        return ast;
    }

private:
    TokenList m_tokens;
    unsigned int i;
    AST ast;

    Token next(__int8 distance = 1)
    {
        /* Returns the next token in the TokenList */
        return m_tokens.get(i + distance);
    }
    void addStatement(Statement stat, __int8 size = 1)
    {
        /* Adds a new statement and increments i by the number of elements of the stat */
        ast.statements.push_back(stat);
        i += size;
    }
    bool followSyntax(deque<TokenType> syntax)
    {
        /* Comproves that a sentence follows a defined syntax step by step */
        bool result = true;
        for (short n = 0; n < syntax.size(); n++)
        {
            if (next(1 + n).type != syntax.at(n))
            {
                result = false;
            }
        }
        return result;
    }
    /* Expr parsing procedure */
    Expr parse_expr(__int8 d = 1)
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
        errorHandler.exit(SYNTAX_ERROR, "Invalid expression");
    }
    void addAssignation(TokenType type, string name)
    {
        variableStack.add(next().value);
        /* Adds a new assignation depending on the type */
        if (followSyntax({IDENTIFIER, EQUAL}))
        {
            // Add an assign with value
            Expr expr = parse_expr(3);
            debug(name + "_INIT -> id: " + next().value + ", value: " + expr.literal.value);
            addStatement(Assign{type, next(), expr}, 3 + expr.size);
        }
        else if (followSyntax({IDENTIFIER}))
        {
            // Add an assign without value
            debug(name + "_INIT -> id: " + next().value + ", value: null");
            addStatement(Assign{type, next(), {NULL_KEYWORD, "null"}}, 2);
        }
        else
        {
            errorHandler.exit(SYNTAX_ERROR, "Expected an initializer");
        }
    }
};
