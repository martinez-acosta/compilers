%{
#include "parser.h"
#include "string.h"
%}

NUM [0-9]+
%%

{NUM}           {
                yylval.entero = atoi(yytext);
                return ENTERO;
                }

[0-9]*"."[0-9]+ {
                yylval.decimal = atof(yytext);
                return DECIMAL;
                }

"+"|"-"|"*"|"/"|"("|")"|","|"\""|"="|"%"|";"|"p"|"["|"]"|">" {

                return (yytext[0]);
                }

[pP][oO][wW]    {
                return POW;
                }

[dD][iI][vV]    {
                return DIV;
                }

[i][n][t]       {
                return INT;
                }

[d][o][u][b][l][e]  {
                     return DOUBLE;
                     }

[s][t][r][i][n][g]  {
                    return STRING;
                    }
[iI][fF] {
                    return IF;
                }

[a-zA-Z]+[0-9]*  {
                yylval.palabra = strdup(yytext);
                return ID;
                }

"\n"            {
                return (yytext[0]);
                }
.

%%
