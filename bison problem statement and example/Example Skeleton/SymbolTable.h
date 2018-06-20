#ifndef SYMBOLTABLE1_H
#define SYMBOLTABLE1_H


#include <bits/stdc++.h>

#define ll long long
using namespace std;


class SymbolInfo
{
    string SymbolName, SymbolType;
public:
    ll i, j, tableId;
    SymbolInfo *next;

    SymbolInfo();

    SymbolInfo(string name, string type);

    void setSymbolName(string name);

    void setSymbolType(string type);

    void setAll(string name, string type);

    string getSymbolName();

    string getSymbolType();
};


class scopeTable
{
    SymbolInfo j;
public:
    ll flag ;
    SymbolInfo *Arr;
    scopeTable *parentScopeTable;
    ll id, N;

    scopeTable(ll n);

    ~scopeTable();

    ll hash(string varName);

    bool insert(string varName, string varType);

    bool Delete(string varName);

    SymbolInfo *lookUp(string varName);

    string printScopeTable();
};



class SymbolTable
{
public:
    ll N;
    scopeTable *currentScopeTable;

    SymbolTable(ll n);

    void enterScope();

    void exitScope();

    bool insert(string varName, string varType);

    bool remove(string varName);

    SymbolInfo *lookUp(string varName);

    void printCurrentScopeTable();

    string printAllScopeTable();
};


#endif // SYMBOLTABLE1_H
