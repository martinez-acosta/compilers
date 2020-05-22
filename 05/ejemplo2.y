%{
#include <stdio.h>
#define INT_ 0x01
#define DOUBLE_ 0x02
#define STRING_ 0x03
#define NUMBER_ 0x04
#define UNDEF_ 0x05
#define ARR_ 0x06

int yylex(void);
void yyerror (char *);
char * restarCadena(char*, char*);
char * sumarCadena(char*, char*);
char * powCadena(char*,int);
char * divCadena(char*,char*);
char * invertirCadena(char*);
char isBinA(char*,char*);
void appendChar(char*,char);
void copiarCadena(char *, char *, int);
char compararCadena(char *, char *);
int longitudCadena(char*);

typedef struct Valor {
        int entero;
        double decimal;
        char* palabra;
        double* arr;
        int tamArr;
}Valor;

typedef struct Simbolo {
    char    *nombre;
    int tipo;
    struct Valor valor;
    struct Simbolo *next;
} Simbolo;

typedef struct TablaSimbolos {
    Simbolo *first;
}TablaSimbolos;


//Funciones tabla de símbolos
void imprimirTabla();
void imprimirSimbolo(Simbolo*);
void agregarSimbolo(char*,int,Valor*);
Simbolo* obtenerSimbolo(char*);
char existeSimbolo(char*);
void agregarInt(char*name,int val);
void agregarDouble(char*name,double val);
void agregarString(char*name,char* val);

%}

/* Declaraciones de BISON */
%union{
    int entero;
    double decimal;
    char* palabra;
    struct Dato {
            char tipo;
            double numero;
            char* palabra;
    }dato;
}
%token POW DIV INT DOUBLE STRING IF

%token <entero> ENTERO
%token <decimal> DECIMAL
%token <palabra> ID

%type <entero> exp_entera
%type <decimal> exp_decimal
%type <palabra> exp_string
%type <dato> expr
//Para expr hay cuatro tipos de datos:
//Puede ser una expresión de enteros
//Puede ser una expresión de doubles
//Puede ser una expresión de cadenas
//O puede ser una combinación no válida, que es UNDEF_
%left '+' '-'
%left '*' '/'
%right '%'
%right '='
%left UNARYMINUS

/* Gramática */
%%

input:    /* cadena vacía */
| input line
;
line:     '\n'
| 'p' {imprimirTabla();}
| decl ';' '\n' {printf("\n");}
| exp_entera '\n' {printf("res entero-%d-\n",$1);}
| exp_decimal '\n'{printf("res decimal -%f-\n",$1);}
| exp_string '\n' {printf("res string-%s-\n",$1);}
| error
;

//expresiones
decl:     ID
| INT ID {
    if(existeSimbolo($2))
        printf("El símbolo ya existe\n");
    else {
        Valor *tmp = malloc(sizeof(Valor));
        agregarSimbolo($2,INT_,tmp);
    }
}
| DOUBLE ID {
    if(existeSimbolo($2))
        printf("El símbolo ya existe\n");
    else {
        Valor *tmp = malloc(sizeof(Valor));
        agregarSimbolo($2,DOUBLE_,tmp);
    }
}
| STRING ID {
    if(existeSimbolo($2))
        printf("El símbolo ya existe\n");
    else {
        Valor *tmp = malloc(sizeof(Valor));
        agregarSimbolo($2,STRING_,tmp);
    }
}
| DOUBLE ID '[' ENTERO ']' {
    printf("Expresión inválida.\n");
    if(existeSimbolo($2))
        printf("El símbolo ya existe\n");
    else {
        Valor *tmp = malloc(sizeof(Valor));
        tmp->arr = malloc(sizeof($4));
        tmp->tamArr = $4;
        agregarSimbolo($2,ARR_,tmp);
    }
}

