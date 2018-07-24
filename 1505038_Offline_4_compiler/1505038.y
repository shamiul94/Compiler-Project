%{
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include "SymbolTable.h"
#include "Functions.h"
#include <sstream>

	using namespace std;

	int yyparse(void);
	int yylex(void);

	extern FILE *yyin;
	extern int lineCount;

	string varType , retLabel ;

	SymbolTable *myTable = new SymbolTable(11);

	ofstream plogout, perrout , asmout ;

	int warningNo = 0, errorNo = 0, totalArgsNo = 0, typeAndIDArgsNo = 0;
	int passedParamNo = 0;

	vector<SymbolInfo *> Params;
	vector<Data> dataSegment ; 

	void yyerror(const char *s)
	{
		//write your code
		printf("%s\n", s);
	}

	int labelCount=0;
	int tempCount=0;

char *newLabel()
{
	char *lb= new char[4];
	strcpy(lb,"L");
	char b[3];
	sprintf(b,"%d", labelCount);
	labelCount++;
	strcat(lb,b);
	return lb;
}

char *newTemp()
{
	char *t= new char[4];
	strcpy(t,"t");
	char b[3];
	sprintf(b,"%d", tempCount);
	tempCount++;
	strcat(t,b);
	//printf("%s\n",t);
	return t;
}

string IntToString (int a)
{
    ostringstream temp;
    temp<<a;
    return temp.str();
}

%}
%union {
	SymbolInfo *s;
}

		%token IF ELSE FOR WHILE DO BREAK INT CHAR FLOAT DOUBLE VOID RETURN SWITCH CASE DEFAULT CONTINUE INCOP DECOP ASSIGNOP BITOP NOT LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD COMMA SEMICOLON PRINTLN COMMENT ERROR

		%token<s> ID CONST_INT CONST_STRING CONST_FLOAT CONST_CHAR ADDOP MULOP LOGICOP RELOP

		%type<s> term unary_expression factor variable type_specifier logic_expression rel_expression simple_expression arguments argument_list start program unit func_declaration func_definition parameter_list var_declaration declaration_list statement statements expression expression_statement compound_statement

		%nonassoc LOWER_THAN_ELSE 
		%nonassoc ELSE 
		%error-verbose 
%%
start : program
{

	plogout << "At line no: " << lineCount << " : "
			<< "start : program" << endl
			<< endl;

	plogout << $1->codeSegment << endl
			<< endl;

	$$ = $1;

	//if(errorNo == 0)
	{
		//$1->assemblyCode +="\n\n DEC_OUT PROC NEAR\n\n\tpush ax\n\tpush bx\n\tpush cx\n\tpush dx\n\tor ax,ax\n \tjge enddif\n\tpush ax\n\tmov dl,'-'\n\tmov ah,2\n\tint 21h\n\tpop ax\n\tneg ax\nenddif:\n\txor cx,cx\n\tmov bx,10d\nrepeat:\n\txor dx,dx\n\tdiv bx\n\t push dx\n\tinc cx\n\tor ax,ax\n\tjne repeat\n\tmov ah,2\nprint_loop:\n\tpop dx\n\tor dl,30h\n\tint 21h\n\tloop print_loop\n\tpop dx\n\tpop cx\n\tpop bx\n\tpop ax\n\tret\n\nDEC_OUT  ENDP\n";

		asmout <<".model small\n.stack 100h\n\n.data\n" ; 

		for(int i = 0 ; i < dataSegment.size(); i++)
		{
			if(dataSegment[i].IdType == "VAR")
			{
					asmout << dataSegment[i].varName << " " << "   dw    ?\n" ; 
			}
			else if(dataSegment[i].IdType == "ARR")
			{
				asmout << dataSegment[i].varName << "   dw   " << dataSegment[i].initValue  << "    dup(?)  "  << endl ; 
			}
		}
}
	
	asmout << ".code" << endl ; 
	asmout << $$ -> assemblyCode << endl ; 
};

program : program unit
{
	plogout << "At line no: " << lineCount << " : "
			<< "program : program unit" << endl
			<< endl;

	plogout << $1->codeSegment << " " << $2->codeSegment << endl
			<< endl;

	SymbolInfo *x = new SymbolInfo();
	$$ = x;
	$$->codeSegment = $1->codeSegment + " " + $2->codeSegment;

	$$ -> assemblyCode = $1 -> assemblyCode ; 
	$$ -> assemblyCode += $2 -> assemblyCode ; 
}
| unit
{
	plogout << "At line no: " << lineCount << " : "
			<< "program : unit" << endl
			<< endl;

	plogout << $1->codeSegment << endl;
	$$ = $1;
};

unit : var_declaration
{
	plogout << "At line no: " << lineCount << " : "
			<< "unit : var_declaration" << endl
			<< endl;

	plogout << $1->codeSegment << endl
			<< endl;

	$$ = $1;
	
}
| func_declaration
{
	plogout << "At line no: " << lineCount << " : "
			<< "unit : func_declaration" << endl
			<< endl;

	plogout << $1->codeSegment << endl
			<< endl;

	$$ = $1;
}
| func_definition
{
	plogout << "At line no: " << lineCount << " : "
			<< "unit : func_definition" << endl
			<< endl;
	plogout << $1->codeSegment << endl
			<< endl;

	$$ = $1;
};

func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON
{
	plogout << "At line no: " << lineCount << " : "
			<< "func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON" << endl
			<< endl;

	plogout << $1->codeSegment << " " << $2->getSymbolName() << "(" << $4->codeSegment << ") ;" << endl << endl;

	//plogout << $1 -> getSymbolType() << endl<< $2 -> getSymbolName() << endl << endl ;

	SymbolInfo *tem = myTable->lookUpInCurr($2->getSymbolName(), "ID");

	if (tem == 0)
	{
		SymbolInfo *func = new SymbolInfo($2->getSymbolName(), "ID");
		func = myTable->insert(func);

		func->setIdType("FUNC");
		func->setFuncReturnType(varType);
		func->setParamNo(totalArgsNo);
		func->setParamList(Params);
		func->funcDeclared = true;
		initializeParam();
	}
	else
	{
		errorNo++;
		perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : ID \"" << $2->getSymbolName() << "\" has already been declared before in this scope." << endl
				<< endl;
		myTable->printAllScopeTable(perrout);
	}

	SymbolInfo *x = new SymbolInfo();
	$$ = x;
	$$->codeSegment = $1->codeSegment + " " + $2->getSymbolName() + "(" + $4->codeSegment + ") ;";

	//asmout << $$ -> assemblyCode << endl ; 
}
| type_specifier ID LPAREN RPAREN SEMICOLON
{
	plogout << "At line no: " << lineCount << " : "
			<< "func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON" << endl
			<< endl;

	plogout << $1->codeSegment << " " << $2->getSymbolName() << "("
			<< ") ;" << endl
			<< endl;

	SymbolInfo *tem = myTable->lookUpInCurr($2->getSymbolName(), "ID");

	if (tem == 0)
	{
		SymbolInfo *func = new SymbolInfo($2->getSymbolName(), "ID");
		func = myTable->insert(func);
		func->setIdType("FUNC");
		func->setFuncReturnType(varType);
		func->setParamNo(0);
		func->funcDeclared = true;
		initializeParam();
	}
	else
	{
		errorNo++;
		perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : ID \"" << $2->getSymbolName() << "\" has already been declared before in this scope." << endl
				<< endl;
		myTable->printAllScopeTable(perrout);
	}

	SymbolInfo *x = new SymbolInfo();
	$$ = x;
	$$->codeSegment = $1->codeSegment + " " + $2->getSymbolName() + "(" + ") ;";
};

