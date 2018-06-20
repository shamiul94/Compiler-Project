%{
#include<bits/stdc++.h>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include "SymbolTable.h"

using namespace std;

int yyparse(void);
int yylex(void);
extern FILE *yyin;

string varType; 

SymbolTable *myTable = new SymbolTable(11);

ofstream plogout, perrout ; 

int errorNo =  -1 , totalArgsNo = 0 , typeAndIDArgsNo = 0; 

vector<SymbolInfo*> Params ; 

extern int lineCount; 

int stoi(std::string s) //The conversion function
{
    return atoi(s.c_str());
}

float stof(string s) //The conversion function
{
    return atof(s.c_str());
}



void yyerror(const char *s)
{
	//write your code
}


void initializeParam()
{
	Params.clear(); 
	totalArgsNo = 0 ; 
	typeAndIDArgsNo = 0 ;
}


%}
%union{
	SymbolInfo *s; 
}


%token IF ELSE FOR WHILE DO BREAK INT CHAR FLOAT DOUBLE VOID RETURN SWITCH CASE DEFAULT CONTINUE INCOP DECOP ASSIGNOP BITOP NOT LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD COMMA SEMICOLON PRINTLN COMMENT ERROR

%token <s> ID CONST_INT CONST_STRING CONST_FLOAT CONST_CHAR ADDOP MULOP LOGICOP RELOP

%type <s> term unary_expression factor variable type_specifier expression logic_expression rel_expression simple_expression 


%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%error-verbose
%%
start : program
		{
			plogout << "At line no: " << lineCount << " : " << "start : program" << endl << endl ; 
		};

program : program unit
		  {
				plogout << "At line no: " << lineCount << " : " << "program : program unit" << endl << endl ; 
		  }
	      | unit
	      {
	      	plogout << "At line no: " << lineCount << " : " << "program : unit" << endl << endl ;
	      }
	      ;
	
unit : var_declaration
		{
		plogout << "At line no: " << lineCount << " : " << "unit : var_declaration" << endl << endl ;
		}
     | func_declaration {
		plogout << "At line no: " << lineCount << " : " << "unit : func_declaration" << endl << endl ;
		}
     | func_definition {
		plogout << "At line no: " << lineCount << " : " << "unit : func_definition" << endl << endl ;
		}
     ;
     
func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON {
		plogout << "At line no: " << lineCount << " : " << "func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON" << endl << endl ;

		plogout << $1 -> getSymbolType() << endl<< $2 -> getSymbolName() << endl << endl ; 

		SymbolInfo* tem = myTable -> lookUpInCurr($2 -> getSymbolName(), "ID");

		if(tem == 0)
		{
			SymbolInfo* func = new SymbolInfo($2 -> getSymbolName(), "ID");
			func = myTable -> insert(func); 

			func -> setIdType("FUNC");
			func -> setFuncReturnType(varType);
			func -> setParamNo(totalArgsNo);
			func -> setParamList(Params);
			initializeParam();
		}
		else 
		{
			errorNo++;
			perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : ID \"" << $2 -> getSymbolName() << "\" has already been declared before in this scope." << endl << endl ; 
		}


		}
		| type_specifier ID LPAREN RPAREN SEMICOLON {
		plogout << "At line no: " << lineCount << " : " << "func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON" << endl << endl ;

		plogout << $1 -> getSymbolName() << endl<< $2 -> getSymbolName() << endl << endl ; 

		SymbolInfo* tem = myTable -> lookUpInCurr($2 -> getSymbolName(), "ID");

		if(tem == 0)
		{
			SymbolInfo* func = new SymbolInfo($2 -> getSymbolName(), "ID");
			func = myTable -> insert(func); 
			func -> setIdType("FUNC");
			func -> setFuncReturnType(varType);
			func -> setParamNo(0);
			func -> setParamList(Params);
			
			initializeParam();
 
		}
		else 
		{
			errorNo++;
			perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : ID \"" << $2 -> getSymbolName() << "\" has already been declared before in this scope." << endl << endl ; 
		}
		}
		;
		 
