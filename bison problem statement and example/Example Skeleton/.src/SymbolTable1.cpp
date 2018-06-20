#include "SymbolTable1.h"


SymbolInfo::SymbolInfo()
{
    SymbolName = "";
    SymbolType = "";
    next = 0;
}

SymbolInfo::SymbolInfo(string name, string type)
{
    SymbolName = name;
    SymbolType = type;
    next = 0;
}

void SymbolInfo::setSymbolName(string name)
{
    SymbolName = name;
}

void SymbolInfo::setSymbolType(string type)
{
    SymbolType = type;
}

void SymbolInfo::setAll(string name, string type)
{
    SymbolName = name;
    SymbolType = type;
}

string SymbolInfo::getSymbolName()
{
    return SymbolName;
}

string SymbolInfo::getSymbolType()
{
    return SymbolType;
}





scopeTable::scopeTable(ll n)
{
    Arr = new SymbolInfo[n];
    parentScopeTable = 0;
    N = n;
    id = 1;
    flag = 0 ;
}


bool scopeTable::insert(string varName, string varType)
{
    SymbolInfo tem(varName, varType);
    ll positionInArray = hash(varName);

    SymbolInfo *head;
    head = &Arr[positionInArray];

    SymbolInfo *curr;
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

    SymbolInfo *NewVar;
    NewVar = new SymbolInfo();
    NewVar->setAll(varName, varType);
    NewVar->i = positionInArray;
    NewVar->j = num;
    NewVar->tableId = id;

    curr->next = NewVar;
    flag = 1 ;

    return true;
}


SymbolInfo *scopeTable::lookUp(string varName)
{
    ll positionInArray = hash(varName);
    SymbolInfo *curr = &Arr[positionInArray];


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
    SymbolInfo *curr = &Arr[positionInArray];
    SymbolInfo *prev = 0;

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

        SymbolInfo *curr = &Arr[i];
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




SymbolTable::SymbolTable(ll n)
{
    N = n;
    scopeTable *tem;
    tem = new scopeTable(N);
    currentScopeTable = tem;
}


void SymbolTable::enterScope()
{
    scopeTable *newScopeTable = new scopeTable(N);
    newScopeTable->id = currentScopeTable->id + 1;
    newScopeTable->parentScopeTable = currentScopeTable;
    currentScopeTable = newScopeTable;
    return;
}

void SymbolTable::exitScope()
{
    scopeTable *parent;
    parent = currentScopeTable->parentScopeTable;

    free(currentScopeTable);
    currentScopeTable = parent;
    return;
}

bool SymbolTable::insert(string varName, string varType)
{
    bool inserted = currentScopeTable->insert(varName, varType);
    return (inserted) ? true : false;
}

bool SymbolTable::remove(string varName)
{
    bool deleted = currentScopeTable->Delete(varName);
    return (deleted) ? true : false;
}

SymbolInfo *SymbolTable::lookUp(string varName)
{
    scopeTable *tem;
    tem = currentScopeTable;

    while (tem != 0)
    {
        SymbolInfo *found = tem->lookUp(varName);
        if (found != 0)
        {
            return found;
        }
        tem = tem->parentScopeTable;
    }
    return 0;
}

void SymbolTable::printCurrentScopeTable()
{
    cout << "ScopeTable # " << currentScopeTable->id << endl;
    currentScopeTable->printScopeTable();
    return;
}

string SymbolTable::printAllScopeTable()
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