func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement
{
	plogout << "At line no: " << lineCount << " : "
			<< "func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement" << endl
			<< endl;

	plogout << $1->codeSegment << " " << $2->getSymbolName() << "( " << $4->codeSegment << " ) " << endl
			<< $6->codeSegment << endl
			<< endl;

	//plogout << $2 -> getSymbolName() << endl << endl ;

	SymbolInfo *tem = myTable->lookUpInCurr($2->getSymbolName(), "ID");

	//cout << typeAndIDArgsNo << " " << totalArgsNo << endl ;

	if (tem == 0)
	{
		SymbolInfo *func = new SymbolInfo($2->getSymbolName(), "ID");
		func = myTable->insert(func);
		func->setIdType("FUNC");
		//cout << $1 -> getSymbolName() << endl ;
		func->setFuncReturnType($1->getSymbolName());
		func->setParamNo(totalArgsNo);
		func->setParamList(Params);
		func->setIsFuncDefined();



		initializeParam();
	}
	else if (tem->getIdType() != "FUNC")
	{
		errorNo++;
		perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : " << tem->getSymbolName() << " has been declared as " << tem->getIdType() << " so, can not be defined as function now." << endl
				<< endl;

		initializeParam();
	}
	else if (tem->funcDeclared == true && tem->getParamNo() != typeAndIDArgsNo)
	{
		errorNo++;
		perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : "
				<< " Argument number mismatch between Function definition and declaration of function " << $2->getSymbolName() << "." << endl
				<< endl;
		initializeParam();
	}
	else if (totalArgsNo != typeAndIDArgsNo)
	{
		errorNo++;
		perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : "
				<< " Parameter mismatch for Function " << $2->getSymbolName() << endl
				<< endl;

		initializeParam();
	}
	else
	{
		if (tem->checkIfFuncDefined() == true)
		{
			errorNo++;
			perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Function" << $2->getSymbolName() << " has been already defined." << endl
					<< endl;

			initializeParam();
		}
		else
		{
			// check if it's really function. not var/array
			if (tem->getFuncReturnType() != $1->getSymbolName())
			{
				errorNo++;
				perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Return Type of Function " << $2->getSymbolName() << " doesn't match." << endl
						<< endl;
				initializeParam();
			}
			else if (tem->getParamNo() != totalArgsNo)
			{
				errorNo++;
				perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : "
						<< " Parameter mismatch for Function " << $2->getSymbolName() << endl
						<< endl;

				initializeParam();
			}
			else if (tem->paramList.size() == Params.size())
			{
				bool err = false;

				for (int i = 0; i < tem->paramList.size(); i++)
				{
					//cout << "RUMMAN " << Params[i] -> getVarType() << " " << tem -> paramList[i] -> getVarType() << endl ;
					if (Params[i]->getVarType() != tem->paramList[i]->getVarType())
					{
						//cout << Params[i] -> getVarType() << " " << tem -> paramList[i] -> getVarType() << endl ;
						errorNo++;
						perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : "
								<< " Parameter mismatch for Function " << $2->getSymbolName() << "  because " << tem->paramList[i]->getVarType() << " doesn't match with " << Params[i]->getVarType() << "." << endl
								<< endl;
						err = true;

						initializeParam();
					}
				}
				if (err == false)
				{
					tem->setIdType("FUNC");
					tem->setFuncReturnType($1->getSymbolName());
					tem->setParamNo(totalArgsNo);
					tem->setParamList(Params);
					tem->setIsFuncDefined();
					//initializeParam();
				}
			}
		}
	}

	SymbolInfo *x = new SymbolInfo();
	$$ = x;

	$$->codeSegment = $1->codeSegment + " " + $2->getSymbolName() + "( " + $4->codeSegment + " ) " + "\n" + $6->codeSegment;

	


	 //type_specifier ID LPAREN parameter_list RPAREN compound_statement

	 $$ -> setAsmVarName($2 -> getSymbolName());

	$$ -> assemblyCode += $2 -> getSymbolName() + " PROC NEAR\n"; 
	$$ -> assemblyCode += $6 -> assemblyCode ; 

	if($2 -> getSymbolName() == "main")
	{
		$$->assemblyCode +="mov ah , 4ch\nint 21h\n";
	}
	else {
		
		$$ -> assemblyCode +=  retLabel + " : \n" ; 

		if(Params.size() != 0)
		{
			$$ -> assemblyCode += "pop bp\n";
		}
		
		$$ -> assemblyCode += "ret  " ; 
	

		if(2 * Params.size() != 0)
		{
			$$ -> assemblyCode +=  IntToString(2*Params.size()) + "\n" ;
		}
	}

	$$ -> assemblyCode += $2 -> getSymbolName() + " ENDP\n" ; 

	initializeParam();
	retLabel = "";

	asmout << "problem ..."  << $$ -> assemblyCode << endl ; 
	
}
| type_specifier ID LPAREN RPAREN compound_statement
{
	plogout << "At line no: " << lineCount << " : "
			<< "func_definition : type_specifier ID LPAREN RPAREN compound_statement" << endl
			<< endl;

	plogout << $1->codeSegment << " " << $2->getSymbolName() << "( ) " << endl
			<< $5->codeSegment << endl
			<< endl;

	//plogout << $2 -> getSymbolName() << endl << endl ;

	SymbolInfo *tem = myTable->lookUpInCurr($2->getSymbolName(), "ID");

	//cout << tem -> getParamNo() << " " << totalArgsNo << endl ;

	if (tem == 0)
	{
		SymbolInfo *func = new SymbolInfo($2->getSymbolName(), "ID");
		func = myTable->insert(func);
		func->setIdType("FUNC");
		func->setFuncReturnType($1->getSymbolName());
		func->setParamNo(0);
		func->setIsFuncDefined();

		initializeParam();

	SymbolInfo* x = new SymbolInfo();
	$$ = x ;

	$$->codeSegment = $1->codeSegment + " " + $2->getSymbolName() + "( ) \n" + $5->codeSegment;
	

	// type_specifier ID LPAREN RPAREN compound_statement

	 $$ -> setAsmVarName($2 -> getSymbolName());

	$$ -> assemblyCode += $2 -> getSymbolName() + " PROC NEAR\n"; 
	$$ -> assemblyCode += $5 -> assemblyCode ; 

	if($2 -> getSymbolName() == "main")
	{
		$$->assemblyCode +="mov ah , 4ch\nint 21h\n";
	}
	else {
		$$ -> assemblyCode +=  retLabel + " : \n" ; 

		$$ -> assemblyCode += "ret  " ; 
	
		if(2 * Params.size() != 0)
		{
			$$ -> assemblyCode +=  IntToString(2*Params.size()) + "\n" ;
		}
	}

	$$ -> assemblyCode += $2 -> getSymbolName() + "  ENDP\n" ; 

	initializeParam();
	retLabel = "";


	}
	else
	{
		if (tem->checkIfFuncDefined() == true)
		{
			errorNo++;
			perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Function" << $2->getSymbolName() << " has been already defined." << endl
					<< endl;

			initializeParam();
		}
		else
		{
			// check if it's really function. not var/array
			if (tem->getIdType() != "FUNC")
			{
				errorNo++;
				perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : " << $2->getSymbolName() << " has been already declared as Variable or Array." << endl
						<< endl;

				initializeParam();
			}
			else if (tem->getFuncReturnType() != $1->getSymbolName())
			{
				errorNo++;
				perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Return Type of Function " << $2->getSymbolName() << " doesn't match." << endl
						<< endl;
				initializeParam();
			}
			else if (tem->getParamNo() != totalArgsNo)
			{
				errorNo++;
				perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : "
						<< " Parameter mismatch for Function " << $2->getSymbolName() << endl
						<< endl;

				initializeParam();
			}
		}

			$$ = tem ;

	$$->codeSegment = $1->codeSegment + " " + $2->getSymbolName() + "( ) \n" + $5->codeSegment;
	

	// type_specifier ID LPAREN RPAREN compound_statement

	 $$ -> setAsmVarName($2 -> getSymbolName());

	$$ -> assemblyCode += $2 -> getSymbolName() + " PROC NEAR\n"; 
	$$ -> assemblyCode += $5 -> assemblyCode ; 

	if($2 -> getSymbolName() == "main")
	{
		$$->assemblyCode +="mov ah , 4ch\nint 21h\n";
	}
	else {
		$$ -> assemblyCode +=  retLabel + " : \n" ; 

		$$ -> assemblyCode += "ret  " ; 
	
		if(2 * Params.size() != 0)
		{
			$$ -> assemblyCode +=  IntToString(2*Params.size()) + "\n" ;
		}
	}

	$$ -> assemblyCode += $2 -> getSymbolName() + " ENDP\n" ; 

	initializeParam();
	retLabel = "";
	}

	


};

parameter_list : parameter_list COMMA type_specifier ID
{

	plogout << "At line no: " << lineCount << " : "
			<< "parameter_list  : parameter_list COMMA type_specifier ID" << endl
			<< endl;

	plogout << $1->codeSegment << " , " << $3->codeSegment << " " << $4->getSymbolName() << endl
			<< endl;

	totalArgsNo++;
	typeAndIDArgsNo++;

	SymbolInfo *tem = new SymbolInfo($4->getSymbolName(), "ID");
	tem->setIdType("VAR");

	tem->setVarType($3->getSymbolName());
	Params.push_back(tem);

	SymbolInfo *x = new SymbolInfo();
	$$ = x;
	$$->codeSegment = $1->codeSegment + " , " + $3->codeSegment + " " + $4->getSymbolName();
}
| parameter_list COMMA type_specifier
{

	totalArgsNo++;

	plogout << "At line no: " << lineCount << " : "
			<< "parameter_list  : parameter_list COMMA type_specifier" << endl
			<< endl;

	plogout << $1->codeSegment << " , " << $3->codeSegment << endl;

	SymbolInfo *tem = new SymbolInfo("#", "ID");
	tem->setIdType("VAR");
	tem->setVarType($3->getSymbolName());

	Params.push_back(tem);

	SymbolInfo *x = new SymbolInfo();
	$$ = x;
	$$->codeSegment = $1->codeSegment + " , " + $3->codeSegment;
}
| type_specifier ID
{
	plogout << "At line no: " << lineCount << " : "
			<< "parameter_list  : type_specifier ID" << endl
			<< endl;

	plogout << $1->codeSegment << " " << $2->getSymbolName() << endl
			<< endl;
	totalArgsNo++;
	typeAndIDArgsNo++;

	SymbolInfo *tem = new SymbolInfo($2->getSymbolName(), "ID");
	tem->setVarType($1->getSymbolName());
	tem->setIdType("VAR");
	Params.push_back(tem);

	SymbolInfo *x = new SymbolInfo();
	$$ = x;
	$$->codeSegment = $1->codeSegment + " " + $2->getSymbolName();
}
| type_specifier
{
	plogout << "At line no: " << lineCount << " : "
			<< "parameter_list  : type_specifier" << endl
			<< endl;

	plogout << $1->codeSegment << endl
			<< endl;

	totalArgsNo++;

	SymbolInfo *tem = new SymbolInfo("#", "ID");
	tem->setIdType("VAR");
	tem->setVarType($1->getSymbolName());

	Params.push_back(tem);

	SymbolInfo *x = new SymbolInfo();
	$$ = x;
	$$->codeSegment = $1->codeSegment;
};

