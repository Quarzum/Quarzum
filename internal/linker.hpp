class Linker
{
public:
    Linker(Root root) : m_root(move(root)) {}

    Root link()
    {
        deque<Import> imports = m_root.imports;
        for (unsigned short i = 0; i < imports.size(); i++)
        {
            string src = getSource(imports.at(i).path);
            cout << src << endl;
        }
        return m_root;
    }

private:
    Root m_root;
};