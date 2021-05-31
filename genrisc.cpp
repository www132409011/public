#include"./node.hpp"
Node* root = new Node(NODE_ROOT);
extern std::ofstream Mycout;
int STK;
void genfuncheader(Node* func_header)
{
    string name = func_header->Child[0]->ID.substr(2,
    func_header->Child[0]->ID.size()-2);
    Mycout<<"\t"<<".text"<<endl;
    Mycout<<"\t"<<".align   2"<<endl;
    Mycout<<"\t"<<".global  "<<name<<endl;
    Mycout<<"\t"<<".type    "<<name<<", @function"<<endl;
    Mycout<<name<<":"<<endl;
    int space = func_header->Child[2]->int_val;
    STK = (space/4 + 1)*16;
    Mycout<<"\taddi\tsp, sp, -"<<STK<<endl;
    Mycout<<"\tsw  \tra, "<<STK-4<<"(sp)"<<endl;
}
void genfuncend(Node* func_end)
{
    string name = func_end->Child[0]->ID.substr(2,
    func_end->Child[0]->ID.size()-2);
    Mycout<<"\t.size\t"<<name<<", .-"<<name<<endl;
}
void genglobalvar(Node* global_var)
{
    string name =global_var->Child[0]->ID;
    Mycout<<"\t.global\t"<<name<<endl;
    Mycout<<"\t.section\t"<<".sdata"<<endl;
    Mycout<<"\t.align\t"<<"2"<<endl;
    Mycout<<"\t.type\t"<<name<<", @object"<<endl;
    Mycout<<"\t.size\t"<<name<<", 4"<<endl;
    Mycout<<name<<":"<<endl;
    Mycout<<"\t.word\t"<<global_var->Child[1]->int_val<<endl;
}
void genglobalarr(Node* global_arr)
{
    string name = global_arr->Child[0]->ID;
    int int_val = global_arr->Child[1]->int_val;
    Mycout<<"\t.comm\t"<<name<<", "<<int_val<<", 4"<<endl;

}
void gen_RARBR(Node* exp)
{
    string reg1 = exp->Child[0]->ID;
    string reg2 = exp->Child[1]->ID;
    string reg3 = exp->Child[3]->ID;
    string op = exp->Child[2]->ID;
    if(op == "+")
    {
        Mycout<<"\tadd\t"<<reg1<<", "<<reg2
        <<", "<<reg3<<endl;
    }
    if(op == "-")
    {
        Mycout<<"\tsub\t"<<reg1<<", "<<reg2
        <<", "<<reg3<<endl;
    }
    if(op == "*")
    {
        Mycout<<"\tmul\t"<<reg1<<", "<<reg2
        <<", "<<reg3<<endl;
    }
    if(op == "/")
    {
        Mycout<<"\tdiv\t"<<reg1<<", "<<reg2
        <<", "<<reg3<<endl;
    }
    if(op == "%")
    {
        Mycout<<"\trem\t"<<reg1<<", "<<reg2
        <<", "<<reg3<<endl;
    }
    if(op == "<")
    {
        Mycout<<"\tslt\t"<<reg1<<", "<<reg2
        <<", "<<reg3<<endl;
    }
    if(op == ">")
    {
        Mycout<<"\tsgt\t"<<reg1<<", "<<reg2
        <<", "<<reg3<<endl;
    }
    if(op == "<=")
    {
        Mycout<<"\tsgt\t"<<reg1<<", "<<reg2
        <<", "<<reg3<<endl;
        Mycout<<"\tseqz\t"<<reg1<<", "<<reg2
        <<", "<<reg3<<endl;
    }
    if(op == ">=")
    {
        Mycout<<"\tslt\t"<<reg1<<", "<<reg2
        <<", "<<reg3<<endl;
        Mycout<<"\tseqz\t"<<reg1<<", "<<reg2
        <<", "<<reg3<<endl;
    }
    if(op == "&&")
    {
        Mycout<<"\tsnez\t"<<reg1<<", "<<reg2<<endl;
        Mycout<<"\tsnez\ts0"<<", "<<reg3<<endl;
        Mycout<<"\tand\t"<<reg1<<", "<<reg1<<", s0"<<endl;
    }
    if(op == "||")
    {
        Mycout<<"\tor\t"<<reg1<<", "<<reg2<<", "
        <<reg3<<endl;
        Mycout<<"\tsnez\t"<<reg1<<", "<<reg1<<endl;
    }
    if(op == "!=")
    {
        Mycout<<"\txor\t"<<reg1<<", "<<reg2<<", "
        <<reg3<<endl;
        Mycout<<"\tsnez\t"<<reg1<<", "<<reg1<<endl;
    }
    if(op == "==")
    {
        Mycout<<"\txor\t"<<reg1<<", "<<reg2<<", "
        <<reg3<<endl;
        Mycout<<"\tseqz\t"<<reg1<<", "<<reg1<<endl;
    }
}

