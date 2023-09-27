#pragma once
void chechForConfigFile(string path)
{
    /* Determines the location where the config file should be */
    string location = path.substr(0, path.find_last_of("/") + 1);
    /* Extracts the name of the file and checks if there is a name with that name with ".config.qz" */
    path = path.substr(path.find_last_of("/") + 1);
    path = path.substr(0, path.size() - 3);
    ifstream input(location + path + ".config.qz");
    cout << location + path + ".config.qz" << endl;
    if (input.good())
    {
        /* If it exists, execute instructions */
        cout << "Config file detected" << endl;
    }
}