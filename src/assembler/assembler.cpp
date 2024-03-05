#pragma once
#include "../Quarzum.h"

class Assembler {

public:
    Assembler (vector<Statement> input) : m_input(input) {}

    string assemble(){
        m_output << ".data\n";
        for(int i = 0; i < symbolTable.size(); ++i) {
            Symbol s = symbolTable.get(i);
            if(s.isConst) {
                if(s.type == "int"){
                    m_output << "\t" << s.name << " = " << s.value << "\n";
                } 
            }
            else {
                if(s.type == "int"){
                    m_output << "\t" << s.name << ": .int " << s.value << "\n";
                } 
            }
            
        }

        m_output << ".text\n.globl _start\n_start:\n";

        for(int i = 0; i < m_input.size(); ++i) {
            Statement s = m_input[i];
            if(s.type == inc_stmt) {
                m_output << "\tadd $" << any_cast<string>(s.args[1]) << ", " << any_cast<string>(s.args[0]) << "\n";
            }
            if(s.type == dec_stmt) {
                m_output << "\tsub $" << any_cast<string>(s.args[1]) << ", " << any_cast<string>(s.args[0]) << "\n";
            }
            if(s.type == exit_stmt) {
                m_output << "\tmov $60, %rax\n\tmov $" << any_cast<string>(s.args[0]) << ", %rdi\n\tsyscall\n";
            }
        }

        exitProgram();

        return m_output.str();
    }
private:
    vector<Statement> m_input;
    stringstream m_output;

    void exitProgram(){
        m_output << "\n\tmov $60, %rax\n\tmov $0, %rdi\n\tsyscall\n";
    }
};