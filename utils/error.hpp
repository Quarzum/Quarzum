string errors[] = {
    "FileNotFoundError",
    "ReferenceError",
    "RuntimeError",
    "LexicalError",
    "SyntaxError",
    "Out of range",
    "ArithmeticError",
    "TypeError"};

void throwError(unsigned short int code, string description = "")
{
    cerr << errors[code] << ":\n    " << description << " - Error code: " << code << endl;
    exit(EXIT_FAILURE);
}