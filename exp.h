//
// Created by Jazmin on 6/11/2024.
//

#ifndef COMPILADORES_EXP_H
#define COMPILADORES_EXP_H

#include <string>
#include <unordered_map>
#include <list>
#include "visitor.h"

using namespace std;
enum BinaryOp { PLUS_OP, MINUS_OP, MUL_OP, DIV_OP,LT_OP, LE_OP, EQ_OP };
enum UnaryOp {PLUSPLUS_OP};

class Body;

class Exp {
public:
    virtual int  accept(Visitor* visitor) = 0;
    virtual ~Exp() = 0;
    static string binopToChar(BinaryOp op);
    static string unaryopToChar(UnaryOp op);
};
class IFExp : public Exp {
public:
    Exp *left, *right;
    Exp* cond;

    IFExp(Exp cond, Exp l, Exp* r);
    int accept(Visitor* visitor);
    ~IFExp();
};

class UnaryExp : public Exp{
public:
    Exp *unary;
    UnaryOp op;
    UnaryExp(Exp *u, UnaryOp op);
    int accept(Visitor* visitor);
    ~UnaryExp();
};


class BinaryExp : public Exp {
public:
    Exp *left, *right;
    BinaryOp op;
    BinaryExp(Exp* l, Exp* r, BinaryOp op);
    int accept(Visitor* visitor);
    ~BinaryExp();
};

class NumberExp : public Exp {
public:
    int value;
    NumberExp(int v);
    int accept(Visitor* visitor);
    ~NumberExp();
};

class BoolExp : public Exp {
public:
    int value;
    BoolExp(bool v);
    int accept(Visitor* visitor);
    ~BoolExp();
};

class IdentifierExp : public Exp {
public:
    std::string name;
    IdentifierExp(const std::string& n);
    int accept(Visitor* visitor);
    ~IdentifierExp();
};

class FCallExp : public Exp {
public:
    string name;
    list<Exp*> args;
    FCallExp(string& name, list<Exp*> args);
    int accept(Visitor* visitor);
    ~FCallExp();
};

class Stm {
public:
    virtual int accept(Visitor* visitor) = 0;
    virtual ~Stm() = 0;
};

class AssignStatement : public Stm {
public:
    std::string id;
    Exp* rhs;
    AssignStatement(std::string id, Exp* e);
    int accept(Visitor* visitor);
    ~AssignStatement();
};

//Modificar
class PrintStatement : public Stm {
public:
    Exp* e;
    PrintStatement(Exp* e);
    int accept(Visitor* visitor);
    ~PrintStatement();
};


class IfStatement : public Stm {
public:
    Exp* condition;
    Body* then;
    Body* els;
    IfStatement(Exp* condition, Body* then, Body* els);
    int accept(Visitor* visitor);
    ~IfStatement();
};
class WhileStatement : public Stm {
public:
    Exp* condition;
    Body* b;
    WhileStatement(Exp* condition, Body* b);
    int accept(Visitor* visitor);
    ~WhileStatement();
};

class ForStatement : public Stm {
public:
    Exp* start;
    Exp* end;
    Exp* step;
    Body* b;
    ForStatement(Exp* start, Exp* end, Exp* step, Body* b);
    int accept(Visitor* visitor);
    ~ForStatement();
};

class VarDec {
public:
    string type;
    list<string> vars;
    VarDec(string type, list<string> vars);
    int accept(Visitor* visitor);
    ~VarDec();
};

class VarDecList{
public:
    list<VarDec*> vardecs;
    VarDecList();
    void add(VarDec* vardec);
    int accept(Visitor* visitor);
    ~VarDecList();
};

class StatementList {
public:
    list<Stm*> stms;
    StatementList();
    void add(Stm* stm);
    int accept(Visitor* visitor);
    ~StatementList();
};


class Body{
public:
    VarDecList* vardecs;
    StatementList* slist;
    Body(VarDecList* vardecs, StatementList* stms);
    int accept(Visitor* visitor);
    ~Body();
};

class FunDec {
public:
    string type;
    string name;
    list<pair<string,string>> params;
    Body* body;
    FunDec(string type, string name, list<pair<string,string>> params, Body* body);
    int accept(Visitor* visitor);
    ~FunDec();
};

class FunDecList {
public:
    list<FunDec*> fundecs;
    FunDecList();
    void add(FunDec* fundec);
    int accept(Visitor* visitor);
    ~FunDecList();
};

class LibraDec{
public:
    string nameLibrary;
    string extension;
    LibraDec(string name, string extension): nameLibrary(name), extension(extension){}
    int accept(Visitor* visitor);
    ~LibraDec();
};

class LibraDecList{
public:
    list<LibraDec*> librarys;
    LibraDecList();
    void add(LibraDec* libradec);
    int accept(Visitor* visitor);
    ~LibraDecList();
};



class ReturnStatement : public Stm {
public:
    Exp* returnExp;
    ReturnStatement(Exp* returnExp);
    int accept(Visitor* visitor);
    ~ReturnStatement();
};

class Program {
public:
    LibraDecList* libradecs;
    VarDecList* vardecs;
    FunDecList* fundecs;
    Program(LibraDecList* libradecs , VarDecList* vardecs, FunDecList* fundecs);
    int accept(Visitor* visitor);
    ~Program();
};




#endif //COMPILADORES_EXP_H