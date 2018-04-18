//
// Created by Heisenberg on 14-Apr-18.
//

#include "SymbolInfo_1505038.h"


#include <bits/stdc++.h>

#define ll long long
using namespace std;


symbolInfo::symbolInfo()
{
    symbolName = "";
    symbolType = "";
    next = 0;
}

symbolInfo::symbolInfo(string name, string type)
{
    symbolName = name;
    symbolType = type;
    next = 0;
}

void symbolInfo::setSymbolName(string name)
{
    symbolName = name;
}

void symbolInfo::setSymbolType(string type)
{
    symbolType = type;
}

void symbolInfo::setAll(string name, string type)
{
    symbolName = name;
    symbolType = type;
}

string symbolInfo::getSymbolName()
{
    return symbolName;
}

string symbolInfo::getSymbolType()
{
    return symbolType;
}
