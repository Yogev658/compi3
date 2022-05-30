#include "Element.h"

Element::Element() {

}
Element::Element(TypeName name, bool is_auto): name(name), is_auto(is_auto) {

}

Identifier::Identifier(int name, Element *type, int offset): name(name), *type(type), offset(offset) {

}

FuncDecl::FuncDecl(vector<TypeName> _args, TypeName returnArg): args(), returnArg(returnArg) {
    copy(_args.begin(), _args.end(), back_inserter(args));
}

RetType::RetType(TypeName type): type(type) {

}

FormalsList::FormalsList(vector<pair<TypeName, name>> args): args(args) {

}

FormalsList::addToFormalList(pair<TypeName, name>> &arg) {
    args.push_back(arg)
}

Statement::Statement(bool _return=false, bool _continue=false, bool _break=false, TypeName returnArg): _return(_return),
    _continue(_continue), _break(_break), returnArg(returnArg) {

}

Call::Call(TypeName type): type(type) {

}

ExpList::ExpList(vector<Exp*> expList): expList(){

}

ExpList::addExpToExpList(Exp* exp) {
    expList.push_back(exp);
}

Type::Type(TypeName type): type(type) {

}

Exp::Exp(TypeName type): type(type) {

}