compound_statement : LCURL
{
	plogout << "At line no: " << lineCount << " : "
			<< "compound_statement : LCURL statements RCURL" << endl
			<< endl;

	myTable->enterScope();
	for (int i = 0; i < Params.size(); i++)
	{
		if (Params[i]->getSymbolName() != "#")
		{
			SymbolInfo *t = myTable->insert(Params[i]);
			t->setIdType(Params[i]->getIdType());
			t->setVarType(Params[i]->getVarType());
		}
	}
}
statements
{
}
RCURL
{

	$$ = $3 ; 
	//asmout << $$ -> assemblyCode  << endl ; 

	$$->codeSegment = "{\n" + $3->codeSegment + "\n}\n";

	plogout << $$->codeSegment << endl
			<< endl;

	myTable->printAllScopeTable(plogout);
	plogout << endl
			<< endl;

	myTable->exitScope();
	plogout << "Scope exited" << endl
			<< endl;
}
| LCURL RCURL
{
	plogout << "At line no: " << lineCount << " : "
			<< "compound_statement : LCURL RCURL" << endl
			<< endl;

	plogout << "{ }" << endl
			<< endl;

	SymbolInfo *tem = new SymbolInfo();
	$$ = tem;
	$$->codeSegment = "{ }";
};

var_declaration : type_specifier declaration_list SEMICOLON
{
	plogout << "At line no: " << lineCount << " : "
			<< "var_declaration : type_specifier declaration_list SEMICOLON" << endl
			<< endl;

	plogout << $1->codeSegment << " " << $2->codeSegment << " ;" << endl
			<< endl;

	SymbolInfo *tem = new SymbolInfo();
	$$ = tem;

	$$->codeSegment = $1->codeSegment + " " + $2->codeSegment + " ;\n";
}
| type_specifier declaration_list error
{
	errorNo++;
	perrout << "Error No: " << errorNo << " at line no: " << lineCount << " ; missing." << endl
			<< endl;
};

type_specifier : INT
{
	plogout << "At line no: " << lineCount << " : "
			<< "type_specifier	: INT" << endl
			<< endl;

	plogout << "int" << endl
			<< endl;

	SymbolInfo *tem = new SymbolInfo("INT");
	$$ = tem;

	$$->codeSegment = "int";

	varType = "INT";
}
| FLOAT
{
	plogout << "At line no: " << lineCount << " : "
			<< "type_specifier	: FLOAT" << endl
			<< endl;

	plogout << "float" << endl
			<< endl;

	SymbolInfo *tem = new SymbolInfo("FLOAT");
	$$ = tem;

	$$->codeSegment = "float";

	varType = "FLOAT";
}
| VOID
{
	plogout << "At line no: " << lineCount << " : "
			<< "type_specifier	: VOID" << endl
			<< endl;

	plogout << "void" << endl
			<< endl;

	SymbolInfo *tem = new SymbolInfo("VOID");
	$$ = tem;

	$$->codeSegment = "void";

	varType = "VOID";
};

declaration_list : declaration_list COMMA ID
{

	plogout << "At line no: " << lineCount << " : "
			<< "declaration_list : declaration_list COMMA ID" << endl
			<< endl;

	plogout << $1->codeSegment << " , " << $3->getSymbolName() << endl
			<< endl;

	//plogout << $3 -> getSymbolName() << endl << endl ;

	if (varType == "VOID")
	{
		errorNo++;
		perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Variable \"" << $3->getSymbolName() << "\" can not be of type VOID." << endl
				<< endl;
	}
	else
	{
		SymbolInfo *tem = myTable->lookUpInCurr($3->getSymbolName(), "ID");

		if (tem == 0)
		{
			SymbolInfo *t = new SymbolInfo($3->getSymbolName(), "ID");

			t = myTable->insert(t);
			t->setVarType(varType);
			t->setIdType("VAR");
			char* temp = newTemp();
			t-> setAsmVarName(string(temp));
			dataSegment.push_back(Data(string(temp) , "VAR", "0"));
		}
		else
		{
			errorNo++;
			perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : ID \"" << $3->getSymbolName() << "\" has already been declared before in this scope." << endl
					<< endl;
		}
	}

	myTable->printAllScopeTable(plogout);

	plogout << endl
			<< endl;

	SymbolInfo *x = new SymbolInfo();

	$$ = x;
	$$->codeSegment = $1->codeSegment + " , " + $3->getSymbolName();

}
| declaration_list COMMA ID LTHIRD CONST_INT RTHIRD
{
	plogout << "At line no: " << lineCount << " : "
			<< "declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD" << endl
			<< endl;

	plogout << $1->codeSegment << " , " << $3->getSymbolName() << "[" << $5->getSymbolName() << "]" << endl
			<< endl;

	//plogout << $3 -> getSymbolName() << endl << $5 -> getSymbolName() << endl << endl ;

	if (varType == "VOID")
	{
		errorNo++;
		perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Array \"" << $3->getSymbolName() << "[]\" can not be of type VOID." << endl
				<< endl;
	}
	else
	{
		SymbolInfo *tem = myTable->lookUpInCurr($3->getSymbolName(), "ID");

		if (tem == 0)
		{
			int arraySize = stoi($5->getSymbolName());

			SymbolInfo *t = new SymbolInfo($3->getSymbolName(), "ID");

			t = myTable->insert(t);
			t->setArraySize(arraySize);
			t->fillArray();
			t->setVarType(varType);
			t->setIdType("ARR");

			char* temp = newTemp();
			t-> setAsmVarName(string(temp));
			dataSegment.push_back(Data(string(temp), "ARR", $5 -> getSymbolName()));
		}
		else
		{
			errorNo++;
			perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : ID \"" << $3->getSymbolName() << "\" has already been declared before in this scope." << endl
					<< endl;
		}
	}

	SymbolInfo *x = new SymbolInfo();
	$$ = x;
	$$->codeSegment = $1->codeSegment + " , " + $3->getSymbolName() + "[" + $5->getSymbolName() + "]";
}
| ID
{
	plogout << "At line no: " << lineCount << " : "
			<< "declaration_list : ID" << endl
			<< endl;

	plogout << $1->getSymbolName() << endl
			<< endl;

	if (varType == "VOID")
	{
		errorNo++;
		perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Variable \"" << $1->getSymbolName() << "\" can not be of type VOID." << endl
				<< endl;
	}
	else
	{
		SymbolInfo *tem = myTable->lookUpInCurr($1->getSymbolName(), "ID");

		if (tem == 0)
		{
			SymbolInfo *t = new SymbolInfo($1->getSymbolName(), "ID");
			t = myTable->insert(t);
			t->setVarType(varType);
			t->setIdType("VAR");

			char* temp = newTemp();
			t-> setAsmVarName(string(temp));
			dataSegment.push_back(Data(string(temp)  , "VAR", "0"));
		}
		else
		{
			errorNo++;
			perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : ID \"" << $1->getSymbolName() << "\" has already been declared before in this scope." << endl
					<< endl;
		}
	}

	SymbolInfo *x = new SymbolInfo();
	$$ = x;
	$$->codeSegment = $1->getSymbolName();
}
| ID LTHIRD CONST_INT RTHIRD
{
	plogout << "At line no: " << lineCount << " : "
			<< "declaration_list : ID LTHIRD CONST_INT RTHIRD" << endl
			<< endl;

	plogout << $1->getSymbolName() << "[" << $3->getSymbolName() << "]" << endl
			<< endl;

	if (varType == "VOID")
	{
		errorNo++;
		perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Array \"" << $1->getSymbolName() << "[]\" can not be of type VOID." << endl
				<< endl;
	}
	else
	{
		SymbolInfo *tem = myTable->lookUpInCurr($1->getSymbolName(), "ID");

		if (tem == 0)
		{
			int arraySize = stoi($3->getSymbolName());

			SymbolInfo *t = new SymbolInfo($1->getSymbolName(), "ID");

			t = myTable->insert(t);
			t->setVarType(varType);
			t->setIdType("ARR");
			t->setArraySize(arraySize);
			t->fillArray();

			char* temp = newTemp();
			t-> setAsmVarName(string(temp));
			dataSegment.push_back(Data(string(temp) , "ARR", $3 -> getSymbolName()));
		}
		else
		{
			errorNo++;
			perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : ID \"" << $1->getSymbolName() << "\" has already been declared before in this scope." << endl
					<< endl;
		}
	}

	SymbolInfo *x = new SymbolInfo();
	$$ = x;
	$$->codeSegment = $1->getSymbolName() + "[" + $3->getSymbolName() + "]";
};

statements : statement
{
	plogout << "At line no: " << lineCount << " : "
			<< "statements : statement" << endl
			<< endl;

	plogout << $1->codeSegment << endl
			<< endl;

	$$ = $1;
}
| statements statement
{
	plogout << "At line no: " << lineCount << " : "
			<< "statements : statements statement" << endl
			<< endl;

	plogout << $1->codeSegment << endl
			<< $2->codeSegment << endl;

	SymbolInfo *tem = new SymbolInfo();

	$$ = tem;
	$$->codeSegment = $1->codeSegment + " " + $2->codeSegment;

	$$ -> assemblyCode = $1 -> assemblyCode ; 
	$$ -> assemblyCode += $2 -> assemblyCode ; 
	//asmout << "statemnt  " << $2 -> assemblyCode << endl ; 
};

