#include "Quarzum.h"
/*

    Minimal main.cpp, all the procedures are into Quarzum.h

*/
int main(int argc, char *argv[])
{
    // Initializing the Command Line Interface
    CLI cli = CLI(argv, argc);
    if (cli.input() != "")
    {
        Source.route = cli.input();
        Source.validate();
        chechForConfigFile(cli.input());
        // If all is correct, compile the source code
        compile(Source.get());
    }
    else
    {
        Error.exit(FILE_NOT_FOUND_ERROR, "No such file or directory");
    }

    return 0;
}