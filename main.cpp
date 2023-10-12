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
        throwError(FILE_NOT_FOUND_ERROR, "No such file or directory");
    }
    // Source source = Source(argv[1]);
    src.route = argv[1];
    src.validate();
    chechForConfigFile(argv[1]);
    // If all is correct, compile the source code
    compile(src.get());

    return 0;
}