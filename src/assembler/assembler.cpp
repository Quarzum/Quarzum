#pragma once
#include "../Quarzum.h"

class Assembler {

public:
    Assembler (vector<Statement> input) : m_input(input) {}

    string assemble(){
        m_output << ".data\n";
        for(int i = 0; i < symbolTable.size(); i++){
            Symbol s = symbolTable.get(i);
            if(s.type == "int"){
                m_output << "\t" << s.name << ": .int " << s.value << "\n";
            }
        }

        m_output << ".text\n.globl _start\n_start:\n";

        exitProgram();

        return m_output.str();
    }
private:
    vector<Statement> m_input;
    stringstream m_output;

    void exitProgram(){
        m_output << "\tmov $60, %rax\n\tmov $0, %rdi\n\tsyscall\n";
    }
};