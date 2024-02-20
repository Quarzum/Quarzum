#pragma once
#include "../Quarzum.h"

// Converts a list of statements into a string with the code in asm at&t for x86_32
const string analyze(vector<Statement> input) noexcept{
    stringstream output;
    vector<qstring> var;

    output << ".text\n";
    output << ".global _start\n";
    output << "_start:\n";

    for (size_t i = 0; i < input.size(); i++)
    {
        Statement s = input.at(i);
        string varName;
        switch (s.type)
        {
        case exit_stmt:
            output << "    movq $60, %rax\n";
            output << "    movq $" << any_cast<Token>(s.args[0]).value.value << ", %rdi\n";
            output << "    syscall\n\n";
            break;
        
        case out_stmt:
            varName = "_out" + to_string(var.size());
            var.push_back(any_cast<qstring>(s.args[0]));
            var[var.size()-1].pop();
            var[var.size()-1] += "\\n\"";
            output << STDWRITE + "    movq $"+varName+", %rsi\n    movq $_len" + to_string(var.size() - 1) + ", %rdx\n    syscall\n\n";
            break;
        
        case redec_stmt:
            output << "     movq $" << any_cast<Token>(s.args[1]).value.value  << ", " << any_cast<qstring>(s.args[0]).value << "\n\n";
            break;
    
        }
    }
    output << "    movq $60, %rax\n    movq $0, %rdi\n    syscall\n"; // exit 0 if not specified
    output << ".data\n";
    for (size_t i = 0; i < input.size(); i++){
        if(input.at(i).type == var_stmt){
            output <<"\t"<< any_cast<qstring>(input.at(i).args[1]).value << ": ." << any_cast<qstring>(input.at(i).args[0]).value << " " << any_cast<qstring>(input.at(i).args[2]).value << "\n";
        }
    }
    for (size_t i = 0; i < var.size(); i++)
    {
        output << "    _out"+ to_string(i) +": .ascii " + var[i].value + "\n    _len"+ to_string(i) +" = . - _out"+ to_string(i) +"\n";
    }
    output << ".ident \"Quarzum Compiler 0.0.1\"\n";
    return output.str();
}