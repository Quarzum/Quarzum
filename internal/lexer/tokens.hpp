const string tokens[] = {
    "INT_KEYWORD",
    "NUM_KEYWORD",
    "STR_KEYWORD",
    "CHAR_KEYWORD",
    "BOOL_KEYWORD",
    "ANY_KEYWORD",
    "NULL_KEYWORD",
    "FUNCTION_KEYWORD",
    "RETURN",
    "EXIT",
    "IF",
    "ELSE",
    "FOR",
    "WHILE",
    "SWITCH",
    "CASE",
    "BREAK",
    "CONTINUE",
    "DEFAULT",
    "IMPORT",
    "FROM",
    "MODULE",
    "CLASS",
    "PUBLIC",
    "PRIVATE",
    "CONSTRUCT",
    "DESTROY",
    "STRUCT",
    "ENUM",
    "TRY",
    "CATCH",
    "FINALLY",
    "CONST",
    "STATIC",
    "TYPEOF",
    "THROW",
    "DELETE",

    "INT",
    "NUM",
    "STR",
    "BOOL",
    "CHAR",

    "ID",

    "EQUAL",
    "PLUS",
    "MINUS",
    "PRODUCT",
    "DIVIDE",
    "POWER",
    "INTDIV",
    "PAR_OPEN",
    "PAR_CLOSE",
    "AND",
    "OR",
    "NOT",
    "SQUARE_OPEN",
    "SQUARE_CLOSE",
    "CURLY_OPEN",
    "CURLY_CLOSE",
    "GREATER",
    "LESS"

};
// Shows in console a list of tokens
void debugTokens(deque<Token> composed)
{
    cout << "\nTokens\n-----------\n";

    int maxNameLength = 16;

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