#pragma once
#include "../Quarzum.h"

// Converts a list of statements into a string with the code in asm at&t for x86_32
const string analyze(deque<Statement> input) noexcept{
    string output;
    deque<string> var;
    output = ".text\n.global _start\n_start:\n";

    for (size_t i = 0; i < input.size(); i++)
    {
        Statement s = input.at(i);
        switch (s.type)
        {
        case exit_stmt:
            output += "\tmovq $60, %rax\n\tmovq $" + any_cast<string>(s.args[0]) + ", %rdi\n\tsyscall\n\n";
            break;
        
        case out_stmt:
            string varName = "_out" + to_string(var.size());
            var.push_back(any_cast<string>(s.args[0]));
            var[var.size()-1].pop_back();
            var[var.size()-1] += "\\n\"";
            output += STDWRITE + "\tmovq $"+varName+", %rsi\n\tmovq $_len" + to_string(var.size() - 1) + ", %rdx\n\tsyscall\n\n";
            break;
        }
    }
    output += "\tmovq $60, %rax\n\tmovq $0, %rdi\n\tsyscall\n"; // exit 0 if not specified
    output += ".data\n";
    for (size_t i = 0; i < var.size(); i++)
    {
        output += "\t_out"+ to_string(i) +": .ascii " + var[i] + "\n\t_len"+ to_string(i) +" = . - _out"+ to_string(i) +"\n";
    }
    output += ".ident \"Quarzum Compiler 0.0.1\"\n";
    return output;
}