#pragma once

#include <string>
#include <vector>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

#define YYSTYPE Element*

enum TypeName {TYPE_VOID, TYPE_INT, TYPE_BOOL, TYPE_STRING, TYPE_BYTE};

struct Element {
public:
    TypeName typeName;
    // bool is_auto;  //TODO needed?
    Element();
    Element(TypeName name);
    template <typename T> T* to();
};



struct Identifier: public  Element {
    string name;
    TypeName type;
    int offset;
    Identifier(string name, TypeName type, int offset);
};

struct FuncDecl: public Element {
    vector<TypeName> args;
    TypeName returnArg;
    FuncDecl(vector<TypeName> args, TypeName returnArg);
};

struct RetType: public Element {
    TypeName type;
    RetType(TypeName type);
};

struct FormalsList: public Element {
    vector<pair<TypeName, string>> args;
    FormalsList(vector<pair<TypeName, string>> args);
    void addToFormalList(pair<TypeName, string>& arg);
};

struct Statement: public Element {
    bool _return;
    bool _continue;
    bool _break;
    TypeName _returnArg;
    Statement(TypeName returnArg, bool ret=false, bool cont =false, bool brk=false);
};

struct Call: public Element {
    TypeName type;
    Call(TypeName type);
};

struct Exp: public  Element {
    TypeName type;
    Exp(TypeName type);
};


struct ExpList: public Element { //TODO
    vector<Exp*> expList;
    ExpList(vector<Exp*> expList);
    void addExpToExpList(Exp* exp);
};

struct Type: public Element {
    TypeName type;
    Type(TypeName type);
};

template <typename T> // TODO
T* Element::to() {
    T* e = dynamic_cast<T*>(this);
    if (e == nullptr) {
       cout << "Wasn't able to cast from *" << typeid(this).name() << "to *" << typeid(T).name() <<endl; // TODO: change!!!!
    }
    return e;
}