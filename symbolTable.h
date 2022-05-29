//
// Created by yoggev on 24/05/2022.
//

#ifndef COMPI3_SYMBOLTABLE_H
#define COMPI3_SYMBOLTABLE_H

#include <stack>
#include <vector>

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

};

class symbolTable {
    stack<Scope&> _scopesStack;

public:
    SymbolTable(): _scopeStack(){}
    ~SymbolTable(){}

void SymbolTable::pushScope(){
    assert(_scopeStack.size() != 0);
    int offset = _scopesStack->top()->offset + _scopesStack->top()->size();
    this->_scopeStack(Scope(offset));
}
    void addScope();

    void insert();
    Identifier* find();
    void removeScope();

    void addFunctionScope();
    void removeFunctionScope();





};


#endif //COMPI3_SYMBOLTABLE_H
