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
            Error.exit(FILE_NOT_FOUND_ERROR, "No such file or directory");
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
            Error.exit(REFERENCE_ERROR, "Invalid file format");
        }
    }

    string route;

private:
    deque<int> jumps;
};

// Initialize the source
static SourceComponent Source = SourceComponent("");