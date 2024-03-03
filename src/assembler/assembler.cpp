#pragma once
#include "../Quarzum.h"

class Assembler {

public:
    Assembler (vector<Statement> input) : m_input(input) {}

    string assemble(){
        m_output << ".data\n";

        m_output << ".text\n.globl _start\n_start:\n";
        
        return m_output.str();
    }
private:
    vector<Statement> m_input;
    stringstream m_output;
};