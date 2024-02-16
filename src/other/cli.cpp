#pragma once
class CLI{
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
    const bool isFlag(string arg) noexcept{
        return arg[0] = '-' and arg[1] == '-';
    }
};