void applyConfig(const string path)
{
    /* TODO: Applies a config rule */
    uint16_t i = 0;
    string buffer;
    while (i < path.size())
    {
        buffer += path.at(i);
        if (buffer == "#auto-resize(true)" || buffer == " #auto-resize")
        {
            AUTO_RESIZE = true;
            buffer.clear();
        }
        if (buffer == "#auto-resize(false)")
        {
            AUTO_RESIZE = false;
            buffer.clear();
        }
        i++;
    }
}

void chechForConfigFile(string path)
{
    /* Determines the location where the config file should be */
    string location = path.substr(0, path.find_last_of("/") + 1);
    /* Extracts the name of the file and checks if there is a name with that name with ".config.qz" */
    path = path.substr(path.find_last_of("/") + 1);
    path = path.substr(0, path.size() - 3);
    ifstream input(location + path + ".config.qz");

    if (input.good())
    {
        SourceComponent source = SourceComponent(location + path + ".config.qz");
        /* If it exists, execute instructions */
        applyConfig(source.get());
    }
}