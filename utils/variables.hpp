deque<string> variableNames;

void addVar(string name)
{
    /* Adds a new variable to the list. If the variable already exists, throw an error. */
    for (unsigned int i = 0; i < variableNames.size(); i++)
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
    /* Remove an existing variable in the list. If the variable doesn't exists, throw an error. */
    for (unsigned int i = 0; i < variableNames.size(); i++)
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
    /* Show in console the list of existing variables at the end of the parsing */
    if (SHOW_COMPILER_DEBUG)
    {
        cout << "\nVariables\n------------\n";
        for (int i = 0; i < variableNames.size(); i++)
        {
            cout << variableNames[i] << endl;
        }
    }
}