// C declarations
%{
#include <stdio.h>
#include <stdlib.h> 
#include "data.h"
#include "functions.h"
%}

%option yylineno
%option noyywrap
%option noinput
%option nounput

// Pattern definition
decimal [0-9]+
octal 0[oO][0-7]+
binary 0[bB][01]+
hexadecimal 0[xX][0-9a-fA-F]+
letter [a-zA-Z]
float {decimal}"."{decimal}
boolean (true|false|TRUE|FALSE)
string \"([^\\\"]|\\.)*\"

trig_func (cos|sin|tan|COS|SIN|TAN)

plus      \+
minus     \-
mult      \*
div       /
mod       %
pow       \*\*

gt        >
ge        >=
lt        <
le        <=
eq        ==
ne        <>

not       not | NOT
and       and | AND
or        or  | OR

pi        pi | PI
e         e  | E

%%

// ID
{letter}({letter}|{digit})* {
yylval.ident.lexema = strdup(yytext);
yylval.ident.lenght = yyleng;
yylval.ident.line = yylineno;
yylval.ident.id_val.val_type = UNKNOWN_TYPE;
return ID;
}

// ASSIGN
":=" { return ASSIGN; }

// INTEGER DECIMAL
decimal {
    yylval.integer = atoi(yytext);
    return INTEGER;
}

// INTEGER OCTAL
octal {
    yylval.integer = strtol(yytext, NULL, 8);
    return INTEGER;
}

// INTEGER BINARY
binary {
    yylval.integer = strtol(yytext, NULL, 2);
    return INTEGER;
}

// INTEGER HEXADECIMAL
hexadecimal {
    yylval.integer = strtol(yytext, NULL, 16);
    return INTEGER;
}

// FLOAT
{float} {
yylval.real = atof(yytext);
return REAL;
}

// BOOLEAN
{boolean} {
yylval.boolean = (strcmp(yytext, "true") == 0 || strcmp(yytext, "TRUE") == 0) ? 1 : 0;
return BOOLEAN;
}

// STRING
{string} {
yylval.cadena = strdup(yytext);
return CADENA;
}

{trig_func} {
        return (strcmp(yytext, "cos") == 0 || strcmp(yytext, "COS") == 0) ? COS :
               (strcmp(yytext, "sin") == 0 || strcmp(yytext, "SIN") == 0) ? SIN :
               (strcmp(yytext, "tan") == 0 || strcmp(yytext, "TAN") == 0) ? TAN : -1;
}

{plus} {
    return PLUS;
}

{minus} {
    return MINUS;
}

{mult} {
    return MULT;
}

{div} {
    return DIV;
}

{mod} {
    return MOD;
}

{pow} {
    return POW;
}

{gt} {
    return GT;
}

{ge} {
    return GE;
}

{lt} {
    return LT;
}

{le} {
    return LE;
}

{eq} {
    return EQ;
}

{ne} {
    return NE;
}

{not} {
    return NOT;
}

{and} {
    return AND;
}

{or} {
    return OR;
}

{pi} {
    return PI;
}

{e} {
    return E;
}

// Comments
//.* { }
/*([^*]|\*+[^/])*\*+/ { }
#.* { }

// Blank spaces
^[ \t]*[\n] { }
[\n] { return ENDLINE; }

// Other characters
. { }

%%
