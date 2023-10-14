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
        errorHandler.exit(FILE_NOT_FOUND_ERROR, "No such file or directory");
    }
    // Source source = Source(argv[1]);
    quarzumCLI.setArgs(argv, argc);
    quarzumCLI.getFlags();
    src.route = quarzumCLI.output();
    src.validate();
    chechForConfigFile(quarzumCLI.output());
    // If all is correct, compile the source code
    compile(src.get());

    return 0;
}