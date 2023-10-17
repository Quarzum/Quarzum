enum Modes
{
    NONE = -1,
    RUN = 0,
    INIT = 1,
    INSTALL = 2,
    PUBLISH = 3
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
        case NONE:
            getFlags();
            break;
        }
    }

    // Returns the flag with the output file path
    string input()
    {
        if (o_index == -1)
        {
            return "";
        }
        return args[o_index];
    }

    int mode = -1;
    short o_index = -1;

private:
    char **args;
    unsigned short argc;

    // Returns if the value starts with "--" (is a flag) or not
    bool isArg(string str)
    {
        return str[0] != '-' && str[1] != '-';
    }
    // List of all the avaliable modes
    const char *commands[4] = {
        "run",
        "init",
        "install",
        "publish"

    };
    // Set the mode depending on the first parameter
    void setCommand()
    {
        for (unsigned short i = 0; i < 4; i++)
        {
            if (strcmp(args[1], commands[i]) == 0)
            {
                mode = i;
            }
        }
    }
    // Creates a Quarzum project template
    void init()
    {
        cout << "\nCreating a new project..." << endl;
        ofstream program("main.qz");
        ofstream configfile("main.config.qz");
        if (_mkdir("modules") == 0)
        {
            cout << "Project created successfully!\n\nCreated 3 files:\n  - main.qz\n  - main.config.qz\n  - /modules\n"
                 << endl;
            program.close();
            configfile.close();
        }
        else
        {
            Error.exit(RUNTIME_ERROR, "Error creating a new project: unable to make directories");
        }
    }
    // Gets the flags and execute them
    void getFlags()
    {
        for (unsigned short i = (1 + (mode != -1)); i < argc; i++)
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
                cout << "\n\n Usage: quarzum.exe [action] [options] file"
                        "\n\n Actions:       "
                        "\n\n init : Creates a new Quarzum project template."
                        "\n run [path] : Runs a Quarzum script."
                        "\n install [package-name] : Installs a package"
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
