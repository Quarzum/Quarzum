class VariableStack
{
public:
    VariableStack() {}
    deque<string> stack;
    void add(string name)
    {
        /* Adds a new variable to the list. If the variable already exists, throw an error. */
        for (unsigned int i = 0; i < stack.size(); i++)
        {
            if (stack[i] == name)
            {
                errorHandler.exit(REFERENCE_ERROR, "Variable re-initialization");
            }
        }
        stack.push_back(name);
    }
    void remove(string name)
    {
        /* Remove an existing variable in the list. If the variable doesn't exists, throw an error. */
        for (unsigned int i = 0; i < stack.size(); i++)
        {
            if (stack[i] == name)
            {
                stack.erase(stack.begin() + 2);
            }
            else if (i == stack.size() - 1)
            {
                errorHandler.exit(REFERENCE_ERROR, "Variable " + name + " doesn't exists");
            }
        }
    }
    void debug()
    {
        /* Show in console the list of existing variables at the end of the parsing */
        if (SHOW_COMPILER_DEBUG)
        {
            cout << "\nVariables\n------------\n";
            for (unsigned int i = 0; i < stack.size(); i++)
            {
                cout << stack[i] << endl;
            }
        }
    }
};

static VariableStack variableStack = VariableStack();