statement : var_declaration
{
	plogout << "At line no: " << lineCount << " : "
			<< "statement : var_declaration" << endl
			<< endl;

	plogout << $1->codeSegment << endl
			<< endl;

	$$ = $1; 
}
| expression_statement
{
	plogout << "At line no: " << lineCount << " : "
			<< "statement : expression_statement" << endl
			<< endl;

	plogout << $1->codeSegment << endl
			<< endl;

	$$ = $1;
}
| compound_statement
{
	plogout << "At line no: " << lineCount << " : "
			<< "statement : compound_statement" << endl
			<< endl;

	plogout << $1->codeSegment << endl
			<< endl;

	$$ = $1;
}
| FOR LPAREN expression_statement expression_statement expression RPAREN statement
{
	plogout << "At line no: " << lineCount << " : "
			<< "statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement" << endl
			<< endl;

	plogout << "for(" << $3->codeSegment << $4->codeSegment << $5->codeSegment << ")" << $7->codeSegment;

	$$ = $3;
	$$->codeSegment = "for(" + $3->codeSegment + $4->codeSegment + $5->codeSegment + ")" + $7->codeSegment;


	char *label1 = newLabel();
	char *label2 = newLabel();

	$$->assemblyCode += string(label1) + ":\n";
	$$->assemblyCode+=$4->assemblyCode;
	$$->assemblyCode+="mov ax , "+$4->getAsmVarName() +"\n";
	$$->assemblyCode+="cmp ax , 0\n";
	$$->assemblyCode+="je "+string(label2)+"\n";
	$$->assemblyCode+=$7->assemblyCode;
	$$->assemblyCode+=$5->assemblyCode;
	$$->assemblyCode+="jmp "+string(label1)+"\n";
	$$->assemblyCode+=string(label2)+":\n";

}
| IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE
{
	plogout << "At line no: " << lineCount << " : "
			<< "statement : IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE" << endl
			<< endl;

	plogout << "if(" << $3->codeSegment << ")" << $5->codeSegment << endl;

	$$ = $3;
	$$->codeSegment = "if(" + $3->codeSegment + ")" + $5->codeSegment;

	char* label = newLabel();
	$$ -> assemblyCode += "mov ax , " + $3 -> getAsmVarName() + " \n";
	$$ -> assemblyCode += "cmp ax , 0\n" ; 
	$$ -> assemblyCode += "je " + string(label) + "\n";
	$$ -> assemblyCode += $5 -> assemblyCode ; 
	$$ -> assemblyCode += string(label) + " : \n";
	  
	$$ -> setAsmVarName("if");
}
| IF LPAREN expression RPAREN statement ELSE statement
{
	plogout << "At line no: " << lineCount << " : "
			<< "statement : IF LPAREN expression RPAREN statement ELSE statement" << endl
			<< endl;

	plogout << "if (" << $3->codeSegment << ") " << $5->codeSegment << " else " << $7->codeSegment << endl
			<< endl;

	SymbolInfo *tem = new SymbolInfo();

	$$ = tem;
	$$->codeSegment = "if (" + $3->codeSegment + ") " + $5->codeSegment + " else " + $7->codeSegment;

	char* else_  = newLabel();
	char* exit_ = newLabel();

	$$ -> assemblyCode = $3 -> assemblyCode ; 
	$$ -> assemblyCode += "mov ax , " + $3 -> getAsmVarName() + "\n";
	$$ ->assemblyCode += "cmp ax , 0\n";
	$$ -> assemblyCode += "je " + string(else_) + "\n" ; 
	$$ -> assemblyCode += $5 -> assemblyCode ; 
	$$ -> assemblyCode += "jmp " + string(exit_); 

	$$ -> assemblyCode += string(else_) + " : \n"; 
	$$ -> assemblyCode += $7 -> assemblyCode ; 

	$$ -> assemblyCode += string(exit_) + " : \n" ; 

}
| WHILE LPAREN expression RPAREN statement
{
	plogout << "At line no: " << lineCount << " : "
			<< "statement : WHILE LPAREN expression RPAREN statement" << endl
			<< endl;

	plogout << "while(" << $3->codeSegment << ") " << $5->codeSegment << endl
			<< endl;

	SymbolInfo *tem = new SymbolInfo();
	$$ = tem;

	$$->codeSegment = "while(" + $3->codeSegment + ") " + $5->codeSegment;

	char* whileLabel = newLabel(); 
	char* exitLabel = newLabel();

	$$ -> assemblyCode = string(whileLabel) + " : \n"; 
	$$ -> assemblyCode += $3 -> assemblyCode ; 
	$$ -> assemblyCode += "mov ax , " + $3 -> getAsmVarName() ; 
	$$ -> assemblyCode += "cmp ax , 0\n";
	$$ -> assemblyCode += "je " + string(exitLabel) + "\n" ;

	$$ -> assemblyCode += $5 -> assemblyCode ; 
	$$ -> assemblyCode += "jmp " + string(whileLabel)  + "\n" ; 

	$$ -> assemblyCode += string(exitLabel) + " : \n" ; 

	$$ -> setAsmVarName("while") ; 

}
| PRINTLN LPAREN ID RPAREN SEMICOLON
{
	plogout << "At line no: " << lineCount << " : "
			<< "statement : PRINTLN LPAREN ID RPAREN SEMICOLON" << endl
			<< endl;

	plogout << "println(" << $3->getSymbolName() << ");\n"
			<< endl
			<< endl;

	SymbolInfo *tem = new SymbolInfo();
	$$ = tem;

	$$->codeSegment = "println(" + $3->getSymbolName() + ");\n";

	$$ -> assemblyCode += "mov ax , " + $3 -> getAsmVarName() + " \n " ; 
	$$ -> assemblyCode += "call DEC_OUT\n" ; 

}
| PRINTLN LPAREN ID RPAREN error
{
	errorNo++;
	perrout << "Error No: " << errorNo << " at line no: " << lineCount << " ; missing." << endl << endl;

}
| RETURN expression SEMICOLON
{
	plogout << "At line no: " << lineCount << " : "
			<< "statement : RETURN expression SEMICOLON" << endl
			<< endl;

	plogout << "return " << $2->codeSegment << " ;" << endl
			<< endl;

	SymbolInfo *tem = new SymbolInfo();
	$$ = tem;

	$$->codeSegment = "return " + $2->codeSegment + " ;";

	$$ -> assemblyCode = $2 -> assemblyCode ; 
	$$->assemblyCode+="\tmov dx , "+$2->getAsmVarName()+"\n";
	$$->assemblyCode+="\tjmp  "+string(retLabel)+"\n";

}
| RETURN expression error
{
	errorNo++;
	perrout << "Error No: " << errorNo << " at line no: " << lineCount << " ; missing." << endl
			<< endl;
};

expression_statement : SEMICOLON
{
	plogout << "At line no: " << lineCount << " : "
			<< "expression_statement 	: SEMICOLON" << endl
			<< endl;

	plogout << ";" << endl
			<< endl;

	SymbolInfo *x = new SymbolInfo();

	$$ = x;
	$$->codeSegment = ";\n";
	$$->assemblyCode="";
}
| expression SEMICOLON
{
	plogout << "At line no: " << lineCount << " : "
			<< "expression_statement 	: expression SEMICOLON" << endl
			<< endl;

	plogout << $1->codeSegment << ";" << endl
			<< endl;

	$$ = $1;
	$$->codeSegment = $1->codeSegment + ";\n";
}
| expression error
{
	errorNo++;
	perrout << "Error No: " << errorNo << " at line no: " << lineCount << " ; missing." << endl
			<< endl;
};

variable : ID
{
	plogout << "At line no: " << lineCount << " : "
			<< "variable : ID" << endl
			<< endl;

	plogout << $1->getSymbolName() << endl
			<< endl;

	SymbolInfo *tem = myTable->lookUp($1->getSymbolName(), "ID");

	if (tem == 0)
	{
		errorNo++;
		perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Variable \"" << $1->getSymbolName() << "\" was not declared before." << endl
				<< endl;
	}
	else
	{
		if (tem->getIdType() != "VAR")
		{

			//myTable -> printAllScopeTable(perrout) ;
			errorNo++;
			perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : " << $1->getSymbolName() << " was declared before as " << tem->getIdType() << ". So, it can not be used as a variable now." << endl
					<< endl;
		}
		else
		{
				$$ = tem ;
				$$->codeSegment = $1->getSymbolName();

				$$-> assemblyCode = "" ;
				$$ -> setAsmVarName(tem -> getAsmVarName() ) ;
		}
	}
	
}
| ID LTHIRD expression RTHIRD
{
	plogout << "At line no: " << lineCount << " : "
			<< "variable : ID LTHIRD expression RTHIRD" << endl
			<< endl;

	plogout << $1->getSymbolName() << "[" << $3->codeSegment << "]" << endl
			<< endl;

	SymbolInfo *tem = myTable->lookUp($1->getSymbolName(), "ID");

	if ($3->getVarType() == "FLOAT")
	{
		errorNo++;
		perrout << "Error No: " << errorNo << " at line no: " << lineCount << " Array index must be an integer." << endl
				<< endl;
	}
	else if (tem == 0)
	{
		errorNo++;
		perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Variable \"" << $1->getSymbolName() << "\" was not declared before." << endl
				<< endl;
	}
	else
	{
		if (tem->getIdType() != "ARR")
		{
			errorNo++;
			perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : " << $1->getSymbolName() << " was declared before as " << tem->getIdType() << ". So, it can not be used as an array now." << endl
					<< endl;
		}
		else
		{
			if (tem->arraySize <= $3->intVarValue)
			{
				errorNo++;
				perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Size of Array " << $1->getSymbolName() << " is " << tem->arraySize << ", so index " << $3->intVarValue << " can not be accessed." << endl
						<< endl;
			}
			else
			{
				$$ = tem;

				$$ -> assemblyCode = $3 -> assemblyCode ; 
				$$ -> assemblyCode += "mov bx , " + $3 -> getAsmVarName()  + "\n";
				$$ -> assemblyCode += "add bx , bx \n";
				$$ -> assemblyCode += "mov ax , " + tem -> getAsmVarName() + "[bx] \n"; 
				char* temp = newTemp();
				$$ -> assemblyCode += "mov " + string(temp) + " , ax\n"; 
				$$ -> setAsmVarName(string(temp) ) ;
				dataSegment.push_back(Data($$ -> getAsmVarName() , "VAR", "0"));
			}
		}
	}

		$$->codeSegment = $1->getSymbolName() + "[" + $3->codeSegment + "]";
	
};

