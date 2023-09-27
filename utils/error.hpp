std::string errors[] = {
    "File not found",
    "Format not supported",
    "Unexpected token",
    "Syntax error",
    "Expected expression"};

void throwError(int code)
{
    std::cerr << "[ ERROR ] - " << errors[code] << " - Error code: " << code << std::endl;
    exit(EXIT_FAILURE);
}