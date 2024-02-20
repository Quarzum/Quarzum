#pragma once

struct Variable{
    qstring name;
    qstring type;
    qstring value;
};



class VarList{
public:
    VarList(){}
    void addVariable(Variable var){
        if(isUnique(var.name.value)){
            v_list.push_back(var);
        }
    }
    void removeVariable(qstring name){
        for (size_t i = 0; i < v_list.size(); i++)
        {
            if(v_list.at(i).name == name){
                v_list.erase(v_list.begin() + i);
            }
        }
    }
    Variable getVariable(qstring name){
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
    bool isUnique(qstring name){
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