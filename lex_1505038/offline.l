%option noyywrap

%{
#include<bits/stdc++.h>
#include<cstring>
#include"SymbolTable_1505038.h"
FILE *logout;
FILE *tokenout;
int lineCount = 1 ; 

char* upper(char* s)
{
	char* Up = new char[100] ; 
	strcpy(Up,yytext); 

	for(int i = 0 ; i < strlen(Up); i++)
	{
		if(Up[i] >= 'a' && Up[i] <= 'z')
        		{
           	     Up[i] = Up[i] - 'a' + 'A';
        		}
	}
	return Up ;
}

void outputIdentifier()
{
	fprintf(tokenout , "<%s> " , upper(yytext));
	fprintf(logout , "Line No %d: Token <%s> Lexeme %s Found.\n" , lineCount , upper(yytext) , yytext);
}


%}

whiteSpace [ \t\f\r\v]+
newLine \n
integerLiteral [0-9]+
floatingPointLiteral ([0-9]*\.?[0-9]+|[0-9]+\.?[0-9]*)(E[+|-]?[0-9]+)?

characterLiteral '.'|'\\[nt"afrbv0\\]'

identifier [a-zA-Z_]([a-zA-Z0-9_]){0,30}

stringPattern \"([^\\\"\n]|\\([^\n]|\n))*\"



singleLineComment \/\/([^\n]*\\\n)*[^\n]*

