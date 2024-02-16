#pragma once
#include "../Quarzum.h"
typedef unsigned char int8;
typedef unsigned int uint;
#define repeat(d, r) for(d = 0; d < r; d++)
const string ZERO = "0";
bool isDebugging = false;
/**
 *   Creates a new file and writes content inside it.
 *   @param name The name of the created file.
 *   @param content The content that will be wrote inside the file.
*/
inline void createFile(std::string name, std::string content = "") noexcept{
    ofstream out(name);
    out << content;
    out.close();
}

/**
 *   Prints a string on the console if the compiler has the isDebugging condition true.
 *   @param content The content that will be printed. 
*/
inline void print(std::string content) noexcept{
    if(isDebugging == true){ std::cout << content << std::endl;}
}
/**
 *   The string array that contains all the Quarzum's keywords and symbols.
*/

const unordered_map<string, int8> prefabs = {
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

/**
 * An object that stores a list of inmutable Tokens.
*/
class TokenList{
    public:
        /**
         * Adds a new Token to the TokenList.
         * @param t The new Token's type.
         * @param v The new Token's value.
        */
        void addToken(TokenType t, string v) noexcept{
            tokens.push_back({t,v});
        }
        /**
         * Adds a new Token to the TokenList.
         * @param t The new Token.
        */
        void addToken(Token t) noexcept{
            tokens.push_back(t);
        }
        /**
         * Returns an specified Token without deleting it.
         * @param n The index of the target Token.
         * @return The Token with index n inside the list.
        */
        const inline Token get(int n) noexcept{
            if(n > size()){
                return {};
            }
            return tokens.at(n);
        }
        /**
         * @return The size of the TokenList.
        */
        const inline int size() noexcept{
            return tokens.size();
        }

        void toString(){
            for (size_t i = 0; i < tokens.size(); i++)
            {
                cout <<  tokens.at(i).type << " - " << tokens.at(i).value << endl;
            }
            
        }
    private:
        std::deque<Token> tokens;
};

const std::string STDWRITE = "\tmovq $1, %rax\n\tmovq $1, %rdi\n";

bool isSymbol(char c){
    string s;
    s = c;
    auto it = prefabs.find(s);
    return it != prefabs.end();
}

int search(string buff, int min = 0){
    auto it = prefabs.find(buff);
    if(it != prefabs.end() and it->second > min){
        return it->second;
    }
    return 0;
}
int search(char c, int min = 0){
    string buff;
    buff += c;
    auto it = prefabs.find(buff);
    if(it != prefabs.end() and it->second > min){
        return it->second;
    }
    return 0;
}

bool isIntLiteral(TokenType t){
    return t == TokenType::int_lit || t == TokenType::byte_lit;
}
wstring charToString(char c){
    wstring s;
    s += c;
    return s;
}