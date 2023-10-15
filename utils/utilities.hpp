const map<char, unsigned short> symbols = {
    {'&', 25},
    {'|', 26},
    {'!', 27},
    {'>', 28},
    {'<', 29},
    {'=', 30},
    {',', 31},
    {'.', 32},
    {'(', 33},
    {')', 34},
    {'{', 35},
    {'}', 36},
    {'[', 37},
    {']', 38},
    {';', 53}};

const bool isOperator(char value) { return (value == '+' || value == '-' || value == '*' || value == '/' || value == '%' || value == '^'); };
const bool isComparator(char value) { return (value == '<' || value == '>'); }
const bool isSizeModifier(string value) { return (value == "x8" || value == "x16" || value == "x32" || value == "x64"); };
const bool isLiteral(TokenType type) { return (type == INT || type == NUMBER || type == STRING); }
const bool isBoolean(TokenType type) { return (type == TRUE || type == FALSE); }
const bool isSymbol(char src) { return symbols.count(src); }
const bool isType(TokenType type) { return (type == INT_KEYWORD || type == STRING_KEYWORD || type == BOOL_KEYWORD || type == NUMBER_KEYWORD || type == ANY_KEYWORD); }
string toString(char c)
{
    string s;
    s = c;
    return s;
}
// If is enabled, show as output the prodedure
void debug(string input)
{
    if (SHOW_COMPILER_DEBUG)
    {
        cout << input << endl;
    }
}
// Checks if the TokenType is a valid expression term
bool isTerm(TokenType t)
{
    return isLiteral(t) || t == IDENTIFIER || t == NULL_KEYWORD;
}
bool isBool(TokenType t)
{
    return t == IDENTIFIER || isBoolean(t);
}