const string tokens[] = {
    "EXIT",
    "RETURN",
    "IMPORT",
    "FROM",
    "INT",
    "INT_KEYWORD",
    "STRING",
    "STRING_KEYWORD",
    "NUMBER",
    "NUMBER_KEYWORD",
    "TRUE",
    "FALSE",
    "BOOL",
    "BOOL_KEYWORD",
    "ANY",
    "ANY_KEYWORD",
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
    "DELETE",
    "IDENTIFIER",
    "EOL",
    "SEMICOLON",
    "OUT",
    "INPUT",
    "TYPEOF",
    "TO_INT",
    "TO_STR",
    "TO_NUM",
    "IF",
    "ELSE",
    "FOR",
    "WHILE",
    "COMMENT"};
// Shows in console a list of tokens
void debugTokens(deque<Token> composed)
{
    cout << "\nTokens\n-----------\n";

    for (unsigned short i = 0; i < composed.size(); i++)
    {
        cout << tokens[composed.at(i).type] << " -> " << composed.at(i).value << endl;
    }
    cout << "\n\n";
}