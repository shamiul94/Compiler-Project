#include <bits/stdc++.h>
//#include "SymbolTable.h"

using namespace std;

extern int lineCount;
extern int errorNo, totalArgsNo, typeAndIDArgsNo ;
extern ofstream plogout, perrout ;

extern SymbolTable *myTable ;
extern vector<SymbolInfo*> Params ; 

int stoi(std::string s) //The conversion function
{
    return atoi(s.c_str());
}

float stof(string s) //The conversion function
{
    return atof(s.c_str());
}

void initializeParam()
{
    Params.clear();
    totalArgsNo = 0 ;
    typeAndIDArgsNo = 0 ;
}

void divByZeroError()
{
    errorNo++;
    perrout << "Error No: " << errorNo << " at line no: " << lineCount << " Division by 0 is not possible." << endl << endl ;
}

void modByZeroError()
{
    errorNo++;
    perrout << "Error No: " << errorNo << " at line no: " << lineCount << " Modulus by 0 is not possible." << endl << endl ;
}

void modNotBothIntError()
{
    errorNo++;
    perrout << "Error No: " << errorNo << " at line no: " << lineCount << " Both operand of \% operation must be Integers." << endl << endl ;
}

SymbolInfo* VVIIM(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("VVIIM", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("INT");
    tem -> intVarValue = tem1 -> intVarValue * tem3 -> intVarValue ;
    return tem ;
}

SymbolInfo* VVIFM(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("VVIFM", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> intVarValue * tem3 -> floatVarValue ;
    return tem ;
}

SymbolInfo* VVFIM(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("VVFIM", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> floatVarValue * tem3 -> intVarValue ;
    return tem ;
}

SymbolInfo* VVFFM(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("VVFFM", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> floatVarValue * tem3 -> floatVarValue ;
    return tem ;
}

SymbolInfo* VAIIM(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("VAIIM", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("INT");
    tem -> intVarValue = tem1 -> intVarValue * tem3 -> intArray[tem3 -> currentArrayIndex] ;
    return tem ;
}


SymbolInfo* VAIFM(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("VAIFM", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> intVarValue * tem3 -> floatArray[tem3 -> currentArrayIndex] ;
    return tem ;
}


SymbolInfo* VAFIM(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("VAFIM", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> floatVarValue * tem3 -> intArray[tem3 -> currentArrayIndex] ;
    return tem ;
}


SymbolInfo* VAFFM(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("VAFFM", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> floatVarValue * tem3 -> floatArray[tem3 -> currentArrayIndex] ;
    return tem ;
}


SymbolInfo* AVIIM(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("AVIIM", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("INT");
    tem -> intVarValue = tem1 -> intArray[tem1 -> currentArrayIndex] * tem3 -> intVarValue;
    return tem ;
}


SymbolInfo* AVIFM(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("AVIFM", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> intArray[tem1 -> currentArrayIndex] * tem3 -> floatVarValue ;
    return tem ;
}


SymbolInfo* AVFIM(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("AVFIM", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> floatArray[tem1 -> currentArrayIndex] * tem3 -> intVarValue ;
    return tem ;
}


SymbolInfo* AVFFM(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("AVFFM", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> floatArray[tem1 -> currentArrayIndex] * tem3 -> floatVarValue ;
    return tem ;
}


SymbolInfo* AAIIM(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("AAIIM", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("INT");
    tem -> intVarValue = tem1 -> intArray[tem1 -> currentArrayIndex] * tem3 -> intArray[tem3 -> currentArrayIndex] ;
    return tem ;
}


SymbolInfo* AAIFM(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("AAIFM", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> intArray[tem1 -> currentArrayIndex] * tem3 -> floatArray[tem3 -> currentArrayIndex] ;
    return tem ;
}

SymbolInfo* AAFIM(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("AAFIM", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> floatArray[tem1 -> currentArrayIndex] * tem3 -> intArray[tem3 -> currentArrayIndex] ;
    return tem ;
}

SymbolInfo* AAFFM(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("AAFFM", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> floatArray[tem1 -> currentArrayIndex] * tem3 -> floatArray[tem3 -> currentArrayIndex] ;
    return tem ;
}


SymbolInfo* VVIID(SymbolInfo* tem1, SymbolInfo* tem3)
{
    if(tem3 -> intVarValue == 0)
    {
        divByZeroError();
        return 0;
    }
    else
    {
        SymbolInfo* tem = new SymbolInfo("VVIID", "ID");
        tem -> setIdType("VAR");
        tem -> setVarType("INT");
        tem -> intVarValue = tem1 -> intVarValue / tem3 -> intVarValue ;
        return tem ;
    }
}


SymbolInfo* VVIFD(SymbolInfo* tem1, SymbolInfo* tem3)
{
    if(tem3 -> floatVarValue == 0.0)
    {
        divByZeroError();
        return 0;
    }
    else
    {
        SymbolInfo* tem = new SymbolInfo("VVIFD", "ID");
        tem -> setIdType("VAR");
        tem -> setVarType("FLOAT");
        tem -> floatVarValue = tem1 -> intVarValue / tem3 -> floatVarValue ;
        return tem ;
    }
}


SymbolInfo* VVFID(SymbolInfo* tem1, SymbolInfo* tem3)
{
    if(tem3 -> intVarValue == 0)
    {
        divByZeroError();
        return 0;
    }
    else
    {
        SymbolInfo* tem = new SymbolInfo("VVFID", "ID");
        tem -> setIdType("VAR");
        tem -> setVarType("FLOAT");
        tem -> floatVarValue = tem1 -> floatVarValue / tem3 -> intVarValue ;
        return tem ;
    }
}


SymbolInfo* VVFFD(SymbolInfo* tem1, SymbolInfo* tem3)
{
    if(tem3 -> floatVarValue == 0.0)
    {
        divByZeroError();
        return 0;
    }
    else
    {
        SymbolInfo* tem = new SymbolInfo("VVFFD", "ID");
        tem -> setIdType("VAR");
        tem -> setVarType("FLOAT");

        tem -> floatVarValue = tem1 -> floatVarValue / tem3 -> floatVarValue ;
        return tem ;
    }
}


SymbolInfo* VAIID(SymbolInfo* tem1, SymbolInfo* tem3)
{
    if(tem3 -> intArray[tem3 -> currentArrayIndex] == 0)
    {
        divByZeroError();
        return 0;
    }
    else
    {
        SymbolInfo* tem = new SymbolInfo("VAIID", "ID");
        tem -> setIdType("VAR");
        tem -> setVarType("INT");

        tem -> intVarValue = tem1 -> intVarValue / tem3 -> intArray[tem3 -> currentArrayIndex] ;
        return tem ;
    }
}


SymbolInfo* VAIFD(SymbolInfo* tem1, SymbolInfo* tem3)
{
    if(tem3 -> floatArray[tem3 -> currentArrayIndex] == 0.0)
    {
        divByZeroError();
        return 0;
    }
    else
    {
        SymbolInfo* tem = new SymbolInfo("VAIFD", "ID");
        tem -> setIdType("VAR");
        tem -> setVarType("FLOAT");

        tem -> floatVarValue = tem1 -> intVarValue / tem3 -> floatArray[tem3 -> currentArrayIndex] ;
        return tem ;
    }
}


SymbolInfo* VAFID(SymbolInfo* tem1, SymbolInfo* tem3)
{
    if(tem3 -> intArray[tem3 -> currentArrayIndex] == 0)
    {
        divByZeroError();
        return 0;
    }
    else
    {
        SymbolInfo* tem = new SymbolInfo("VAFID", "ID");
        tem -> setIdType("VAR");
        tem -> setVarType("FLOAT");

        tem -> floatVarValue = tem1 -> floatVarValue / tem3 -> intArray[tem3 -> currentArrayIndex] ;
        return tem ;
    }
}


SymbolInfo* VAFFD(SymbolInfo* tem1, SymbolInfo* tem3)
{
    if(tem3 -> floatArray[tem3 -> currentArrayIndex] == 0.0)
    {
        divByZeroError();
        return 0;
    }
    else
    {
        SymbolInfo* tem = new SymbolInfo("VAFFD", "ID");
        tem -> setIdType("VAR");
        tem -> setVarType("FLOAT");

        tem -> floatVarValue = tem1 -> floatVarValue / tem3 -> floatArray[tem3 -> currentArrayIndex] ;
        return tem ;
    }
}



SymbolInfo* AVIID(SymbolInfo* tem1, SymbolInfo* tem3)
{
    if(tem3 -> intVarValue == 0)
    {
        divByZeroError();
        return 0;
    }
    else
    {
        SymbolInfo* tem = new SymbolInfo("AVIID", "ID");
        tem -> setIdType("VAR");
        tem -> setVarType("INT");

        tem -> intVarValue = tem1 -> intArray[tem1 -> currentArrayIndex] / tem3 -> intVarValue ;
        return tem ;
    }
}



SymbolInfo* AVIFD(SymbolInfo* tem1, SymbolInfo* tem3)
{
    if(tem3 -> floatVarValue == 0.0)
    {
        divByZeroError();
        return 0;
    }
    else
    {
        SymbolInfo* tem = new SymbolInfo("AVIFD", "ID");
        tem -> setIdType("VAR");
        tem -> setVarType("FLOAT");

        tem -> floatVarValue = tem1 -> intArray[tem1 -> currentArrayIndex] / tem3 -> floatVarValue ;
        return tem ;
    }
}


SymbolInfo* AVFID(SymbolInfo* tem1, SymbolInfo* tem3)
{
    if(tem3 -> intVarValue == 0)
    {
        divByZeroError();
        return 0;
    }
    else
    {
        SymbolInfo* tem = new SymbolInfo("AVFID", "ID");
        tem -> setIdType("VAR");
        tem -> setVarType("FLOAT");

        tem -> floatVarValue = tem1 -> floatArray[tem1 -> currentArrayIndex] / tem3 -> intVarValue ;
        return tem ;
    }
}




SymbolInfo* AVFFD(SymbolInfo* tem1, SymbolInfo* tem3)
{
    if(tem3 -> floatVarValue == 0.0)
    {
        divByZeroError();
        return 0;
    }
    else
    {
        SymbolInfo* tem = new SymbolInfo("AVFFD", "ID");
        tem -> setIdType("VAR");
        tem -> setVarType("FLOAT");

        tem -> floatVarValue = tem1 -> floatArray[tem1 -> currentArrayIndex] * tem3 -> floatVarValue ;
        return tem ;
    }
}


SymbolInfo* AAIID(SymbolInfo* tem1, SymbolInfo* tem3)
{
    if(tem3 -> intArray[tem3 -> currentArrayIndex] == 0)
    {
        divByZeroError();
        return 0;
    }
    else
    {
        SymbolInfo* tem = new SymbolInfo("AAIID", "ID");
        tem -> setIdType("VAR");
        tem -> setVarType("INT");

        tem -> intVarValue = tem1 -> intArray[tem1 -> currentArrayIndex] / tem3 -> intArray[tem3 -> currentArrayIndex] ;
        return tem ;
    }
}


SymbolInfo* AAIFD(SymbolInfo* tem1, SymbolInfo* tem3)
{
    if(tem3 -> floatArray[tem3 -> currentArrayIndex] == 0.0)
    {
        divByZeroError();
        return 0;
    }
    else
    {
        SymbolInfo* tem = new SymbolInfo("AAIFD", "ID");
        tem -> setIdType("VAR");
        tem -> setVarType("FLOAT");

        tem -> floatVarValue = tem1 -> intArray[tem1 -> currentArrayIndex] / tem3 -> floatArray[tem3 -> currentArrayIndex] ;
        return tem ;
    }
}

SymbolInfo* AAFID(SymbolInfo* tem1, SymbolInfo* tem3)
{
    if(tem3 -> intArray[tem3 -> currentArrayIndex] == 0)
    {
        divByZeroError();
        return 0;
    }
    else
    {
        SymbolInfo* tem = new SymbolInfo("AAFID", "ID");
        tem -> setIdType("VAR");
        tem -> setVarType("FLOAT");

        tem -> floatVarValue = tem1 -> floatArray[tem1 -> currentArrayIndex] / tem3 -> intArray[tem3 -> currentArrayIndex] ;
        return tem ;
    }
}

SymbolInfo* AAFFD(SymbolInfo* tem1, SymbolInfo* tem3)
{
    if(tem3 -> floatArray[tem3 -> currentArrayIndex] == 0)
    {
        divByZeroError();
        return 0;
    }
    else
    {
        SymbolInfo* tem = new SymbolInfo("AAFFD", "ID");
        tem -> setIdType("VAR");
        tem -> setVarType("FLOAT");

        tem -> floatVarValue = tem1 -> floatArray[tem1 -> currentArrayIndex] / tem3 -> floatArray[tem3 -> currentArrayIndex] ;
        return tem ;
    }
}



SymbolInfo* VVIIMOD(SymbolInfo* tem1, SymbolInfo* tem3)
{
    if(tem3 -> intVarValue == 0)
    {
        modByZeroError();
        return 0;
    }
    else
    {
        SymbolInfo* tem = new SymbolInfo("VVIIMOD", "ID");
        tem -> setIdType("VAR");
        tem -> setVarType("INT");
        tem -> intVarValue = tem1 -> intVarValue % tem3 -> intVarValue ;
        return tem ;
    }
}


SymbolInfo* VAIIMOD(SymbolInfo* tem1, SymbolInfo* tem3)
{
    if(tem3 -> intArray[tem3 -> currentArrayIndex] == 0)
    {
        modByZeroError();
        return 0;
    }
    else
    {
        SymbolInfo* tem = new SymbolInfo("VAIIMOD", "ID");
        tem -> setIdType("VAR");
        tem -> setVarType("INT");

        tem -> intVarValue = tem1 -> intVarValue % tem3 -> intArray[tem3 -> currentArrayIndex] ;
        return tem ;
    }
}

SymbolInfo* AVIIMOD(SymbolInfo* tem1, SymbolInfo* tem3)
{
    if(tem3 -> intVarValue == 0)
    {
        modByZeroError();
        return 0;
    }
    else
    {
        SymbolInfo* tem = new SymbolInfo("AVIIMOD", "ID");
        tem -> setIdType("VAR");
        tem -> setVarType("INT");

        tem -> intVarValue = tem1 -> intArray[tem1 -> currentArrayIndex] % tem3 -> intVarValue ;
        return tem ;
    }
}

SymbolInfo* AAIIMOD(SymbolInfo* tem1, SymbolInfo* tem3)
{
    if(tem3 -> intArray[tem3 -> currentArrayIndex] == 0)
    {
        modByZeroError();
        return 0;
    }
    else
    {
        SymbolInfo* tem = new SymbolInfo("AAIIMOD", "ID");
        tem -> setIdType("VAR");
        tem -> setVarType("INT");

        tem -> intVarValue = tem1 -> intArray[tem1 -> currentArrayIndex] % tem3 -> intArray[tem3 -> currentArrayIndex] ;
        return tem ;
    }
}


/*********************** ADDOP FUnctions **********************/


SymbolInfo* VVIIA(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("VVIIA", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("INT");
    tem -> intVarValue = tem1 -> intVarValue + tem3 -> intVarValue ;
    return tem ;
}

SymbolInfo* VVIFA(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("VVIFA", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> intVarValue + tem3 -> floatVarValue ;
    return tem ;
}

SymbolInfo* VVFIA(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("VVFIA", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> floatVarValue + tem3 -> intVarValue ;
    return tem ;
}

SymbolInfo* VVFFA(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("VVFFA", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> floatVarValue + tem3 -> floatVarValue ;
    return tem ;
}

SymbolInfo* VAIIA(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("VAIIA", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("INT");
    tem -> intVarValue = tem1 -> intVarValue + tem3 -> intArray[tem3 -> currentArrayIndex] ;
    return tem ;
}


SymbolInfo* VAIFA(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("VAIFA", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> intVarValue + tem3 -> floatArray[tem3 -> currentArrayIndex] ;
    return tem ;
}


SymbolInfo* VAFIA(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("VAFIA", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> floatVarValue + tem3 -> intArray[tem3 -> currentArrayIndex] ;
    return tem ;
}


SymbolInfo* VAFFA(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("VAFFA", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> floatVarValue + tem3 -> floatArray[tem3 -> currentArrayIndex] ;
    return tem ;
}


SymbolInfo* AVIIA(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("AVIIA", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("INT");
    tem -> intVarValue = tem1 -> intArray[tem1 -> currentArrayIndex] + tem3 -> intVarValue ; 
    return tem ;
}


SymbolInfo* AVIFA(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("AVIFA", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> intArray[tem1 -> currentArrayIndex] + tem3 -> floatVarValue ;
    return tem ;
}


SymbolInfo* AVFIA(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("AVFIA", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> floatArray[tem1 -> currentArrayIndex] + tem3 -> intVarValue ;
    return tem ;
}


SymbolInfo* AVFFA(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("AVFFA", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> floatArray[tem1 -> currentArrayIndex] + tem3 -> floatVarValue ;
    return tem ;
}


SymbolInfo* AAIIA(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("AAIIA", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("INT");
    tem -> intVarValue = tem1 -> intArray[tem1 -> currentArrayIndex] + tem3 -> intArray[tem3 -> currentArrayIndex] ;
    return tem ;
}


SymbolInfo* AAIFA(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("AAIFA", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> intArray[tem1 -> currentArrayIndex] + tem3 -> floatArray[tem3 -> currentArrayIndex] ;
    return tem ;
}

SymbolInfo* AAFIA(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("AAFIA", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> floatArray[tem1 -> currentArrayIndex] + tem3 -> intArray[tem3 -> currentArrayIndex] ;
    return tem ;
}

SymbolInfo* AAFFA(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("AAFFA", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> floatArray[tem1 -> currentArrayIndex] + tem3 -> floatArray[tem3 -> currentArrayIndex] ;
    return tem ;
}



/************************** MINUS Functions ************************/ 




SymbolInfo* VVIIMIN(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("VVIIMIN", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("INT");
    tem -> intVarValue = tem1 -> intVarValue - tem3 -> intVarValue ;
    return tem ;
}

SymbolInfo* VVIFMIN(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("VVIFMIN", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> intVarValue - tem3 -> floatVarValue ;
    return tem ;
}

SymbolInfo* VVFIMIN(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("VVFIMIN", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> floatVarValue - tem3 -> intVarValue ;
    return tem ;
}

SymbolInfo* VVFFMIN(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("VVFFMIN", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> floatVarValue - tem3 -> floatVarValue ;
    return tem ;
}

SymbolInfo* VAIIMIN(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("VAIIMIN", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("INT");
    tem -> intVarValue = tem1 -> intVarValue - tem3 -> intArray[tem3 -> currentArrayIndex] ;
    return tem ;
}


SymbolInfo* VAIFMIN(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("VAIFMIN", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> intVarValue - tem3 -> floatArray[tem3 -> currentArrayIndex] ;
    return tem ;
}


SymbolInfo* VAFIMIN(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("VAFIMIN", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> floatVarValue - tem3 -> intArray[tem3 -> currentArrayIndex] ;
    return tem ;
}


SymbolInfo* VAFFMIN(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("VAFFMIN", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> floatVarValue - tem3 -> floatArray[tem3 -> currentArrayIndex] ;
    return tem ;
}


SymbolInfo* AVIIMIN(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("AVIIMIN", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("INT");
    tem -> intVarValue = tem1 -> intArray[tem1 -> currentArrayIndex] - tem3 -> intVarValue ; 
    return tem ;
}


SymbolInfo* AVIFMIN(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("AVIFMIN", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> intArray[tem1 -> currentArrayIndex] - tem3 -> floatVarValue ;
    return tem ;
}


SymbolInfo* AVFIMIN(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("AVFIMIN", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> floatArray[tem1 -> currentArrayIndex] - tem3 -> intVarValue ;
    return tem ;
}


SymbolInfo* AVFFMIN(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("AVFFMIN", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> floatArray[tem1 -> currentArrayIndex] - tem3 -> floatVarValue ;
    return tem ;
}


SymbolInfo* AAIIMIN(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("AAIIMIN", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("INT");
    tem -> intVarValue = tem1 -> intArray[tem1 -> currentArrayIndex] - tem3 -> intArray[tem3 -> currentArrayIndex] ;
    return tem ;
}


SymbolInfo* AAIFMIN(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("AAIFMIN", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> intArray[tem1 -> currentArrayIndex] - tem3 -> floatArray[tem3 -> currentArrayIndex] ;
    return tem ;
}

SymbolInfo* AAFIMIN(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("AAFIMIN", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> floatArray[tem1 -> currentArrayIndex] - tem3 -> intArray[tem3 -> currentArrayIndex] ;
    return tem ;
}

SymbolInfo* AAFFMIN(SymbolInfo* tem1, SymbolInfo* tem3)
{
    SymbolInfo* tem = new SymbolInfo("AAFFMIN", "ID");
    tem -> setIdType("VAR");
    tem -> setVarType("FLOAT");
    tem -> floatVarValue = tem1 -> floatArray[tem1 -> currentArrayIndex] - tem3 -> floatArray[tem3 -> currentArrayIndex] ;
    return tem ;
}


/*********************** greater equal ********************/ 

/*
1 --- >= 
2 --- > 
3 --- <= 
4 --- < 
*/

SymbolInfo* relationOperator(SymbolInfo* tem1 , SymbolInfo* tem3, int op)
{
	SymbolInfo* tem = new SymbolInfo("" , "ID");
				tem -> setVarType("INT");
				tem -> setIdType("VAR");

				if(tem1 -> getVarType() == "INT")
				{
					if(tem3 -> getVarType() == "INT")
					{
						if(op==1)tem -> intVarValue = (tem1 -> intVarValue >= tem3 -> intVarValue);
						else if(op == 2) tem -> intVarValue = (tem1 -> intVarValue > tem3 -> intVarValue);
						else if(op == 3) tem -> intVarValue = (tem1 -> intVarValue <= tem3 -> intVarValue);
						else if(op == 4) tem -> intVarValue = (tem1 -> intVarValue < tem3 -> intVarValue);
					}
					else if(tem3 -> getVarType() == "FLOAT")
					{
						if(op==1)tem -> intVarValue = (tem1 -> intVarValue >= tem3 -> floatVarValue);
						else if(op == 2)tem -> intVarValue = (tem1 -> intVarValue > tem3 -> floatVarValue);
						else if(op == 3)tem -> intVarValue = (tem1 -> intVarValue <= tem3 -> floatVarValue);
						else if(op == 4)tem -> intVarValue = (tem1 -> intVarValue < tem3 -> floatVarValue);
					}
					else if(tem3 -> getVarType() == "CHAR")
					{
						if(op==1)tem -> intVarValue = (tem1 -> intVarValue >= tem3 -> charVarValue);
						else if(op == 2)tem -> intVarValue = (tem1 -> intVarValue > tem3 -> charVarValue);
						else if(op == 3)tem -> intVarValue = (tem1 -> intVarValue <= tem3 -> charVarValue);
						else if(op == 4)tem -> intVarValue = (tem1 -> intVarValue < tem3 -> charVarValue);
					}
				}
				else if(tem1 -> getVarType() == "FLOAT")
				{
					if(tem3 -> getVarType() == "INT")
					{
						if(op==1)tem -> intVarValue = (tem1 -> floatVarValue >= tem3 -> intVarValue);
						else if(op == 2)tem -> intVarValue = (tem1 -> floatVarValue > tem3 -> intVarValue);
						else if(op == 3)tem -> intVarValue = (tem1 -> floatVarValue <= tem3 -> intVarValue);
						else if(op == 4)tem -> intVarValue = (tem1 -> floatVarValue < tem3 -> intVarValue);
					}
					else if(tem3 -> getVarType() == "FLOAT")
					{
						if(op==1)tem -> intVarValue = (tem1 -> floatVarValue >= tem3 -> floatVarValue);
						else if(op == 2)tem -> intVarValue = (tem1 -> floatVarValue > tem3 -> floatVarValue);
						else if(op == 3)tem -> intVarValue = (tem1 -> floatVarValue <= tem3 -> floatVarValue);
						else if(op == 4)tem -> intVarValue = (tem1 -> floatVarValue < tem3 -> floatVarValue);
					}
					else if(tem3 -> getVarType() == "CHAR")
					{
						if(op==1)tem -> intVarValue = (tem1 -> floatVarValue >= tem3 -> charVarValue);
						else if(op == 2)tem -> intVarValue = (tem1 -> floatVarValue > tem3 -> charVarValue);
						else if(op == 3)tem -> intVarValue = (tem1 -> floatVarValue <= tem3 -> charVarValue);
						else if(op == 4)tem -> intVarValue = (tem1 -> floatVarValue < tem3 -> charVarValue);
					}
				}
				else if(tem1 -> getVarType() == "CHAR")
				{
					if(tem3 -> getVarType() == "INT")
					{
						if(op==1)tem -> intVarValue = (tem1 -> charVarValue >= tem3 -> intVarValue);
						else if(op == 2)tem -> intVarValue = (tem1 -> charVarValue > tem3 -> intVarValue);
						else if(op == 3)tem -> intVarValue = (tem1 -> charVarValue <= tem3 -> intVarValue);
						else if(op == 4)tem -> intVarValue = (tem1 -> charVarValue < tem3 -> intVarValue);
					}
					else if(tem3 -> getVarType() == "FLOAT")
					{
						if(op==1)tem -> intVarValue = (tem1 -> charVarValue >= tem3 -> floatVarValue);
						else if(op == 2)tem -> intVarValue = (tem1 -> charVarValue > tem3 -> floatVarValue);
						else if(op == 3)tem -> intVarValue = (tem1 -> charVarValue <= tem3 -> floatVarValue);
						else if(op == 4)tem -> intVarValue = (tem1 -> charVarValue < tem3 -> floatVarValue);
					}
					else if(tem3 -> getVarType() == "CHAR")
					{
						if(op==1)tem -> intVarValue = (tem1 -> charVarValue >= tem3 -> charVarValue);
						else if(op == 2)tem -> intVarValue = (tem1 -> charVarValue > tem3 -> charVarValue);
						else if(op == 3)tem -> intVarValue = (tem1 -> charVarValue <= tem3 -> charVarValue);
						else if(op == 4)tem -> intVarValue = (tem1 -> charVarValue < tem3 -> charVarValue);
					}

				}

				return tem ; 
}



