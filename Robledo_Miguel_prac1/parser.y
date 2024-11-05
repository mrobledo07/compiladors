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
%token PI 
%token E

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
    | expression
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
    | expr_arithmetic_boolean
    | expr_trig
    | expr_len
    | expr_substr
    ;

expr_arithmetic:
    expr_op
    ;

expr_op:
    expr_term
    | PLUS expr_op
    | MINUS expr_op
    | expr_op PLUS expr_term
    | expr_op MINUS expr_term
    ;

expr_term:
    expr_pow
    | expr_term MULT expr_pow
    | expr_term DIV expr_pow
    | expr_term MOD expr_pow
    ;

expr_pow:
    factor_arithmetic
    | expr_pow POW factor_arithmetic
    ;

factor_arithmetic: 
    ID 
    | INTEGER 
    | REAL 
    | STRING 
    | PI
    | E
    | '(' expression ')' 
    ;

expr_arithmetic_boolean:
    expr_arithmetic GT expr_arithmetic
    | expr_arithmetic LT expr_arithmetic
    | expr_arithmetic GE expr_arithmetic
    | expr_arithmetic LE expr_arithmetic
    | expr_arithmetic EQ expr_arithmetic
    | expr_arithmetic NE expr_arithmetic
    | expr_boolean
    ;

expr_boolean:
    expr_boolean_not
    ;

expr_boolean_not:
    expr_boolean_and
    | NOT expr_boolean_not
    ;

expr_boolean_and:
    expr_boolean_or
    | expr_boolean_and AND expr_boolean_or
    ;

expr_boolean_or:
    factor_boolean
    | expr_boolean_or OR factor_boolean
    ;

factor_boolean:
    ID
    | INTEGER
    | REAL
    | PI
    | E
    | '(' expression ')'
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
    
expr_len:
    LEN '(' STRING ')'
    | len '(' STRING ')'
    ;

expr_substr:
    SUBSTR '(' STRING ';' INTEGER ';' INTEGER ')'
    | substr '(' STRING ';' INTEGER ';' INTEGER ')'
    ;

%%