func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement {
		plogout << "At line no: " << lineCount << " : " << "func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement" << endl << endl ;

		plogout << $2 -> getSymbolName() << endl << endl ; 

		SymbolInfo* tem = myTable -> lookUpInCurr($2 -> getSymbolName(), "ID");



		if(totalArgsNo != typeAndIDArgsNo)
		{
			errorNo++;
			perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : " << " Parameter mismatch for Function "<< $2->getSymbolName() << endl << endl;

			initializeParam(); 
		}
		

		if(tem == 0)
		{
			SymbolInfo* func = new SymbolInfo($2 -> getSymbolName(), "ID");
			func = myTable -> insert(func);
			func -> setIdType("FUNC");
			func -> setFuncReturnType(varType);
			func -> setParamNo(totalArgsNo);
			func -> setParamList(Params);
			func -> setIsFuncDefined();

			initializeParam(); 
		}
		else 
		{
			if(tem -> checkIfFuncDefined() == true)
			{
				errorNo++;
				perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Function" << $2->getSymbolName() <<  " has been already defined."<<  << endl << endl;

				initializeParam();
			}
			else  
			{
				// check if it's really function. not var/array
				if(tem -> getIdType() != "FUNC")
				{
					errorNo++;
					perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : " << $2->getSymbolName() <<  " has been already declared as Variable or Array."<<  << endl << endl; 

					initializeParam();
				}
				else if(tem -> getFuncReturnType() != varType)
				{
					errorNo++;
					perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Return Type of Function " << $2->getSymbolName() <<  " doesn't match."<<  << endl << endl; 
					initializeParam();
				}
				else if(tem -> getParamNo() != totalArgsNo)
				{
					errorNo++;
					perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : " << " Parameter mismatch for Function "<< $2->getSymbolName() << endl << endl;

					initializeParam();
				}
				else if(tem -> paramList.size() == Params.size())
				{
					for(int i = 0 ; i < tem -> paramList.size(); i++)
					{
						if(Params[i] -> getVarType() != tem -> paramList[i] -> getVarType());
						{
							errorNo++;
							perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : " << " Parameter mismatch for Function "<< $2->getSymbolName() << " because " <<  tem -> paramList[i] -> getVarType() << "doesn't match with " << Params[i] -> getVarType() << endl << endl;

							initializeParam();
						}
					}
				}
			}
		}


		}
		| type_specifier ID LPAREN RPAREN compound_statement {
		plogout << "At line no: " << lineCount << " : " << "func_definition : type_specifier ID LPAREN RPAREN compound_statement" << endl << endl ;
		
		plogout << $2 -> getSymbolName() << endl << endl ; 

		SymbolInfo* tem = myTable -> lookUpInCurr($2 -> getSymbolName(), "ID");


		if(tem == 0)
		{
			SymbolInfo* func = new SymbolInfo($2 -> getSymbolName(), "ID");
			func = myTable -> insert(func);
			func -> setIdType("FUNC");
			func -> setFuncReturnType(varType);
			func -> setParamNo(0);
			func -> setParamList.clear();
			func -> setIsFuncDefined();

			initializeParam(); 

			
		}
		else 
		{
			if(tem -> checkIfFuncDefined() == true)
			{
				errorNo++;
				perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Function" << $2->getSymbolName() <<  " has been already defined."<<  << endl << endl;

				initializeParam();
			}
			else  
			{
				// check if it's really function. not var/array
				if(tem -> getIdType() != "FUNC")
				{
					errorNo++;
					perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : " << $2->getSymbolName() <<  " has been already declared as Variable or Array."<<  << endl << endl; 

					initializeParam();
				}
				else if(tem -> getFuncReturnType() != varType)
				{
					errorNo++;
					perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Return Type of Function " << $2->getSymbolName() <<  " doesn't match."<<  << endl << endl; 
					initializeParam();
				}
				else if(tem -> getParamNo() != totalArgsNo)
				{
					errorNo++;
					perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : " << " Parameter mismatch for Function "<< $2->getSymbolName() << endl << endl;

					initializeParam();
				}
			}
		}

		}
 		;				