expression : logic_expression
{
	plogout << "At line no: " << lineCount << " : "
			<< "expression : logic_expression" << endl
			<< endl;

	plogout << $1->codeSegment << endl
			<< endl;

	$$ = $1;
}
| variable ASSIGNOP logic_expression
{
	plogout << "At line no: " << lineCount << " : "
			<< "expression : variable ASSIGNOP logic_expression" << endl
			<< endl;

	plogout << $1->codeSegment << " = " << $3->codeSegment << endl
			<< endl;

	$$ = $1 ; 

	if ($1->getIdType() == "VAR")
	{
		if ($3->getIdType() == "VAR")
		{
			if ($1->getVarType() == "INT" && $3->getVarType() == "FLOAT")
			{
				warningNo++;
				perrout << "Warning No: " << warningNo << " at line no: " << lineCount << " : "
						<< " Float value is assigned to Int value (Type casting)." << endl
						<< endl;
			}
			else if ($1->getVarType() == "FLOAT" && $3->getVarType() == "INT")
			{
				warningNo++;
				perrout << "Warning No: " << warningNo << " at line no: " << lineCount << " : "
						<< " Int value is assigned to Float value (Type casting)." << endl
						<< endl;
			}
		}
		else if ($3->getIdType() == "ARR")
		{
			if ($1->getVarType() == "INT" && $3->getVarType() == "FLOAT")
			{
				warningNo++;
				perrout << "Warning No: " << warningNo << " at line no: " << lineCount << " : "
						<< " Float value is assigned to Int value (Type casting)." << endl
						<< endl;

			}
			else if ($1->getVarType() == "FLOAT" && $3->getVarType() == "INT")
			{
				warningNo++;
				perrout << "Warning No: " << warningNo << " at line no: " << lineCount << " : "
						<< " Int value is assigned to Float value (Type casting)." << endl
						<< endl;

			}
		}

		$$ -> assemblyCode = $3 -> assemblyCode + $1 -> assemblyCode ; 
		$$ -> assemblyCode += "mov ax , " + $3 -> getAsmVarName() + " \n";
		$$ -> assemblyCode += "mov  " +  $1 -> getAsmVarName() + " , ax\n";

		$$ -> setAsmVarName($1 -> getAsmVarName()) ; 

	}
	else if ($1->getIdType() == "ARR")
	{
		if ($3->getIdType() == "VAR")
		{
			if ($1->getVarType() == "INT" && $3->getVarType() == "FLOAT")
			{
				warningNo++;
				perrout << "Warning No: " << warningNo << " at line no: " << lineCount << " : "
						<< " Float value is assigned to Int value (Type casting)." << endl
						<< endl;

			}
			else if ($1->getVarType() == "FLOAT" && $3->getVarType() == "INT")
			{
				warningNo++;
				perrout << "Warning No: " << warningNo << " at line no: " << lineCount << " : "
						<< " Int value is assigned to Float value (Type casting)." << endl
						<< endl;
			}
		}
		else if ($3->getIdType() == "ARR")
		{
			if ($1->getVarType() == "INT" && $3->getVarType() == "FLOAT")
			{
				warningNo++;
				perrout << "Warning No: " << warningNo << " at line no: " << lineCount << " : "
						<< " Float value is assigned to Int value (Type casting)." << endl
						<< endl;

			}
			else if ($1->getVarType() == "FLOAT" && $3->getVarType() == "INT")
			{
				warningNo++;
				perrout << "Warning No: " << warningNo << " at line no: " << lineCount << " : "
						<< " Int value is assigned to Float value (Type casting)." << endl
						<< endl;

			}
		}


		$$ -> assemblyCode = $3 -> assemblyCode + $1 -> assemblyCode ; 
		$$ -> assemblyCode += "mov ax , " + $3 -> getAsmVarName() + "\n";
		$$ -> assemblyCode += "mov " +  $1 -> getAsmVarName() + "[bx] , ax\n";

		$$ -> setAsmVarName($1 -> getAsmVarName()) ; 

	}

	$$->codeSegment = $1->getSymbolName() + " = " + $3->codeSegment;
};

logic_expression : rel_expression
{
	plogout << "At line no: " << lineCount << " : "
			<< "logic_expression : rel_expression" << endl
			<< endl;

	plogout << $1->codeSegment << endl
			<< endl;

	$$ = $1;
}
| rel_expression LOGICOP rel_expression
{
	plogout << "At line no: " << lineCount << " : "
			<< "logic_expression : rel_expression LOGICOP rel_expression" << endl
			<< endl;

	plogout << $1->codeSegment << $2->getSymbolName() << $3->codeSegment << endl
			<< endl;

	SymbolInfo *tem = new SymbolInfo("", "ID");

	$$ = tem;

	tem->setVarType("INT");
	tem->setIdType("VAR");

	char * label1 = newLabel();
	char * label2 = newLabel();
	char * temp = newTemp();

	if ($2->getSymbolName() == "&&")
	{
		$$ -> assemblyCode = $1 -> assemblyCode ; 
	    $$ -> assemblyCode += $3 -> assemblyCode ; 

		$$ -> assemblyCode += "mov ax , " + $1 -> getAsmVarName() + " \n";
		$$ -> assemblyCode += "cmp ax , 0\n";
		$$ -> assemblyCode += "je " + string(label1) + "\n" ;
		$$ -> assemblyCode += "mov ax , " + $3 -> getAsmVarName() + " \n";
		$$ -> assemblyCode += "cmp ax , 0\n";
		$$ -> assemblyCode += "je " + string(label1);
		$$ -> assemblyCode += "mov " + string(temp) + " ,  1\n";
		$$ -> assemblyCode += "jmp " + string(label2) + "\n";
		$$ -> assemblyCode += string(label1) + " : \n"; 
		$$ -> assemblyCode += "mov " + string(temp) + " , 0\n";
		$$ -> assemblyCode += string(label2) + " : \n";

		$$ -> setAsmVarName(string(temp));

		dataSegment.push_back(Data(string(temp) , "VAR", "0"));

	}
	else if ($2->getSymbolName() == "||")
	{
		 
		$$ -> assemblyCode = $1 -> assemblyCode ; 
	    $$ -> assemblyCode += $3 -> assemblyCode ; 

		$$ -> assemblyCode += "mov ax , " + $1 -> getAsmVarName() + " \n";
		$$ -> assemblyCode += "cmp ax , 0\n";
		$$ -> assemblyCode += "jne " + string(label1) + "\n" ;
		$$ -> assemblyCode += "mov ax , " + $3 -> getAsmVarName() + " \n";
		$$ -> assemblyCode += "cmp ax , 0\n";
		$$ -> assemblyCode += "jne " + string(label1);
		$$ -> assemblyCode += "mov " + string(temp) + " ,  0\n";
		$$ -> assemblyCode += "jmp " + string(label2) + "\n";
		$$ -> assemblyCode += string(label1) + " : \n"; 
		$$ -> assemblyCode += "mov " + string(temp) + " , 1\n";
		$$ -> assemblyCode += string(label2) + " : \n";

		$$ -> setAsmVarName(string(temp));

		dataSegment.push_back(Data(string(temp) , "VAR", "0"));
 
	}

	tem->codeSegment = $1->codeSegment + $2->getSymbolName() + $3->codeSegment;
	
};

