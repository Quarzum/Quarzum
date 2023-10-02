string errors[] = {
    "File not found",
    "Format not supported",
    "Unexpected token",
    "Syntax error",
    "Expected expression",
    "Out of range",
    "Divide by zero",
    "Expected literal"};

void throwError(int code)
{
    cerr << "[ ERROR ] - " << errors[code] << " - Error code: " << code << endl;
    exit(EXIT_FAILURE);
}