#pragma once
#include "../Quarzum.h"
typedef unsigned char int8;
typedef unsigned int uint;
#define NC "\e[0m"
#define RED_BG "\e[30;41m"
#define YELLOW_BG "\e[30;103m"
#define GREEN_BG "\e[30;102m"
#define TEAL "\e[36;40m"
#define YELLOW "\e[93;40m"
#define GRAY "\e[90;40m"

bool isDebugging = false;
/**
 *    Searchs for a string inside a string array. 
 *    If the target string is not found, returns -1.
 *    @param target The target string to find.
 *    @param list The list where the function will search.
 *    @param maxIndex The max index to find.
 *    @return The index of the target string inside the array.
*/
inline const signed int search(std::string target,const std::string list[], int maxIndex) noexcept{
    for (uint i = 0; i < maxIndex; i++)
    {
        if(list[i] == target){ return i;}
    }
    return -1;
}

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
    "private",
    "uint",
    "short",
    "long",
    "byte"
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
    "]",
    ";",
    ">",
    "<",
    "==",
    ">=",
    "<="
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
            return tokens.at(n);
        }
        /**
         * @return The size of the TokenList.
        */
        const inline int size() noexcept{
            return tokens.size();
        }
    private:
        std::deque<Token> tokens;
};

const std::string STDWRITE = "\tmovq $1, %rax\n\tmovq $1, %rdi\n";

bool isSymbol(char c){
    string s;
    s = c;
    return search(s, symbols, 28) != 0x200;
}
/**
 * This class manages the input file, creating a Source object with a specified path.
*/
class Source{
public:
    string path;
    Source(string path){
        this->path = path;
    }
    /**
     * @return The input file content
    */
    const string getContent(){
        string line, result;
        ifstream input(path);
        if(input.is_open()){
            while (getline(input, line))
            {
                result += line + "\n";
            }
            input.close();
            return result;
        }
        else{
            cerr << "FileNotFoundError: The specified path does not match any file.\n";
            exit(EXIT_FAILURE);
        }
    }
};
bool isIntLiteral(TokenType t){
    return t == TokenType::int_lit || t == TokenType::byte_lit;
}
wstring charToString(char c){
    wstring s;
    s += c;
    return s;
}