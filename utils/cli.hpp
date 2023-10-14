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
                cout << "Creating a new project..." << endl;
                ofstream program("main.qz");
                ofstream configfile("main.config.qz");
                if (_mkdir("modules") == 0)
                {
                    cout << "Project created successfully" << endl;
                    program.close();
                    configfile.close();
                }
                else
                {
                    errorHandler.exit(RUNTIME_ERROR, "Error creating a new project: unable to make directories");
                }
            }
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

    bool isArg(string str)
    {
        return str.front() != '-';
    }
};

CLI quarzumCLI = CLI();