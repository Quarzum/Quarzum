class CLI
{
public:
    CLI() {}
    void getFlags()
    {
        for (int8_t i = 1; i < argc; i++)
        {
            if (strcmp(args[i], "-v") == 0 || strcmp(args[i], "-version") == 0)
            {
                wcout << "[Quarzum " << L'\u00A9' << " 2023] - Version: 1.0.0" << endl;
            }
            else if (strcmp(args[i], "-h") == 0 || strcmp(args[i], "-help") == 0)
            {
                cout << "help" << endl;
            }
            else if (strcmp(args[i], "-init") == 0)
            {
            }
            cout << "\n";
        }
    }
    char *output()
    {
        return args[o_index];
    }
    void setArgs(char **x, int8_t count)
    {
        args = x;
        argc = count;
    }

private:
    char **args;
    int8_t argc;
    int8_t o_index = 1;
};

CLI quarzumCLI = CLI();