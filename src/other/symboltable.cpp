#pragma once
#include "../Quarzum.h"

struct Symbol {
    string name;
    string type;
    string value;
};

class SymbolTable {
    
public:

    void add(Symbol s) {
        m_content.push_back(s);
    }

    size_t size(){
        return m_content.size();
    }

    Symbol get(size_t n) {
        return m_content[n];
    }

private:
    vector<Symbol> m_content;
};

SymbolTable symbolTable;