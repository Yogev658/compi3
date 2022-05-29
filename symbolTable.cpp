//
// Created by yogge on 24/05/2022.
//

#include "symbolTable.h"

Scope::Scope(int offset) : _offset(offset), _elements(new vector<Identifier*>()) {}

Scope::~Scope(){
    // TODO: delete elements inside vector (maybe);
    delete _elements;
}

void Scope::insert(Identifier* id){
    _elements->push_back(id);
    _offset++;
}

Identifier* Scope::find(string idName){
    for (int i = 0; i < _elements->size(); i++){
        // TODO: use identifier's structure to find its name;
        // if (_elements[i].name == idName){
        //     return &_elements[i];
        // }
    }
    return nullptr;
}



void SymbolTable::popScope(){
    _scopeStack->pop();
}

void pushFunctionScope(){}
void popFunctionScope(){}

