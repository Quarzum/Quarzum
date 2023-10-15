class AST
{
public:
    AST() {}
    int size()
    {
        return childcount;
    }

    void addInit(TokenType type, string name, Expr value = nullExpr)
    {
        debug(identate() + tokens[type] + "_INIT -> id: " + name + ", value: " + value.literal.value);
        newStmt(Statement{Assign{type, name, value}});
    }

    void addCond(string name, Cond value)
    {
        debug(identate() + tokens[BOOL] + "_INIT -> id: " + name + ", value: " + value.literal.value);
        newStmt(Statement{Assign{BOOL, name, value}});
    }

    void addReturn(Expr expr)
    {
        debug(identate() + "RETURN -> value: " + expr.literal.value);
        newStmt(Statement{Return{expr}});
    }

    void addExit(Expr expr)
    {
        debug(identate() + "EXIT -> value: " + expr.literal.value);
        newStmt(Statement{Exit{expr}});
    }

    void addAssign(string name, Expr value)
    {
        debug(identate() + "REASSIGN -> id: " + name + ", value: " + value.literal.value);
        newStmt(Statement{ReAssign{name, value}});
    }

    void addUnaryPlus(string name)
    {
        Expr expr = Expr{INT, name + " + 1", 3};
        addAssign(name, expr);
    }
    void addUnaryMinus(string name)
    {
        Expr expr = Expr{INT, name + " - 1", 3};
        addAssign(name, expr);
    }

    void addFunction(TokenType type, string name)
    {
        debug(identate() + tokens[type] + "_FUNCTION -> id: " + name + ", args: (), content: ");
        newStmt(Statement{Function{type, name, {}, Block{}}});
    }

    void addModule(string name)
    {
        debug(identate() + "MODULE -> id: " + name);
        identations.push_back({"module", name, Block{}});
    }
    void closeLastIdent()
    {
        Identation lastIdent = identations.at(identations.size() - 1);
        if (lastIdent.type == "module")
        {
            newStmt(Statement{Module{lastIdent.name, lastIdent.content}});
        }
        identations.pop_back();
        debug("");
    }

    deque<Statement> nodes;
    deque<Identation> identations;

private:
    int childcount;

    void newStmt(Statement stmt)
    {
        if (identations.size() > 0)
        {
            identations.at(identations.size() - 1).content.stmts.push_back(stmt);
        }
        else
        {
            nodes.push_back(stmt);
        }
    }

    string identate()
    {
        string result;
        for (short i = 0; i < identations.size(); i++)
        {
            result += "  ";
        }
        return result;
    }
};

static AST ast = AST();