| INT ID '=' expr {
    if ( existeSimbolo($2) )
        printf("El símbolo ya existe\n");
    else {
        Valor *tmp = malloc(sizeof(Valor));
        switch ($4.tipo) {
        case NUMBER_:
            tmp->entero = $4.numero;
            agregarSimbolo($2,INT_,tmp);
            break;
        case STRING_:
        case UNDEF_:
            printf("expr inválida");
            break;
        }
    }
}
| DOUBLE  ID '=' expr {
    if(existeSimbolo($2))
        printf("El símbolo ya existe\n");
    else {
        Valor *tmp = malloc(sizeof(Valor));
        switch ($4.tipo) {
        case NUMBER_:
            tmp->decimal = $4.numero;
            agregarSimbolo($2,DOUBLE_,tmp);
            break;
        case STRING_:
        case UNDEF_:
            printf("expr inválida");
            break;
        }
    }
}
| STRING ID '=' expr {
    if ( existeSimbolo($2) )
        printf("El símbolo ya existe\n");
    else {
        Valor *tmp = malloc(sizeof(Valor));
        switch ($4.tipo) {
        case STRING_:
            tmp->palabra = $4.palabra;
            agregarSimbolo($2,STRING_,tmp);
            break;
        case NUMBER_:
        case UNDEF_:
            printf("expr inválida");
            break;
        }
    }
}
| ID '[' ENTERO ']' '=' expr {
    printf("llegamos\n");

    if (!existeSimbolo($1)) {
        printf("no existe el símbolo, expr inválida\n");
        //$$.tipo = UNDEF_;
    } else {
        printf("llegamos\n");

        Simbolo *sim = obtenerSimbolo($1);
        if (sim->tipo == INT_ || sim->tipo == DOUBLE_ || sim->tipo == STRING_) {
            //$$.tipo = UNDEF_;
            printf("expr inválida, no es un array el símbolo que intenta accesar.\n");
        } else if (sim->tipo == ARR_) {
            if ($3 > sim->valor.tamArr) {
              printf("está fuera del rango del array, use un num más pequeño\n");
            }
            switch ($6.tipo) {
            case NUMBER_:
                *(sim->valor.arr + $3) = $6.numero;//asignamos en el array
                //$$.numero = $6.numero;//asignamos en la expr recursiva
                //$$.tipo = NUMBER_;
                break;

            default:
                //algo salió mal
                printf("Deje de asginar cosas que no v:\n");
                //$$.tipo = UNDEF_;
                break;
            }

        }
    }
    printf("ID [%d] \t",$3);
}
| ID '=' expr {
    if ( !existeSimbolo($1) )
        printf("El símbolo no existe\n");
    else if ($3.tipo == UNDEF_)
        printf("expr inválida\n");
    else {
        printf("Símbolo encontrado\n");
        Simbolo *sim = obtenerSimbolo($1);
        switch (sim->tipo) {
        case INT_:
            if ( $3.tipo == NUMBER_)
                sim->valor.entero = $3.numero;
            else if ($3.tipo == STRING_)
                printf("No intente asignar un string a un entero. Tipo de datos incompatibles.\n");
            break;
        case DOUBLE_:
            if ( $3.tipo == NUMBER_)
                sim->valor.decimal = $3.numero;
            else if ($3.tipo == STRING_)
                printf("No intente asignar un string a un double. Tipo de datos incompatibles.\n");
            break;
        case STRING_:
            if ( $3.tipo == NUMBER_)
                printf("No intente asignar un entero/double a un string. Tipo de datos incompatibles.\n");
            else if ($3.tipo == STRING_)
                sim->valor.palabra = $3.palabra;
            break;
        }
    }
    printf("id: %s\n",$1);
}
| INT '=' expr { printf("Nombre de variable inválido, debe empezar por alguna letra\n"); }
| DOUBLE '=' expr { printf("Nombre de variable inválido, debe empezar por alguna letra\n"); }
| STRING '=' expr { printf("Nombre de variable inválido, debe empezar por alguna letra\n"); }
| IF '('expr '>' expr ')' {
    if ($3.numero>$5.numero)
        printf("Expresión 1 es mayor a expresión 2, VERDADERO\n");
    else
        printf("FALSO\n");
}
;
expr: exp_entera {
    $$.tipo = NUMBER_;
    $$.numero = $1;
    printf("expr: expr_entera\n");
                 }
| exp_decimal {
    $$.tipo = NUMBER_;
    $$.numero = $1;
    printf("expr: expr_decimal\n");
              }
| exp_string {
    $$.tipo = STRING_;
    $$.palabra = $1;
    printf("expr: expr_string\n");
             }
