class Source
{
public:
    Source(const string path) : route(move(path)) {}
    const string get()
    {
        /* Reads the file and returns its content */
        ifstream input(route);
        if (input.fail())
        {
            throwError(FILE_NOT_FOUND_ERROR, "No such file or directory");
        }
        string source, line;
        while (getline(input, line))
        {
            source += line + '\n';
        }
        return source;
    }
    void validate()
    {
        if (route.substr(route.size() - 3) != ".qz")
        {
            throwError(REFERENCE_ERROR, "Invalid file format");
        }
    }

private:
    string route;
};