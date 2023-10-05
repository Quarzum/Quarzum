class Linker
{
public:
    Linker(AST root) : m_root(move(root)) {}

    AST link()
    {
        // deque<Import> imports = m_root.imports;
        // for (unsigned short i = 0; i < imports.size(); i++)
        // {
        //     string src = getSource(imports.at(i).path);
        //     cout << src << endl;
        // }
        return m_root;
    }

private:
    AST m_root;
};