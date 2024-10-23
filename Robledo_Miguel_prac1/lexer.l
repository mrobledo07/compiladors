// C declarations
%{
#include #include #include %}

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

%%

// ID
{letter}({letter}|{digit})* {
yylval.ident.lexema = strdup(yytext);
yylval.ident.lenght = yyleng;
yylval.ident.line = yylineno;
yylval.ident.id_val.val_type = UNKNOWN_TYPE;
return ID;
}

// ASSIG
"=" { return ASSIGN; }

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
