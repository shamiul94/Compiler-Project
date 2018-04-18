//
// Created by Heisenberg on 14-Apr-18.
//

#ifndef INC_1505038_COMPILER_1_SYMBOLINFO_1505038_H
#define INC_1505038_COMPILER_1_SYMBOLINFO_1505038_H


#include <bits/stdc++.h>

#define ll long long
using namespace std;

class symbolInfo
{
    string symbolName, symbolType;
public:
    ll i, j, tableId;
    symbolInfo *next;

    symbolInfo();

    symbolInfo(string name, string type);

    void setSymbolName(string name);

    void setSymbolType(string type);

    void setAll(string name, string type);

    string getSymbolName();

    string getSymbolType();
};

#endif //INC_1505038_COMPILER_1_SYMBOLINFO_1505038_H
