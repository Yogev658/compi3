#ifndef COMPI3_ELEMENT_H
#define COMPI3_ELEMENT_H

#define YYSTUPE Element*

#include <string>
#include <iostream>

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
    Type(TypeName name, bool is_var, bool is_func, vector<Type> args, Type returnArg);
};

class Element {
public:
    string str;
    Element();
    template <type T> T* to();
};

template <type T> T *Element::to() {
    T* e = dynamic_cast<T*>(this);
    if (e == nullptr) {
       cout << "Wasn't able to cast from *" << typeid(this).name() << "to *" << typeid(T).name() <<endl; #TODO Change!
    }
    return e;
}

struct



#endif //COMPI3_ELEMENT_H
