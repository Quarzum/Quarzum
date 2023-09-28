#pragma once

void applyConfig(const string path)
{
    /* TODO: Applies a config rule */
    AUTO_RESIZE = true;
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
        /* If it exists, execute instructions */
        applyConfig(getSource(location + path + ".config.qz"));
    }
}