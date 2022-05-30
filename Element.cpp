#include "Element.h"

Element::Element() {

}
Element::Element(TypeName name, bool is_auto): typeName(name), is_auto(is_auto) {

}

Identifier::Identifier(string name, Element *type, int offset): Element(name, false), name(name), type(type), offset(offset) {

}

FuncDecl::FuncDecl(vector<TypeName> _args, TypeName returnArg): args(), returnArg(returnArg) {
    copy(_args.begin(), _args.end(), back_inserter(args));
}

RetType::RetType(TypeName type): type(type) {

}

FormalsList::FormalsList(vector<pair<TypeName, string>> args): args(args) {

}

void FormalsList::addToFormalList(pair<TypeName, string> &arg) {
    args.push_back(arg)
}

Statement::Statement(TypeName returnArg, bool _return=false, bool _continue=false, bool _break=false ): _return(_return),
    _continue(_continue), _break(_break), returnArg(returnArg) {

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