void gen_RARBN(Node* exp)
{
    string reg1 = exp->Child[0]->ID;
    string reg2 = exp->Child[1]->ID;
    string reg3 = "s0";
    int int_val = exp->Child[3]->int_val;
    string op = exp->Child[2]->ID;
    Mycout<<"\tli\t"<<reg3<<", "<<int_val<<endl;
    if(op == "+")
    {
        Mycout<<"\tadd\t"<<reg1<<", "<<reg2
        <<", "<<reg3<<endl;
    }
    if(op == "-")
    {
        Mycout<<"\tsub\t"<<reg1<<", "<<reg2
        <<", "<<reg3<<endl;
    }
    if(op == "*")
    {
        Mycout<<"\tmul\t"<<reg1<<", "<<reg2
        <<", "<<reg3<<endl;
    }
    if(op == "/")
    {
        Mycout<<"\tdiv\t"<<reg1<<", "<<reg2
        <<", "<<reg3<<endl;
    }
    if(op == "%")
    {
        Mycout<<"\trem\t"<<reg1<<", "<<reg2
        <<", "<<reg3<<endl;
    }
    if(op == "<")
    {
        Mycout<<"\tslt\t"<<reg1<<", "<<reg2
        <<", "<<reg3<<endl;
    }
    if(op == ">")
    {
        Mycout<<"\tsgt\t"<<reg1<<", "<<reg2
        <<", "<<reg3<<endl;
    }
    if(op == "<=")
    {
        Mycout<<"\tsgt\t"<<reg1<<", "<<reg2
        <<", "<<reg3<<endl;
        Mycout<<"\tseqz\t"<<reg1<<", "<<reg2
        <<", "<<reg3<<endl;
    }
    if(op == ">=")
    {
        Mycout<<"\tslt\t"<<reg1<<", "<<reg2
        <<", "<<reg3<<endl;
        Mycout<<"\tseqz\t"<<reg1<<", "<<reg2
        <<", "<<reg3<<endl;
    }
    if(op == "&&")
    {
        Mycout<<"\tsnez\t"<<reg1<<", "<<reg2<<endl;
        Mycout<<"\tsnez\ts0"<<", "<<reg3<<endl;
        Mycout<<"\tand\t"<<reg1<<", "<<reg1<<", s0"<<endl;
    }
    if(op == "||")
    {
        Mycout<<"\tor\t"<<reg1<<", "<<reg2<<", "
        <<reg3<<endl;
        Mycout<<"\tsnez\t"<<reg1<<", "<<reg1<<endl;
    }
    if(op == "!=")
    {
        Mycout<<"\txor\t"<<reg1<<", "<<reg2<<", "
        <<reg3<<endl;
        Mycout<<"\tsnez\t"<<reg1<<", "<<reg1<<endl;
    }
    if(op == "==")
    {
        Mycout<<"\txor\t"<<reg1<<", "<<reg2<<", "
        <<reg3<<endl;
        Mycout<<"\tseqz\t"<<reg1<<", "<<reg1<<endl;
    }
}

