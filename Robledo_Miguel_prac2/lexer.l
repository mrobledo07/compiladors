%{
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "../build/parser.tab.h"
#include "../include/functions.h"
%}

%option yylineno
%option noyywrap
%option noinput
%option nounput


digit [0-9]
decimal {digit}+
octal 0[oO][0-7]+
binary 0[bB][01]+
hexadecimal 0[xX][0-9a-fA-F]+
letter [a-zA-Z]
float {decimal}"."{decimal}
boolean (true|false|TRUE|FALSE)
string \"([^\\\"]|\\.)*\"

trig_func (cos|sin|tan|COS|SIN|TAN)

len (len|LEN)
substr (substr|SUBSTR)

repeat (repeat)
do (do)
done (done)

plus      \+
minus     \-
mult      \*
div       \/
mod       %
pow       \*\*

gt        >
ge        >=
lt        <
le        <=
eq        ==
ne        <>

not       (not|NOT)
and       (and|AND)
or        (or|OR)

pi        (pi|PI)
e         (e|E)

%%



"//".* { return COMMENT; }
"#".* { return COMMENT; }
"/*"([^\*]|\*+[^"/"])*\*+"/" { return COMMENT; }


{boolean} {
    yylval.boolean = (strcmp(yytext, "true") == 0 || strcmp(yytext, "TRUE") == 0) ? 1 : 0;
    return BOOLEAN;
}

{trig_func} {
        return (strcmp(yytext, "cos") == 0 || strcmp(yytext, "COS") == 0) ? COS :
               (strcmp(yytext, "sin") == 0 || strcmp(yytext, "SIN") == 0) ? SIN :
               (strcmp(yytext, "tan") == 0 || strcmp(yytext, "TAN") == 0) ? TAN : -1;
}

{len} {
    return LEN;
}

{substr} {
    return SUBSTR;
}

{repeat} {
    yylval.ident.line = yylineno;
    return REPEAT;
}

{do} {
    return DO;
}

{done} {
    return DONE;
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

{letter}({letter}|{digit}|"_")* {
    yylval.ident.lexema = strdup(yytext);
    yylval.ident.lenght = yyleng;
    yylval.ident.line = yylineno;
    yylval.ident.id_val.val_type = UNKNOWN_TYPE;
    return ID;
}

":=" { return ASSIGN; }

{decimal} {
    yylval.integer = atoi(yytext);
    return INTEGER;
}

{octal} {
    yylval.integer = strtol(yytext+2, NULL, 8);
    return INTEGER;
}

{binary} {
    yylval.integer = strtol(yytext+2, NULL, 2);
    return INTEGER;
}

{hexadecimal} {
    yylval.integer = strtol(yytext, NULL, 16);
    return INTEGER;
}

{float} {
    yylval.real = atof(yytext);
    return REAL;
}

{string} {
    yylval.string = strdup(yytext);
    return STRING;
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

\( { return LPAREN; }

\) { return RPAREN; }

"," { return COMMA; }


^[ \t]*\n { }
[ \t] { }
[\n] { return ENDLINE; }

. { 
    // Format error explanation with unknown character
    char *error_message = (char *)malloc(37+strlen(yytext));
    strcpy(error_message, "Lexycal error - Unknown character: ");
    char *error = malloc(strlen(yytext) + 1);
    strcpy(error, yytext);

    // Call yyerror with error message with unknown character
    yyerror(strcat(error_message, error));
}

%%
