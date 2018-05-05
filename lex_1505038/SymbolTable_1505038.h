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


class scopeTable
{
    symbolInfo j;
public:
    ll flag ;
    symbolInfo *Arr;
    scopeTable *parentScopeTable;
    ll id, N;

    scopeTable(ll n);

    ~scopeTable();

    ll hash(string varName);

    bool insert(string varName, string varType);

    bool Delete(string varName);

    symbolInfo *lookUp(string varName);

    string printScopeTable();
};



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

    string printAllScopeTable();
};



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





scopeTable::scopeTable(ll n)
{
    Arr = new symbolInfo[n];
    parentScopeTable = 0;
    N = n;
    id = 1;
    flag = 0 ;
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
    flag = 1 ;

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

string scopeTable::printScopeTable()
{
    string s = "";

    for (ll i = 0; i < N; i++)
    {
        s = s + (char)(i - '0');
        s = s +" --> ";
        //cout << i << " --> ";

        symbolInfo *curr = &Arr[i];
        while (curr != 0)
        {
            curr = curr->next;

            if (curr != 0)
            {
                s = s + "< ";
                s = s + curr->getSymbolName() ;
                s = s + ':' ;
                s = s + curr->getSymbolType() ;
                s = s + " >" ;
                //cout << "< " << curr->getSymbolName() << ':' << curr->getSymbolType() << " >";
            }
            if (curr != 0 && curr->next != 0)
            {
                s = s + " , " ;
                cout << " , ";
            }
        }
        s = s + '\n' ;
        //cout << endl;
    }
    return s;
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

string symbolTable::printAllScopeTable()
{
    string s ;
    scopeTable *tem;
    tem = currentScopeTable;

    while (tem != 0)
    {
        if(tem->flag == 1)
        {
            s = s + "ScopeTable # " ;
            s = s + (char)(tem->id - '0');
            //cout << "ScopeTable # " << tem->id << endl;
            s = s + tem->printScopeTable();
            s = s + '\n' ;
            tem = tem->parentScopeTable;
        }
    }
    return s ;
}