void gen_RASR(Node* exp)
{
    string reg1 = exp->Child[0]->ID;
    string op = exp->Child[1]->ID;
    string reg2 = exp->Child[2]->ID;
    if(op == "-")
    {
        Mycout<<"\tneg\t"<<reg1<<", "<<reg2<<endl;
    }
    if(op == "!")
    {
        Mycout<<"\tseqz\t"<<reg1<<", "<<reg2<<endl;
    }
}
void gen_RAR(Node* exp)
{
    string reg1 = exp->Child[0]->ID;
    string reg2 = exp->Child[1]->ID;
    Mycout<<"\tmv\t"<<reg1<<", "<<reg2<<endl;
}
void gen_RAN(Node* exp)
{
    string reg = exp->Child[0]->ID;
    int int_val = exp->Child[1]->int_val;
    Mycout<<"\tli\t"<<reg<<", "<<int_val<<endl;
}
void gen_RLNRAR(Node* exp)
{
    string reg1 = exp->Child[0]->ID;
    int int_val = exp->Child[1]->int_val;
    string reg2 = exp->Child[2]->ID;
    Mycout<<"\tsw\t"<<reg2<<", "<<int_val<<"("
    <<reg1<<")"<<endl;
}
void gen_RARLNR(Node* exp)
{
    string reg1 = exp->Child[0]->ID;
    string reg2 = exp->Child[1]->ID;
    int int_val = exp->Child[2]->int_val;
    Mycout<<"\tlw\t"<<reg1<<", "<<int_val
    <<"("<<reg2<<")"<<endl;
}
void gen_IRLRGL(Node* exp)
{
    string reg1 = exp->Child[0]->ID;
    string op = exp->Child[1]->ID;
    string reg2 = exp->Child[2]->ID;
    string label = exp->Child[3]->ID;
    if(op == "<")
    {
        Mycout<<"\tblt\t"<<reg1<<", "<<reg2
        <<", ."<<label<<endl;
    }
    if(op == ">")
    {
       Mycout<<"\tbgt\t"<<reg1<<", "<<reg2
       <<", ."<<label<<endl; 
    }
    if(op == "<=")
    {
        Mycout<<"\tble\t"<<reg1<<", "<<reg2
        <<", ."<<label<<endl;
    }
    if(op == ">=")
    {
        Mycout<<"\tbge\t"<<reg1<<", "<<reg2
        <<", ."<<label<<endl;
    }
    if(op == "!=")
    {
        Mycout<<"\tbne\t"<<reg1<<", "<<reg2
        <<", ."<<label<<endl;
    }
    if(op == "==")
    {
        Mycout<<"\tbeq\t"<<reg1<<", "<<reg2
        <<", ."<<label<<endl;
    }
}
void gen_GL(Node* exp)
{
    string label = exp->Child[0]->ID;
    Mycout<<"\tj ."<<label<<endl;
}
void gen_LC(Node* exp)
{
    string label = exp->Child[0]->ID;
    Mycout<<"."<<label<<":"<<endl;
}
void gen_CF(Node* exp)
{
    string func = exp->Child[0]->ID.substr(2,
    exp->Child[0]->ID.size()-2);
    Mycout<<"\tcall\t"<<func<<endl;
}
void gen_R()
{
    Mycout<<"\tlw\t"<<"ra, "<<STK-4<<"(sp)"<<endl;
    Mycout<<"\taddi\t"<<"sp, sp, "<<STK<<endl;
    Mycout<<"\tret"<<endl;
}
void gen_SRN(Node* exp)
{
    string reg = exp->Child[0]->ID;
    int int_val = exp->Child[1]->int_val;
    Mycout<<"\tsw\t"<<reg<<", "<<int_val
    <<"*4(sp)"<<endl;
}
void gen_LNR(Node* exp)
{
    int int_val = exp->Child[0]->int_val;
    string reg = exp->Child[1]->ID;
    Mycout<<"\tlw\t"<<reg<<", "<<int_val
    <<"*4(sp)"<<endl;
}
void gen_LVR(Node* exp)
{
    string var = exp->Child[0]->ID;
    string reg = exp->Child[1]->ID;
    Mycout<<"\tlui\t"<<reg<<", %hi("<<var
    <<")"<<endl;
    Mycout<<"\tlw\t"<<reg<<", %lo("<<var
    <<")("<<reg<<")"<<endl;
}
void gen_LADDRNR(Node* exp)
{
    int int_val = exp->Child[0]->int_val;
    string reg = exp->Child[1]->ID;
    Mycout<<"\taddi\t"<<reg<<", sp, "<<int_val
    <<"*4"<<endl;
}
void gen_LADDRVR(Node* exp)
{
    string var = exp->Child[0]->ID;
    string reg = exp->Child[1]->ID;
    Mycout<<"\tla\t"<<reg<<", "<<var<<endl;
}

