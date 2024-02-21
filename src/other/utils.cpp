#pragma once
#include "../Quarzum.h"

typedef unsigned int uint;
using tokens::TokenType;


const qstring ZERO = "0";
bool isDebugging = false;
/**
 *   Creates a new file and writes content inside it.
 *   @param name The name of the created file.
 *   @param content The content that will be wrote inside the file.
*/
inline void createFile(string name, string content = "") noexcept{
    ofstream out(name);
    out << content;
    out.close();
}

/**
 *   Prints a string on the console if the compiler has the isDebugging condition true.
 *   @param content The content that will be printed. 
*/
inline void print(string content) noexcept{
    if(isDebugging == true){ cout << content << "\n";}
}
/**
 *   The string array that contains all the Quarzum's keywords and symbols.
*/

const unordered_map<const char*, int8> prefabs = {
    {"int",1},
    {"number",2},
    {"string",3},
    {"char",4},
    {"bool",5},
    {"any",6},
    {"return",7},
    {"function",8},
    {"enum",9},
    {"const",10},
    {"exit",11},
    {"out",12},
    {"input",13},
    {"struct",14},
    {"if",15},
    {"else",16},
    {"for",17},
    {"foreach",18},
    {"while",19},
    {"do",20},
    {"break",21},
    {"continue",22},
    {"repeat",23},
    {"try",24},
    {"catch",25},
    {"finally",26},
    {"throw",27},
    {"module",28},
    {"import",29},
    {"class",30},
    {"public",31},
    {"private",32},
    {"uint",33},
    {"short",34},
    {"long",35},
    {"byte",36},
    {"async",37},
    {"await",38},
    {"operator",39},
    {"in", 40},
    {"=", 41},
    {"(",42},
    {")",43},
    {"!!", 44},
    {"&", 45},
    {"|", 46},
    {"$", 47},
    {"!", 48},
    {"&&",49},
    {"||",50},
    {"$$",51},
    {".", 52},
    {",", 53},
    {"+", 54},
    {"-", 55},
    {"*", 56},
    {"/", 57},
    {"^", 58},
    {">", 64},
    {"<", 65},
    {"==",66},
    {">=",67},
    {"<=",68},
    {"%", 69}
};
const string STDWRITE = "\tmovq $1, %rax\n\tmovq $1, %rdi\n";

bool isSymbol(char c){
    qstring s = c;
    auto it = prefabs.find(s.value);
    return it != prefabs.end();
}

int search(qstring buff, const unsigned int min = 0){
    auto it = prefabs.find(buff.value);
    if(it != prefabs.end() and it->second > min){
        return it->second;
    }
    return 0;
}
int search(char c,const unsigned int min = 0){
    qstring buff = c;
    auto it = prefabs.find(buff.value);
    if(it != prefabs.end() and it->second > min){
        return it->second;
    }
    return 0;
}

bool isIntLiteral(TokenType t){
    return t == TokenType::int_lit || t == TokenType::byte_lit;
}