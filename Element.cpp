#include "Element.h"

Element::Element() {

}
Element::Element(TypeName type): typeName(type) {

}

Identifier::Identifier(string name, TypeName type, int offset): Element(type), name(name), type(type), offset(offset) {

}

FuncDecl::FuncDecl(vector<TypeName> _args, TypeName returnArg): args(), returnArg(returnArg) {
    copy(_args.begin(), _args.end(), back_inserter(args));
}

RetType::RetType(TypeName type): type(type) {}

FormalsList::FormalsList(vector<pair<TypeName, string>> args): args(args) {

}

void FormalsList::addToFormalList(pair<TypeName, string> &arg) {
    args.push_back(arg);
}

Statement::Statement(TypeName returnArg, bool ret, bool cont, bool brk): _return(ret),
    _continue(cont), _break(brk), _returnArg(returnArg) {

}

Call::Call(TypeName type): type(type) {

}

ExpList::ExpList(vector<Exp*> expList): expList(){

}

void ExpList::addExpToExpList(Exp* exp) {
    expList.push_back(exp);
}

Type::Type(TypeName type): type(type) {

}

Exp::Exp(TypeName type): type(type) {

}