void genexpressions(Node* exps)
{
    cout<<exps->Child.size()<<endl;
    for(int i = 0; i < exps->Child.size(); ++i)
    {
        if(exps->Child[i]->nodetype == NODE_RARBR)
            gen_RARBR(exps->Child[i]);
        if(exps->Child[i]->nodetype == NODE_RARBN)
            gen_RARBN(exps->Child[i]);
        if(exps->Child[i]->nodetype == NODE_RAOR)
            gen_RASR(exps->Child[i]);
        if(exps->Child[i]->nodetype == NODE_RAR)
            gen_RAR(exps->Child[i]);
        if(exps->Child[i]->nodetype == NODE_RAN)
            gen_RAN(exps->Child[i]);
        if(exps->Child[i]->nodetype == NODE_RLNRAR)
            gen_RLNRAR(exps->Child[i]);
        if(exps->Child[i]->nodetype == NODE_RARLNR)
            gen_RARLNR(exps->Child[i]);
        if(exps->Child[i]->nodetype == NODE_IRLRGL)
            gen_IRLRGL(exps->Child[i]);
        if(exps->Child[i]->nodetype == NODE_GL)
            gen_GL(exps->Child[i]);
        if(exps->Child[i]->nodetype == NODE_LC)
            gen_LC(exps->Child[i]);
        if(exps->Child[i]->nodetype == NODE_CF)
            gen_CF(exps->Child[i]);
        if(exps->Child[i]->nodetype == NODE_R)
            gen_R();
        if(exps->Child[i]->nodetype == NODE_SRN)
            gen_SRN(exps->Child[i]);
        if(exps->Child[i]->nodetype == NODE_LNR)
            gen_LNR(exps->Child[i]);
        if(exps->Child[i]->nodetype == NODE_LVR)
            gen_LVR(exps->Child[i]);
        if(exps->Child[i]->nodetype == NODE_LADDRNR)
            gen_LADDRNR(exps->Child[i]);
        if(exps->Child[i]->nodetype == NODE_LADDRVR)
            gen_LADDRVR(exps->Child[i]);
    }
}
void gen_code()
{
    for(int i = 0; i < root->Child.size(); ++i)
    {
        if(root->Child[i]->nodetype == NODE_GLOBAL_DECL_NUM)
            genglobalvar(root->Child[i]);
        if(root->Child[i]->nodetype == NODE_GLOBAL_DECL_ARR)
            genglobalarr(root->Child[i]);
    }
    for(int i = 0; i < root->Child.size(); ++i)
    {
        if(root->Child[i]->nodetype == NODE_FuncDef)
        {
            Node* func_header = root->Child[i]->Child[0];
            Node* exps = root->Child[i]->Child[1];
            Node* func_end = root->Child[i]->Child[2];
            genfuncheader(func_header);
            genexpressions(exps);
            genfuncend(func_end);
        }
    }
}