%{

	//Estructuras 

	typedef struct element{
		char *id;
		char *value;
		int type; 					//1.- Entero 2.- Double 3.- Cadena
		struct element *next;
	}Element;

	typedef struct datos{
		int tipo;
		int entero;
		double doble;
		char* string;
	}Dato;

	typedef struct cola{
		Element *first;
		Element *last;
		int size;
	}Cola;

	//Bibliotecas

	#include <stdio.h>
	#include <string.h>
	#include <math.h>
	#include <stdlib.h> 
	#include <stdbool.h>

	//Prototipos
	int yylex ( void );
	void yyerror (char *s);
	void push(char *id,char *value,int type);				//Agrega elementos
	void print();											//Imprime todos los elementos
	bool search(char *);									//1 si el elemento existe, 0 si no existe
	void modify(char *id,char *value,int tipo);				//Modifica variable
	struct element consulta(char *id);						//Consigue elemento

	//Variable Global

	Cola *new;												//Cola
%}
             
/* Declaraciones de BISON */
%union{
	char* cadena;
	struct datos dato;
}

%token 				INT
%token 				DOUBLE
%token				STRING
%token              POW
%token <dato> 		DATO
%token <cadena>		ID
%type  <dato> 		exp

%left '+'
%left '-'
%left '*'
%left '/'
%left '%'
%left '^'
             
/* Gramática */
%%
             
input:    /* cadena vacía */
        | input line             
;

line:     '\n'
        | exp '\n'  	{
			if($1.tipo==1){
				printf("\t resultado: %d\n",$1.entero);
        	}
        	if($1.tipo==2){
				printf("\t resultado: %f\n",$1.doble);
			}
        	if($1.tipo==3){
        		printf("\t resultado: %s\n",$1.string);
			} else {
        		print();
        	}
        };