| ID '[' ENTERO ']' {
    printf("llegamos1\n");

    if (!existeSimbolo($1)) {
        printf("no existe el símbolo, expr inválida\n");
        $$.tipo = UNDEF_;
    } else {
        printf("llegamos1\n");

        Simbolo *sim = obtenerSimbolo($1);
        if (sim->tipo == INT_ || sim->tipo == DOUBLE_ || sim->tipo == STRING_) {
            $$.tipo = UNDEF_;
            printf("expr inválida, no es un array el símbolo que intenta accesar.\n");
        } else if (sim->tipo == ARR_) {
            if ($3 > sim->valor.tamArr) {
              printf("está fuera del rango del array, use un num más pequeño\n");
            }
                $$.numero = *(sim->valor.arr + $3);//asignamos en la expr recursiva
                $$.tipo = NUMBER_;
                printf("Valor es: %f\n",*(sim->valor.arr + $3));
        }
    }
    printf("ID [%d] \t",$3);
}
| exp_entera '+' expr {
    switch ($3.tipo) {
    case NUMBER_:
        $$.numero = $1+$3.numero;
        $$.tipo = NUMBER_;
        break;
    case STRING_:
    case UNDEF_:
        $$.numero = 0;
        $$.tipo = UNDEF_;
        printf("Operación inválida, no puede sumar un número con un string\n");
        break;
    }
    printf("expr: expr_entera + expr\n");
}
| exp_entera '-' expr {
    switch ($3.tipo) {
    case NUMBER_:
        $$.numero = $1-$3.numero;
        $$.tipo = NUMBER_;
        break;
    case STRING_:
    case UNDEF_:
        $$.tipo = UNDEF_;
        $$.numero = 0;
        printf("Operación inválida, no puede restar un número con un string\n");
        break;
    }
    printf("expr: expr_entera - expr\n");
}
| exp_entera '/' expr {
    switch ($3.tipo) {
    case NUMBER_:
        if ($3.numero == 0.0)
            printf("No se puede dividir entre cero.\n");
        $$.numero = $1/$3.numero;
        $$.tipo = NUMBER_;
        break;
    case STRING_:
    case UNDEF_:
        $$.tipo = UNDEF_;
        printf("Operación inválida, no puede dividir un número con un string\n");
        break;
    }
    printf("expr: expr_entera / expr\n");
}
| exp_entera '*' expr {
    switch ($3.tipo) {
    case NUMBER_:
        $$.numero = $1*$3.numero;
        $$.tipo = NUMBER_;
        break;
    case STRING_:
    case UNDEF_:
        $$.tipo = UNDEF_;
        printf("Operación inválida, no puede multiplicar un número con un string\n");
        break;
    }
    printf("expr: expr_entera * expr\n");
}
| exp_entera '%' expr {
    switch ($3.tipo) {
    case NUMBER_:
        $$.numero = $1%(int)$3.numero;
        $$.tipo = NUMBER_;
        break;
    case STRING_:
    case UNDEF_:
        $$.tipo = UNDEF_;
        printf("Operación inválida, no puede multiplicar un número con un string\n");
        break;
    }
    printf("expr: expr_entera % expr\n");
}
| POW '(' exp_entera ',' expr ')' {
    switch ($5.tipo) {
    case NUMBER_:
        for (int i =1; i<(int)$5.numero;i++)
            $3 *= $3;
        $$.numero = $3;
        $$.tipo = NUMBER_;
        break;
    case STRING_:
    case UNDEF_:
        printf("Operación inválida, no puede hacer DIV de un número con un string\n");
        $$.tipo = UNDEF_;
        break;
    }
    printf("expr: DIV(expr_entera, expr)\n");
}
| exp_decimal '+' expr {
    switch ($3.tipo) {
    case NUMBER_:
        $$.numero = $1+$3.numero;
        $$.tipo = NUMBER_;
        break;
    case STRING_:
    case UNDEF_:
        printf("Operación inválida, no puede sumar un número con un string\n");
        $$.tipo = UNDEF_;
        break;
    }
    printf("expr: expr_decimal + expr\n");
}
| exp_decimal '-' expr {
    switch ($3.tipo) {
    case NUMBER_:
        $$.numero = $1-$3.numero;
        $$.tipo = NUMBER_;
        break;
    case STRING_:
    case UNDEF_:
        $$.tipo = UNDEF_;
        printf("Operación inválida, no puede restar un número con un string\n");
        break;
    }
    printf("expr: expr_decimal - expr\n");
}
| exp_decimal '/' expr {
    switch ($3.tipo) {
    case NUMBER_:
        if($3.numero == 0.0) {
            printf("No se puede dividir entre cero\n");
            $$.numero = 0;
        }else
            $$.numero = $1/$3.numero;
        $$.tipo = NUMBER_;
        break;
    case STRING_:
    case UNDEF_:
        printf("Operación inválida, no puede dividir un número con un string\n");
        $$.tipo = UNDEF_;
        break;
    }

    printf("expr: expr_decimal / expr\n");
}//compiladores19@gmail.com
| exp_decimal '*' expr {
    switch ($3.tipo) {
    case NUMBER_:
            $$.numero = $1*$3.numero;
            $$.tipo = NUMBER_;
        break;
    case STRING_:
    case UNDEF_:
        printf("Operación inválida, no puede multiplicar un número con un string\n");
        $$.tipo = UNDEF_;
        break;
    }
    printf("expr: expr_decimal * expr\n");
}
| exp_decimal '%' expr {
    switch ($3.tipo) {
    case NUMBER_:
            $$.numero = (int)$1%(int)$3.numero;
            $$.tipo = NUMBER_;
        break;
    case STRING_:
    case UNDEF_:
        printf("Operación inválida, no puede multiplicar un número con un string\n");
        $$.tipo = UNDEF_;
        break;
    }
    printf("expr: expr_decimal % expr\n");
}
| POW '(' exp_decimal ',' expr ')' {
    switch ($5.tipo) {
    case NUMBER_:
        $3 = (int)$3;
        for (int i =1; i<(int)$5.numero;i++)
            $3 *= $3;
        $$.numero = (int)$3;
        $$.tipo = NUMBER_;
        break;
    case STRING_:
    case UNDEF_:
        printf("Operación inválida, no puede hacer DIV de un número con un string\n");
        $$.tipo = UNDEF_;
        break;
    }
    printf("expr: DIV(expr_decimal, expr)\n");
}
| exp_string '+' expr {
    switch ($3.tipo) {
    case STRING_:
        $$.palabra = sumarCadena($1,$3.palabra);
        $$.tipo = STRING_;
        break;
    case NUMBER_:
    case UNDEF_:
        $$.tipo = UNDEF_;
        printf("Operación inválida, no puede sumar un string con un número\n");
        break;
    }
    printf("expr: expr_string + expr\n");
}
| exp_string '-' expr {
    switch ($3.tipo) {
    case STRING_:
        $$.palabra = restarCadena($1,$3.palabra);
        $$.tipo = STRING_;
        break;
    case NUMBER_:
    case UNDEF_:
        printf("Operación inválida, no puede restar un string con un número\n");
        break;
    }
    printf("expr: expr_string - expr\n");
}
| exp_string '/' expr {
    switch ($3.tipo) {
    case STRING_:
        printf("Operación inválida, no puede dividir un string con otro string de esta manera, use DIV para ello\n");
        $$.tipo = UNDEF_;
        break;
    case NUMBER_:
    case UNDEF_:
        printf("Operación inválida, no puede dividir un string con un número\n");
        $$.tipo = UNDEF_;
        break;
    }
    printf("expr: expr_string / expr\n");
}
| exp_string '*' expr {
    switch ($3.tipo) {
    case STRING_:
        $$.tipo = UNDEF_;
        printf("Operación inválida, no puede multiplicar un string con otro string de esta manera, use POW para ello\n");
        $$.palabra = $1;
        break;
    case NUMBER_:
    case UNDEF_:
        $$.tipo = UNDEF_;
        printf("Operación inválida, no puede multiplicar un string con un número\n");
        break;
    }
    printf("expr: expr_string * expr\n");
}
| exp_string '%' expr {
    switch ($3.tipo) {
    case STRING_:
        $$.tipo = UNDEF_;
        printf("Operación inválida, no puede % un string con otro string de esta manera, use POW para ello\n");
        $$.palabra = $1;
        break;
    case NUMBER_:
    case UNDEF_:
        $$.tipo = UNDEF_;
        printf("Operación inválida, no puede % un string con un número\n");
        break;
    }
    printf("expr: expr_string * expr\n");
}
| DIV '(' exp_string ',' expr ')' {
    if ( $5.tipo == UNDEF_) {
        printf("expr inválida\n");
        $$.tipo = UNDEF_;
    } else {
        $$.tipo = STRING_;
        $$.palabra = divCadena($3,$5.palabra);
    }
    printf("DIV(expr,expr)\t");
}
| POW '(' exp_string ',' expr ')' {
    if ( $5.tipo == UNDEF_ || $5.tipo == STRING_ ) {
        printf("expr inválida\n");
        $$.tipo = UNDEF_;
    } else if ( $5.tipo == NUMBER_ ) {
        $$.tipo = STRING_;
        $$.palabra = powCadena(invertirCadena($3),(int)$5.numero);
    }
    printf("DIV(expr,expr)\t");
}
| expr '+' expr {
    if ( $1.tipo == NUMBER_ && $3.tipo == NUMBER_ ) {
        $$.tipo = NUMBER_;
        $$.numero = $1.numero + $3.numero;
    } else if ($1.tipo == STRING_ && $3.tipo == STRING_) {
        $$.tipo = STRING_;
        $$.palabra = sumarCadena($1.palabra,$3.palabra);
    } else {
        printf("operación con tipos de datos incompatibles\n");
        $$.tipo = UNDEF_;
    }
    printf("expr + expr\t");
}
| expr '-' expr {
    if ( $1.tipo == NUMBER_ && $3.tipo == NUMBER_ ) {
        $$.tipo = NUMBER_;
        $$.numero = $1.numero - $3.numero;
    } else if ($1.tipo == STRING_ && $3.tipo == STRING_) {
        $$.tipo = STRING_;
        $$.palabra = restarCadena($1.palabra,$3.palabra);
    } else {
        $$.tipo = UNDEF_;
        printf("operación con tipos de datos incompatibles\n");
    }
    printf("expr - expr\t");
}
| expr '/' expr {
    if ( $1.tipo == NUMBER_ && $3.tipo == NUMBER_ ) {
        $$.tipo = NUMBER_;
        if ( $3.numero == 0.0 ) {
            printf("no se puede dividir entre cero.");
            $$.numero = 0;
            $$.tipo = NUMBER_;
        } else
            $$.numero = $1.numero / $3.numero;
    } else {
        $$.tipo = UNDEF_;
        printf("operación con tipos de datos incompatibles\n");
    }
    printf("expr / expr\t");
}
| expr '*' expr {
    if ( $1.tipo == NUMBER_ && $3.tipo == NUMBER_ ) {
        $$.tipo = NUMBER_;
            $$.numero = $1.numero * $3.numero;
    } else {
        $$.tipo = UNDEF_;
        printf("operación con tipos de datos incompatibles\n");
    }
    printf("expr * expr\t");
}
| expr '%' expr {
    if ( $1.tipo == NUMBER_ && $3.tipo == NUMBER_ ) {
        $$.tipo = NUMBER_;
            $$.numero = (int)$1.numero % (int)$3.numero;
    } else {
        $$.tipo = UNDEF_;
        printf("operación con tipos de datos incompatibles\n");
    }
    printf("expr % expr\t");
}
| DIV '(' expr ',' expr ')' {
    if ($3.tipo == UNDEF_ || $5.tipo == UNDEF_) {
        printf("expr inválida\n");
        $$.tipo = UNDEF_;
    } else if ($3.tipo == STRING_ && $5.tipo == STRING_) {
        $$.tipo = STRING_;
        $$.palabra = divCadena($3.palabra,$5.palabra);
    } else {
        printf("expr inválida, solo puede usarse este operador entre cadenas\n");
        $$.tipo = UNDEF_;
    }
    printf("DIV(expr,expr)\t");
}
| POW '(' expr ',' expr ')' {
    if ( $3.tipo == UNDEF_ || $5.tipo == UNDEF_ ) {
        printf("expr inválida\n");
        $$.tipo = UNDEF_;
    } else if ( $3.tipo == STRING_ && $5.tipo == NUMBER_ ) {
        $$.tipo = STRING_;
        $$.palabra = powCadena($3.palabra,(int)$5.numero);
    } else if ( $3.tipo == NUMBER_ && $5.tipo == NUMBER_ ) {
        $3.numero = (int)$3.numero;
        for (int i =1; i <(int)$5.numero ;i++)
            $3.numero *= $3.numero;
        $$.tipo = NUMBER_;
        $$.numero = $3.numero;
    } else {
        printf("expr inválida, solo puede usarse este operador entre cadenas\n");
        $$.tipo = UNDEF_;
    }
    printf("DIV(expr,expr)\t");
}
| ID            {
    if (!existeSimbolo($1)) {
        printf("no existe el símbolo, expr inválida\n");
        $$.tipo = UNDEF_;
    } else {
        Simbolo *sim = obtenerSimbolo($1);
        if (sim->tipo == INT_ ) {
            $$.tipo = NUMBER_;
            $$.numero = sim->valor.entero;
        } else if (sim->tipo == DOUBLE_) {
            $$.tipo = NUMBER_;
            $$.numero = sim->valor.decimal;
        } else if (sim->tipo == STRING_){
            $$.tipo = STRING_;
            $$.palabra = sim->valor.palabra;
        }
    }
    printf("ID\t");
}
| ID '+' expr     {
    if (!existeSimbolo($1)) {
        printf("no existe el símbolo, expr inválida\n");
        $$.tipo = UNDEF_;
    } else if( $3.tipo == UNDEF_ ) {
        printf("expr inválida\n");
    } else {
        Simbolo *sim = obtenerSimbolo($1);
        if (sim->tipo == INT_ && $3.tipo == NUMBER_){
            $$.tipo = NUMBER_;
            $$.numero = sim->valor.entero + $3.numero;
        } else if (sim->tipo == DOUBLE_ && $3.tipo == NUMBER_ ) {
            $$.tipo = NUMBER_;
            $$.numero = sim->valor.decimal + $3.numero;
        } else if (sim->tipo == STRING_ && $3.tipo == STRING_ ){
            $$.tipo = STRING_;
            $$.palabra = sumarCadena(sim->valor.palabra,$3.palabra);
        }
    }
    printf("ID + expr\t");
}
| ID '-' expr     {
    if (!existeSimbolo($1)) {
        printf("no existe el símbolo, expr inválida\n");
        $$.tipo = UNDEF_;
    } else if( $3.tipo == UNDEF_ ) {
        printf("expr inválida\n");
    } else {
        Simbolo *sim = obtenerSimbolo($1);
        if (sim->tipo == INT_ && $3.tipo == NUMBER_){
            $$.tipo = NUMBER_;
            $$.numero = sim->valor.entero - $3.numero;
        } else if (sim->tipo == DOUBLE_ && $3.tipo == NUMBER_ ) {
            $$.tipo = NUMBER_;
            $$.numero = sim->valor.decimal - $3.numero;
        } else if (sim->tipo == STRING_ && $3.tipo == STRING_ ){
            $$.tipo = STRING_;
            $$.palabra = restarCadena(sim->valor.palabra,$3.palabra);
        }
    }
    printf("ID - expr\t");
}
| ID '/' expr     {
    if (!existeSimbolo($1)) {
        printf("no existe el símbolo, expr inválida\n");
        $$.tipo = UNDEF_;
    } else if( $3.tipo == UNDEF_ ) {
        printf("expr inválida\n");
    } else {
        Simbolo *sim = obtenerSimbolo($1);
        if (sim->tipo == INT_ && $3.tipo == NUMBER_){
            $$.tipo = NUMBER_;
            if ( $3.numero == 0.0 ) {
                printf("No se puede dividir entre cero\n");
                $$.numero = 0;
            } else
                $$.numero = sim->valor.entero / $3.numero;
            $$.tipo = NUMBER_;
        } else if ( sim->tipo == DOUBLE_ && $3.tipo == NUMBER_ ) {
            if ( $3.numero == 0.0 ) {
                printf("No se puede dividir entre cero\n");
                $$.numero = 0;
            } else
                $$.numero = sim->valor.decimal / $3.numero;
            $$.tipo = NUMBER_;
        } else if ( sim->tipo == STRING_ && $3.tipo == STRING_ ){
            $$.tipo = UNDEF_;
            printf("expr inválida, para dividir cadenas use DIV\n");
        }
    }
    printf("ID / expr\t");
}
| ID '*' expr     {
    if (!existeSimbolo($1)) {
        printf("no existe el símbolo, expr inválida\n");
        $$.tipo = UNDEF_;
    } else if( $3.tipo == UNDEF_ ) {
        printf("expr inválida\n");
    } else {
        Simbolo *sim = obtenerSimbolo($1);
        if (sim->tipo == INT_ && $3.tipo == NUMBER_){
            $$.tipo = NUMBER_;
            $$.numero = sim->valor.entero * $3.numero;
        } else if (sim->tipo == DOUBLE_ && $3.tipo == NUMBER_ ) {
            $$.tipo = NUMBER_;
            $$.numero = sim->valor.decimal * $3.numero;
        } else if (sim->tipo == STRING_ && $3.tipo == STRING_ ){
            $$.tipo = UNDEF_;
            printf("expr inválida, para multiplicar cadenas use POW\n");
        }
    }
    printf("ID * expr\t");
}
| ID '%' expr     {
    if (!existeSimbolo($1)) {
        printf("no existe el símbolo, expr inválida\n");
        $$.tipo = UNDEF_;
    } else if( $3.tipo == UNDEF_ ) {
        printf("expr inválida\n");
    } else {
        Simbolo *sim = obtenerSimbolo($1);
        if (sim->tipo == INT_ && $3.tipo == NUMBER_){
            $$.tipo = NUMBER_;
            $$.numero = (int)sim->valor.entero % (int)$3.numero;
        } else if (sim->tipo == DOUBLE_ && $3.tipo == NUMBER_ ) {
            $$.tipo = NUMBER_;
            $$.numero = (int)sim->valor.decimal % (int)$3.numero;
        } else if (sim->tipo == STRING_ && $3.tipo == STRING_ ){
            $$.tipo = UNDEF_;
            printf("expr inválida, para multiplicar cadenas use POW\n");
        }
    }
    printf("ID % expr\t");
}
;


