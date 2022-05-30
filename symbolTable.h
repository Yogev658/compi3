//
// Created by yoggev on 24/05/2022.
//

#ifndef COMPI3_SYMBOLTABLE_H
#define COMPI3_SYMBOLTABLE_H

#include <stack>
#include <vector>
#include <iostream>
#include <assert.h>

#include "hw3_output.hpp"

using namespace std;
class Identifier;

struct Scope{
    vector<Identifier*>* _elements;
    int _offset;

    Scope(int offset);
    ~Scope();

    void insert(Identifier* id);
    Identifier* find(string idName);
    int size();

};

class SymbolTable {
    stack<Scope&> _scopeStack;

public:
    SymbolTable(): _scopeStack(){}
    ~SymbolTable(){}


    void pushScope();
    void popScope();
    void insert();
    Identifier* find();
    void removeScope();

    void addFunctionScope();
    void removeFunctionScope();
};


#endif //COMPI3_SYMBOLTABLE_H
