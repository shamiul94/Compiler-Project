#include "SymbolTable.h"

SymbolInfo::SymbolInfo()
{
    SymbolName = "";
    SymbolType = "";
    next = 0;
    isFuncDefined = false ; 
    funcDeclared = false ; 
    codeSegment = "";
}

void SymbolInfo:: setIsFuncDefined()
{
    isFuncDefined = true; 
    return ; 
}

bool SymbolInfo::checkIfFuncDefined()
{
    return isFuncDefined; 
}


SymbolInfo::SymbolInfo(string type)
{
    SymbolName = type; 
    funcDeclared = false ; 
    isFuncDefined = false ;
    codeSegment = "";
}

SymbolInfo::SymbolInfo(string name, string type)
{
    SymbolName = name;
    SymbolType = type;
    next = 0;
    isFuncDefined = false ;
    funcDeclared = false ; 
    codeSegment = "";
}

void SymbolInfo::setVarType(string s)
{
    varType = s ; 
    return; 
}

string SymbolInfo::getVarType()
{
    return varType ; 
}

void SymbolInfo::setArraySize(int N)
{
    arraySize = N; 
    return;
}

int SymbolInfo::getArraySize()
{
    return arraySize;
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

void SymbolInfo::setFuncReturnType(string s)
{
    funcReturnType = s;
    return; 
}

int SymbolInfo::getParamNo()
{
    return paramNo;
}

string SymbolInfo::getFuncReturnType()
{
    return funcReturnType;
}

void SymbolInfo::setIdType(string s)
{
    idType = s ; 
    return; 
}

string SymbolInfo::getIdType()
{
    return idType; 
}


void SymbolInfo::fillArray()
{
    if(varType == "INT")
    {
        for(int i = 0 ; i < arraySize ; i++)
        {
            intArray.push_back(0);
        }
    }
    else if(varType == "FLOAT")
    {
        for(int i = 0 ; i < arraySize ; i++)
        {
            floatArray.push_back(0);
        }
    }
    else if(varType == "CHAR")
    {
        for(int i = 0 ; i < arraySize ; i++)
        {
            charArray.push_back('\0');
        }
    }
    return; 
}


void SymbolInfo::setParamNo(int n)
{
    paramNo = n ; 
    return ; 
}


void SymbolInfo::setParamList(vector<SymbolInfo*> vec)
{
    paramList = vec ; 
    return ; 
}





scopeTable::scopeTable(ll n)
{
    Arr = new SymbolInfo[n];
    parentScopeTable = 0;
    N = n;
    id = 1;
}


SymbolInfo* scopeTable::insert(string varName, string varType)
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
                return 0;
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

    //cout << "Mara  " << curr -> next -> getIdType() << endl ; 
    return NewVar;
}


SymbolInfo *scopeTable::lookUp(string varName, string varType)
{
    ll positionInArray = hash(varName);
    SymbolInfo *curr = &Arr[positionInArray];


    while (curr->next != 0)
    {
        curr = curr->next;

        if (curr != 0)
        {
            if (curr->getSymbolName() == varName && curr -> getSymbolType() == varType)
            {
                //cout << curr -> getIdType() << " " << curr -> getSymbolName() << endl ; 
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

void scopeTable::printScopeTable(ofstream& fileOut)
{
    for (ll i = 0; i < N; i++)
    {
        fileOut << i << " --> ";

        SymbolInfo *curr = &Arr[i];
        while (curr != 0)
        {
            curr = curr->next;

            if (curr != 0)
            {
                fileOut << "< " << curr->getSymbolName() << "," << curr->getSymbolType() << "," << curr -> getVarType() << "," << curr -> getIdType() << "," << curr -> getFuncReturnType() << " >";
            }
            if (curr != 0 && curr->next != 0)
            {
                fileOut << " , ";
            }
        }
        fileOut << endl;
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

SymbolInfo* SymbolTable::insert(string varName, string varType)
{
    SymbolInfo* inserted = currentScopeTable->insert(varName, varType);
    return inserted ;
}

SymbolInfo* SymbolTable::insert(SymbolInfo* s)
{
    SymbolInfo* inserted = insert(s -> getSymbolName(), s -> getSymbolType());
    return inserted ;
}

bool SymbolTable::remove(string varName)
{
    bool deleted = currentScopeTable->Delete(varName);
    return (deleted) ? true : false;
}

SymbolInfo *SymbolTable::lookUp(string varName, string varType)
{
    scopeTable *tem;
    tem = currentScopeTable;

    while (tem != 0)
    {
        SymbolInfo *found = tem->lookUp(varName, varType);
        if (found != 0)
        {
            return found;
        }
        tem = tem->parentScopeTable;
    }
    return 0;
}



SymbolInfo* SymbolTable::lookUpInCurr(string varName , string varType)
{
    SymbolInfo* ret = currentScopeTable -> lookUp(varName , varType);
    return ret ; 
}




void SymbolTable::printCurrentScopeTable(ofstream& fileOut)
{
    fileOut << "ScopeTable # " << currentScopeTable->id << endl;
    currentScopeTable->printScopeTable(fileOut);
    return;
}

void SymbolTable::printAllScopeTable(ofstream& fileOut)
{
    scopeTable *tem;
    tem = currentScopeTable;

    while (tem != 0)
    {
        fileOut << "ScopeTable # " << tem->id << endl;
        tem->printScopeTable(fileOut);
        tem = tem->parentScopeTable;
    }
    return;
}



