enum StatementType
{
    S_ASSIGN,
    S_EXIT,
    S_RETURN,
    S_REASSIGN
};
class Statement
{
public:
    // Assign constructor
    Statement(Assign assign) : m_type(StatementType::S_ASSIGN), assignContent(assign) {}
    // Exit constructor
    Statement(Exit exit) : m_type(StatementType::S_EXIT), exitContent(exit) {}
    // Return constructor
    Statement(Return ret) : m_type(StatementType::S_RETURN), returnContent(ret) {}
    // ReAssign constructor
    Statement(ReAssign reassign) : m_type(StatementType::S_REASSIGN), reassignContent(reassign) {}
    // Copy constructor
    Statement(const Statement &other) : m_type(other.m_type)
    {
        if (m_type == StatementType::S_ASSIGN)
            assignContent = other.assignContent;
        else if (m_type == StatementType::S_EXIT)
            exitContent = other.exitContent;
        else if (m_type == StatementType::S_RETURN)
            returnContent = other.returnContent;
        else if (m_type == StatementType::S_REASSIGN)
            reassignContent = other.reassignContent;
    }
    ~Statement() {}

    union
    {
        Assign assignContent;
        Exit exitContent;
        Return returnContent;
        ReAssign reassignContent;
    };

    StatementType m_type;
};