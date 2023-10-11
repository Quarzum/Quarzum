const string getSource(const string path)
{
    /* Reads the file and returns its content */
    ifstream input(path);
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

void validateFormat(char *argv[])
{
    string path;
    path = argv[1];
    if (path.substr(path.size() - 3) != ".qz")
    {
        throwError(REFERENCE_ERROR, "Invalid file format");
    }
}
