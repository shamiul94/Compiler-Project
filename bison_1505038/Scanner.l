%x cms 
%x COMMENT_MULTI_LINE

%{
#include<bits/stdc++.h>
#include"SymbolTable.h"
#include "y.tab.h"


FILE *logout;
FILE *tokenout;


int lineCount = 1 ; 
int error=0;

extern SymbolTable *myTable ; 

extern YYSTYPE yylval;
void yyerror(char *);
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

"if" 	{return IF;}

"for"	{return FOR;}

"do"	{return DO;}

"int"	{return INT;}

"float"	{return FLOAT;}

"void"	{return VOID;}

"switch"	{return SWITCH;}

"default" {return DEFAULT;}

"else"	{return ELSE;} 

"while"	{return WHILE;}
	
"break"	{return BREAK;}

"char"	{return CHAR;}

"double"	{return DOUBLE;}

"return"	{return RETURN;}

"case"	{return CASE;}

"continue" {return CONTINUE;}


{integerLiteral} {
    SymbolInfo *s = new SymbolInfo(yytext , "CONST_INT");
    yylval.s = s; 
    return CONST_INT; 
}

{floatingPointLiteral} {
    SymbolInfo *s = new SymbolInfo(yytext , "CONST_FLOAT");
    yylval.s = s; 
    return CONST_FLOAT; 
}

{characterLiteral} {

	char* c = new char[20];

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

    SymbolInfo *s = new SymbolInfo(c , "CONST_CHAR");
    yylval.s = s; 
    return CONST_CHAR; 
}


[+-] {
    SymbolInfo *s= new  SymbolInfo(yytext, "ADDOP");
    yylval.s = s;
    return ADDOP;
}

[\*\/%] {
    SymbolInfo *s= new  SymbolInfo(yytext, "MULOP");
    yylval.s = s;
    return MULOP;
}

"++"  {
    return INCOP;
}

"--" {
    return DECOP; 
}

(<=)|(>=)|(==)|(!=)|(<)|(>) {
    SymbolInfo *s= new  SymbolInfo(yytext, (char *)"RELOP");
    yylval.s = s;
    return RELOP;
}

"=" {
    return ASSIGNOP;
}

"&&"|"||" {
    SymbolInfo *s= new  SymbolInfo(yytext, "LOGICOP");
    yylval.s = s;
    return LOGICOP;
}

[&]|[\^]|(<<)|(>>)|[|] {
    SymbolInfo *s= new  SymbolInfo(yytext, "BITOP");
    yylval.s = s;
    return BITOP;
}

"!" {return NOT;}

"(" {return LPAREN;}

")" {return RPAREN;}


"{" {return LCURL;}

"}" {return RCURL;}

"[" {return LTHIRD;}

"]" {return RTHIRD;}

"," {return COMMA;}

";" {return SEMICOLON;} 

{identifier} {
    SymbolInfo *s  = new SymbolInfo(yytext, "ID");
    yylval.s = s;                     
    return ID;
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
                s = s + yytext[i] ;
            }
        }
    }


    SymbolInfo *si= new  SymbolInfo(s, (char *)"CONST_STRING");
    yylval.s = si;
    return CONST_STRING;

}


{singleLineComment} {
    fprintf(logout , "Line No %d:  <COMMENT> Lexeme %s Found.\n\n" , lineCount , yytext);
    return COMMENT; 
}

{multiLineComment} {
    fprintf(logout , "Line No %d:  <COMMENT> Lexeme %s Found.\n\n" , lineCount , yytext);
    return COMMENT;
}

{tooManyDecimalError} {

    fprintf(logout , "Error at line %d: Too many decimal point %s\n\n", lineCount , yytext);
    return ERROR; 
}

{illFormedError} {
    fprintf(logout , "Error at line %d: Ill formed number %s\n\n", lineCount , yytext);
    return ERROR; 
}


{invalidSuffix} {
    fprintf(logout , "Error at line %d: Invalid prefix on ID or invalid suffix on Number %s\n\n",lineCount ,  yytext);

    return ERROR; 
}


{multiCharError} {
    fprintf(logout , "Error at line %d: Multi character constant error %s\n\n", lineCount  , yytext);
    return ERROR; 

}

{unfinishedChar1} {
    fprintf(logout , "Error at line %d: Unterminated character %s\n\n", lineCount  , yytext);
    return ERROR; 
}


{unfinishedChar2} {
    fprintf(logout , "Error at line %d: Unterminated character %s\n\n", lineCount  , yytext);
    return ERROR; 
}


{emptyChar} {
    fprintf(logout , "Error at line %d: Empty character constant error %s\n\n", lineCount  , yytext);

    return ERROR; 

}

{unfinishedString} {
    fprintf(logout , "Error at line %d: Unterminated String %s\n\n", lineCount  , yytext);

    return ERROR; 

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
    return ERROR; 
}


. {
     fprintf(logout , "Error at line %d: <Unrecognized Character Error> Lexeme %s Found.\n\n" , lineCount  , yytext);
     return ERROR; 
}

%%

int yywrap(void)
{
    return 1;
}


