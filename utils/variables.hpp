deque<string> variableNames;

void addVar(string name)
{
    for (int i = 0; i < variableNames.size(); i++)
    {
        if (variableNames[i] == name)
        {
            throwError(REFERENCE_ERROR, "Variable re-initialization");
        }
    }
    variableNames.push_back(name);
}

void debugVariables()
{
    if (SHOW_COMPILER_DEBUG)
    {
        cout << "\nVariables\n------------\n";
        for (int i = 0; i < variableNames.size(); i++)
        {
            cout << variableNames[i] << endl;
        }
    }
}