parameter_list  : parameter_list COMMA type_specifier ID {

		plogout << "At line no: " << lineCount << " : " << "parameter_list  : parameter_list COMMA type_specifier ID" << endl << endl ;

		plogout << $4 -> getSymbolName() << endl << endl ; 

		totalArgsNo++;
		typeAndIDArgsNo++;


		SymbolInfo* tem = new SymbolInfo($4 -> getSymbolName(), "ID");
		tem -> setIdType("VAR");

		tem -> setVarType(varType);
 		Params.push_back(tem);


		}
		| parameter_list COMMA type_specifier {

			totalArgsNo++;

		plogout << "At line no: " << lineCount << " : " << "parameter_list  : parameter_list COMMA type_specifier" << endl << endl ;

		

		SymbolInfo* tem = new SymbolInfo("#", "ID");
		tem -> setIdType("VAR");
		tem -> setVarType(varType);

		Params.push_back(tem);

		}
 		| type_specifier ID {
		plogout << "At line no: " << lineCount << " : " << "parameter_list  : type_specifier ID" << endl << endl ;

		totalArgsNo++;
		typeAndIDArgsNo++;


		SymbolInfo* tem = new SymbolInfo($2 -> getSymbolName(), "ID");
		tem -> setVarType(varType);
		tem -> setIdType("VAR");
		Params.push_back(tem);

		}
		| type_specifier {
		plogout << "At line no: " << lineCount << " : " << "parameter_list  : type_specifier" << endl << endl ;

		totalArgsNo++;

		SymbolInfo* tem = new SymbolInfo("#", "ID");
		tem -> setIdType("VAR");
		tem -> setVarType(varType);

		Params.push_back(tem);
		}
 		;

 		
compound_statement : LCURL {

		myTable.enterScope(); 
		for(int i = 0 ; i < Params.size(); i++)
		{
			if(Params[i].getSymbolName() != '#')
			{
				myTable.insert(Params[i]); 
			}
		}
		Params.clear();

		} statements {

				myTable.printAllScopeTable(plogout);

		} RCURL {

			plogout << "At line no: " << lineCount << " : " << "compound_statement : LCURL statements RCURL" << endl << endl ;

			myTable.exitScope();
			plogout << "Scope exited" << endl ; 

		}
 		    | LCURL RCURL{
		plogout << "At line no: " << lineCount << " : " << "compound_statement : LCURL RCURL" << endl << endl ;
		}
 		    ;
 		    
var_declaration : type_specifier declaration_list SEMICOLON{
		plogout << "At line no: " << lineCount << " : " << "var_declaration : type_specifier declaration_list SEMICOLON" << endl << endl ;
		}
 		;
 		 
type_specifier	: INT{
		plogout << "At line no: " << lineCount << " : " << "type_specifier	: INT" << endl << endl ;

		SymbolInfo *tem = new SymbolInfo("INT");
		$$ = tem ; 

		varType = "INT";
		}
 		| FLOAT{
		plogout << "At line no: " << lineCount << " : " << "type_specifier	: FLOAT" << endl << endl ;

		SymbolInfo *tem = new SymbolInfo("FLOAT");
		$$ = tem ; 

		varType = "FLOAT";
		}
 		| VOID{
		plogout << "At line no: " << lineCount << " : " << "type_specifier	: VOID" << endl << endl ;

		SymbolInfo *tem = new SymbolInfo("VOID");
		$$ = tem ; 

		varType = "VOID";
		}
 		;
 		
