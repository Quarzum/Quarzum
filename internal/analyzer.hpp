class Analyzer
{
public:
    Analyzer(deque<Statement> ast) : m_ast(move(ast)){};
    void analyze()
    {
        debug("\nOptimizations\n------------\n");
        for (int i = 0; i < m_ast.size(); i++)
        {
            Statement stat = m_ast.at(i);

            if (stat.type == "assign")
            {
                Assign content = get<Assign>(stat.stmt);

                cout << stoi("7+1");

                string eval = evalExpr(get<Expr>(content.value), content.type);

                debug("asg | " + content.id + " : " + tokens[content.type] + " <- " + get<Expr>(content.value).literal.value);
            }

            if (stat.type == "reassign")
            {
                ReAssign content = get<ReAssign>(stat.stmt);
                debug("mov | " + content.id + " <- " + content.value.literal.value);
            }
        }
    }

private:
    deque<Statement> m_ast;

    string evalExpr(Expr expr, TokenType exprType)
    {
        if (expr.size == 1)
        {
            if (exprType == checkType(expr))
            {
                return (expr.literal.value);
            }
            Error.exit(TYPE_ERROR);
        }

        else
        {
        }
    }

    bool isInt(Expr expr)
    {
        return isdigit(expr.literal.value[0]);
    }

    TokenType checkType(Expr expr)
    {
        if (isInt(expr))
        {
            return INT;
        }

        return {};
    }

    int IntSum(string a, string b)
    {
        return (stoi(a) + stoi(b));
    }
};