rel_expression : simple_expression
{
	plogout << "At line no: " << lineCount << " : "
			<< "rel_expression	: simple_expression" << endl
			<< endl;

	plogout << $1->codeSegment << endl
			<< endl;

	$$ = $1;
}
| simple_expression RELOP simple_expression
{
	plogout << "At line no: " << lineCount << " : "
			<< "rel_expression	: simple_expression RELOP simple_expression" << endl
			<< endl;

	plogout << $1->codeSegment << $2->getSymbolName() << $3->codeSegment << endl
			<< endl;


		char* temp = newTemp();
		char *label1=newLabel();
		char *label2=newLabel();

	if ($2->getSymbolName() == "==")
	{
		if ($1->getVarType() != $3->getVarType())
		{
			errorNo++;
			perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : "
					<< "Type mismatch on both side of == operator." << endl
					<< endl;
		}
		else
		{
			if ($1->getVarType() == "INT" && $3->getVarType() == "INT")
			{
				SymbolInfo *tem = new SymbolInfo("IIEQUAL", "ID");
				tem->setVarType("INT");
				tem->setIdType("VAR");
				tem->intVarValue = (int)($1->intVarValue == $3->intVarValue);
				$$ = tem;
			}
			if ($1->getVarType() == "FLOAT" && $3->getVarType() == "FLOAT")
			{
				SymbolInfo *tem = new SymbolInfo("FFEQUAL", "ID");
				tem->setVarType("INT");
				tem->setIdType("VAR");
				tem->intVarValue = (int)($1->floatVarValue == $3->floatVarValue);
				$$ = tem;
			}
		}


		$$ -> assemblyCode = $1 -> assemblyCode ; 
		$$ -> assemblyCode += $3 -> assemblyCode ; 
		
		$$ -> assemblyCode += "mov ax , " + $1 -> getAsmVarName()  + "\n" ; 
		$$ -> assemblyCode += "cmp ax , " + $3 -> getAsmVarName() + "\n" ; 

		$$ -> assemblyCode += "je " + string(label1) + "\n";

	}
	else if ($2->getSymbolName() == "!=")
	{
		if ($1->getVarType() != $3->getVarType())
		{
			errorNo++;
			perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : "
					<< "Type mismatch on both side of != operator." << endl
					<< endl;
		}
		else
		{
			if ($1->getVarType() == "INT" && $3->getVarType() == "INT")
			{
				SymbolInfo *tem = new SymbolInfo("IINotEQUAL", "ID");
				tem->setVarType("INT");
				tem->setIdType("VAR");
				$$ = tem;
			}
			if ($1->getVarType() == "FLOAT" && $3->getVarType() == "FLOAT")
			{
				SymbolInfo *tem = new SymbolInfo("FFNotEQUAL", "ID");
				tem->setVarType("INT");
				tem->setIdType("VAR");
				$$ = tem;
			}
		}

		$$ -> assemblyCode = $1 -> assemblyCode ; 
		$$ -> assemblyCode += $3 -> assemblyCode ; 
		
		$$ -> assemblyCode += "mov ax , " + $1 ->  getAsmVarName()  + "\n" ; 
		$$ -> assemblyCode += "cmp ax , " + $3 ->  getAsmVarName()   + "\n" ; 

		$$ -> assemblyCode += "jne " + string(label1) + "\n";

	}
	else if ($2->getSymbolName() == ">=")
	{
		$$ = relationOperator($1, $2, 1);

		$$ -> assemblyCode = $1 -> assemblyCode ; 
		$$ -> assemblyCode += $3 -> assemblyCode ; 
		
		$$ -> assemblyCode += "mov ax , " + $1 -> getAsmVarName()   + "\n" ; 
		$$ -> assemblyCode += "cmp ax , " + $3 -> getAsmVarName()   + "\n" ; 

		$$ -> assemblyCode += "jge " + string(label1) + "\n";
	}
	else if ($2->getSymbolName() == ">")
	{
		$$ = relationOperator($1, $2, 2);

		$$ -> assemblyCode = $1 -> assemblyCode ; 
		$$ -> assemblyCode += $3 -> assemblyCode ; 
		
		$$ -> assemblyCode += "mov ax , " + $1 -> getAsmVarName()   + "\n" ; 
		$$ -> assemblyCode += "cmp ax , " + $3 -> getAsmVarName()   + "\n" ; 

		$$ -> assemblyCode += "jg " + string(label1) + "\n";

	}
	else if ($2->getSymbolName() == "<=")
	{
		$$ = relationOperator($1, $2, 3);

		$$ -> assemblyCode = $1 -> assemblyCode ; 
		$$ -> assemblyCode += $3 -> assemblyCode ; 
		
		$$ -> assemblyCode += "mov ax , " + $1 -> getAsmVarName()   + "\n" ; 
		$$ -> assemblyCode += "cmp ax , " + $3 -> getAsmVarName()   + "\n" ; 

		$$ -> assemblyCode += "jle " + string(label1) + "\n";

	}
	else if ($2->getSymbolName() == "<")
	{
		$$ = relationOperator($1, $2, 4);

		$$ -> assemblyCode = $1 -> assemblyCode ; 
		$$ -> assemblyCode += $3 -> assemblyCode ; 
		
		$$ -> assemblyCode += "mov ax , " + $1 ->getAsmVarName()   + "\n" ; 
		$$ -> assemblyCode += "cmp ax , " + $3 ->getAsmVarName()   + "\n" ; 

		$$ -> assemblyCode += "jl " + string(label1) + "\n";
	}

	$$ -> assemblyCode += "mov " + string(temp) + " , 0\n"; 
	$$ -> assemblyCode += "jmp " + string(label2) + "\n";
	$$ -> assemblyCode += string(label1) + " :  \n" ; 
	$$ -> assemblyCode += "mov " + string(temp) + " , 1\n";

	$$ -> assemblyCode += string(label2) + " : \n";
	$$ -> setAsmVarName(string(temp));
	dataSegment.push_back(Data(string(temp) , "VAR", "0"));

	plogout << $1->codeSegment << $2->getSymbolName() << $3->codeSegment << endl
			<< endl;

	$$->codeSegment = $1->codeSegment + $2->getSymbolName() + $3->codeSegment;
};

simple_expression : term
{
	plogout << "At line no: " << lineCount << " : "
			<< "simple_expression : term" << endl
			<< endl;

	plogout << $1->codeSegment << endl
			<< endl;

	$$ = $1;
}
| simple_expression ADDOP term
{
	plogout << "At line no: " << lineCount << " : "
			<< "simple_expression : simple_expression ADDOP term" << endl
			<< endl;

	plogout << $1->codeSegment << $2->getSymbolName() << $3->codeSegment << endl
			<< endl;

	$$ = $1 ; 

	if ($2->getSymbolName() == "+")
	{
		$$ -> assemblyCode = $1 -> assemblyCode ; 
		$$ -> assemblyCode += $3 -> assemblyCode ; 

		char* temp = newTemp();
		$$ -> assemblyCode += "mov ax , " + $1 -> getAsmVarName() + "\n";
		$$ -> assemblyCode += "add ax , " + $3 -> getAsmVarName() + "\n";
		$$ -> assemblyCode += "mov " + string(temp) +  " , ax\n"; 
		dataSegment.push_back(Data(string(temp) , "VAR", "0"));
		$$ -> setAsmVarName(string(temp));
	}
	else if ($2->getSymbolName() == "-")
	{
		$$ -> assemblyCode = $1 -> assemblyCode ; 
		$$ -> assemblyCode += $3 -> assemblyCode ; 

		char* temp = newTemp();
		$$ -> assemblyCode += "mov ax , " + $1 -> getAsmVarName() + "\n";
		$$ -> assemblyCode += "sub ax , " + $3 -> getAsmVarName() + "\n";
		$$ -> assemblyCode += "mov " + string(temp) + " , ax \n"; 
		dataSegment.push_back(Data(string(temp) , "VAR", "0"));
		$$ -> setAsmVarName(string(temp));
	}

	//plogout << $1 -> codeSegment << " " << $2 -> getSymbolName() << $3 -> codeSegment ;

	$$->codeSegment = $1->codeSegment + $2->getSymbolName() + $3->codeSegment;
};

