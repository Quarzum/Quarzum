#pragma once
#include "../Quarzum.h"

enum ErrorType{

};

struct Error{
    ErrorType type;
    int line;
    string description;
};

// Stores a limited amount of Errors. At the end of a process, it should be executed by the run() method.
class ErrorHandler{
    public:
        void run(){
            if(errors.size() > 0){
                for (size_t i = 0; i <= errors.size(); i++)
                {
                    cout << errToStr(errors.at(i).type) << " - " << errors.at(i).description << " at line " << errors.at(i).line << endl; 
                }
                
                exit(EXIT_FAILURE);
            }
        }
        void err(Error e){
            errors.push_back(e);
        }
    private:
        deque<Error> errors;

        string errToStr(ErrorType e){
            return "err";
        }
};