#include "asserts.h"
#include "Element.h"

bool assertBothNumeric(Element* e1, Element* e2) {
    return (e1->typeName == TypeName::TYPE_INT || e1->typeName == TypeName::TYPE_BYTE) && (e2->typeName == TypeName::TYPE_INT || e2->typeName == TypeName::TYPE_BYTE);
}

bool assertValidRelop(Element* e1, Element* e2, Element* retType) {
    return assertBothNumeric(e1, e2) && (retType->typeName == TypeName::TYPE_BOOL);
}

bool assertValidBoolean(Element* e1, Element* e2, Element* retType) {
    return (e1->typeName == TypeName::TYPE_BOOL) && (e2->typeName == TypeName::TYPE_BOOL) && (retType->typeName == TypeName::TYPE_BOOL);
}

bool assertValidBinop(Element* e1, Element* e2, Element* retType) {
    bool assertRetTypeRange = false;
    if (e1->typeName == TypeName::TYPE_INT && e2->typeName == TypeName::TYPE_INT) {
       if (retType->typeName == TypeName::TYPE_INT) { assertRetTypeRange = true; }
    }

    if ((e1->typeName == TypeName::TYPE_INT && e2->typeName == TypeName::TYPE_BYTE) || (e1->typeName == TypeName::TYPE_BYTE && e2->typeName == TypeName::TYPE_INT)) {
            if (retType->typeName == TypeName::TYPE_INT) { assertRetTypeRange = true; }
    }

    if (e1->typeName == TypeName::TYPE_BYTE && e2->typeName == TypeName::TYPE_BYTE) {
        if (retType->typeName == TypeName::TYPE_BYTE) { assertRetTypeRange = true; }
    }

    return assertBothNumeric(e1, e2) && assertRetTypeRange;
}

bool assertTypesMatch(TypeName t1, TypeName t2) {
    return t1 == t2;
}

bool assertCastingIsLegal(Element* src, Element* dest) { //TODO: add for rule 8
    if (src->typeName == dest->typeName) {
        return true;
    }

    if ((src->typeName == TypeName::TYPE_BYTE) && (dest->typeName == TypeName::TYPE_INT)) {
        return true;
    }
}

bool assertReturnTypeForPrint(TypeName t1, TypeName retType) {
    return t1 == TypeName::TYPE_STRING && retType == TypeName::TYPE_VOID;
}

bool assertReturnTypeForPrint_i(TypeName t1, TypeName retType) {
    return (t1 == TypeName::TYPE_INT || t1 == TypeName::TYPE_BYTE) && retType == TypeName::TYPE_VOID;
}

bool assertReturnType(TypeName expected, TypeName given) {
    return expected == given;
}

//TODO: rules with stack
bool assertVariableNotDefined();
bool assertVariableDefined();
bool assertInWhile();