//decimal con decimal
exp_decimal:    DECIMAL    { $$ = $1; }
| exp_decimal '+' exp_decimal        { $$ = $1 + $3;    }
| exp_decimal '-' exp_decimal        { $$ = $1 - $3;    }
| exp_decimal '*' exp_decimal        { $$ = $1 * $3;    }
| POW '(' exp_decimal ',' exp_decimal ')'        {
    for(int i = 1; i<(int)$5; i++)
        $3 *= $3;
    $$ = (int)$3;
}
| exp_decimal '%' exp_decimal        { $$ = (int)$1 % (int)$3;    }
| exp_decimal '/' exp_decimal        { if( $3 == 0.0f ) { printf("El denominador no debe ser cero\n"); $$=0; } else { $$ = $1 / $3; } }
| exp_entera '+' exp_decimal        { $$ = $1 + $3;    }
| exp_entera '-' exp_decimal        { $$ = $1 - $3;    }
| exp_entera '*' exp_decimal        { $$ = $1 * $3;    }
| exp_entera '%' exp_decimal        { $$ = (int)$1 % (int)$3;    }
| exp_entera '/' exp_decimal        { if( $3 == 0.0f ) { printf("El denominador no debe ser cero\n"); $$=0; } else { $$ = $1 / $3; } }
| exp_decimal '+' exp_entera        { $$ = $1 + $3;    }
| exp_decimal '-' exp_entera        { $$ = $1 - $3;    }
| exp_decimal '*' exp_entera        { $$ = $1 * $3;    }
| POW '(' exp_decimal ',' exp_entera ')'        {
    for(int i = 1; i<$5; i++)
        $3 *= $3;
    $$ = (int)$3;
}
| exp_decimal '%' exp_entera        { $$ = (int)$1 % (int)$3;    }
| exp_decimal '/' exp_entera        { if( $3 == 0 ) { printf("El denominador no debe ser cero\n"); $$=0; } else { $$ = $1 / $3; } }
| '-' exp_decimal  %prec UNARYMINUS { $$ = -$2; }
;

