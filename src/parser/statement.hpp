#pragma once
#include "../Quarzum.h"

enum StmtType{
    exit_stmt,
    out_stmt,
    var_stmt,
    func_stmt,
    redec_stmt,
    inc_stmt,
    dec_stmt,
    mul_stmt,
    div_stmt,
    if_stmt,
    while_stmt,
    for_stmt
};

// A Statement is a structure that contains one order of type "type" and with 8 possible arguments to pass in.
struct Statement{
    StmtType type;
    string args[8];
    any children;
};

class StatementList {
public:
    Statement get(size_t n) {
        return m_content[n];
    }
    void add(Statement s){
        m_content.push_back(s);
    }
    vector<Statement> getAll() {
        return m_content;
    }
private:
    vector<Statement> m_content;
};