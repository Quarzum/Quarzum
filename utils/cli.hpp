enum Modes
{
    RUN,
    INIT,
    INSTALL,
    PUBLISH
};

class CLI
{
public:
    CLI(char **x, unsigned short count)
    {
        args = x;
        argc = count;
        setCommand();
        switch (mode)
        {
        case INIT:
            init();
            break;
        case INSTALL:
            break;
        case RUN:
            getFlags();
            break;
        }
    }

    // Returns the flag with the output file path
    char *input()
    {
        if (o_index == -1)
        {
            return "";
        }
        return args[o_index];
    }

    int mode;
    short o_index = -1;

private:
    char **args;
    unsigned short argc;

    bool isArg(string str)
    {
        return str[0] != '-' && str[1] != '-';
    }

    const char *commands[4] = {
        "run",
        "init",
        "install",
        "publish"

    };

    void setCommand()
    {
        for (unsigned short i = 0; i < 4; i++)
        {
            if (strcmp(args[1], commands[i]) == 0)
            {
                cout << commands[i];
                mode = i;
            }
        }
    }

    void init()
    {
        cout << "\nCreating a new project..." << endl;
        ofstream program("main.qz");
        ofstream configfile("main.config.qz");
        if (_mkdir("modules") == 0)
        {
            cout << "Project created successfully!" << endl;
            program.close();
            configfile.close();
        }
        else
        {
            Error.exit(RUNTIME_ERROR, "Error creating a new project: unable to make directories");
        }
    }

    void getFlags()
    {
        for (unsigned short i = 2; i < argc; i++)
        {
            if (strcmp(args[i], "--v") == 0 || strcmp(args[i], "--version") == 0)
            {
                /*

                If flags --v or --version exist, show the version of the compiler

                */
                wcout << "[Quarzum " << L'\u00A9' << " 2023] - Version: 1.0.0" << endl;
            }
            else if (strcmp(args[i], "--h") == 0 || strcmp(args[i], "--help") == 0)
            {
                /*

                If flags --h or --help exist, show the help panel

                */
                cout << "\n\n Usage: quarzum.exe [options] file"
                        "\n\n Options:       "
                        "\n\n --v / --version : Displays the current compiler version."
                        "\n --h / --help : Displays this panel."
                        "\n --i / --input: Specifies the input file location."
                        "\n --o / --output: Specifies the output file location.\n"
                     << endl;
            }
            else if (strcmp(args[i], "--i") == 0 || strcmp(args[i], "--input") == 0)
            {
                /*

                If flags --i or --input exist, select that path as the input file location

                */
                if (isArg(args[i + 1]))
                {
                    i++;
                    o_index = i;
                }
                else
                {
                    Error.exit(RUNTIME_ERROR, "No input file provided.");
                }
            }
            else
            {
                o_index = i;
            }
        }
    }
};
