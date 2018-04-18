//
// Created by Heisenberg on 14-Apr-18.
//

#include <bits/stdc++.h>

#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)

#include "SymbolTable_1505038.h"

#define  ll long long
using namespace std;
ll P;

int main()
{
    fi;
    fo;
    ll N;
    cin >> N;
    char c;
    symbolTable mySymbolTable(N);

    while (scanf(" %c", &c) != EOF)
    {
        if (mySymbolTable.currentScopeTable == 0)
        {
            cout << "There is no more scope table. Program terminated." << endl;
            return 0;
        }

        switch (c)
        {
        case 'I':
        {
            string varName, varType;
            cin >> varName >> varType;
            bool done = mySymbolTable.insert(varName, varType);
            cout << 'I' << " " << varName << " " << varType << endl << endl;
            if (done)
            {
                cout << "   Inserted in ScopeTable # " << mySymbolTable.currentScopeTable->id <<
                     "at position " << mySymbolTable.lookUp(varName)->i << " , " <<
                     mySymbolTable.lookUp(varName)->j << endl;
            }
            else
            {
                cout << "   <" << varName << "> already exists in current ScopeTable" << endl;
            }
            break;
        }
        case 'L':
        {
            string varName;
            cin >> varName;
            symbolInfo *ret = mySymbolTable.lookUp(varName);

            cout << "L" << " " << varName << endl << endl;
            if (ret)
            {
                cout << "   Found in ScopeTable # " << ret->tableId <<
                     " at position " << ret->i << " , " <<
                     ret->j << endl;
            }
            else
            {
                cout << "   Not found" << endl;
            }
            break;
        }
        case 'D':
        {

            string varName;
            cin >> varName;
            ll i, j;
            symbolInfo *found;
            found = mySymbolTable.currentScopeTable->lookUp(varName);

            if (found)
            {
                i = found->i;
                j = found->j;
                cout << "   Found in ScopeTable# " << found->tableId << " at position " << i << "," << j << endl ;
                mySymbolTable.remove(varName);
                cout << "   Deleted entry at " << i << " , " << j << " from current ScopeTable" << endl;
            }
            else
            {
                cout << "   Entry Not Found." << endl;
            }
            break;
        }
        case 'P':
        {

            char b;
            scanf(" %c", &b);

            cout << "P ";
            if (b == 'A')
            {
                cout << 'A' << endl;
                mySymbolTable.printAllScopeTable();
            }
            else if (b == 'C')
            {
                cout << 'C' << endl;
                mySymbolTable.printCurrentScopeTable();
            }
            break;
        }
        case 'S':
        {
            mySymbolTable.enterScope();
            break;
        }
        case 'E':
        {
            mySymbolTable.exitScope();
            break;
        }
        default:
        {
            cout << "   Invalid Choice" << endl;
            break;
        }
        }
        //mySymbolTable.printAllScopeTable();
    }
    return 0;
}
