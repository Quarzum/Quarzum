#pragma once
#include "../Quarzum.h"

// Converts a list of statements into a string with the code in asm at&t for x86_32
string analyze(deque<Statement> input){
    string output;

    output = ".text\n.global _start\n_start:\n";

    for (size_t i = 0; i < input.size(); i++)
    {
        Statement s = input.at(i);
        switch (s.type)
        {
        case return_stmt:
            output += "\tmovl $1, %eax\n\tmovl $" + any_cast<string>(s.args[0]) + ", %ebx\n\tint $0x80\n";
            break;
        }
    }
    return output;
}