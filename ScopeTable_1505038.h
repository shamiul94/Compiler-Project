//
// Created by Heisenberg on 14-Apr-18.
//

#ifndef INC_1505038_COMPILER_1_SCOPETABLE_1505038_H
#define INC_1505038_COMPILER_1_SCOPETABLE_1505038_H


#include "SymbolInfo_1505038.h"


class scopeTable
{
    symbolInfo j;
public:
    symbolInfo *Arr;
    scopeTable *parentScopeTable;
    ll id, N;

    scopeTable(ll n);

    ~scopeTable();

    ll hash(string varName);

    bool insert(string varName, string varType);

    bool Delete(string varName);

    symbolInfo *lookUp(string varName);

    void printScopeTable();
};


#endif //INC_1505038_COMPILER_1_SCOPETABLE_1505038_H
