const string tokens[] = {
    "int_k",
    "num_k",
    "str_k",
    "bool_k",
    "any",
    "null",

    "int",
    "num",
    "str",
    "bool",

    "id",

    "equal",
    "plus"};
// Shows in console a list of tokens
void debugTokens(deque<Token> composed)
{
    cout << "\nTokens\n-----------\n";

    for (unsigned short i = 0; i < composed.size(); i++)
    {
        cout << TEAL << tokens[composed.at(i).type] << NC << " -> " << composed.at(i).value << endl;
    }
    cout << "\n\n";
}