class Statement
{
public:
    enum class StatementType
    {
        ASSIGN,
        EXIT
    };

    // Assign constructor
    Statement(Assign assign) : m_type(StatementType::ASSIGN), assignContent(assign) {}

    // Exit constructor
    Statement(Exit exit) : m_type(StatementType::EXIT), exitContent(exit) {}

    // Copy constructor
    Statement(const Statement &other) : m_type(other.m_type)
    {
        if (m_type == StatementType::ASSIGN)
            assignContent = other.assignContent; // Asumiendo que Assign tiene un operador de copia adecuado
        else if (m_type == StatementType::EXIT)
            exitContent = other.exitContent; // Asumiendo que Exit tiene un operador de copia adecuado
    }
    ~Statement() {}

private:
    union
    {
        Assign assignContent;
        Exit exitContent;
    };

    StatementType m_type;
};