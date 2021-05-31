#ifndef NODE_H
#define NODE_H


#include<vector>
#include<iostream>
#include <string>
#include<map>
#include<fstream>
#include<cstdlib>
using namespace std;
#define YYSTYPE Node *
enum Nodetype
{
    NODE_ROOT,
    NODE_REG,
    NODE_LABEL,
    NODE_FUNC,
    NODE_VAR,
    NODE_NUM,


    NODE_GLOBAL_DECL_NUM,
    NODE_GLOBAL_DECL_ARR,
    NODE_FuncDef,
    NODE_Header,
    NODE_End,
    NODE_EXPS,

    NODE_AND,
    NODE_OR,
    NODE_ADD,
    NODE_MINUS,
    NODE_MUL,
    NODE_DIV,
    NODE_MOD,
    NODE_NEQ,
    NODE_EQUAL,
    NODE_MORE,
    NODE_LESS,
    NODE_GEQ,
    NODE_LEQ,
    NODE_NOT,
    NODE_RARBR,
    NODE_RARBN,
    NODE_RAOR,
    NODE_RAR,
    NODE_RAN,
    NODE_RLNRAR,
    NODE_RARLNR,
    NODE_IRLRGL,
    NODE_GL,
    NODE_LC,
    NODE_CF,
    NODE_R,
    NODE_SRN,
    NODE_LNR,
    NODE_LVR,
    NODE_LADDRNR,
    NODE_LADDRVR
}
;
class Node
{
    public:
    Nodetype nodetype;
    vector<Node *> Child;
    int int_val;
    string ID;
    Node(Nodetype nodetype_)
    {
        nodetype = nodetype_;
        Child = vector<Node *>();
    }
};
#include "./tigger.tab.hpp"

#endif 