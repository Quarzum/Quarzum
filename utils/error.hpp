string errors[] = {
    "FileNotFoundError",
    "ReferenceError",
    "RuntimeError",
    "LexicalError",
    "SyntaxError",
    "Expected expression",
    "Out of range",
    "ArithmeticError",
    "Expected literal",
    "Expected string"

};

void throwError(unsigned short int code, string description = "")
{
    cerr << errors[code] << ": " << description << " - Error code: " << code << endl;
    exit(EXIT_FAILURE);
}