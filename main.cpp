#include "Quarzum.h"
/*

    Minimal main.cpp, all the procedures are into Quarzum.h

*/
int main(int argc, char *argv[])
{
    /*
    Throw error if file is not found or there is an invalid format
    */
    if (argc < 2)
    {
        Error.exit(FILE_NOT_FOUND_ERROR, "No such file or directory");
    }
    // Source source = Source(argv[1]);
    CLI.setArgs(argv, argc);
    CLI.getFlags();

    if (CLI.input() != "")
    {
        Source.route = CLI.input();
        Source.validate();
        chechForConfigFile(CLI.input());
        // If all is correct, compile the source code
        compile(Source.get());
    }

    return 0;
}