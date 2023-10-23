enum Errorcode
{
    FILE_NOT_FOUND_ERROR,
    REFERENCE_ERROR,
    RUNTIME_ERROR,
    LEXICAL_ERROR,
    SYNTAX_ERROR,
    OUT_OF_RANGE,
    ARITHMETIC_ERROR,
    TYPE_ERROR
};

class ErrorComponent
{
public:
    ErrorComponent() {}
    // Throws an error and stops the program
    void exit(unsigned short code, string description = "")
    {
        cerr << RED_BG "[ERROR]" NC;
        cerr << " " + errors[code] << ": " << description << endl;
        std::exit(EXIT_FAILURE);
    }

    // Throws a warning, but continues the program
    void warn(string description = "")
    {
        cerr << YELLOW_BG "[WARNING]" NC;
        cerr << " " + description << endl;
    }

    void success(string description = "")
    {
        cerr << GREEN_BG "[SUCCESS]" NC;
        cerr << " " + description << endl;
    }

private:
    string errors[8] = {"FileNotFoundError", "ReferenceError", "RuntimeError", "LexicalError", "SyntaxError", "Out of range", "ArithmeticError", "TypeError"};
};

static ErrorComponent Error = ErrorComponent();