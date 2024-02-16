#pragma once
/**
 * This class manages the input file, creating a Source object with a specified path.
 * @param path The target file's path.
*/
class Source: public QComponent{
private:
    string path;
public:
    Source(string path): path(move(path)){
        if(not(this->path.substr(this->path.size() -3) == ".qz")){
            errorHandler.errCritical({file_not_found_err, 0, "Invalid format."});
        }
    }
    /**
     * @return The input file content
    */
    const string getContent(){
        string line, result;
        ifstream input(path);
        if(input.is_open()){
            while (getline(input, line))
            {
                result += line + "\n";
            }
            input.close();
            return result;
        }
        errorHandler.errCritical({file_not_found_err, 0, "The specified path does not match any file."});
    }
};