declaration_list : declaration_list COMMA ID{

		plogout << "At line no: " << lineCount << " : " << "declaration_list : declaration_list COMMA ID" << endl << endl ;

		plogout << $3 -> getSymbolName() << endl << endl ; 

		if(varType == "VOID")
		{
			errorNo++;
			perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Variable \"" << $3 -> getSymbolName() << "\" can not be of type VOID." << endl << endl ;
		}
		else 
		{
		    SymbolInfo* tem = myTable -> lookUpInCurr($3 ->getSymbolName(), "ID");

		    if(tem == 0)
		    {
		    	SymbolInfo* t = new SymbolInfo($3 -> getSymbolName(), "ID");
		    	t = myTable -> insert(t);
		    	t -> setVarType(varType);
		    	t -> setIdType("VAR");
		    }
		    else 
		    {
		    	errorNo++;
				perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : ID \"" << $3 -> getSymbolName() << "\" has already been declared before in this scope." << endl << endl ; 
		    }

		}

		}
 		  | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD{
		plogout << "At line no: " << lineCount << " : " << "declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD" << endl << endl ;

		plogout << $3 -> getSymbolName() << endl << $5 -> getSymbolName() << endl << endl ; 

		if(varType == "VOID")
		{
			errorNo++;
			perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Array \"" << $3 -> getSymbolName() << "[]\" can not be of type VOID." << endl << endl ;
		}
		else 
		{
		    SymbolInfo* tem = myTable -> lookUpInCurr($3 -> getSymbolName(), "ID");

		    if(tem == 0)
		    {
		    	int arraySize = stoi($5 -> getSymbolName());

				SymbolInfo* t = new SymbolInfo($3 -> getSymbolName(), $3 -> getSymbolType());

		    	t = myTable -> insert(t);
		    	t -> setArraySize(arraySize); 
		    	t-> fillArray();
		    	t -> setVarType(varType);
		    	t -> setIdType("ARR");
		    }
		    else 
		    {
		    	errorNo++;
				perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : ID \"" << $3 -> getSymbolName() << "\" has already been declared before in this scope." << endl << endl ; 
		    }

		}


		}
 		  | ID{
		plogout << "At line no: " << lineCount << " : " << "declaration_list : ID" << endl << endl ;

		plogout << $1 -> getSymbolName() << endl << endl ; 

		if(varType == "VOID")
		{
			errorNo++;
			perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Variable \"" << $1 -> getSymbolName() << "\" can not be of type VOID." << endl << endl ;
		}
		else 
		{
		    SymbolInfo* tem = myTable -> lookUpInCurr($1 ->getSymbolName(), "ID");

		    if(tem == 0)
		    {
		    	SymbolInfo* t = new SymbolInfo($1 -> getSymbolName(), "ID");
		    	t = myTable -> insert(t);
		    	t -> setVarType(varType);
		    	t -> setIdType("VAR");
		    }
		    else 
		    {
		    	errorNo++;
				perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : ID \"" << $1 -> getSymbolName() << "\" has already been declared before in this scope." << endl << endl ; 
		    }

		}

		}
 		  | ID LTHIRD CONST_INT RTHIRD{
		plogout << "At line no: " << lineCount << " : " << "declaration_list : ID LTHIRD CONST_INT RTHIRD" << endl << endl ;

		plogout << $1 -> getSymbolName() << endl << $3 -> getSymbolName() << endl << endl ; 

		if(varType == "VOID")
		{
			errorNo++;
			perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Array \"" << $1 -> getSymbolName() << "[]\" can not be of type VOID." << endl << endl ;
		}
		else 
		{
		    SymbolInfo* tem = myTable -> lookUpInCurr($1 -> getSymbolName(), "ID");

		    if(tem == 0)
		    {
		    	int arraySize = stoi ($3 -> getSymbolName());

		    	SymbolInfo* t = new SymbolInfo($1 -> getSymbolName(), "ID");

		    	t = myTable -> insert(t);
		    	t -> setVarType(varType);
		    	t -> setIdType("ARR");
		    	t -> setArraySize(arraySize); 
		    	t-> fillArray();
		    }
		    else 
		    {
		    	errorNo++;
				perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : ID \"" << $1 -> getSymbolName() << "\" has already been declared before in this scope." << endl << endl ; 
		    }

		}

		}
 		  ;
 		  
statements : statement{
		plogout << "At line no: " << lineCount << " : " << "statements : statement" << endl << endl ;
		}
	   | statements statement{
		plogout << "At line no: " << lineCount << " : " << "statements : statements statement" << endl << endl ;
		}
	   ;
	   
