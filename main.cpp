#include "Quarzum.h"
/*

    Minimal main.cpp, all the procedures are into Quarzum.h

*/
int main(int argc, char *argv[])
{
    CLI cli = CLI(argv, argc);

    if (cli.mode == INIT)
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
            Error.exit(RUNTIME_ERROR, "Error creating a new project: unable to make directories");
        }
    }

    if (cli.mode == INSTALL)
    {
    }

    if (cli.mode == RUN)
    {
        cli.getFlags();
        if (cli.input() != "")
        {
            Source.route = cli.input();
            Source.validate();
            chechForConfigFile(cli.input());
            // If all is correct, compile the source code
            compile(Source.get());
        }
        if (cli.getIndex() == -1)
        {
            Error.exit(FILE_NOT_FOUND_ERROR, "No such file or directory");
        }
    }

    return 0;
}