class VariableStackComponent
{
public:
    VariableStackComponent() {}
    deque<string> stack;
    bool exists(string name)
    {
        for (unsigned int i = 0; i < stack.size(); i++)
        {
            if (stack[i] == name)
            {
                return true;
            }
        }
        return false;
    }
    // Add a new variable to the list. If the variable already exists, throw an error.
    void add(string name)
    {
        for (unsigned int i = 0; i < stack.size(); i++)
        {
            if (stack[i] == name)
            {
                Debug.err("Variable re-initialization", "ReferenceError");
            }
        }
        stack.push_back(name);
    }
    // Remove an existing variable in the list. If the variable doesn't exists, throw an error.
    void remove(string name)
    {
        for (unsigned int i = 0; i < stack.size(); i++)
        {
            if (stack[i] == name)
            {
                stack.erase(stack.begin() + i);
                break;
            }
            else if (i == stack.size() - 1)
            {
                Debug.err("Variable " + name + " doesn't exist", "ReferenceError");
            }
        }
    }
    // Show in console the list of existing variables at the end of the parsing
    void debug()
    {
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

// Initializing the stack
static VariableStackComponent VariableStack = VariableStackComponent();