exp:     DATO	 { $$ = $1; }
	| exp '+' exp       {
							//Entero+Entero
							if( $1.tipo==1 && $3.tipo==1) {
								$$.tipo = 1;
								$$.entero = $1.entero + $3.entero;	
							}
							//Entero+Doble
							else if( $1.tipo==1 && $3.tipo==2 ) {
								$$.tipo = 2;
								$$.doble = $1.entero + $3.doble;	
							}
							//Doble+Entero
							else if( $1.tipo==2 && $3.tipo==1 ) {
								$$.tipo = 2;
								$$.doble = $1.doble + $3.entero;	
							}
							//Doble+Doble
							else if( $1.tipo==2 && $3.tipo==2 ) {
								$$.tipo = 2;
								$$.doble = $1.doble + $3.doble;	
							}
							//String+String
							else if( $1.tipo==3 && $3.tipo==3 ) {
								int i, j, n, c;
                                $$.tipo=3;
								for( i=0; $1.string[i] != '\0';i++ );
                                for( j=0; $3.string[j] != '\0';j++ );
                                $$.string = malloc(i+j+1);
                                for( n=0; n < i; n++ ) {
                                	$$.string[n]=$1.string[n];
                                }
                                for(c=0;c<j;c++) {
									$$.string[n++] = $3.string[c];
                                }
								$$.string[n] = '\0';
							}
							//Tipos Incompatibles
							else {
								printf("ERROR: Tipos incompatibles\n");
							}	    									
	}
	| exp '-' exp       { 
							//Entero-Entero
							if($1.tipo==1&&$3.tipo==1) {
								$$.tipo = 1;
							$$.entero = $1.entero - $3.entero;	
							}
							//Entero-Doble
							else if($1.tipo==1&&$3.tipo==2) {
								$$.tipo = 2;
								$$.doble = $1.entero - $3.doble;	
							}
							//Doble-Entero
							else if($1.tipo==2&&$3.tipo==1) {
								$$.tipo = 2;
								$$.doble = $1.doble - $3.entero;	
							}
							//Doble-Doble
							else if($1.tipo==2&&$3.tipo==2) {
								$$.tipo = 2;
								$$.doble = $1.doble - $3.doble;	
							}
                            else if($1.tipo==3 && $3.tipo==3) {
                            	int i, j, n, c, bandera, tam;
                            	$$.tipo=3;
                            	$$.string = malloc(255);
                            	for( i = 0; $1.string[i] != '\0'; i++) {
                                	for(j=0; $1.string[i+j] != '\0' && $3.string[j] != '\0'; j++ ) {
	                                	if($1.string[i+j] == $3.string[j]) {
	                                    	bandera=1;
	                                	} else {
	                                        bandera=0;
	                                        break;
	                                    }
                                    }
									if(bandera == 1 && $3.string[j]=='\0')
                                    {
                                    	for(n=0;$1.string[n]!='\0';n++);
                                    	for(c=0;$3.string[c]!='\0';c++);
                                        for(n=0;n<i;n++) {
											$$.string[n]=$1.string[n];
                                        }
										for(i+=c;$1.string[i]!='\0';i++) {
											$$.string[n++]=$1.string[i];
										}
									}
                                }
                			} //Tipos Incompatibles
							else {
								printf("ERROR: Tipos incompatibles\n");
							}
	}
	| exp '*' exp       { 
							//Entero*Entero
							if($1.tipo==1&&$3.tipo==1) {
														$$.tipo = 1;
														$$.entero = $1.entero * $3.entero;	
														}
							//Entero*Doble
							else if($1.tipo==1&&$3.tipo==2) {
														$$.tipo = 2;
														$$.doble = $1.entero * $3.doble;	
														}
							//Doble*Entero
							else if($1.tipo==2&&$3.tipo==1) {
														$$.tipo = 2;
														$$.doble = $1.doble * $3.entero;	
														}
							//Doble*Doble
							else if($1.tipo==2&&$3.tipo==2) {
														$$.tipo = 2;
														$$.doble = $1.doble * $3.doble;	
														}
							//Tipos Incompatibles
							else {
														printf("ERROR: Tipos incompatibles\n");
														}
	}
	| exp '/' exp {
							//Entero/Entero
							if($1.tipo==1&&$3.tipo==1) {
														$$.tipo = 1;
														$$.entero = $1.entero / $3.entero;	
														}
							//Entero/Doble
							else if($1.tipo==1&&$3.tipo==2) {
														$$.tipo = 2;
														$$.doble = $1.entero / $3.doble;	
														}
							//Doble/Entero
							else if($1.tipo==2&&$3.tipo==1) {
														$$.tipo = 2;
														$$.doble = $1.doble / $3.entero;	
														}
							//Doble/Doble
							else if($1.tipo==2&&$3.tipo==2) {
														$$.tipo = 2;
														$$.doble = $1.doble / $3.doble;	
														}
							//Tipos Incompatibles
							else {
								printf("ERROR: Tipos incompatibles\n");
							}
	}
    | exp '%' exp         { 
                            //Entero/Entero
                            if($1.tipo==1&&$3.tipo==1) {
                                $$.tipo=1;
                                $$.entero=$1.entero%$3.entero;	
                            }
                            //Entero/Doble
                            else if($1.tipo==1&&$3.tipo==2) {
                                $$.tipo=2;
                                $$.doble=fmod($1.entero,$3.doble);	
                            }
                            //Doble/Entero
                            else if($1.tipo==2&&$3.tipo==1) {
                                $$.tipo=2;
                                $$.doble=fmod($1.doble,$3.entero);	
                            }
                            //Doble/Doble
                            else if($1.tipo==2&&$3.tipo==2) {
                                $$.tipo=2;
                                $$.doble=fmod($1.doble,$3.doble);	
                            }
                            //En otro caso es una operacion invalida.
                            else
                                printf("ERROR: Tipos incompatibles\n");
	}
    | POW '(' exp ',' exp ')' { 
		//Entero/Entero
        if( $3.tipo == 1 && $5.tipo == 1 ) {
        	$$.tipo = 2;
        	$$.doble = pow( $3.entero, $5.entero);	
        }
		//Entero/Doble
		else if($3.tipo==1&&$5.tipo==2) {
        	$$.tipo=2;
        	$$.doble=pow($3.entero,$5.doble);	
		}
        //Doble/Entero
        else if($3.tipo==2&&$5.tipo==1) {
        	$$.tipo=2;
            $$.doble=pow($3.doble,$5.entero);	
        }
        //Doble/Doble
        else if($3.tipo==2&&$5.tipo==2) {
        	$$.tipo=2;
            $$.doble=pow($3.doble,$5.doble);	
        }
        //String/Entero
        else if( $3.tipo == 3 && $5.tipo == 1) {
        	$$.tipo = 3;
			int i, j, n, c; //i = length of the string
			for(i=0; $3.string[i] != '\0'; i++);

			char* aux;
			aux = (char*) malloc ( sizeof(char) * i );

			if( $5.entero > 0 ) {	//potencia positiva

				$$.string = (char*) malloc( sizeof(char) * i * $5.entero);

				for( n = 0; n < i; n++ ) {
					aux[n] = $3.string[n];
				}
				for	(j = 0; j < $5.entero; j++) {
					for	(n = 0; n < i; n++) {
						$$.string[j * i + n] = aux[n];
					}
				}
			} else {	//potencia positiva
				$$.string = (char*) malloc( sizeof(char) *i * $5.entero * -1);
				c=i-1;
				for( n=0; n<i; n++ ) {
					aux[n] = $3.string[c];
					c--;
				}
				for	(j = 0; j < $5.entero * -1; j++) {
					for	(n=0; n<i; n++) {
						$$.string[j * i + n] = aux[n];
					}
				}
			}
        }
        //En otro caso es una operacion invalida.
        else
        	printf("ERROR: Tipos incompatibles\n");
	}
	| '-' exp { 
		//-Entero
		if($2.tipo==1) {
			$$.tipo = 1;
			$$.entero = - $2.entero;	
		}
		//-Doble
		else if($2.tipo==2) {
			$$.tipo = 2;
			$$.doble = - $2.doble;	
		}
		//Tipos Incompatibles
		else {
			printf("ERROR: Tipos incompatibles\n");
		}
	}
	| '+' exp { 
		//+Entero
		if($2.tipo==1) {
			$$.tipo = 1;
			$$.entero = $2.entero;	
		}
		//+Doble
		else if($2.tipo==2) {
			$$.tipo = 2;
			$$.doble = $2.doble;	
		}
		//Tipos Incompatibles
		else {
			printf("ERROR: Tipos incompatibles\n");
		}
	}
	| INT ID ';' {
		if(search($2)==0){
			push($2,NULL,1); 
			//print();
			$$.tipo = 1;
			$$.entero = 0;
		}else{
			printf("ERROR: Ya existe un elemento con ese ID\n");
		}
	}
	| INT ID '=' exp ';' 	 { 
		char *s=malloc(sizeof(char) * 128); 
		char *id=malloc(sizeof(char) * 128); 
		id=$2; 
		if(search($2)==0){
			if($4.tipo==1||$4.tipo==2){
				if($4.tipo==2)
					snprintf(s, sizeof(s), "%f", $4.doble);
				else {
					snprintf(s, sizeof(s), "%d", $4.entero);
				}
				push(id,s,1);
				//print();
				$$.tipo = 1;
				$$.entero = $4.entero;
			}else{
				printf("ERROR: Tipos incompatibles");
			} 						
			//$$ = $2;
		}else{
			printf("ERROR: Ya existe un elemento con ese ID\n");
		}
	}
	| DOUBLE ID ';'		 { 
						if(search($2)==0){
										push($2,NULL,2); 
										//print();
										$$.tipo = 2;
						   				$$.doble = 0;
						   				}else{
												printf("ERROR: Ya existe un elemento con ese ID\n");
						   					}
	}
	| DOUBLE ID '=' exp ';' 	 { 
							char *s=malloc(sizeof(char) * 128); 
						   	char *id=malloc(sizeof(char) * 128); 
						   	id=$2; 
						   	if(search($2)==0){
						   						if($4.tipo==2||$4.tipo==1){
						   										if($4.tipo==1)
															   	snprintf(s, sizeof(s), "%d", $4.entero);
															   	else
															   	snprintf(s, sizeof(s), "%f", $4.doble);
															   	push(id,s,2);
															   	//print();
																$$.tipo = 2;
						   										$$.doble = $4.doble;
																}else{
																		printf("ERROR: Tipos incompatibles\n");
																} 						
						   						//$$ = $2;
						   					}else{
													printf("ERROR: Ya existe un elemento con ese ID\n");
						   							}
	}
	| STRING ID ';'		 { 
						if(search($2)==0){
										push($2,NULL,3); 
										//print();
										$$.tipo = 3;
						   				$$.string = NULL;
						   				}else{
												printf("ERROR: Ya existe un elemento con ese ID\n");
						   					}
	}
	| STRING ID '=' exp ';' 	 { 
							char *s=malloc(sizeof(char) * 128); 
						   	char *id=malloc(sizeof(char) * 128); 
						   	id=$2; 
						   	if(search($2)==0){
						   						if($4.tipo==3){
															   	push(id,$4.string,$4.tipo);
															   	//print();
																$$.tipo = 3;
						   										$$.string = $4.string;
																}else{
																		printf("ERROR: Tipos incompatibles\n");
																}
						   					}else{
													printf("ERROR: Ya existe un elemento con ese ID\n");
						   							}
	}
	| ID '=' exp ';' 		 { 
							
						   	char *id = malloc( sizeof(char) * 128); 
						   	id=$1;

						   		if(search(id)==0){
						   						printf("ERROR: Variable no declarada\n");
						   					}else{
						   							if($3.tipo==1){
						   							char *s = malloc( sizeof(int) ); 
						   							snprintf(s, sizeof(s), "%d", $3.entero);
						   							modify(id,s,$3.tipo);
						   							//print(); 						
						   							//$$ = $1;
						   							}
						   							if($3.tipo==2){
						   							char *s = malloc( sizeof(double) ); 
						   							snprintf(s, sizeof(s), "%f", $3.doble);
						   							modify(id,s,$3.tipo);
						   							//print(); 						
						   							//$$ = $1;
						   							}
						   							if($3.tipo==3){
						   							modify(id,$3.string,$3.tipo);
						   							//print(); 						
						   							//$$ = $1;
						   							}
						   							}
	}
	| ID {
		struct element aux;
		aux.id = malloc(255);
		aux.value = malloc(255);
		aux = consulta($1);
		if( aux.type == 1){
			$$.tipo=aux.type;
			if(aux.value!=NULL) {
				$$.entero=atoi(aux.value);
			}
		}
		if(aux.type==2){
			$$.tipo=aux.type;
			$$.doble=atof(aux.value);
		}
		if(aux.type==3){
			$$.tipo=aux.type;
			$$.string=aux.value;
		}
		if(aux.type==4){
			printf("ERROR: Variable no declarada\n");
		}	
    }
