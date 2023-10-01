bool isOperator(char value)
{
    return (value == '+' || value == '-' || value == '*' || value == '/' || value == '%' || value == '^');
};
bool isSizeModifier(string value)
{
    return (value == "x8" || value == "x16" || value == "x32" || value == "x64");
};
bool isLiteral(TokenType type)
{
    return (type == INT_LITERAL || type == NUMBER_LITERAL || type == STRING_LITERAL);
}
map<string, int> keywords = {
    {"exit", 0},
    {"return", 1},
    {"import", 2},
    {"from", 3},
    {"int", 5},
    {"string", 7},
    {"number", 9},
    {"true", 10},
    {"false", 11},
    {"bool", 12},
    {"var", 13},
    {"function", 14},
    {"null", 15},
    {"struct", 16},
    {"enum", 17},
    {"class", 18},
    {"public", 19},
    {"private", 20},
    {"module", 21},
    {"and", 23},
    {"or", 24},
    {"not", 25},
    {"const", 37},
    {"unsigned", 38},
    {"short", 39},
    {"long", 40},
    {"this", 46},
    {"static", 47},
    {"out", 49},
    {"input", 50},
    {"typeOf", 51},
};
map<char, int> symbols = {
    {'&', 23},
    {'|', 24},
    {'!', 25},
    {'>', 26},
    {'<', 27},
    {'=', 28},
    {',', 29},
    {'.', 30},
    {'(', 31},
    {')', 32},
    {'{', 33},
    {'}', 34},
    {'[', 35},
    {']', 36}};
string tokens[] = {
    "EXIT",
    "RETURN",
    "IMPORT",
    "FROM",
    "INT_LITERAL",
    "INT_KEYWORD",
    "STRING_LITERAL",
    "STRING_KEYWORD",
    "NUMBER_LITERAL",
    "NUMBER_KEYWORD",
    "TRUE",
    "FALSE",
    "BOOL_KEYWORD",
    "VAR_KEYWORD",
    "FUNCTION_KEYWORD",
    "NULL_KEYWORD",
    "STRUCT_KEYWORD",
    "ENUM_KEYWORD",
    "CLASS_KEYWORD",
    "PUBLIC_KEYWORD",
    "PRIVATE_KEYWORD",
    "MODULE_KEYWORD",
    "OPERATOR",
    "AND",
    "OR",
    "NOT",
    "GREATER",
    "LOWER",
    "EQUAL",
    "COMMA",
    "POINT",
    "PAR_OPEN",
    "PAR_CLOSE",
    "C_BRACKET_OPEN",
    "C_BRACKET_CLOSE",
    "S_BRACKET_OPEN",
    "S_BRACKET_CLOSE",
    "CONST",
    "UNSIGNED",
    "SHORT",
    "LONG",
    "X8",
    "X16",
    "X32",
    "X64",
    "X128",
    "THIS",
    "STATIC",
    "IDENTIFIER",
    "OUT",
    "INPUT",
    "TYPEOF"};

int findKeyword(string keyword)
{
    return keywords.at(keyword);
}

string getSource(const string path)
{
    /* Reads the file and returns its content */
    ifstream input(path);
    if (input.fail())
    {
        throwError(FILE_NOT_FOUND);
    }
    string source, line;
    while (getline(input, line))
    {
        source += line + '\n';
    }
    return source;
}
void debugTokens(deque<Token> composed)
{
    cout << "\nTokens\n-----------\n";
    /* Shows in console a list of tokens */
    for (unsigned short int i = 0; i < composed.size(); i++)
    {
        cout << tokens[composed.at(i).type] << " -> " << composed.at(i).value << endl;
    }
    cout << "\n\n";
}
void validateFormat(char *argv[])
{
    string path;
    path = argv[1];
    if (path.substr(path.size() - 3) != ".qz")
    {
        throwError(INVALID_FORMAT);
    }
}
bool isKeyword(string src)
{
    return keywords.count(src);
}
bool isSymbol(char src)
{
    return symbols.count(src);
}