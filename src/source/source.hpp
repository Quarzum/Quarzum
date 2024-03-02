#pragma once
// This class manages the input file, creating a Source object with a specified path
class Source: public QComponent{

public:

    Source(const string path): m_path(path){

        if(m_path.substr(m_path.size() - 3) != ".qz") {
            errorHandler.errCritical({file_not_found_err, 0, "Invalid format."});
        }

    }
    
    const string getContent() {
        string line, result;
        ifstream input(m_path);
        if(input.is_open()){
            while (getline(input, line)) { result += line + "\n"; }
            input.close();
            return result;
        }
        errorHandler.errCritical({file_not_found_err, 0, "The specified path does not match any file."});
        return "";        
    }

private:

    string m_path;

};