//cadena
exp_string:      '"' ID  '"' {  $$ = $2; }
| exp_string '+' exp_string        { $$ = sumarCadena($1,$3); }
| exp_string '-' exp_string        { $$ = restarCadena($1,$3); }
| DIV '(' exp_string ',' exp_string ')' {  $$ = divCadena($3,$5);  }
| POW '(' exp_string ',' exp_entera ')' {
    if( $5 < 0 ) {
        //printf("menor a cero. Cadena invertida:\n%s",invertirCadena($3));
        $$ = powCadena(invertirCadena($3),$5*-1);
    } else if ( $5 == 0) {
        $$ = $3;
    } else {
        $$ = powCadena($3,$5);
    }

}
;

//entero con entero
exp_entera:      ENTERO    { $$ = $1; }
| exp_entera '+' exp_entera        { $$ = $1 + $3; }
| exp_entera '-' exp_entera        { $$ = $1 - $3; }
| exp_entera '*' exp_entera        { $$ = $1 * $3; }
| exp_entera '%' exp_entera        { $$ = $1 % $3; }
| POW '(' exp_entera ',' exp_entera ')'        {
    for(int i = 1; i<$5; i++)
        $3 *= $3;
    $$ = $3;
}
| exp_entera '/' exp_entera        { if($3 == 0)  { printf("El denominador no debe ser cero\n"); $$=0; } else { $$ = $1 / $3; }    }
| '-' exp_entera  %prec UNARYMINUS { $$ = -$2; }
;