;           

%%

void main() {
	new=(Cola*)malloc(sizeof(Cola));
	new->size=0;
	new->last=NULL;
	new->first=NULL;
  	yyparse();
}
             
void yyerror (char *s) {
	printf ("--%s--\n", s);
}
            
int yywrap() {  
	return 1;  
}

//Funciones 

void push(char *id,char *value,int type){

	//Si es el primer elemento
	if(search(id)==1){
		//printf("ERROR: Ya existe un elemento con ese ID\n");
	}else{
		if(new->size==0){
			Element *i;
			i=(Element*)malloc(sizeof(Element));
			i->id=malloc(sizeof(char) * 128);
			i->value=malloc(sizeof(char) * 128);
			i->id=id;
			i->value=value;
			i->type=type;
			i->next=NULL;
			new->first=i;
			new->last=i;
			new->size++;
			}
		else {
			Element *i;
			i=(Element*)malloc(sizeof(Element));
			i->id=malloc(sizeof(char) * 128);
			i->value=malloc(sizeof(char) * 128);
			new->last->next=i;
			i->id=id;
			i->value=value;
			i->type=type;
			i->next=NULL;
			new->last=i;
			new->size++;
		}
	}
}

void print(){
	struct element *control;

	control=NULL;
	//Impresion de la cola dinamica
	if(new->first==NULL&&new->last==NULL){
		//printf("ERROR: No hay nada que imprimir\n");										
	}else{
		printf("La cola está formada por los elementos:\n");
		control=new->first;
		do{ 
			printf("Id: %s, Valor: %s, Value %d\n",control->id,control->value,control->type);
			control=control->next;
		}while(control);
		printf("\n");															
	}	
}

