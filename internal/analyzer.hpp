class Analyzer
{
public:
    Analyzer(){};
    void analyze()
    {
        for (int i = 0; i < ast.nodes.size(); i++)
        {
            Statement stat = ast.nodes.at(i);
            cout << stat.type << endl;
        }
    }

private:
};

static Analyzer analyzer = Analyzer();