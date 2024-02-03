#pragma once
#include "../Quarzum.h"
typedef unsigned char int8;
typedef unsigned int uint;
bool isDebugging = true;
/**
 *    Searchs for a string inside a string array. 
 *    If the target string is not found, returns -1.
 *    @param target The target string to find.
 *    @param list The list where the function will search.
 *    @param maxIndex The max index to find.
 *    @return The index of the target string inside the array.
*/
const signed int search(std::string target,const std::string list[], int maxIndex) noexcept{
    for (uint i = 0; i < maxIndex; i++)
    {
        if(list[i] == target){ return i;}
    }
    return -1;
}

/** 
 *    Shows in console every token with its type (converted to decimal) and its value.
 *    @param list The deque of tokens that will be debugged.
*/
void debugTokens(deque<Token> list) noexcept{
    for (size_t i = 0; i < list.size(); i++)
    {
        cout << list.at(i).type << " - " << list.at(i).value << endl;
    }
}

/**
 *   Creates a new file and writes content inside it.
 *   @param name The name of the created file.
 *   @param content The content that will be wrote inside the file.
*/
void createFile(std::string name, std::string content = "") noexcept{
    ofstream out(name);
    out << content;
    out.close();
}

/**
 *   Prints a string on the console if the compiler has the isDebugging condition true.
 *    @param content The content that will be printed. 
*/
void print(std::string content) noexcept{
    if(isDebugging == true){ std::cout << content << std::endl;}
}
/**
 *   The string array that contains all the Quarzum's keywords.
*/
const std::string keywords[] = {
    "int",
    "number",
    "string",
    "char",
    "bool",
    "any",
    "return",
    "function",
    "enum",
    "const",
    "exit",
    "out",
    "input",
    "struct",
    "if",
    "else",
    "for",
    "foreach",
    "while",
    "do",
    "break",
    "continue",
    "repeat",
    "try",
    "catch",
    "finally",
    "throw",
    "module",
    "import",
    "class",
    "public",
    "private"
};
/**
 *   The string array that contains all the Quarzum's symbols.
*/
const std::string symbols[]={
    "=",
    "(",
    ")",
    "!!",
    "&",
    "|",
    "%",
    "!",
    "&&",
    "||",
    "%%",
    ".",
    ",",
    "+",
    "-",
    "*",
    "/",
    "^",
    "{",
    "}"
    "[",
    "]"
};