multiLineComment \/\*([^*]|\*+[^\/*])*\*+\/

tooManyDecimalError [0-9]*[.]([0-9]*[.]+[0-9]*)+

illFormedError (({integerLiteral}|{floatingPointLiteral}|{tooManyDecimalError})[E]({floatingPointLiteral}|{tooManyDecimalError}))|({tooManyDecimalError}[E]{integerLiteral})

invalidSuffix [0-9]([0-9]*[a-zA-Z_]+)+

%%
{newLine} {lineCount++;}

{whiteSpace} {}

"if" 	{
		outputIdentifier();
	}

"for"	{
		outputIdentifier();
	}

"do"	{
		outputIdentifier();
	}

"int"	{
		outputIdentifier();
	}

"float"	{
		outputIdentifier();
	}

"void"	{
		outputIdentifier();
	}

"switch"	{
		outputIdentifier();
	}

"default" {
		outputIdentifier();
	}

"else"	{
		outputIdentifier();
	} 

"while"	{
		outputIdentifier();
	}
	
"break"	{
		outputIdentifier();		
	}

"char"	{
		outputIdentifier();
	}

"double"	{
		outputIdentifier();
	}

"return"	{
		outputIdentifier();
	}

"case"	{
		outputIdentifier();
	}

"continue" {
		outputIdentifier();	
	  }


{integerLiteral} {
			fprintf(tokenout , "<CONST_INT , %s> ", yytext);
			fprintf(logout , "Line No %d: Token <CONST_INT , %s> Lexeme %s Found.\n" , lineCount , yytext , yytext);
	        }

{floatingPointLiteral} {
		         fprintf(tokenout , "<CONST_FLOAT , %s> ", yytext);
			fprintf(logout , "Line No %d: Token <CONST_FLOAT , %s> Lexeme %s Found.\n" , lineCount , yytext , yytext);
		     }

{characterLiteral} {

	char* c = new char[20];
    char ch ;

    for(int i = 0 ; i < strlen(yytext); i++)
    {
        if(yytext[1] == '\\')
        {
            if(yytext[2] == '\0')
            {
                c[0] = yytext[1];
                c[1] = '\0';
            }
            else
            {
                if(yytext[2] == 'n')
                {
                    c[0] = '\n';
                    c[1] = '\0';
                }
                else if(yytext[2] == 't')
                {
                    c[0] = '\t';
                    c[1] = '\0';
                }
                else if(yytext[2] == '"')
                {
                    c[0] = '\"';
                    c[1] = '\0';

                }
                else if(yytext[2] =='a')
                {
                    c[0] = '\a';
                    c[1] = '\0';
                }
                else if(yytext[2] =='f')
                {
                    c[0] = '\f';
                    c[1] = '\0';
                }
                else if(yytext[2] =='r')
                {
                    c[0] = '\r';
                    c[1] = '\0';
                }
                else if(yytext[2] =='b')
                {
                    c[0] = '\b';
                    c[1] = '\0';
                }
                else if(yytext[2] =='v')
                {
                    c[0] = '\v';
                    c[1] = '\0';
                }
                else if(yytext[2] =='0')
                {
                    c[0] = '\0';
                    c[1] = '\0';
                }
                else if(yytext[2] =='\\')
                {
                    c[0] = '\\';
                    c[1] = '\0';
                }
            }
        }
        else
        {
            c[0] = yytext[1];
            c[1] = '\0';
        }
    }


			fprintf(tokenout , "<CONST_CHAR , %s> ", c);
            fprintf(logout , "Line No %d: Token <CONST_CHAR , %s> Lexeme %s Found.\n" , lineCount , c , yytext);
}


[+|-] {
		fprintf(tokenout , "<ADDOP , %s> ", yytext);
    	fprintf(logout , "Line No %d: Token <ADDOP , %s> Lexeme %s Found.\n" , lineCount , yytext , yytext);
	}

[\*]|[/]|[%] {
		fprintf(tokenout , "<MULOP , %s> ", yytext);
    	fprintf(logout , "Line No %d: Token <MULOP , %s> Lexeme %s Found.\n" , lineCount , yytext , yytext);
	  }

[\+]{2}|[-]{2} {
	fprintf(tokenout , "<INCOP , %s> ", yytext);
    	fprintf(logout , "Line No %d: Token <INCOP , %s> Lexeme %s Found.\n" , lineCount , yytext , yytext);
}

(<)|(<=)|(>)|(>=)|(==)|(!=) {
	fprintf(tokenout , "<RELOP , %s> ", yytext);
    	fprintf(logout , "Line No %d: Token <RELOP , %s> Lexeme %s Found.\n" , lineCount , yytext , yytext);
}

= {
	fprintf(tokenout , "<ASSIGNOP , %s> ", yytext);
    	fprintf(logout , "Line No %d: Token <ASSIGNOP , %s> Lexeme %s Found.\n" , lineCount , yytext , yytext);
}

[&]{2}|[|]{2} {
	fprintf(tokenout , "<LOGICOP , %s> ", yytext);
    	fprintf(logout , "Line No %d: Token <LOGICOP , %s> Lexeme %s Found.\n" , lineCount , yytext , yytext);
}

[&]|[\^]|(<<)|(>>)|[|] {
	fprintf(tokenout , "<BITOP , %s> ", yytext);
    	fprintf(logout , "Line No %d: Token <BITCOP , %s> Lexeme %s Found.\n" , lineCount , yytext , yytext);
}

[\!] {
	fprintf(tokenout , "<BNOT , %s> ", yytext);
    	fprintf(logout , "Line No %d: Token <NOT , %s> Lexeme %s Found.\n" , lineCount , yytext , yytext);
}

[(] {
	fprintf(tokenout , "<LPAREN , %s> ", yytext);
    	fprintf(logout , "Line No %d: Token <LPAREN , %s> Lexeme %s Found.\n" , lineCount , yytext , yytext);
}

[)] {
	fprintf(tokenout , "<RPAREN , %s> ", yytext);
    	fprintf(logout , "Line No %d: Token <RPAREN , %s> Lexeme %s Found.\n" , lineCount , yytext , yytext);
}


[\{] {
	fprintf(tokenout , "<LCURL , %s> ", yytext);
    	fprintf(logout , "Line No %d: Token <LCURL , %s> Lexeme %s Found.\n" , lineCount , yytext , yytext);
}

[}] {
	fprintf(tokenout , "<RCURL , %s> ", yytext);
    	fprintf(logout , "Line No %d: Token <RCURL , %s> Lexeme %s Found.\n" , lineCount , yytext , yytext);
}

[\[] {
	fprintf(tokenout , "<LTHIRD , %s> ", yytext);
    	fprintf(logout , "Line No %d: Token <LTHIRD , %s> Lexeme %s Found.\n" , lineCount , yytext , yytext);
}

[]] {
	fprintf(tokenout , "<RTHIRD , %s> ", yytext);
    	fprintf(logout , "Line No %d: Token <RTHIRD , %s> Lexeme %s Found.\n" , lineCount , yytext , yytext);
}

[,] {
	fprintf(tokenout , "<COMMA , %s> ", yytext);
    	fprintf(logout , "Line No %d: Token <COMMA , %s> Lexeme %s Found.\n" , lineCount , yytext , yytext);
}

[;] {
	fprintf(tokenout , "<SEMICOLON , %s> ", yytext);
    	fprintf(logout , "Line No %d: Token <SEMICOLON , %s> Lexeme %s Found.\n" , lineCount , yytext , yytext);
} 

{identifier} {
    fprintf(tokenout , "<ID , %s> ", yytext);
        fprintf(logout , "Line No %d: Token <ID , %s> Lexeme %s Found.\n" , lineCount , yytext , yytext);
}


{stringPattern} {
    fprintf(tokenout , "<STRING , %s> ", yytext);
        fprintf(logout , "Line No %d: Token <STRING , %s> Lexeme %s Found.\n" , lineCount , yytext , yytext);
}


{singleLineComment} {
            fprintf(logout , "Line No %d:  <SINGLE LINE COMMENT , %s> Lexeme %s Found.\n" , lineCount , yytext , yytext);
}

{multiLineComment} {
            fprintf(logout , "Line No %d:  <MULTI LINE COMMENT , %s> Lexeme %s Found.\n" , lineCount , yytext , yytext);
}

{tooManyDecimalError} {
            fprintf(logout , "Line No %d: <TOO MANY DECIMAL ERROR , %s> Lexeme %s Found.\n" , lineCount , yytext , yytext);

}

{illFormedError} {
            fprintf(logout , "Line No %d: <ILL FORMED NUMBER ERROR , %s> Lexeme %s Found.\n" , lineCount , yytext , yytext);
}


{invalidSuffix} {
            fprintf(logout , "Line No %d: <INVALID SUFFIX , %s> Lexeme %s Found.\n" , lineCount , yytext , yytext);

}

%%

int main(int argc,char *argv[]){
	
	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	
	logout= fopen("log.txt","w");
	tokenout= fopen("token.txt","w");

	yyin= fin;
	yylex();
	fclose(yyin);
	fclose(tokenout);
	fclose(logout);
	return 0;
}
