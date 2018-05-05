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