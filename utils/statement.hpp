class Statement
{
public:
    enum class StatementType
    {
        ASSIGN,
        EXIT,
        RETURN,
        REASSIGN
    };

    // Assign constructor
    Statement(Assign assign) : m_type(StatementType::ASSIGN), assignContent(assign) {}
    // Exit constructor
    Statement(Exit exit) : m_type(StatementType::EXIT), exitContent(exit) {}
    // Return constructor
    Statement(Return ret) : m_type(StatementType::RETURN), returnContent(ret) {}
    // ReAssign constructor
    Statement(ReAssign reassign) : m_type(StatementType::REASSIGN), reassignContent(reassign) {}
    // Copy constructor
    Statement(const Statement &other) : m_type(other.m_type)
    {
        if (m_type == StatementType::ASSIGN)
            assignContent = other.assignContent; // Asumiendo que Assign tiene un operador de copia adecuado
        else if (m_type == StatementType::EXIT)
            exitContent = other.exitContent; // Asumiendo que Exit tiene un operador de copia adecuado
        else if (m_type == StatementType::RETURN)
            returnContent = other.returnContent;
        else if (m_type == StatementType::REASSIGN)
            reassignContent = other.reassignContent;
    }
    ~Statement() {}

private:
    union
    {
        Assign assignContent;
        Exit exitContent;
        Return returnContent;
        ReAssign reassignContent;
    };

    StatementType m_type;
};