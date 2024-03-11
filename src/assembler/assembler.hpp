#pragma once
/**
 * File: assembler.hpp
 * Description: Contains all the utils for the assembler
 * Contents:    
*/
namespace Quarzum::Asm {
    #include <string>
    constexpr std::string exit(std::string code) {
        return "\tmov $60, %rax\n\tmov $" + code +", %rdi\n\tsyscall\n";
    }
}