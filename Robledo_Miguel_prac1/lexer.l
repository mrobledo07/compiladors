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
digit [0-9]
letter [a-zA-Z]
float {digit}+"."{digit}+
boolean ("true"|"false")
string \"([^\\\"]|\\.)*\"

trig_func (cos|sin|tan)

plus \+
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

not       not
and       and
or        or

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

// INTEGER
{digit}+ {
yylval.enter = atoi(yytext);
return INTEGER;
}

// FLOAT
{float} {
yylval.real = atof(yytext);
return REAL;
}

// BOOLEAN
{boolean} {
yylval.boolean = (strcmp(yytext, "true") == 0) ? 1 : 0;
return BOOLEAN;
}

// STRING
{string} {
yylval.cadena = strdup(yytext);
return CADENA;
}

{trig_func} {
        return (strcmp(yytext, "cos") == 0) ? COS :
               (strcmp(yytext, "sin") == 0) ? SIN :
               (strcmp(yytext, "tan") == 0) ? TAN : -1;
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
