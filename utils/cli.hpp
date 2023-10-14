class CLI
{
public:
    CLI() {}
    void getFlags()
    {
        for (int8_t i = 1; i < argc; i++)
        {
            if (strcmp(args[i], "--v") == 0 || strcmp(args[i], "--version") == 0)
            {
                /*

                If flags -v or -version exist, show the version of the compiler

                */
                wcout << "[Quarzum " << L'\u00A9' << " 2023] - Version: 1.0.0" << endl;
            }
            else if (strcmp(args[i], "--h") == 0 || strcmp(args[i], "--help") == 0)
            {
                /*

                If flags -h or -help exist, show the help panel

                */
                cout << "\n\n Usage: quarzum.exe [options] file"
                        "\n\n Options:       "
                        "\n\n --v / --version : Displays the current compiler version."
                        "\n --h / --help : Displays this panel."
                        "\n --init : Creates a new Quarzum project structure."
                        "\n --i / --input: Specifies the input file location."
                        "\n --o / --output: Specifies the output file location.\n"
                     << endl;
            }
            else if (strcmp(args[i], "--init") == 0)
            {
                /*

                If flag -init exists, create this project structure:
                    > main.qz
                    > main.config.qz
                    > /modules

                */
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
            else
            {
                o_index = i;
            }
        }
    }
    char *output()
    {
        /*

            Returns the flag with the output file path

        */
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
    int8_t o_index = -1;

    bool isArg(string str)
    {
        return str[0] != '-' && str[1] != '-';
    }
};

CLI quarzumCLI = CLI();