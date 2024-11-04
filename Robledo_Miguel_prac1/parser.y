%{
    #include <stdio.h>
    #include <stdlib.h>
    extern int yylex();
    extern int yylineno;
    void yyerror(char *s);
%}

%code requires {
    #include "data.h"
    #include "functions.h"
}

%union {
    struct {
        char *lexema;
        int lenght;
        int line;
        value_info id_val;
    }
    int integer;
    float real;
    char *string;
    int boolean;
    void *no_value;
}

%token <no_value> ASSIGN ENDLINE
%token <integer> INTEGER
%token <ident> ID
%token <real> REAL
%token <string> STRING
%token <boolean> BOOLEAN
%token COS SIN TAN
%token PLUS MINUS MULT DIV MOD POW 
%token GT GE LT LE EQ NE 
%token NOT AND OR 

%start program

%%
program:
    statement_list
    ;

statement_list:
    statement ENDLINE statement_list
    | 
    ;

statement:
    assignment
    | expr_arithmetic
    | expr_boolean
    | expr_string
    | expr_trig
    ;

assignment:
    ID ASSIGN expression {
        // Aquí irá la comprobación de tipos y la asignación
        // yylval.ident.id_val.val_type = tipo de expression;
        printf("Asignación: %s := ...\n", $1.lexema);
    }
    ;

expression:
    expr_arithmetic
    | expr_boolean
    | expr_string
    | expr_trig
    ;

expr_arithmetic:
    expr_arithmetic POW expr_arithmetic
    | expr_arithmetic MULT expr_arithmetic
    | expr_arithmetic DIV expr_arithmetic
    | expr_arithmetic MOD expr_arithmetic
    | expr_arithmetic PLUS expr_arithmetic
    | expr_arithmetic MINUS expr_arithmetic
    | INTEGER
    | REAL
    | ID
    | STRING
    | '(' expr_arithmetic ')'
    ;

expr_boolean:
    expr_arithmetic GT expr_arithmetic
    | expr_arithmetic LT expr_arithmetic
    | expr_arithmetic GE expr_arithmetic
    | expr_arithmetic LE expr_arithmetic
    | expr_arithmetic EQ expr_arithmetic
    | expr_arithmetic NE expr_arithmetic
    | NOT expr_boolean
    | expr_boolean AND expr_boolean
    | expr_boolean OR expr_boolean
    | BOOLEAN
    | ID
    ;

expr_trig:
    SIN '(' expression ')' {
        $$ = sin($3); 
    }
    | COS '(' expression ')' {
        $$ = cos($3);
    }
    | TAN '(' expression ')' {
        $$ = tan($3);
    }
    | ID
    ;
    

%%