statement : var_declaration{
		plogout << "At line no: " << lineCount << " : " << "statement : var_declaration" << endl << endl ;
		}
	  | expression_statement{
		plogout << "At line no: " << lineCount << " : " << "statement : expression_statement" << endl << endl ;
		}
	  | compound_statement{
		plogout << "At line no: " << lineCount << " : " << "statement : compound_statement" << endl << endl ;
		}
	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement{
		plogout << "At line no: " << lineCount << " : " << "statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement" << endl << endl ;
		}
	  | IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE{
		plogout << "At line no: " << lineCount << " : " << "statement : IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE" << endl << endl ;
		}
	  | IF LPAREN expression RPAREN statement ELSE statement{
		plogout << "At line no: " << lineCount << " : " << "statement : IF LPAREN expression RPAREN statement ELSE statement" << endl << endl ;
		}
	  | WHILE LPAREN expression RPAREN statement{
		plogout << "At line no: " << lineCount << " : " << "statement : WHILE LPAREN expression RPAREN statement" << endl << endl ;
		}
	  | PRINTLN LPAREN ID RPAREN SEMICOLON{
		plogout << "At line no: " << lineCount << " : " << "statement : PRINTLN LPAREN ID RPAREN SEMICOLON" << endl << endl ;
		}
	  | RETURN expression SEMICOLON{
		plogout << "At line no: " << lineCount << " : " << "statement : RETURN expression SEMICOLON" << endl << endl ;
		}
	  ;
	  
expression_statement 	: SEMICOLON {
		plogout << "At line no: " << lineCount << " : " << "expression_statement 	: SEMICOLON" << endl << endl ;
		}		
			| expression SEMICOLON {
		plogout << "At line no: " << lineCount << " : " << "expression_statement 	: Sexpression SEMICOLON" << endl << endl ;
		}
			;
	  
variable : ID {
			plogout << "At line no: " << lineCount << " : " << "variable : ID" << endl << endl ;

			plogout << $1 -> getSymbolName() << endl << endl ; 
			SymbolInfo* tem = myTable.lookUp($1 -> getSymbolName(), "ID"); 
			

			if(tem == 0)
			{
				errorNo++;
				perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Variable \"" << $1 -> getSymbolName() << "\" was not declared before." << endl << endl ;
			}
			else
			{
				if(tem -> getVarType() != "VAR")
				{
					errorNo++;
					perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : " << $1 -> getSymbolName() << "was declared before as" << tem -> getVarType() << ". So, it can not be used as a variable now." << endl << endl ;
				}
				else
				{
					$$ = tem ; 
				}
			}

		}
	 | ID LTHIRD expression RTHIRD {
		plogout << "At line no: " << lineCount << " : " << "variable : ID LTHIRD expression RTHIRD" << endl << endl ;

		plogout << $1 -> getSymbolName() << endl << endl ; 

		SymbolInfo* tem = myTable -> lookUp($1 -> getSymbolName() , "ID");

		if(tem == 0)
		{
			errorNo++;
			perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Variable \"" << $1 -> getSymbolName() << "\" was not declared before." << endl << endl ;
		}
		else 
		{
			if(tem -> getVarType() != "ARR")
			{
				errorNo++;
				perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : " << $1 -> getSymbolName() << "was declared before as" << tem -> getVarType() << ". So, it can not be used as an array now." << endl << endl ;
			}
			else
			{
				
			}
		}

	}
	 ;
	 
expression : logic_expression{
		plogout << "At line no: " << lineCount << " : " << "expression : logic_expression" << endl << endl ;
		}
	   | variable ASSIGNOP logic_expression {
		plogout << "At line no: " << lineCount << " : " << "expression : variable ASSIGNOP logic_expression" << endl << endl ;
		}	
	   ;
			
logic_expression : rel_expression{
		plogout << "At line no: " << lineCount << " : " << "logic_expression : rel_expression" << endl << endl ;
		}
		 | rel_expression LOGICOP rel_expression {
		plogout << "At line no: " << lineCount << " : " << "logic_expression : rel_expression LOGICOP rel_expression" << endl << endl ;
		}	
		 ;
			
