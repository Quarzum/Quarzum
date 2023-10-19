#define RED "\e[30;41m"
#define NC "\e[0m"
#define YELLOW "\e[30;103m"
#define GREEN "\e[30;102m"
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
        cerr << RED "[ERROR]" NC;
        cerr << " " + errors[code] << ": " << description << endl;
        std::exit(EXIT_FAILURE);
    }

    // Throws a warning, but continues the program
    void warn(string description = "")
    {
        cerr << YELLOW "[WARNING]" NC;
        cerr << " " + description << endl;
    }

    void success(string description = "")
    {
        cerr << GREEN "[SUCCESS]" NC;
        cerr << " " + description << endl;
    }

private:
    string errors[8] = {"FileNotFoundError", "ReferenceError", "RuntimeError", "LexicalError", "SyntaxError", "Out of range", "ArithmeticError", "TypeError"};
};

static ErrorComponent Error = ErrorComponent();