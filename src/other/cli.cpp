#pragma once
class CLI: public QComponent{
public:
    inline CLI(char* args[]){
        command = args[1];
        /* TO-DO
        
        if(command == "run"){

        }
        else if(command == "install"){

        }
        else if(command == "init"){

        }
        else{

        }*/
        
        Source s = Source("code.qz");

    }
private:
    string command;
    bool isFlag(const string arg) noexcept{
        return arg[0] == '-' and arg[1] == '-';
    }
};