term : unary_expression
{
	plogout << "At line no: " << lineCount << " : "
			<< "term :	unary_expression" << endl
			<< endl;
	$$ = $1;
}
| term MULOP unary_expression
{
	plogout << "At line no: " << lineCount << " : "
			<< "term :	term MULOP unary_expression" << endl
			<< endl;

	plogout << $1->codeSegment << " " << $2->getSymbolName() << $3->codeSegment << endl
			<< endl;

	if ($2->getSymbolName() == "*")
	{

		if ($1->getIdType() == "VAR" && $3->getIdType() == "VAR")
		{
			if ($1->getVarType() == "INT" && $3->getVarType() == "INT")
			{
				$$ = VVIIM($1, $3);
			}
			else if ($1->getVarType() == "INT" && $3->getVarType() == "FLOAT")
			{
				$$ = VVIFM($1, $3);
			}
			else if ($1->getVarType() == "FLOAT" && $3->getVarType() == "INT")
			{
				$$ = VVFIM($1, $3);
			}
			else if ($1->getVarType() == "FLOAT" && $3->getVarType() == "FLOAT")
			{
				$$ = VVFFM($1, $3);
			}
		}
		else if ($1->getIdType() == "VAR" && $3->getIdType() == "ARR")
		{
			if ($1->getVarType() == "INT" && $3->getVarType() == "INT")
			{
				$$ = VAIIM($1, $3);
			}
			else if ($1->getVarType() == "INT" && $3->getVarType() == "FLOAT")
			{
				$$ = VAIFM($1, $3);
			}
			else if ($1->getVarType() == "FLOAT" && $3->getVarType() == "INT")
			{
				$$ = VAFIM($1, $3);
			}
			else if ($1->getVarType() == "FLOAT" && $3->getVarType() == "FLOAT")
			{
				$$ = VAFFM($1, $3);
			}
		}
		else if ($1->getIdType() == "ARR" && $3->getIdType() == "VAR")
		{
			if ($1->getVarType() == "INT" && $3->getVarType() == "INT")
			{
				$$ = AVIIM($1, $3);
			}
			else if ($1->getVarType() == "INT" && $3->getVarType() == "FLOAT")
			{
				$$ = AVIFM($1, $3);
			}
			else if ($1->getVarType() == "FLOAT" && $3->getVarType() == "INT")
			{
				$$ = AVFIM($1, $3);
			}
			else if ($1->getVarType() == "FLOAT" && $3->getVarType() == "FLOAT")
			{
				$$ = AVFFM($1, $3);
			}
		}
		else if ($1->getIdType() == "ARR" && $3->getIdType() == "ARR")
		{
			if ($1->getVarType() == "INT" && $3->getVarType() == "INT")
			{
				$$ = AAIIM($1, $3);
			}
			else if ($1->getVarType() == "INT" && $3->getVarType() == "FLOAT")
			{
				$$ = AAIFM($1, $3);
			}
			else if ($1->getVarType() == "FLOAT" && $3->getVarType() == "INT")
			{
				$$ = AAFIM($1, $3);
			}
			else if ($1->getVarType() == "FLOAT" && $3->getVarType() == "FLOAT")
			{
				$$ = AAFFM($1, $3);
			}
		}

		char* temp = newTemp();
		$$ -> assemblyCode =  $1 -> assemblyCode + $3 -> assemblyCode ; 
		$$ -> assemblyCode += "mov ax , " + $1 -> getAsmVarName() + "\n";
		$$ -> assemblyCode += "mov bx , " + $3 -> getAsmVarName() + "\n"; 
		$$ -> assemblyCode += "mul bx\n";
		$$ -> assemblyCode += "mov " + string(temp) + " , ax\n";
		dataSegment.push_back(Data(string(temp) , "VAR", "0"));
		$$ -> setAsmVarName(string(temp));


	}
	else if ($2->getSymbolName() == "/")
	{
		if ($1->getIdType() == "VAR" && $3->getIdType() == "VAR")
		{
			if ($1->getVarType() == "INT" && $3->getVarType() == "INT")
			{
				$$ = VVIID($1, $3);
			}
			else if ($1->getVarType() == "INT" && $3->getVarType() == "FLOAT")
			{
				$$ = VVIFD($1, $3);
			}
			else if ($1->getVarType() == "FLOAT" && $3->getVarType() == "INT")
			{
				$$ = VVFID($1, $3);
			}
			else if ($1->getVarType() == "FLOAT" && $3->getVarType() == "FLOAT")
			{
				$$ = VVFFD($1, $3);
			}
		}
		else if ($1->getIdType() == "VAR" && $3->getIdType() == "ARR")
		{
			if ($1->getVarType() == "INT" && $3->getVarType() == "INT")
			{
				$$ = VAIID($1, $3);
			}
			else if ($1->getVarType() == "INT" && $3->getVarType() == "FLOAT")
			{
				$$ = VAIFD($1, $3);
			}
			else if ($1->getVarType() == "FLOAT" && $3->getVarType() == "INT")
			{
				$$ = VAFID($1, $3);
			}
			else if ($1->getVarType() == "FLOAT" && $3->getVarType() == "FLOAT")
			{
				$$ = VAFFD($1, $3);
			}
		}
		else if ($1->getIdType() == "ARR" && $3->getIdType() == "VAR")
		{
			if ($1->getVarType() == "INT" && $3->getVarType() == "INT")
			{
				$$ = AVIID($1, $3);
			}
			else if ($1->getVarType() == "INT" && $3->getVarType() == "FLOAT")
			{
				$$ = AVIFD($1, $3);
			}
			else if ($1->getVarType() == "FLOAT" && $3->getVarType() == "INT")
			{
				$$ = AVFID($1, $3);
			}
			else if ($1->getVarType() == "FLOAT" && $3->getVarType() == "FLOAT")
			{
				$$ = AVFFD($1, $3);
			}
		}
		else if ($1->getIdType() == "ARR" && $3->getIdType() == "ARR")
		{
			if ($1->getVarType() == "INT" && $3->getVarType() == "INT")
			{
				$$ = AAIID($1, $3);
			}
			else if ($1->getVarType() == "INT" && $3->getVarType() == "FLOAT")
			{
				$$ = AAIFD($1, $3);
			}
			else if ($1->getVarType() == "FLOAT" && $3->getVarType() == "INT")
			{
				$$ = AAFID($1, $3);
			}
			else if ($1->getVarType() == "FLOAT" && $3->getVarType() == "FLOAT")
			{
				$$ = AAFFD($1, $3);
			}
		}


		char* temp = newTemp();
		$$ -> assemblyCode =  $1 -> assemblyCode + $3 -> assemblyCode ; 
		$$ -> assemblyCode += "xor dx , dx\n";
		$$ -> assemblyCode += "mov ax , " + $1 -> getAsmVarName() + "\n";
		$$ -> assemblyCode += "mov bx , " + $3 -> getAsmVarName() + "\n"; 
		$$ -> assemblyCode += "div bx\n";
		$$ -> assemblyCode += "mov " + string(temp) + " , ax\n";
		dataSegment.push_back(Data(string(temp) , "VAR", "0"));
		$$ -> setAsmVarName(string(temp));

	}

	else if ($2->getSymbolName() == "%")
	{
		if ($1->getIdType() == "VAR" && $3->getIdType() == "VAR")
		{
			if ($1->getVarType() == "INT" && $3->getVarType() == "INT")
			{
				$$ = VVIIMOD($1, $3);
			}
			else
			{
				modNotBothIntError();
			}
		}
		else if ($1->getIdType() == "VAR" && $3->getIdType() == "ARR")
		{
			if ($1->getVarType() == "INT" && $3->getVarType() == "INT")
			{
				$$ = VAIIMOD($1, $3);
			}
			else
			{
				modNotBothIntError();
			}
		}
		else if ($1->getIdType() == "ARR" && $3->getIdType() == "VAR")
		{
			if ($1->getVarType() == "INT" && $3->getVarType() == "INT")
			{
				$$ = AVIIMOD($1, $3);
			}
			else
			{
				modNotBothIntError();
			}
		}
		else if ($1->getIdType() == "ARR" && $3->getIdType() == "ARR")
		{
			if ($1->getVarType() == "INT" && $3->getVarType() == "INT")
			{
				$$ = AAIIMOD($1, $3);
			}
			else
			{
				modNotBothIntError();
			}
		}

		char* temp = newTemp();
		$$ -> assemblyCode =  $1 -> assemblyCode + $3 -> assemblyCode ; 
		$$ -> assemblyCode += "xor dx , dx\n";
		$$ -> assemblyCode += "mov ax , " + $1 -> getAsmVarName() + "\n";
		$$ -> assemblyCode += "mov bx , " + $3 -> getAsmVarName() + "\n"; 
		$$ -> assemblyCode += "div bx\n";
		$$ -> assemblyCode += "mov " + string(temp) + " , dx\n";
		dataSegment.push_back(Data(string(temp) , "VAR", "0"));
		$$ -> setAsmVarName(string(temp));


	}

	//plogout << $1 -> codeSegment << " " << $2 -> getSymbolName() << $3 -> codeSegment << endl << endl ;

	$$->codeSegment = $1->codeSegment + $2->getSymbolName() + $3->codeSegment;
};

unary_expression : ADDOP unary_expression
{
	plogout << "At line no: " << lineCount << " : "
			<< "unary_expression : ADDOP unary_expression " << endl
			<< endl;

	plogout << $1->getSymbolName() << $2->codeSegment << endl
			<< endl;

	SymbolInfo *tem = $2;

	tem->codeSegment = $1->getSymbolName() + $2->codeSegment;

	if ($1->getSymbolName() == "-")
	{
		char* temp = newTemp();
		$2 -> assemblyCode += "mov ax , " + $2 -> getAsmVarName() + "\n";
		$2 -> assemblyCode += "neg ax\n" ; 
		$2 -> assemblyCode += "mov " + string(temp) + " , ax\n"; 
		$2 -> setAsmVarName(string(temp));

		dataSegment.push_back(Data(string(temp) , "VAR", "0"));
		//asmout << $2 -> assemblyCode << endl ; 

			if (tem->getVarType() == "CHAR")
			{
				errorNo++;
				perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Can not put " << $1->getSymbolName() << "operator before Char variable \"" << $2->getSymbolName() << endl
						<< endl;
			}
	}
	else if ($1->getSymbolName() == "+")
	{
			if (tem->getVarType() == "CHAR")
			{
				errorNo++;
				perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Can not put " << $1->getSymbolName() << "operator before Char variable \"" << $2->getSymbolName() << endl
						<< endl;
			}
	}

	$$ = tem;
}
| NOT unary_expression
{
	plogout << "At line no: " << lineCount << " : "
			<< "unary_expression : NOT unary_expression" << endl
			<< endl;

	plogout << "!" << $2->codeSegment << endl
			<< endl;

	SymbolInfo *tem = $2;

		char* temp = newTemp();
		$2 -> assemblyCode += "mov ax , " + $2 -> getAsmVarName() + "\n";
		$2 -> assemblyCode += "not ax\n" ; 
		$2 -> assemblyCode += "mov " + string(temp) + " , ax\n"; 
		$2 -> setAsmVarName(string(temp));

		dataSegment.push_back(Data(string(temp) , "VAR", "0"));
		//asmout << $2 -> assemblyCode << endl ; 

		tem->codeSegment = "!" + $2->codeSegment;

		$$ = tem;
}
| factor
{
	plogout << "At line no: " << lineCount << " : "
			<< "unary_expression : NOT unary_expression" << endl
			<< endl;

	plogout << $1->codeSegment << endl
			<< endl;

	$$ = $1;
};

