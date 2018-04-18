//
// Created by Heisenberg on 14-Apr-18.
//

#include "SymbolTable_1505038.h"

symbolTable::symbolTable(ll n)
{
    N = n;
    scopeTable *tem;
    tem = new scopeTable(N);
    currentScopeTable = tem;
}


void symbolTable::enterScope()
{
    scopeTable *newScopeTable = new scopeTable(N);
    newScopeTable->id = currentScopeTable->id + 1;
    newScopeTable->parentScopeTable = currentScopeTable;
    currentScopeTable = newScopeTable;
    return;
}

void symbolTable::exitScope()
{
    scopeTable *parent;
    parent = currentScopeTable->parentScopeTable;

    free(currentScopeTable);
    currentScopeTable = parent;
    return;
}

bool symbolTable::insert(string varName, string varType)
{
    bool inserted = currentScopeTable->insert(varName, varType);
    return (inserted) ? true : false;
}

bool symbolTable::remove(string varName)
{
    bool deleted = currentScopeTable->Delete(varName);
    return (deleted) ? true : false;
}

symbolInfo *symbolTable::lookUp(string varName)
{
    scopeTable *tem;
    tem = currentScopeTable;

    while (tem != 0)
    {
        symbolInfo *found = tem->lookUp(varName);
        if (found != 0)
        {
            return found;
        }
        tem = tem->parentScopeTable;
    }
    return 0;
}

void symbolTable::printCurrentScopeTable()
{
    cout << "ScopeTable # " << currentScopeTable->id << endl;
    currentScopeTable->printScopeTable();
    return;
}

void symbolTable::printAllScopeTable()
{
    scopeTable *tem;
    tem = currentScopeTable;

    while (tem != 0)
    {
        cout << "ScopeTable # " << tem->id << endl;
        tem->printScopeTable();
        tem = tem->parentScopeTable;
    }
    return;
}
