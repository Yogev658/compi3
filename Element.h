#include <string>
#include <iostream>

#define YYSTUPE Element*

using std::string;
using std::cout;
using std::endl;

enum TypeName {VOID, INT, BOOL, STRING, BYTE};

class Element {
public:
    TypeName typeName;
    bool is_func;
    bool is_auto;  #TODO needed?
    vector<Element> *args;
    Element returnArg;
    Element(TypeName name, bool is_func, bool is_auto, vector<Element> *args, Element returnArg);
    template <Element T> T* to();
};

template <Element T> T *Element::to() {
    T* e = dynamic_cast<T*>(this);
    if (e == nullptr) {
       cout << "Wasn't able to cast from *" << typeid(this).name() << "to *" << typeid(T).name() <<endl; #TODO Change!
    }
    return e;
};

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
    Type type;
    FormalsList(Type type);
};

struct FormalDecl: public Element {
    Type type;
    FormalDecl(Type type);
};

struct Statements: public Element { #TODO
    Type type;
    Statements(Type type);
};

struct Statement: public Element {
    Type type;
    Statement(Type type);
};

struct Call: public Element { #TODO
    Type type;
    Call(Type type);
};

struct ExpList: public Element { #TODO
    vector<Exp*> expList;
    ExpList();
    void addExp(Exp* exp);

};

struct TypeElement: public Element {
    Type type;
    TypeElement(Type type);
};

struct Exp: public  Element {
    Type type;
    Exp(Type type);
};

%%
