//
// Created by yogge on 24/05/2022.
//

#include "symbolTable.h"

Scope::Scope(const int offset) : _offset(offset), _elements(new vector<Identifier*>()) {}

Scope::Scope(vector<Identifier*>* args){
    _elements = args;
}

Scope::~Scope(){
    // TODO: delete elements inside vector (maybe);
    for (int i = 0; i < _elements->size(); i++){
        delete (*_elements)[i];
    }
    delete _elements;
}

void Scope::insert(Identifier* id){
    _elements->push_back(id);
    _offset++;
}

Identifier* Scope::find(string idName){ // TODO: disable shadowing
    for (int i = 0; i < _elements->size(); i++){
        // TODO: use identifier's structure to find its name;
        if ((*_elements)[i]->name == idName){
            return (*_elements)[i];
        }
    }
    return nullptr;
}

int Scope::size(){
    return _elements->size();
}

void SymbolTable::pushScope(){
    assert(_scopeStack.size() != 0);
    const int offset = _scopeStack.top()._offset + _scopeStack.top().size();
    Scope s = Scope(offset);
    _scopeStack.push(s);
}

void SymbolTable::popScope(){
    _scopeStack.pop();
}

void SymbolTable::pushFunctionScope(FormalsList* argsList){
    assert(_scopeStack.size() == 0);
    int offset = -1;
    vector<Identifier*>* args = new vector<Identifier*>();
    for (int i = 0; i < argsList->args->size(); i++){
        pair<TypeName, string> currPair =  (*(argsList->args))[i];
        TypeName currType = currPair.first;
        string currName = currPair.second;
        args->push_back(new Identifier(currName, currType, offset));
        offset--;
    }
    Scope s = Scope(args); // TODO: add this constructor
    _scopeStack.push(s);
}


void SymbolTable::popFunctionScope(){
    assert(_scopeStack.size() == 1);
    popScope();
}

