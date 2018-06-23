
#include <bits/stdc++.h>

#define ll long long
using namespace std;


class SymbolInfo
{
    string SymbolName, SymbolType;
    string funcReturnType;
    string idType ; // VAR , FUNC , ARR 
    string varType ; // INT , FLOAT , CHAR
    

public:
    vector<SymbolInfo*> paramList ; 
    vector<int> intArray; 
    vector<float> floatArray; 
    vector<char> charArray; 

    int intVarValue ; 
    float floatVarValue ; 
    char charVarValue ; 
    int currentArrayIndex ; 
    int arraySize, paramNo ; 
    bool funcDeclared ;
    bool isFuncDefined ; 

    string codeSegment ;  

    ll i, j, tableId;
    SymbolInfo *next;

    SymbolInfo();

    SymbolInfo(string type);

    SymbolInfo(string name, string type);

    void setSymbolName(string name);

    void setSymbolType(string type); // CONST_INT / ID / CONST_CHAR / RELOP

    void setAll(string name, string type);

    string getSymbolName();

    string getSymbolType(); 

    void setFuncReturnType(string s); // "INT"/"FLOAT"/"DOUBLE"/ VOID

    string getFuncReturnType();

    void setIdType(string s); // "VAR"/"FUNC"/"ARRAY"

    string getIdType();

    void setVarType(string s); // "INT"/"FLOAT"/"CHAR"

    string getVarType();

    void setArraySize(int N);

    int getArraySize();

    void fillArray();

    void setParamNo(int n);
    int getParamNo();
    void setParamList(vector<SymbolInfo*> vec);

    void setIsFuncDefined(); 
    bool checkIfFuncDefined();
};




class scopeTable
{
    SymbolInfo j;
public:
    SymbolInfo *Arr;
    scopeTable *parentScopeTable;
    ll id, N;

    scopeTable(ll n);

    ~scopeTable();

    ll hash(string varName);

    SymbolInfo* insert(string varName, string varType);

    bool Delete(string varName);

    SymbolInfo *lookUp(string varName , string varType);

    void printScopeTable(ofstream& fileOut);
};



class SymbolTable
{
public:
    ll N;
    scopeTable *currentScopeTable;

    SymbolTable(ll n);

    void enterScope();

    void exitScope();

    SymbolInfo* insert(string varName, string varType);

    SymbolInfo* insert(SymbolInfo* s); 

    bool remove(string varName);

    SymbolInfo *lookUp(string varName , string varType);

    SymbolInfo *lookUpInCurr(string varName , string varType);

    void printCurrentScopeTable(ofstream& fileOut);

    void printAllScopeTable(ofstream& fileOut);
};

