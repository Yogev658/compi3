#include "Element.h"
#include "hw3_output.hpp"
#include "symbolTable.h"

bool assertBothNumeric(Element* e1, Element* e2);
bool assertValidRelop(Element* e1, Element* e2, Element* retType);
bool assertValidBoolean(Element* e1, Element* e2, Element* retType);
bool assertValidBinop(Element* e1, Element* e2, Element* retType);
bool assertTypesMatch(TypeName t1, TypeName t2);
bool assertCastingIsLegal(Element* src, Element* dest);
bool assertReturnTypeForPrint(TypeName t1, TypeName retType);
bool assertReturnTypeForPrint_i(TypeName t1, TypeName retType);
bool assertReturnType(TypeName expected, TypeName given);

//TODO: rules with stack
bool assertVariableNotDefined(Element* e);
bool assertVariableDefined(Element* e);
bool assertInWhile();
bool assertAssigmentToID(Element* id, Element* exp);

