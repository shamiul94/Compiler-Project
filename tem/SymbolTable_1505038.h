//
// Created by Heisenberg on 14-Apr-18.
//

#ifndef INC_1505038_COMPILER_1_SYMBOLTABLE_1505038_H
#define INC_1505038_COMPILER_1_SYMBOLTABLE_1505038_H


#include "ScopeTable_1505038.h"
#include "SymbolInfo_1505038.h"


class symbolTable
{
public:
    ll N;
    scopeTable *currentScopeTable;

    symbolTable(ll n);

    void enterScope();

    void exitScope();

    bool insert(string varName, string varType);

    bool remove(string varName);

    symbolInfo *lookUp(string varName);

    void printCurrentScopeTable();

    void printAllScopeTable();
};


#endif //INC_1505038_COMPILER_1_SYMBOLTABLE_1505038_H
