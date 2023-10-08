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

void removeVar(string name)
{
    for (int i = 0; i < variableNames.size(); i++)
    {
        if (variableNames[i] == name)
        {
            variableNames.erase(variableNames.begin() + 2);
        }
        else if (i == variableNames.size() - 1)
        {
            throwError(REFERENCE_ERROR, "Variable " + name + " doesn't exists");
        }
    }
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