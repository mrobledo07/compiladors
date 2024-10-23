%{
#include #include #include
extern int yylex();
void yyerror(const char *s);
%}

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

%token ASSIGN ENDLINE
%token INTEGER
%token ID
%token REAL
%token STRING
%token BOOLEAN

%start program

%%



%%