factor : variable
{
	$$ = $1;
	plogout << "At line no: " << lineCount << " : "
			<< "factor	: variable " << endl
			<< endl;

			plogout << $1->codeSegment << endl
			<< endl;

			if($1 -> getIdType() == "ARR")
			{
				char* temp = newTemp();
				$1 -> assemblyCode +=  "mov ax , " + $1 -> getAsmVarName() + "[bx]\n" ;
				$1 -> assemblyCode += "mov "+string(temp)+ " , ax\n" ; 
				$1 -> setAsmVarName(string(temp));

				dataSegment.push_back(Data(string(temp) , "VAR" , "0"));
			}
}
| ID LPAREN argument_list RPAREN
{
	plogout << "At line no: " << lineCount << " : "
			<< "factor	: ID LPAREN argument_list RPAREN  " << endl
			<< endl;

	plogout << $1->getSymbolName() << "(" << $3->codeSegment << ")" << endl
			<< endl;

	SymbolInfo *tem = myTable->lookUp($1->getSymbolName(), "ID");
	//cout << tem -> getSymbolName() << " " <<  tem -> getFuncReturnType() << endl ;

	//cout << passedParamNo << endl ;
	if (tem == 0)
	{
		errorNo++;
		perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Function \"" << $1->getSymbolName() << "\" wasn't declared before." << endl
				<< endl;
	}
	if (tem->isFuncDefined == false)
	{
		errorNo++;
		perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Undefined call to Function " << $1->getSymbolName() << "." << endl
				<< endl;
	}
	if (passedParamNo < tem->getParamNo())
	{
		errorNo++;
		perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Too few arguments for function " << $1->getSymbolName() << "." << endl
				<< endl;
		passedParamNo = 0;
	}
	if (passedParamNo > tem->getParamNo())
	{
		errorNo++;
		perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Too many arguments for function " << $1->getSymbolName() << "." << endl
				<< endl;
		passedParamNo = 0;
	}
	else
	{
		if (tem->getIdType() != "FUNC")
		{
			errorNo++;
			perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Function \"" << $1->getSymbolName() << "\" wasn't declared before." << endl
					<< endl;
		}
		else
		{
			if (tem->getFuncReturnType() == "VOID")
			{
				//cout << "RUMMAN" << endl ;
				errorNo++;
				perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Return type of function \"" << $1->getSymbolName() << "\" is void. So, it can not be called to return a value." << endl
						<< endl;
			}
			else
			{
				SymbolInfo *t = new SymbolInfo("Factor", "ID");

				if (tem->getFuncReturnType() == "INT")
				{
					t->intVarValue = 0;
				}
				else if (tem->getFuncReturnType() == "FLOAT")
				{
					t->floatVarValue = 0;
				}
				else if (tem->getFuncReturnType() == "CHAR")
				{
					t->charVarValue = '\0';
				}

				t->codeSegment = t->codeSegment + $1->getSymbolName() + "(" + $3->codeSegment + ")";

				$$ = t;
			}
		}
	}
}
| LPAREN expression RPAREN
{
	plogout << "At line no: " << lineCount << " : "
			<< "factor	: LPAREN expression RPAREN " << endl
			<< endl;

	plogout << "(" << $2->codeSegment << ")" << endl
			<< endl;

	$2->codeSegment = "(" + $2->codeSegment + ")";

	$$ = $2;
}
| CONST_INT
{
	plogout << "At line no: " << lineCount << " : "
			<< "factor	: CONST_INT " << endl
			<< endl;

	plogout << $1->getSymbolName() << endl
			<< endl;

	SymbolInfo *tem = $1;
	tem->setVarType("INT");
	tem->setIdType("VAR");

	tem->codeSegment = tem->codeSegment + $1->getSymbolName();

	tem -> asmVarName = tem->getSymbolName() ; 
	$$ = tem;
}
| CONST_FLOAT
{
	plogout << "At line no: " << lineCount << " : "
			<< "factor	: CONST_FLOAT " << endl
			<< endl;

	plogout << $1->getSymbolName() << endl
			<< endl;

	SymbolInfo *tem = $1;
	tem->setVarType("FLOAT");
	tem->setIdType("VAR");

	tem->codeSegment = tem->codeSegment + $1->getSymbolName();

	tem -> asmVarName = tem->getSymbolName() ; 

	$$ = tem;
}
| variable INCOP
{
	plogout << "At line no: " << lineCount << " : "
			<< "factor	: variable INCOP " << endl
			<< endl;

	plogout << $1->codeSegment << "++" << endl
			<< endl;

	SymbolInfo *tem = $1;
	$$ = tem;

	if (tem->getIdType() == "VAR")
	{
		if (tem->getVarType() == "INT")
		{
			$$ -> assemblyCode += "mov ax , " + $1 -> getAsmVarName() + "\n" ; 
			$$ -> assemblyCode += "inc ax\n"; 
			$$ -> assemblyCode += "mov " + $1 -> getAsmVarName() + " , ax\n" ; 
			$$ -> setAsmVarName($1 -> getAsmVarName());
		}
	}
	else if (tem->getIdType() == "ARR")
	{
		if (tem->getVarType() == "INT")
		{
			char* temp = newTemp();
			$$ -> assemblyCode += "mov ax , " + $1 -> getAsmVarName() + "[bx]\n"; 
			$$ -> assemblyCode += "inc ax\n";
			$$ -> assemblyCode += "mov " + $1 -> getAsmVarName() + "[bx] , ax\n" ; 
			$$ -> assemblyCode += "mov " + string(temp) + " ,  " + $1 -> getAsmVarName() + "[bx]\n"; 
			$$ -> setAsmVarName(string(temp)); 
			dataSegment.push_back(Data(string(temp)  , "VAR", "0"));
		}
	}

	//asmout << "incop  " <<  $$ -> assemblyCode << endl ; 

	tem->codeSegment = tem->codeSegment + "++";
}
| variable DECOP
{
	plogout << "At line no: " << lineCount << " : "
			<< "factor	: variable DECOP " << endl
			<< endl;

	plogout << $1->codeSegment << "--" << endl
			<< endl;

	SymbolInfo *tem = $1;
	$$ = tem;


	if (tem->getIdType() == "VAR")
	{
		if (tem->getVarType() == "INT")
		{
			$$ -> assemblyCode += "mov ax , " + $1 -> getAsmVarName() + "\n" ; 
			$$ -> assemblyCode += "dec ax\n"; 
			$$ -> assemblyCode += "mov " + $1 -> getAsmVarName() + "  ,  ax\n" ; 
			$$ -> setAsmVarName($1 -> getAsmVarName());
		}
	}
	else if (tem->getIdType() == "ARR")
	{
		if (tem->getVarType() == "INT")
		{
			char* temp = newTemp();
			$$ -> assemblyCode += "mov ax , " + $1 -> getAsmVarName() + "[bx]\n"; 
			$$ -> assemblyCode += "dec ax\n";
			$$ -> assemblyCode += "mov " + $1 -> getAsmVarName() + "[bx] , ax\n" ; 
			$$ -> assemblyCode += "mov " + string(temp) + " ,  " + $1 -> getAsmVarName() + "[bx]\n"; 
			$$ -> setAsmVarName(string(temp)); 
		  	dataSegment.push_back(Data(string(temp)  , "VAR", "0"));
		}
	}

	tem->codeSegment = tem->codeSegment + $1->codeSegment + "--";
};

argument_list : arguments
{
	plogout << "At line no: " << lineCount << " : "
			<< "argument_list : arguments" << endl
			<< endl;

	plogout << $1->codeSegment << endl
			<< endl;

	$$ = $1;
}
|
{
	initializeParam();
	SymbolInfo *x = new SymbolInfo();

	$$ = x;
	$$->codeSegment = " ";
};

arguments : arguments COMMA logic_expression
{
	plogout << "At line no: " << lineCount << " : "
			<< "arguments : arguments COMMA logic_expression " << endl
			<< endl;
	passedParamNo++;

	plogout << $1->codeSegment << " , " << $3->codeSegment << endl
			<< endl;

	SymbolInfo *x = new SymbolInfo();

	$$ = x;
	$$->codeSegment = $1->codeSegment + "," + $3->codeSegment;
}
| logic_expression
{
	plogout << "At line no: " << lineCount << " : "
			<< "arguments : logic_expression" << endl
			<< endl;

	plogout << $1->codeSegment << endl;

	passedParamNo++;

	$$ = $1;

};

%%

int main(int argc, char *argv[])
{
	FILE *fp;

	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		printf("Cannot Open Input File No. 1.\n");
		exit(1);
	}

	asmout.open("assembly.asm");
	plogout.open("plog.txt");
	perrout.open("perror.txt");

	//asmout << "gkh" << endl ; 

	yyin = fp;
	yyparse();

	plogout.close();
	perrout.close();
	asmout.close();

	return 0;
}