%%

TablaSimbolos table; // global

int main() {
  table.first = NULL;
  yyparse();
  return 0;
}

Simbolo * obtenerSimbolo(char *name){
    for (Simbolo *i = table.first; i != NULL; i = i->next)
        if (compararCadena(name,i->nombre))
            return i;
}

void agregarSimbolo(char *nombre,int tipo, Valor *valor) {
    Simbolo *i;

    if (table.first == NULL ) {
        i = malloc(sizeof(Simbolo));
        i->nombre = nombre;
        i->tipo = tipo;
        i->valor = *valor;
        i->next = NULL;
        table.first = i;
    } else {

    for (i  = table.first ; i->next != NULL; i = i->next)
        ;

    i->next = malloc(sizeof(Simbolo));
    i->next->nombre = nombre;
    i->next->tipo = tipo;
    i->next->valor = *valor;
    i->next->next = NULL;
    }
    //imprimirSimbolo(table.first->next);
    imprimirTabla();
}

void imprimirSimbolo(Simbolo *i){
    switch (i->tipo) {
    case INT_:
        printf("%s\t\tint\t%d\n",i->nombre, i->valor.entero);
        break;
    case DOUBLE_:
        printf("%s\t\tdouble\t%f\n",i->nombre, i->valor.decimal);
        break;
    case STRING_:
        printf("%s\t\tstring\t%s\n",i->nombre, i->valor.palabra);
        break;
    case ARR_:
        printf("%s[%d]\tarray double\n",i->nombre, i->valor.tamArr);
        break;
    default:
        printf("%s\tint\t%d\n",i->nombre, i->valor.entero);
        printf("algo anda mal\n");
        break;
    }
}
char existeSimbolo(char*nombre){

    for (Simbolo *i = table.first; i != NULL; i = i->next)
        if (compararCadena(nombre,i->nombre))
            return 1;
    return 0;

}
void imprimirTabla(){
    printf("----------------------------------------------------\n");
    printf("Nombre\t\t tipo\tvalor\n");

    for (Simbolo *i = table.first; i != NULL; i = i->next)
        imprimirSimbolo(i);
}

