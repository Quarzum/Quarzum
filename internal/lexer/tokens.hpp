// Shows in console a list of tokens
void debugTokens(deque<Token> composed)
{
    cout << GRAY << "\nToken Stack\n-------------------\n"
         << NC;

    int maxNameLength = 8;
    for (size_t i = 0; i < composed.size(); i++)
    {
        string name = composed[i].value;
        for (__int8 j = 0; j < maxNameLength - composed[i].value.length(); j++)
        {
            name += " ";
        }
        string num = to_string(i);
        for (size_t n = 0; n < 3 - to_string(i).length(); n++)
        {
            num += " ";
        }

        cout
            << GRAY << "| " << num << " | " << YELLOW << name << GRAY << " |\n-------------------" << NC << endl;
    }
    cout << "\n\n";
}