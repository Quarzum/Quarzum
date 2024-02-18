#pragma once
#include "../Quarzum.h"
#define NC "\e[0m"
#define RED_BG "\e[30;41m"
#define YELLOW_BG "\e[30;103m"
#define GREEN_BG "\e[30;102m"
#define TEAL "\e[36;40m"
#define YELLOW "\e[93;40m"
#define GRAY "\e[90;40m"
#define RED "\e[31m"
enum ErrorType{
    file_not_found_err  = 0,
    lexical_err = 1,
    syntax_err = 2
};

struct Error{
    ErrorType type;
    uint line;
    string description;
};

// Stores a limited amount of Errors. At the end of a process, it should be executed by the run() method.
class ErrorHandler{
    public:
        void run(){
            if(errors.size() > 0){
                for (size_t i = 0; i < errors.size(); i++)
                {
                    if(errors.at(i).line > 0){
                        cout << errToStr(errors.at(i).type).str() << " - " << errors.at(i).description << " at line " << errors.at(i).line << "\n"; 
                    }
                    else{
                        cout << errToStr(errors.at(i).type).str() << " - " << errors.at(i).description << "\n"; 
                    }
                }
                
                exit(EXIT_FAILURE);
            }
        }
        void err(Error e){
            errors.push_back(e);
        }
        void errCritical(Error e){
            errors.push_back(e);
            run();
        }
    private:
        std::deque<Error> errors;

        stringstream errToStr(ErrorType e){
            stringstream s;
            switch (e)
            {
            case file_not_found_err:
                s << RED << "FileNotFoundError" << NC;
                break;
            case syntax_err:
                s << RED << "SyntaxError" << NC;
            default:
                break;
            }
            return s;
        }
};