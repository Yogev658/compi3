#pragma once

#include <string>
#include <vector>
#include <string>
#include <stack>

using namespace std;

#define YYSTYPE Element*

enum class TypeName {VOID, INT, BOOL, STRING, BYTE};

class Element {
public:
    TypeName typeName;
    bool is_auto;  //TODO needed?
    Element(TypeName name, bool is_func, bool is_auto, vector<Element> args, TypeName returnArg);
    // template <Element T> T* to();
};

// template <Element T>
//  T *Element::to() {
//     T* e = dynamic_cast<T*>(this);
//     if (e == nullptr) {
//        cout << "Wasn't able to cast from *" << typeid(this).name() << "to *" << typeid(T).name() <<endl; #TODO Change!
//     }
//     return e;
// };

struct Identifier: public  Element {
    string name;
    Element* type;
    int offset;
    Identifier(string name, Element* type, int offset);
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
    vector<pair<TypeName, name>> args;
    FormalsList(vector<pair<TypeName, name>> args);
    void addToFormalList(vector<pair<TypeName, name>> &args)
    explicit void addToFormalList(<pair<TypeName, name>> arg)
};

struct Statement: public Element {
    bool _return;
    bool _continue;
    bool _break;
    TypeName returnArg;
    Statement(bool _return=false, bool _continue=false, bool _break=false, TypeName returnArg);
};

struct Call: public Element {
    TypeName type;
    Call(TypeName type);
};

struct ExpList: public Element { #TODO
    vector<Exp*> expList;
    ExpList(vector<Exp*> expList);
    void addExpToExpList(Exp* exp);
};

struct Type: public Element {
    TypeName type;
    Type(TypeName type);
};

struct Exp: public  Element {
    TypeName type;
    Exp(TypeName type);
};
