const string tokens[] = {
    "INT_KEYWORD",
    "NUM_KEYWORD",
    "STRING_KEYWORD",
    "BOOL_KEYWORD",
    "ANY_KEYWORD",
    "NULL_KEYWORD",
    "CONST_KEYWORD",
    "MODULE_KEYWORD",
    "RETURN",
    "FUNCTION_KEYWORD",
    "NOT",
    "AND",
    "OR",

    "INT",
    "NUM",
    "STR",
    "BOOL",

    "IDENTIFIER",

    "EQUAL",
    "PLUS",
    "MINUS",
    "MULTIPLY",
    "DIVIDE",
    "MODULE",
    "POINT",
    "COMMA",
    "PAR_OPEN",
    "PAR_CLOSE",
    "C_BRACKET_OPEN",
    "C_BRACKET_CLOSE",
    "S_BRACKET_OPEN",
    "S_BRACKET_CLOSE",

};
// Shows in console a list of tokens
void debugTokens(deque<Token> composed)
{
    cout << "\nTokens\n-----------\n";

    int maxNameLength = 12;

    for (size_t i = 0; i < composed.size(); i++)
    {
        string name = tokens[composed.at(i).type];
        for (__int8 j = 0; j < maxNameLength - tokens[composed.at(i).type].length(); j++)
        {
            name += " ";
        }

        cout << YELLOW << name << GRAY << " -> " << TEAL << composed.at(i).value << NC << endl;
    }
    cout << "\n\n";
}