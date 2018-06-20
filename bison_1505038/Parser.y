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

int errorNo =  -1 , argsNo = 0 ; 

vector<param> Params ; 

extern int lineCount; 

int stoi(std::string s) //The conversion function
{
    return atoi(s.c_str());
}


void yyerror(const char *s)
{
	//write your code
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

		plogout << $1 -> getSymbolName() << endl<< $2 -> getSymbolName() << endl << endl ; 

		SymbolInfo* tem = myTable -> lookUpInCurr($2 -> getSymbolName(), "ID");

		if(tem == 0)
		{
			SymbolInfo* func = new SymbolInfo($2 -> getSymbolName(), "ID");
			func -> setIdType("FUNC");
			func -> setFuncReturnType(varType);





			myTable -> insert(func); 
		}
		else 
		{
			errorNo++;
			perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : ID \"" << $2 -> getSymbolName() << "\" has already been declared before in this scope." << endl << endl ; 
		}


		}
		| type_specifier ID LPAREN RPAREN SEMICOLON {
		plogout << "At line no: " << lineCount << " : " << "func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON" << endl << endl ;
		}
		;
		 
func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement {
		plogout << "At line no: " << lineCount << " : " << "func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement" << endl << endl ;
		}
		| type_specifier ID LPAREN RPAREN compound_statement {
		plogout << "At line no: " << lineCount << " : " << "func_definition : type_specifier ID LPAREN RPAREN compound_statement" << endl << endl ;
		}
 		;				


parameter_list  : parameter_list COMMA type_specifier ID {

		plogout << "At line no: " << lineCount << " : " << "parameter_list  : parameter_list COMMA type_specifier ID" << endl << endl ;

		plogout << $4 -> getSymbolName() << endl << endl ; 

		argsNo++;
		Params.push_back(param($4 -> getSymbolName(), varType));

		}
		| parameter_list COMMA type_specifier {

		plogout << "At line no: " << lineCount << " : " << "parameter_list  : parameter_list COMMA type_specifier" << endl << endl ;




		}
 		| type_specifier ID {
		plogout << "At line no: " << lineCount << " : " << "parameter_list  : type_specifier ID" << endl << endl ;
		}
		| type_specifier {
		plogout << "At line no: " << lineCount << " : " << "parameter_list  : type_specifier" << endl << endl ;
		}
 		;

 		
compound_statement : LCURL statements RCURL {
		plogout << "At line no: " << lineCount << " : " << "compound_statement : LCURL statements RCURL" << endl << endl ;
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
		    	t -> setVarType(varType);
		    	t -> setIdType("VAR");
		    	myTable -> insert(t);
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
		    	SymbolInfo* t = new SymbolInfo($3 -> getSymbolName(), $3 -> getSymbolType());
		    	t -> setVarType(varType);
		    	t -> setIdType("ARR");

		    	int arraySize = stoi($5 -> getSymbolName());

		    	t -> setArraySize(arraySize); 
		    	t-> fillArray();

		    	myTable -> insert(t);
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
		    	t -> setVarType(varType);
		    	t -> setIdType("VAR");
		    	myTable -> insert(t);
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
		    	SymbolInfo* t = new SymbolInfo($1 -> getSymbolName(), "ID");
		    	t -> setVarType(varType);
		    	t -> setIdType("ARR");

		    	int arraySize = stoi ($3 -> getSymbolName());

		    	t -> setArraySize(arraySize); 
		    	t-> fillArray();

		    	myTable -> insert(t);
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
	  
expression_statement 	: SEMICOLON{
		plogout << "At line no: " << lineCount << " : " << "expression_statement 	: SEMICOLON" << endl << endl ;
		}		
			| expression SEMICOLON {
		plogout << "At line no: " << lineCount << " : " << "expression_statement 	: Sexpression SEMICOLON" << endl << endl ;
		}
			;
	  
variable : ID{
		plogout << "At line no: " << lineCount << " : " << "variable : ID" << endl << endl ;

		plogout << $1 -> getSymbolName() << endl << endl ; 
		SymbolInfo* tem ; 


		}
	 | ID LTHIRD expression RTHIRD {
		plogout << "At line no: " << lineCount << " : " << "variable : ID LTHIRD expression RTHIRD" << endl << endl ;
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
		}
     |  term MULOP unary_expression{
		plogout << "At line no: " << lineCount << " : " << "term :	term MULOP unary_expression" << endl << endl ;
		}
     ;

unary_expression : ADDOP unary_expression{
		plogout << "At line no: " << lineCount << " : " << "unary_expression : ADDOP unary_expression " << endl << endl ;
		} 
		 | NOT unary_expression {
		plogout << "At line no: " << lineCount << " : " << "unary_expression : NOT unary_expression" << endl << endl ;
		}
		 | factor {
		plogout << "At line no: " << lineCount << " : " << "punary_expression : NOT unary_expression" << endl << endl ;
		}
		 ;
	
factor	: variable{
		plogout << "At line no: " << lineCount << " : " << "factor	: variable " << endl << endl ;
		}
	| ID LPAREN argument_list RPAREN{
		plogout << "At line no: " << lineCount << " : " << "factor	: ID LPAREN argument_list RPAREN  " << endl << endl ;
		}
	| LPAREN expression RPAREN{
		plogout << "At line no: " << lineCount << " : " << "factor	: LPAREN expression RPAREN " << endl << endl ;
		}
	| CONST_INT{
		plogout << "At line no: " << lineCount << " : " << "factor	: CONST_INT " << endl << endl ;
		}
	| CONST_FLOAT{
		plogout << "At line no: " << lineCount << " : " << "factor	: CONST_FLOAT " << endl << endl ;
		}
	| variable INCOP{
		plogout << "At line no: " << lineCount << " : " << "factor	: variable INCOP " << endl << endl ;
		}
	| variable DECOP {
		plogout << "At line no: " << lineCount << " : " << "factor	: variable DECOP " << endl << endl ;
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

