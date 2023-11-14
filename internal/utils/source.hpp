class SourceComponent
{
public:
    SourceComponent(const string path) : route(move(path)) {}
    // Reads the file and returns its content
    const string get()
    {
        ifstream input(route);
        if (input.fail())
        {
            Debug.err("No such file or directory", "FileNotFoundError");
        }
        string source, line;
        unsigned int index = 0;
        while (getline(input, line))
        {
            source += line + '\n';
        }
        return source;
    }
    // Checks that the file is in a Quarzum able format
    void validate()
    {
        if (route.substr(route.size() - 3) != ".qz")
        {
            Debug.err("Invalid file format", "ReferenceError");
        }
    }

    string route;

private:
    deque<int> jumps;
};

// Initialize the source
static SourceComponent Source = SourceComponent("");