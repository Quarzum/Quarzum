class Source
{
public:
    Source(const string path) : route(move(path)) {}
    const string get()
    {
        /*

        Reads the file and returns its content

        */
        ifstream input(route);
        if (input.fail())
        {
            errorHandler.exit(FILE_NOT_FOUND_ERROR, "No such file or directory");
        }
        string source, line;
        int index = 0;
        while (getline(input, line))
        {
            source += line + '\n';
        }
        return source;
    }
    void validate()
    {
        /*

        Checks that the file is in a Quarzum able format

        */
        if (route.substr(route.size() - 3) != ".qz")
        {
            errorHandler.exit(REFERENCE_ERROR, "Invalid file format");
        }
    }

    string route;

private:
    deque<int> jumps;
};

// Initialize the source
static Source src = Source("");