rel_expression	: simple_expression{
		plogout << "At line no: " << lineCount << " : " << "rel_expression	: simple_expression" << endl << endl ;
		}
		| simple_expression RELOP simple_expression	{
		plogout << "At line no: " << lineCount << " : " << "rel_expression	: simple_expression RELOP simple_expression" << endl << endl ;
		}
		;
				
simple_expression : term{
		plogout << "At line no: " << lineCount << " : " << "simple_expression : term" << endl << endl ;
		}
		  | simple_expression ADDOP term{
		plogout << "At line no: " << lineCount << " : " << "simple_expression : simple_expression ADDOP term" << endl << endl ;
		}
		  ;
					
term :	unary_expression{
		plogout << "At line no: " << lineCount << " : " << "term :	unary_expression" << endl << endl ;
		$$ = $1 ; 

		}
     |  term MULOP unary_expression{
		plogout << "At line no: " << lineCount << " : " << "term :	term MULOP unary_expression" << endl << endl ;


		if($2 -> getSymbolName() == "*")
		{
			
		}
		else if($2 -> getSymbolName() == "/")
		{

		}
		else if($2 -> getSymbolName() == "%")
		{
			
		}



		}
     ;

unary_expression : ADDOP unary_expression {
		plogout << "At line no: " << lineCount << " : " << "unary_expression : ADDOP unary_expression " << endl << endl ;

		SymbolInfo* tem = $2 ; 

		if($1 -> getSymbolName() == "-")
		{
			if(tem -> getIdType() == "VAR")
			{
				if(tem -> getVarType() == "INT")
				{
					tem -> intVarValue = (-1) * tem -> intVarValue ; 
				}
				else if(tem -> getVarType() == "FLOAT")
				{
					tem -> floatVarValue = tem -> floatVarValue * (-1.0) ; 
				}
				else if(tem -> getVarType() == "CHAR")
				{
					errorNo++;
					perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Can not put " << $1 -> getSymbolName() <<  "operator before Char variable \"" << $2 -> getSymbolName() << endl << endl ;
				}
			}
			else if(tem -> getIdType() == "ARR")
			{
				if(tem -> getVarType() == "INT")
				{
					tem -> intArray[tem -> currentArrayIndex] = tem -> intArray[tem -> currentArrayIndex] * (-1) ;  
				}
				else if(getVarType() == "FLOAT")
				{
					tem -> floatArray[tem -> currentArrayIndex] = tem -> floatArray[tem -> currentArrayIndex] * (-1.0) ; 
				}
				else if(getVarType() == "CHAR")
				{
					errorNo++;
					perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Can not put " << $1 -> getSymbolName() <<  "operator before Char Array element. \"" << $2 -> getSymbolName() << endl << endl ;
				}
			}
		}
		else if($1 -> getSymbolName() == "+")
		{
			if(tem -> getIdType() == "VAR")
			{
				if(tem -> getVarType() == "INT")
				{
					tem -> intVarValue = (1) * tem -> intVarValue ; 
				}
				else if(tem -> getVarType() == "FLOAT")
				{
					tem -> floatVarValue = tem -> floatVarValue * (1.0) ; 
				}
				else if(tem -> getVarType() == "CHAR")
				{
					errorNo++;
					perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Can not put " << $1 -> getSymbolName() <<  "operator before Char variable \"" << $2 -> getSymbolName() << endl << endl ;
				}
			}
			else if(tem -> getIdType() == "ARR")
			{
				if(tem -> getVarType() == "INT")
				{
					tem -> intArray[tem -> currentArrayIndex] = tem -> intArray[tem -> currentArrayIndex] * (1) ;  
				}
				else if(getVarType() == "FLOAT")
				{
					tem -> floatArray[tem -> currentArrayIndex] = tem -> floatArray[tem -> currentArrayIndex] * (1.0) ; 
				}
				else if(getVarType() == "CHAR")
				{
					errorNo++;
					perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Can not put " << $1 -> getSymbolName() <<  "operator before Char Array element. \"" << $2 -> getSymbolName() << endl << endl ;
				}
			}
		}

		$$ = tem ;

	} 
		 | NOT unary_expression {
		plogout << "At line no: " << lineCount << " : " << "unary_expression : NOT unary_expression" << endl << endl ;

			SymbolInfo* tem = $2 ; 

			if(tem -> getIdType() == "VAR")
			{
				if(tem -> getVarType() == "INT")
				{
					tem -> intVarValue = !tem -> intVarValue ; 
				}
				else if(tem -> getVarType() == "FLOAT")
				{
					tem -> floatVarValue = !tem -> floatVarValue ; 
				}
				else if(tem -> getVarType() == "CHAR")
				{
					tem -> charVarValue = !tem -> charVarValue ; 
				}
			}
			else if(tem -> getIdType() == "ARR")
			{
				if(tem -> getVarType() == "INT")
				{
					tem -> intArray[tem -> currentArrayIndex] = !tem -> intArray[tem -> currentArrayIndex]  ;  
				}
				else if(getVarType() == "FLOAT")
				{
					tem -> floatArray[tem -> currentArrayIndex] = !tem -> floatArray[tem -> currentArrayIndex] ; 
				}
				else if(getVarType() == "CHAR")
				{
					tem -> cahrArray[tem -> currentArrayIndex] = !tem -> charArray[tem -> currentArrayIndex] ; 
				}
			}
		
			$$ = tem ;

		}
		 | factor {
		plogout << "At line no: " << lineCount << " : " << "punary_expression : NOT unary_expression" << endl << endl ;

		$$ = $1 ; 
		}
		 ;
	
