class Generator
{
public:
    Generator(AST stat) : m_stat(move(stat)) {}
    string generate()
    {
        /* Generates assembly code from the values of the AST */
        string assembly;
        assembly =
            "   global _main\n"
            "   section .text\n"
            "_main:\n"
            "   mov rax, 1\n"
            "   mov rdi, 1\n"
            "   mov rsi, message\n"
            "   mov rdx, 13\n"
            "   syscall\n"
            "   mov rax, 60\n"
            "   xor rdi, rdi\n"
            "   syscall\n"
            "   section '.data'\n"
            "message: db 'Hello world', 10\n";

        return assembly;
    }

private:
    AST m_stat;
};