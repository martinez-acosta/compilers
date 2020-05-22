%{

    typedef struct datos
    {
        int tipo;
        int entero;
        double doble;
        char* string;
    }Dato;

    #include "Practica5.tab.h"
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h> 
    #include <stdbool.h>


%}

NUM [0-9]
LETRAS [^"]
ID [A-Za-z]+[A-Z_a-z0-9]*
%%

{NUM}+  {
            //printf("Numero entero %s\n",yytext);
            yylval.dato.tipo = 1;
            yylval.dato.entero = atoi(yytext);
            return (DATO);
        }
        
{NUM}?"."{NUM}  {
                    //printf("Numero decimal %s\n",yytext);
                    yylval.dato.tipo = 2;
                    yylval.dato.doble = atof(yytext);
                    return (DATO);
                }
                
"+" 	{
        	//printf("Signo mas\n");
	        return (yytext[0]);
    	}
    
"-" 	{
        	//printf("Signo menos\n");
	        return (yytext[0]);
    	}
    
"*"		{
    	    //printf("Signo por\n");
	        return (yytext[0]);
    	}
"/"		{
        	//printf("Signo entre\n");
        	return (yytext[0]);
    	}
"%"		{
	       	return (yytext[0]);
		}    
"="		{
        	//printf("Signo igual\n");
	        return (yytext[0]);
    	}
","		{
			return (yytext[0]);
		}    	
";" 	{
        	//printf("Signo punto y coma\n");
        	return (yytext[0]);
    	}
"("	 	{
			//printf("Parentesis abre\n");
               return (yytext[0]);
        }
")"		{
			//printf("Parentesis cierra\n");
            return (yytext[0]);
        }
"\n"    {
			//printf("Salto de linea\n");
            return (yytext[0]);
		}
int 	{
			//printf("Palabra reservada INT\n");
			return(INT);
		}
double 	{
			//printf("Palabra reservada DOUBLE\n");
			return(DOUBLE);
		}
string 	{
			//printf("Palabra reservada STRING\n");
			return(STRING);
		}
Pow		{
			return(POW);
		}
{ID}	{
			//Sprintf("Identificador %s\n",yytext);
			int i, j;
            char c=yytext[0];
            for(i=0;c!='\0';i++)
                c=yytext[i+1];
			yylval.cadena = malloc(i+1);
            for(j=0;j<i;j++)
                yylval.cadena[j]=yytext[j];
			yylval.cadena[i]='\0';
            return(ID);
		}
"\""{LETRAS}+"\""	{
			int i, j;
        	char c=yytext[0];
        	yylval.dato.tipo = 3;
			yylval.dato.string = malloc(255);
            for(i=0;c!='\0';i++)
                c=yytext[i+1];
            for(j=0;j<(i-2);j++)
                yylval.dato.string[j]=yytext[j+1];
            return (DATO);
		}	
.               ;

%%
