#include <string>
#include <iostream>

#define YYSTUPE Element*

using std::string;
using std::cout;
using std::endl;


enum TypeName {VOID, INT, BOOL, STRING, BYTE};

class Type {
public:
    TypeName name;
    bool is_func;
    bool is_auto;  #TODO needed?
    vector<Type> *args;
    Type returnArg;
    Type(TypeName name, bool is_var, bool is_func, vector<Type> *args, Type returnArg);
};

class Element {
public:
    string name;
    Element();
    template <type T> T* to();
};

template <type T> T *Element::to() {
    T* e = dynamic_cast<T*>(this);
    if (e == nullptr) {
       cout << "Wasn't able to cast from *" << typeid(this).name() << "to *" << typeid(T).name() <<endl; #TODO Change!
    }
    return e;
};

struct Identifier: public  Element {
    string name;
    int offset;
    Type* type;
    Identifier(string name, int offset, Type* type);
};

struct Funcs: public Element {
    Type type;
    Funcs(Type type);
};

struct FuncDecl: public Element {
    Type type;
    FuncDecl(Type type);   #TODO how to pass that is_func == 1???
};

struct RetType: public Element {
    Type type;
    RetType(Type type);
};

struct Formals: public Element {
    Type type;
    Formals(Type type);
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