bool search(char *id){
	struct element *control;
	bool encontrado;

	encontrado=false;
	control=NULL;

	if(new->first==NULL&&new->last==NULL){
		//printf("ERROR: No hay nada que imprimir\n");
	}else{
		//printf("Elementos encontrados:\n");
		control=new->first;
		do{ 
			if(0==strcmp(control->id,id)){
				//printf("Id: %s, Valor: %s",control->id,control->value);
				if(control->type==1)
				printf(" Tipo: int\n");
				if(control->type==2)
				printf(" Tipo: double\n");
				if(control->type==3)
				printf(" Tipo: String\n");
				encontrado=true;
			}
			control=control->next;
		}while(control);
		printf("\n");
	}
	return encontrado;	
}

void modify(char *id,char *value, int tipo){

	struct element *control;
	control=NULL;

	if(new->first==NULL&&new->last==NULL){
		//printf("ERROR: No hay nada que imprimir\n");
	}else{
		//printf("Elementos encontrados:\n");
		control=new->first;
		do{ 
			if(0==strcmp(control->id,id)){
				if(control->type==tipo||(tipo==2&&control->type==1)||(tipo==1&&control->type==2)){
				control->value=value;
				//printf("Id: %s, Valor: %s, Value %d\n",control->id,control->value,control->type);
				}else{
				printf("ERROR: Tipos incompatibles\n");
				}
			}
			control=control->next;
		}while(control);
		//printf("\n");
	}
}

struct element consulta(char *id){
	struct element *control;
	struct element aux;
	aux.id=malloc(255);
	aux.value=malloc(255);
	control=NULL;

	if(new->first==NULL&&new->last==NULL){
		//printf("ERROR: No hay nada que imprimir\n");
	}else{
		//printf("Elementos encontrados:\n");
		control=new->first;
		do{ 
			if(0==strcmp(control->id,id)){
				aux=*control;
				return aux;
			}
			control=control->next;
		}while(control);
		printf("\n");
	}
	aux.type=4;
	return aux;	
}