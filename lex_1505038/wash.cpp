char* c = new char[2000];
c[0] = '\n' ; 
string s = "";  
    char ch ;
"hkbdc\n \t \a .. \(\n)
"
    for(int i = 0 ; i < strlen(yytext)-1; i++)
    {
        if(yytext[i] == '\\')
        {
            if(yytext[i+1] == '\"')
            {

            }
            else
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
            }
        }
        else
        {
            s = s + yytext[i] ;
        }
    }