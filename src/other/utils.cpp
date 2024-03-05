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

// The string array that contains all the Quarzum's keywords and symbols.
const unordered_map<string, unsigned char> prefabs = {
    {"int",1},
    {"number",2},
    {"string",3},
    {"char",4},
    {"bool",5},
    {"var",6},
    {"uint",7},
    {"byte",8},
    {"return",9},
    {"function",10},
    {"enum",11},
    {"const",12},
    {"exit",13},
    {"out",14},
    {"input",15},
    {"struct",16},
    {"if",17},
    {"else",18},
    {"for",19},
    {"foreach",20},
    {"while",21},
    {"do",22},
    {"break",23},
    {"continue",24},
    {"repeat",25},
    {"try",26},
    {"catch",27},
    {"finally",28},
    {"throw",29},
    {"module",30},
    {"import",31},
    {"class",32},
    {"public",33},
    {"private",34},
    {"short",35},
    {"long",36},
    {"async",37},
    {"await",38},
    {"true",39},
    {"false",40},
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
    {".", 523},
    {",", 524},
    {"+", 525},
    {"-", 526},
    {"*", 527},
    {"/", 528},
    {"^", 529},
    {"{", 530},
    {"}", 531},
    {"[", 532},
    {"]", 533},
    {";", 534},
    {">", 535},
    {"<", 536},
    {"==",537},
    {">=",538},
    {"<=",539},
    {"%", 540},
    {"+=", 541},
    {"++",542},
    {"-=",543},
    {"--",544},
    {"*=", 545},
    {"/=", 546},
    {"%=", 547},
    {"⁼", 548},
    {"!=", 549}
};

const string STDWRITE = "\tmovq $1, %rax\n\tmovq $1, %rdi\n";

bool isSymbol(const char c){
    string s;
    s = c;
    auto it = prefabs.find(s);
    return it != prefabs.end();
}

int search(const string buff){
    auto it = prefabs.find(buff);
    if(it != prefabs.end() and it->second > 0){
        return it->second;
    }
    return 0;
}