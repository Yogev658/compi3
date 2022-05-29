#pragma once

#include <string>
#include <vector>
#include <string>
#include <stack>

using namespace std;

#define YYSTUPE Element*


enum class TypeName {VOID, INT, BOOL, STRING, BYTE};

class Element {
public:
    TypeName typeName;
    bool is_func;
    bool is_auto;  //TODO needed?
    vector<TypeName> args;
    TypeName returnArg;
    Element(TypeName name, bool is_func, bool is_auto, vector<Element> *args, Element returnArg);
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
    string IdName;
    Element* type;
    int offset;
    Identifier(string IdName, Element* type, int offset);
};

struct FuncDecl: public Element {
    Element element;
    FuncDecl(Element element);
};

struct FormalsList: public Element {  #TODO
    Element element;
    FormalsList(Element element);
};

struct FormalDecl: public Element {
    Element element;
    FormalDecl(Element element);
};

struct Statements: public Element { #TODO
    Element element;
    Statements(Element element);
};

struct Statement: public Element {
    Element element;
    Statement(Element element);
};

struct Call: public Element { #TODO
    Element element;
    Call(Element element);
};

struct ExpList: public Element { #TODO
    vector<Exp*> expList;
    ExpList();
    void addExp(Exp* exp);

};

struct Type: public Element {
    Element element;
    TypeElement(Element element);
};

struct Exp: public  Element {
    Element element;
    Exp(Element element);
};

%%
