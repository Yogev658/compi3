#pragma once

#include <string>
#include <vector>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

#define YYSTYPE Element*

enum TypeName {TYPE_VOID, TYPE_INT, TYPE_BOOL, TYPE_STRING, TYPE_BYTE};

class Element {
public:
    TypeName typeName;
    // bool is_auto;  //TODO needed?
    Element();
    virtual ~Element() = default;
    Element(TypeName name);
    template <typename T> T* to();
};


class Identifier: public  Element {
public:
    string name;
    TypeName type;
    int offset;
    Identifier(string name, TypeName type, int offset);
};

class FuncDecl: public Element {
public:
    vector<TypeName> args;
    TypeName returnArg;
    FuncDecl(vector<TypeName> args, TypeName returnArg);
};

class RetType: public Element {
public:
    TypeName type;
    RetType(TypeName type);
};

class FormalsList: public Element {
public:
    vector<pair<TypeName, string>> args;
    FormalsList(vector<pair<TypeName, string>> args);
    void addToFormalList(pair<TypeName, string>& arg);
};

class Statement: public Element {
public:
    bool _return;
    bool _continue;
    bool _break;
    TypeName _returnArg;
    Statement(TypeName returnArg, bool ret=false, bool cont =false, bool brk=false);
};

class Call: public Element {
public:
    TypeName type;
    Call(TypeName type);
};

class Exp: public  Element {
public:
    TypeName type;
    Exp(TypeName type);
};

class ExpList: public Element { //TODO
public:
    vector<Exp*> expList;
    ExpList(vector<Exp*> expList);
    void addExpToExpList(Exp* exp);
};

class Type: public Element {
public:
    TypeName type;
    Type(TypeName type);
};

template<typename T>
T *Element::to() {
    T* res = dynamic_cast<T*>(this);
    if(res == nullptr){
        cout << "bad cast" << endl; 
        throw std::bad_cast();
    }
    return res;
}