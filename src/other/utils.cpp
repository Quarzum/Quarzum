#pragma once
#include "../Quarzum.h"
const string ZERO = "0";

/**
 *   Creates a new file and writes content inside it.
 *   @param name The name of the created file.
 *   @param content The content that will be wrote inside the file.
*/
void createFile(const string name,const string content = "") noexcept{
    ofstream out(name);
    out << content;
    out.close();
}

// The string array that contains all the Quarzum's keywords and symbols.
const unordered_map<string, unsigned char> prefabs = {
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
    {"=", 513},
    {"(",514},
    {")",515},
    {"!!", 516},
    {"&", 517},
    {"|", 518},
    {"$", 519},
    {"!", 520},
    {"&&",521},
    {"||",522},
    {"$$",523},
    {".", 524},
    {",", 525},
    {"+", 526},
    {"-", 527},
    {"*", 528},
    {"/", 529},
    {"^", 530},
    {"{", 531},
    {"}", 532},
    {"[", 533},
    {"]", 534},
    {";", 535},
    {">", 536},
    {"<", 537},
    {"==",538},
    {">=",539},
    {"<=",540},
    {"%", 541}
};

const string STDWRITE = "\tmovq $1, %rax\n\tmovq $1, %rdi\n";

bool isSymbol(const char c){
    string s;
    s = c;
    auto it = prefabs.find(s);
    return it != prefabs.end();
}

int search(const string buff,const int min = 0){
    auto it = prefabs.find(buff);
    if(it != prefabs.end() and it->second > min){
        return it->second;
    }
    return 0;
}
int search(const char c,const int min = 0){
    string buff;
    buff += c;
    auto it = prefabs.find(buff);
    if(it != prefabs.end() and it->second > min){
        return it->second;
    }
    return 0;
}

const wstring charToString(const char n){
    wstring s;
    s += n;
    return s;
}