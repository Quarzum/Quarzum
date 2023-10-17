#define REDB "\e[30;41m"
#define NC "\e[0m"
#define YLW "\e[30;103m"
#define GRN "\e[30;102m"
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

enum Warncode
{
    DEPRECATED
};

class ErrorComponent
{
public:
    ErrorComponent() {}
    // Throws an error and stops the program
    void exit(unsigned short code, string description = "")
    {
        cerr << REDB "[ERROR]" NC;
        cerr << " " + errors[code] << ":\n    " << description << endl;
        std::exit(EXIT_FAILURE);
    }

    // Throws a warning, but continues the program
    void warn(unsigned short code, string description = "")
    {
        cerr << YLW "[WARNING]" NC;
        cerr << " " + warnings[code] << ":\n    " << description << endl;
    }

    void success(string description = "")
    {
        cerr << GRN "[SUCCESS]" NC;
        cerr << " " + description << endl;
    }

private:
    string errors[8] = {"FileNotFoundError", "ReferenceError", "RuntimeError", "LexicalError", "SyntaxError", "Out of range", "ArithmeticError", "TypeError"};
    string warnings[1] = {
        "DeprecatedWarning"};
};

static ErrorComponent Error = ErrorComponent();