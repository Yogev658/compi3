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
#include "Element.h"

using namespace std;

struct Scope{
    vector<Identifier*>* _elements;
    int _offset;

    Scope(const int offset);
    Scope(vector<Identifier*>* args);
    ~Scope();

    void insert(Identifier* id);
    Identifier* find(string idName);
    int size();
};

class SymbolTable {
    stack<Scope> _scopeStack;
    Scope * _currFunc;

public:
    SymbolTable(): _scopeStack(), _currFunc(nullptr){}
    ~SymbolTable(){}


    void pushScope();
    void popScope();
    void insert();
    Identifier* find();
    // void removeScope();

    void pushFunctionScope(FormalsList* argsList);
    void popFunctionScope();
};


#endif //COMPI3_SYMBOLTABLE_H
