#pragma once
using namespace std;
class Parser
{
public:
    Parser(TokenList tokens) : m_tokens(move(tokens)) {}

    /* Expr parsing procedure */
    optional<Expr> parse_expr(unsigned short int d = 1)
    {
        if (isLiteral(next(d).type))
        {

            TokenType t = next(d).type;
            /* Check if is not a single literal, but a 2 literal operation */
            if (isOperator(next(d + 1).value[0]))
            {
                Token arg1 = next(d);
                char op = next(d + 1).value[0];
                Token arg2 = next(d + 2);
                /* Check if the types match */
                if (arg2.type == t || arg2.type == IDENTIFIER)
                {
                    /* Check if there is not a division by 0 */
                    if (op != '/' && arg2.value != "0")
                    {
                        string s = arg1.value + " " + op + " " + arg2.value;
                        /* Return an expr with the new value */
                        return Expr{t, s};
                    }
                    throwError(DIVIDE_BY_ZERO);
                }
                throwError(EXPECTED_LITERAL);
            }
            return Expr{t, next(d).value};
        }
        return {};
    }

    /* String parsing procedure */
    optional<string> parse_string(unsigned short int d = 1)
    {
    }

    Root parse()
    {
        i = 0;
        debug("Statements\n-------------");
        /* Converts tokens into an AST */
        while (i < m_tokens.size())
        {
            t = m_tokens.get(i);
            switch (t.type)
            {

            case IMPORT:

                if (followSyntax({IDENTIFIER, FROM, STRING_LITERAL}))
                {
                    addImport({next(), next(3).value});
                }
                break;

            case EXIT:

                if (auto expr = parse_expr())
                {
                    // Push-back an int assign with value
                    debug("EXIT -> code: " + expr.value().literal.value);
                    addStatement(Exit{expr.value()}, 2);
                    break;
                }

                throwError(EXPECTED_EXPR);

            case RETURN:

                if (auto expr = parse_expr())
                {
                    // Push-back an int assign with value
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
        return tree;
    }

private:
    TokenList m_tokens;
    Token t;
    unsigned int i;
    Root tree;
    Token next(short unsigned int distance = 1)
    {
        return m_tokens.get(i + distance);
    }
    void debug(string input)
    {
        if (SHOW_COMPILER_DEBUG)
        {
            cout << input << endl;
        }
    }
    void addStatement(any stat, short unsigned int size = 1)
    {
        /* Adds a new statement and increments i by the number of elements of the stat */
        tree.childs.push_back(stat);
        i += size;
    }
    void addImport(Import imp)
    {
        /* Adds a new import statement */
        tree.imports.push_back(imp);
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
};
