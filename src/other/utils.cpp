#pragma once
#include "../Quarzum.h"
/**
 *   Creates a new file and writes content inside it.
 *   @param name The name of the created file.
 *   @param content The content that will be wrote inside the file.
*/
void createFile(const string name,const string content = "") {
    ofstream out(name);
    out << content;
    out.close();
}

