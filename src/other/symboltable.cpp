#pragma once
#include "../Quarzum.h"

enum SymbolType {
    INT,
    NUMBER,
    BYTE,
    BOOL,
    CHAR,
    STRING,
    UINT,
    FUNCTION,
    CLASS,
    OBJECT,
    STRUCT,
    VAR
};

struct Symbol {
    string name;
    SymbolType type;
    string value;
};

class SymbolTable {
    
public:
    void add(Symbol s) {
        m_content.push_back(s);
    }
private:
    vector<Symbol> m_content;
};

SymbolTable symbolTable;