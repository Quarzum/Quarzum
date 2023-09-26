#pragma once
using namespace std;

bool isOperator(char value)
{
    return (value == '+' || value == '-' || value == '*' || value == '/' || value == '%' || value == '^');
};
bool isSizeModifier(string value)
{
    return (value == "x8" || value == "x16" || value == "x32" || value == "x64");
};
map<string, int> keywords = {
    {"exit", 0},
    {"return", 1},
    {"import", 2},
    {"from", 3},
    {"int", 5},
    {"string", 7},
    {"number", 9},
    {"true", 10},
    {"false", 11},
    {"bool", 12},
    {"var", 13},
    {"function", 14},
    {"null", 15},
    {"struct", 16},
    {"enum", 17},
    {"class", 18},
    {"public", 19},
    {"private", 20},
    {"module", 21},
    {"const", 37},
    {"unsigned", 38},
    {"short", 39},
    {"long", 40},
};
int findKeyword(string keyword)
{
    return keywords.at(keyword);
}

struct Operator
{
    TokenType op;
};

struct Expr
{
    Token literal;
};

struct Exit
{
    Expr value;
};

struct Assign
{
    TokenType type;
    Token ident;
    Expr value;
};
struct ReAssign
{
    Token ident;
    Expr value;
};

struct Import
{
    Token id;
    string path;
};

struct Root
{
    deque<Exit> childs;
    deque<Import> imports;
};

string getSource(const string path)
{
    /* Reads the file and returns its content */
    ifstream input(path);
    if (input.fail())
    {
        throwError(FILE_NOT_FOUND);
    }
    string source, line;
    while (getline(input, line))
    {
        source += line + '\n';
    }
    return source;
}
void debug(deque<Token> composed)
{
    /* Shows in console a list of tokens */
    for (unsigned short int i = 0; i < composed.size(); i++)
    {
        cout << composed.at(i).type << " | " << composed.at(i).value << endl;
    }
}
void validateFormat(char *argv[])
{
    string path;
    path = argv[1];
    if (path.substr(path.size() - 3) != ".qz")
    {
        throwError(INVALID_FORMAT);
    }
}