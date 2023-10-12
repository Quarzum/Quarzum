const map<char, __int8> symbols = {
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
string toString(char c)
{
    string s;
    s = c;
    return s;
}
void debug(string input)
{
    /* If is enabled, show as output the prodedure*/
    if (SHOW_COMPILER_DEBUG)
    {
        cout << input << endl;
    }
}
bool isTerm(TokenType t)
{
    /* Checks if the TokenType is a valid expression term */
    return isLiteral(t) || t == IDENTIFIER || t == NULL_KEYWORD || isBoolean(t);
}
