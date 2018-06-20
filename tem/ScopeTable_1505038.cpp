//
// Created by Heisenberg on 14-Apr-18.
//

#include "ScopeTable_1505038.h"
#include "SymbolInfo_1505038.h"

#include <bits/stdc++.h>

#define ll long long
using namespace std;


scopeTable::scopeTable(ll n)
{
    Arr = new symbolInfo[n];
    parentScopeTable = 0;
    N = n;
    id = 1;
}


bool scopeTable::insert(string varName, string varType)
{
    symbolInfo tem(varName, varType);
    ll positionInArray = hash(varName);

    symbolInfo *head;
    head = &Arr[positionInArray];

    symbolInfo *curr;
    curr = head;

    ll num = 0;
    while (curr->next != 0)
    {
        curr = curr->next;
        num++;

        if (curr != 0)
        {
            if (curr->getSymbolName() == varName)
            {
                return false;
            }
        }
    }

    symbolInfo *NewVar;
    NewVar = new symbolInfo();
    NewVar->setAll(varName, varType);
    NewVar->i = positionInArray;
    NewVar->j = num;
    NewVar->tableId = id;

    curr->next = NewVar;

    return true;
}


symbolInfo *scopeTable::lookUp(string varName)
{
    ll positionInArray = hash(varName);
    symbolInfo *curr = &Arr[positionInArray];


    while (curr->next != 0)
    {
        curr = curr->next;

        if (curr != 0)
        {
            if (curr->getSymbolName() == varName)
            {
                return curr;
            }
        }
    }
    return 0;
}

bool scopeTable::Delete(string varName)
{
    ll positionInArray = hash(varName);
    symbolInfo *curr = &Arr[positionInArray];
    symbolInfo *prev = 0;

    while (curr->next != 0)
    {
        prev = curr;
        curr = curr->next;

        if (curr != 0)
        {
            if (curr->getSymbolName() == varName)
            {
                prev->next = curr->next;
                free(curr);
                return true;
            }
        }
    }
    return false;
}

void scopeTable::printScopeTable()
{
    for (ll i = 0; i < N; i++)
    {
        cout << i << " --> ";

        symbolInfo *curr = &Arr[i];
        while (curr != 0)
        {
            curr = curr->next;

            if (curr != 0)
            {
                cout << "< " << curr->getSymbolName() << ':' << curr->getSymbolType() << " >";
            }
            if (curr != 0 && curr->next != 0)
            {
                cout << " , ";
            }
        }
        cout << endl;
    }
    return;
}

ll scopeTable::hash(string name)
{


    ll mod = N;
    ll c = 16777619;
    ll tem, ret = 0;

    for (ll i = 0; i < name.size(); i++)
    {
        tem = c ^ (ll) name[i];
        tem *= 193;
        tem = c ^ (ll) name[i];
        tem = tem % mod;
        ret = (ret % mod + tem % mod) % mod;
    }
    return ret;
}

scopeTable::~scopeTable()
{
    free(Arr);
    free(parentScopeTable);
}