int longitudCadena(char *a) {
    int i;
    for ( i = 0; a[i] != '\0'; i++)
        ;
    return i;
}

char isBinA(char*a, char*b) {
    int sizeA = longitudCadena(a);
    int sizeB = longitudCadena(b);

    if ( sizeB > sizeA )//es mayor la longitud de b, terminamos
        return 0;
    //Si 'b' está en 'a'...

    for ( int i = 0; i<sizeA; i++ )//recorremos cadena 'a'
        if ( a[i] != '\0' && compararCadena(a+i,b) )
            return 1;

    return 0;
}

char * restarCadena(char *a, char *b) {

    int sizeA = longitudCadena(a);
    int sizeB = longitudCadena(b);
    int size = sizeA;

    //no interesa alojar más espacio del necesario
    //total, termina de imprimir la cadena al encontrar el primer '\0'
    char * str = malloc(size+1);

    //limpiamos cadena
    for (int i = 0; i < size+1; i++)
        str[i] = 0;


    //verificamos que la cadena b esté contenida en 'a'
    if (!isBinA(a,b))//si no está, regresamos simplemente 'a'
        return a;

    //quitamos la primer instancia de 'b'

    for (int i = 0; i < sizeA; i++)
        if (a[i] != '\0' && compararCadena(a+i,b)) {
            //copiamos lo anterior de la cadena
            for ( int j = 0; j < i; j++)
                str[j] = a[j];

            //copiamos lo que falta
            for ( int j = i+sizeB; j < size+1; j++){
                //printf("char: %c\n",a[j]);
                str[j-sizeB] = a[j];
            }

            //marcamos fin de cadena
            str[size+1-sizeB] = '\0';
            break;
        }

    return str;

}
char * sumarCadena(char *a, char *b){

    int sizeA = longitudCadena(a);
    int sizeB = longitudCadena(b);
    int size = sizeA+sizeB;

    char * str = malloc(size+1);

    //limpiamos cadena
    for (int i = 0; i < size; i++)
        str[i] = 0;


    //copiamos primer cadena
    for (int i = 0; i < sizeA; i++)
        *(str+i) = a[i];

    //copiamos segunda cadena
    for (int i = 0; i < sizeB; i++)
        *(str+sizeA+i) = b[i];

    str[size+1] = '\0'; //marcamos el fin de la cadena
    return str;
}

char * invertirCadena(char *a) {
    int size = longitudCadena(a);
    char * str = malloc(size);
    int i,j;
    for (i = size-1, j=0; i>=0;i--,j++)
        str[j] = a[i];

    str[j+1]='\0';

    return str;
}

char compararCadena(char *a, char *b) {
    int sizeB = longitudCadena(b);

    for (int i = 0; i < sizeB; i++)
        if (a[i] != b[i])
            return 0;

    return 1;
}
void copiarCadena(char *str, char *a, int sizeB) {

    //copiamos
    for (int i = 0; i < sizeB; i++)
        str[i] = a[i];
}
char *divCadena(char*a,char*b){

    char * str = a;//es el max tam que puede tener la cadena

    for(int i = 0; i < longitudCadena(a); i++)
        str = restarCadena(str,b);
    return str;
}
char *powCadena(char*a,int b){
    char * str = a;
    for (int i =0; i<b-1; i++)
        str = sumarCadena(str,a);
    return str;
}
void yyerror (char *s) {
  printf ("--%s--\n", s);
}

int yywrap() {
  return 1;
}