factor	: variable{
		plogout << "At line no: " << lineCount << " : " << "factor	: variable " << endl << endl ;
		$$ = $1 ; 
		}
	| ID LPAREN argument_list RPAREN{
		plogout << "At line no: " << lineCount << " : " << "factor	: ID LPAREN argument_list RPAREN  " << endl << endl ;

		plogout << $1 -> getSymbolName() << endl << endl ; 

		SymbolInfo* tem = myTable.lookUp($1 -> getSymbolName(), "ID");

		if(tem == 0)
		{
			errorNo++;
			perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Function \"" << $1 -> getSymbolName() << "\" wasn't declared before." << endl << endl ; 
		}
		else 
		{
			if(tem -> getIdType() != "FUNC")
			{
				errorNo++;
				perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Function \"" << $1 -> getSymbolName() << "\" wasn't declared before." << endl << endl ;
			}
			else 
			{
				if(tem -> getFuncReturnType() == "VOID")
				{
					errorNo++;
					perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Return type of function \"" << $1 -> getSymbolName() << " is void." << endl << endl ;
				}
				else 
				{
					SymbolInfo* t = new SymbolInfo("Factor" , "ID");

					if(tem -> getFuncReturnType() == "INT")
					{
						t -> intVarValue = 0; 
					}
					else if(tem -> getFuncReturnType() == "FLOAT")
					{
						t -> floatVarValue = 0 ; 
					}
					else if(tem -> getFuncReturnType() == "CHAR")
					{
						t -> charVarValue = '\0' ; 
					}
					$$ = t ; 
				}
			}
		}

		}
	| LPAREN expression RPAREN{
		plogout << "At line no: " << lineCount << " : " << "factor	: LPAREN expression RPAREN " << endl << endl ;

		$$ = $2 ; 

		}
	| CONST_INT{
		plogout << "At line no: " << lineCount << " : " << "factor	: CONST_INT " << endl << endl ;

		plogout << $1 -> getSymbolName() << endl << endl ; 

		SymbolInfo* tem = $1 ; 
		tem -> setVarType("INT");
		tem -> setIdType("VAR");
		tem -> intVarValue = stoi(tem -> getSymbolName());

		$$ = tem ; 

		}
	| CONST_FLOAT{
		plogout << "At line no: " << lineCount << " : " << "factor	: CONST_FLOAT " << endl << endl ;

		plogout << $1 -> getSymbolName() << endl << endl ; 

		SymbolInfo* tem = $1 ; 
		tem -> setVarType("FLOAT");
		tem -> setIdType("VAR");
		tem -> floatVarValue = stof(tem -> getSymbolName());

		$$ = tem ; 

		}
	| variable INCOP{
		plogout << "At line no: " << lineCount << " : " << "factor	: variable INCOP " << endl << endl ;


		plogout << $1 -> getSymbolName() << "++" << endl << endl ; 

		SymbolInfo* tem = $1 ; 

		if(tem -> getIdType() == "VAR")
		{
			if(tem -> getVarType() == "INT")
			{
				tem -> intVarValue++; 
			}
			else if(tem -> getVarType() == "FLOAT")
			{
				tem -> floatVarValue = tem -> floatVarValue + 1.0 ; 
			}
			else if(tem -> getVarType() == "CHAR")
			{
				tem -> charVarValue = tem -> charVarValue + 1 ;
			}
		}
		else if(tem -> getIdType() == "ARR")
		{
			if(tem -> getVarType() == "INT")
			{
				tem -> intArray[tem -> currentArrayIndex] = tem -> intArray[tem -> currentArrayIndex] + 1 ;  
			}
			else if(getVarType() == "FLOAT")
			{
				tem -> floatArray[tem -> currentArrayIndex] = tem -> floatArray[tem -> currentArrayIndex] + 1.0 ; 
			}
			else if(getVarType() == "CHAR")
			{
				tem -> charArray[tem -> currentArrayIndex] = tem -> charArray[tem -> currentArrayIndex] + 1 ; 
			}
		}

		$$ = tem ; 
	}
	| variable DECOP {
		plogout << "At line no: " << lineCount << " : " << "factor	: variable DECOP " << endl << endl ;

		plogout << $1 -> getSymbolName() << "--" << endl << endl ; 

		SymbolInfo* tem = $1 ; 

		if(tem -> getIdType() == "VAR")
		{
			if(tem -> getVarType() == "INT")
			{
				tem -> intVarValue--; 
			}
			else if(tem -> getVarType() == "FLOAT")
			{
				tem -> floatVarValue = tem -> floatVarValue - 1.0 ; 
			}
			else if(tem -> getVarType() == "CHAR")
			{
				tem -> charVarValue = tem -> charVarValue - 1 ;
			}
		}
		else if(tem -> getIdType() == "ARR")
		{
			if(tem -> getVarType() == "INT")
			{
				tem -> intArray[tem -> currentArrayIndex] = tem -> intArray[tem -> currentArrayIndex] - 1 ;  
			}
			else if(getVarType() == "FLOAT")
			{
				tem -> floatArray[tem -> currentArrayIndex] = tem -> floatArray[tem -> currentArrayIndex] - 1.0 ; 
			}
			else if(getVarType() == "CHAR")
			{
				tem -> charArray[tem -> currentArrayIndex] = tem -> charArray[tem -> currentArrayIndex] - 1 ; 
			}
		}

		$$ = tem ;
	}
	;
	
argument_list : arguments{
		plogout << "At line no: " << lineCount << " : " << "argument_list : arguments" << endl << endl ;
		}
			  |
			  ;
	
arguments : arguments COMMA logic_expression{
		plogout << "At line no: " << lineCount << " : " << "arguments : arguments COMMA logic_expression " << endl << endl ;
		}
	      | logic_expression{
		plogout << "At line no: " << lineCount << " : " << "arguments : logic_expression" << endl << endl ;
		}
	      ;
 

%%
int main(int argc,char *argv[])
{
	FILE* fp  ; 

	if((fp=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File No. 1.\n");
		exit(1);
	}

	plogout.open("plog1.txt");
	perrout.open("perror1.txt");

	yyin=fp;
	yyparse();

	plogout.close();
	perrout.close();

	if((fp=fopen(argv[2],"r"))==NULL)
	{
		printf("Cannot Open Input File No. 2.\n");
		exit(1);
	}

	plogout.open("plog2.txt");
	perrout.open("perror2.txt");

	yyin=fp;
	yyparse();

	plogout.close();
	perrout.close();
	
	return 0;
}

