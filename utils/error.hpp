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
    void exit(unsigned short code, string description = "")
    {
        /*

        Throws an error and stops the program

        */
        cerr << errors[code] << ":\n    " << description << " - Error code: " << code << endl;
        abort();
    }

private:
    string errors[8] = {
        "FileNotFoundError",
        "ReferenceError",
        "RuntimeError",
        "LexicalError",
        "SyntaxError",
        "Out of range",
        "ArithmeticError",
        "TypeError"};
    void abort() { exit(EXIT_FAILURE); }
};

static ErrorComponent Error = ErrorComponent();