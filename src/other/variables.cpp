#pragma once

struct Variable{
    string name;
    string type;
    string value;
};



class VarList{
public:
    VarList(){}
    void addVariable(Variable var){
        if(isUnique(var.name)){
            v_list.push_back(var);
        }
    }
    void removeVariable(string name){
        for (size_t i = 0; i < v_list.size(); i++)
        {
            if(v_list.at(i).name == name){
                v_list.erase(v_list.begin() + i);
            }
        }
    }
    Variable getVariable(string name){
        for (size_t i = 0; i < v_list.size(); i++)
        {
            if(v_list.at(i).name == name){
                return v_list.at(i);
            }
        }
        return {};
    }
    // TO DO: updateVariable

private:
    vector<Variable> v_list;
    bool isUnique(string name){
        for (size_t i = 0; i < v_list.size(); i++)
        {
            if(v_list.at(i).name == name){
                return false;
            }
        }
        return true;
    }
};

    VarList varlist = VarList();