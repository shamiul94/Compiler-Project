%option noyywrap
%x cms 
%x COMMENT_MULTI_LINE

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
	fprintf(logout , "Line No %d: Token <%s> Lexeme %s Found.\n\n" , lineCount , upper(yytext) , yytext);
}


%}

whiteSpace [ \t\f\r\v]+
newLine \n
integerLiteral [0-9]+
floatingPointLiteral ([0-9]*\.?[0-9]+|[0-9]+\.?[0-9]*)(E[+|-]?[0-9]+)?

characterLiteral \'[^\\\'\r\n]\'|\'\\[nt\"\'afrbv0\\]\'

identifier [a-zA-Z_]([a-zA-Z0-9_])*

stringPattern \"([^\\\"\n]|\\([^\n]|\n))*\"



singleLineComment \/\/([^\n]*\\\n)*[^\n]*

multiLineComment \/\*([^*]|\*+[^\/*])*\*+\/

tooManyDecimalError [0-9]*[.]([0-9]*[.]+[0-9]*)+

illFormedError (({integerLiteral}|{floatingPointLiteral}|{tooManyDecimalError})[E]({floatingPointLiteral}|{tooManyDecimalError}))|({tooManyDecimalError}[E]{integerLiteral})

invalidSuffix [0-9]([0-9]*[a-zA-Z_]+)+

emptyChar \'\'

multiCharError \'(([^\n\\][^\n]+)|(\\[^ntbafrv0\\\"])|(\\[^\n\\]{2,})|((\\\\)+))\'

unfinishedChar1 (\'[^\'\n \t]*)

unfinishedChar2 (\'\\[^nfarbtv0\"\\\']?\')

unfinishedString \"([^\\\"\n]|\\+([^\n\"]|\n))*





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
			fprintf(tokenout , "<CONST_INT, %s> ", yytext);
			fprintf(logout , "Line No. %d: Token <INT> Lexeme %s found\n\n", lineCount , yytext);
}

{floatingPointLiteral} {
		    fprintf(tokenout , "<CONST_FLOAT, %s> ", yytext);
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


	fprintf(tokenout , "<CONST_CHAR, %s> ", c);
    fprintf(logout , "Line No. %d: Token <CONST_CHAR> Lexeme %s found\n\n" ,lineCount , yytext);
}


[+|-] {
		fprintf(tokenout , "<ADDOP, %s> ", yytext);
    	fprintf(logout , "Line No %d: Token <ADDOP> Lexeme %s Found.\n\n" , lineCount  , yytext);
	}

[\*]|[/]|[%] {
		fprintf(tokenout , "<MULOP , %s> ", yytext);
    	fprintf(logout , "Line No %d: Token <MULOP> Lexeme %s Found.\n\n" , lineCount , yytext);
	  }

[\+]{2}|[-]{2} {
	fprintf(tokenout , "<INCOP , %s> ", yytext);
    	fprintf(logout , "Line No %d: Token <INCOP> Lexeme %s Found.\n\n" , lineCount , yytext);
}

(<)|(<=)|(>)|(>=)|(==)|(!=) {
	fprintf(tokenout , "<RELOP , %s> ", yytext);
    	fprintf(logout , "Line No %d: Token <RELOP> Lexeme %s Found.\n\n" , lineCount, yytext);
}

= {
	fprintf(tokenout , "<ASSIGNOP , %s> ", yytext);
    	fprintf(logout , "Line No %d: Token <ASSIGNOP> Lexeme %s Found.\n\n" , lineCount , yytext);
}

[&]{2}|[|]{2} {
	fprintf(tokenout , "<LOGICOP , %s> ", yytext);
    	fprintf(logout , "Line No %d: Token <LOGICOP> Lexeme %s Found.\n\n" , lineCount , yytext);
}

[&]|[\^]|(<<)|(>>)|[|] {
	fprintf(tokenout , "<BITOP , %s> ", yytext);
    	fprintf(logout , "Line No %d: Token <BITCOP> Lexeme %s Found.\n\n" , lineCount  , yytext);
}

[\!] {
	fprintf(tokenout , "<BNOT , %s> ", yytext);
    	fprintf(logout , "Line No %d: Token <NOT> Lexeme %s Found.\n\n" , lineCount  , yytext);
}

[(] {
	fprintf(tokenout , "<LPAREN , %s> ", yytext);
    	fprintf(logout , "Line No %d: Token <LPAREN> Lexeme %s Found.\n\n" , lineCount, yytext);
}

[)] {
	fprintf(tokenout , "<RPAREN , %s> ", yytext);
    	fprintf(logout , "Line No %d: Token <RPAREN> Lexeme %s Found.\n\n" , lineCount , yytext);
}


[\{] {
	fprintf(tokenout , "<LCURL , %s> ", yytext);
    	fprintf(logout , "Line No %d: Token <LCURL> Lexeme %s Found.\n\n" , lineCount , yytext);
}

[}] {
	fprintf(tokenout , "<RCURL , %s> ", yytext);
    	fprintf(logout , "Line No %d: Token <RCURL> Lexeme %s Found.\n\n" , lineCount , yytext);
}

[\[] {
	fprintf(tokenout , "<LTHIRD , %s> ", yytext);
    	fprintf(logout , "Line No %d: Token <LTHIRD> Lexeme %s Found.\n\n" , lineCount  , yytext);
}

[]] {
	fprintf(tokenout , "<RTHIRD , %s> ", yytext);
    	fprintf(logout , "Line No %d: Token <RTHIRD> Lexeme %s Found.\n\n" , lineCount , yytext);
}

[,] {
	fprintf(tokenout , "<COMMA , %s> ", yytext);
    	fprintf(logout , "Line No %d: Token <COMMA> Lexeme %s Found.\n\n" , lineCount , yytext);
}

[;] {
	fprintf(tokenout , "<SEMICOLON , %s> ", yytext);
    	fprintf(logout , "Line No %d: Token <SEMICOLON> Lexeme %s Found.\n\n" , lineCount  , yytext);
} 

{identifier} {
    fprintf(tokenout , "<ID, %s> ", yytext);
    fprintf(logout , "Line No. %d: Token <ID> Lexeme %s found\n\n", lineCount , yytext);
}


{stringPattern} {


    string s = "";  

    for(int i = 0 ; i < strlen(yytext); i++)
    {
        if(yytext[i] == '\\')
        {
                if(yytext[i+1] == 'n')
                {
                    s = s + '\n'; 
                    i++;
                }
                else if(yytext[i+1] == 't')
                {
                    s = s + '\t'; 
                    i++;
                }
                else if(yytext[i+1] == '\"')
                {
                    s = s + '\"'; 
                    i++;

                }
                else if(yytext[i+1] =='a')
                {
                    s = s + '\a'; 
                    i++;
                }
                else if(yytext[i+1] =='f')
                {
                    s = s + '\f'; 
                    i++;
                }
                else if(yytext[i+1] =='r')
                {
                    s = s + '\r'; 
                    i++;
                }
                else if(yytext[i+1] =='b')
                {
                    s = s + '\b'; 
                    i++;
                }
                else if(yytext[i+1] =='v')
                {
                    s = s + '\v'; 
                    i++;
                }
                else if(yytext[i+1] =='0')
                {
                    s = s + '\0'; 
                    i++;
                }
                else if(yytext[i+1] =='\\')
                {
                    s = s + '\\'; 
                    i++;
                }
                else if(yytext[i+1] =='\n')
                { 
                    i++;
                }
        }
        else
        {
            if(yytext[i]!='\n')
            {
                s = s + yytext[i] ;\
            }
        }
    }

    int i = 0 ; 
    char ch[1000] = {0}; 
    for(i = 0 ; i < s.size(); i++)
    {
        ch[i] = s[i]; 
    }
    ch[i] = '\0' ; 


    fprintf(tokenout , "<STRING , %s> ", ch);
    fprintf(logout , "Line No %d: Token <STRING , %s> Lexeme %s Found.\n\n" , lineCount , ch , yytext);
}


{singleLineComment} {
            fprintf(logout , "Line No %d:  <COMMENT> Lexeme %s Found.\n\n" , lineCount , yytext);
}

{multiLineComment} {
            fprintf(logout , "Line No %d:  <COMMENT> Lexeme %s Found.\n\n" , lineCount , yytext);
}

{tooManyDecimalError} {
    fprintf(logout , "Error at line %d: Too many decimal point %s\n\n", lineCount , yytext);
}

{illFormedError} {
    fprintf(logout , "Error at line %d: Ill formed number %s\n\n", lineCount , yytext);
}


{invalidSuffix} {
    fprintf(logout , "Error at line %d: Invalid prefix on ID or invalid suffix on Number %s\n\n",lineCount ,  yytext);

}


{multiCharError} {
    fprintf(logout , "Error at line %d: Multi character constant error %s\n\n", lineCount  , yytext);

}

{unfinishedChar1} {
  fprintf(logout , "Error at line %d: Unterminated character %s\n\n", lineCount  , yytext);

}


{unfinishedChar2} {
    fprintf(logout , "Error at line %d: Unterminated character %s\n\n", lineCount  , yytext);
}


{emptyChar} {
        fprintf(logout , "Error at line %d: Empty character constant error %s\n\n", lineCount  , yytext);

}

{unfinishedString} {
    fprintf(logout , "Error at line %d: Unterminated String %s\n\n", lineCount  , yytext);

}



"/*" { 
  BEGIN(COMMENT_MULTI_LINE); 
}

<COMMENT_MULTI_LINE>"*/" { 
  BEGIN(INITIAL); 
}

<COMMENT_MULTI_LINE>. { 

} 

<COMMENT_MULTI_LINE>\n { 

} 

<COMMENT_MULTI_LINE><<EOF>> {      
    fprintf(logout , "Error at line %d: Unterminated comment %s\n\n" , lineCount , yytext);
    yyterminate();
}


. {
     fprintf(logout , "Error at line %d: <Unrecognized Character Error> Lexeme %s Found.\n\n" , lineCount  , yytext);

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
