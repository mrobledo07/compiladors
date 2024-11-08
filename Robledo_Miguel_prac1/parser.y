%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <string.h>
    extern int yylex();
    extern int yylineno;
    void yyerror(char *s);
%}

%code requires {
    #include "data.h"
    #include "functions.h"
    #include "symtab.h"
}

%union {
    struct {
        char *lexema;
        int lenght;
        int line;
        value_info id_val;
    } ident;
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
%token LEN SUBSTR

%type <ident.id_val> expression
%type <ident.id_val> expr_arithmetic
%type <ident.id_val> expr_op
%type <ident.id_val> expr_term
%type <ident.id_val> expr_pow
%type <ident.id_val> factor_arithmetic
%type <ident.id_val> expr_arithmetic_boolean
%type <ident.id_val> expr_boolean
%type <ident.id_val> expr_boolean_not
%type <ident.id_val> expr_boolean_and
%type <ident.id_val> expr_boolean_or
%type <ident.id_val> factor_boolean
%type <ident.id_val> expr_trig
%type <ident.id_val> expr_len
%type <ident.id_val> expr_substr

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
    | expression {
        // Print the result of the expression
        printf("Expression result: %s\n", value_info_to_str($1));
    }
    ;

assignment:
ID ASSIGN expression {
        // Assign only if the type is compatible or if it has not been initialized
        if ($1.id_val.val_type == UNKNOWN_TYPE || $1.id_val.val_type == $3.val_type) {
            $1.id_val.val_type = $3.val_type;
            if ($3.val_type == INT_TYPE) {
                $1.id_val.val_int = $3.val_int;
            } else if ($3.val_type == FLOAT_TYPE) {
                $1.id_val.val_float = $3.val_float;
            } else if ($3.val_type == STR_TYPE) {
                $1.id_val.val_str = $3.val_str;
            } else if ($3.val_type == BOOL_TYPE) {
                $1.id_val.val_bool = $3.val_bool;
            }
            value_info value = {
                .val_type = $3.val_type,
                .val_int = $3.val_int,
                .val_float = $3.val_float,
                .val_bool = $3.val_bool,
                .val_str = $3.val_str
            };
            if (sym_enter($1.lexema, &value) == SYMTAB_OK) {
                printf("Assignment: %s := %s\n", $1.lexema, value_info_to_str($1.id_val));
            } else {
                yyerror("Error: Variable could not be entered into the symbol table. Stack overflow.");
            }
        } else {
            yyerror("Incompatible types in assignment");
        }
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
    | PLUS expr_op {
        // Verify its a number
        if ($2.val_type == INT_TYPE || $2.val_type == FLOAT_TYPE) {
            if ($2.val_type == INT_TYPE) {
                $$.val_int = $2.val_int;
                $$.val_type = INT_TYPE;
            } else {
                $$.val_float = $2.val_float;
                $$.val_type = FLOAT_TYPE;
            }
        }
    }
    | MINUS expr_op {
        // Verify its a number
        if ($2.val_type == INT_TYPE || $2.val_type == FLOAT_TYPE) {
            if ($2.val_type == INT_TYPE) {
                $$.val_int = -$2.val_int;
                $$.val_type = INT_TYPE;
            } else {
                $$.val_float = -$2.val_float;
                $$.val_type = FLOAT_TYPE;
            }
        }
    }
    | expr_op PLUS expr_term {
        // Verify that are numbers
        if (($1.val_type == INT_TYPE || $1.val_type == FLOAT_TYPE) &&
            ($3.val_type == INT_TYPE || $3.val_type == FLOAT_TYPE)) {
                if ($1.val_type == INT_TYPE && $3.val_type == INT_TYPE) {
                    $$.val_int = ($1.val_int + $3.val_int);
                    $$.val_type = INT_TYPE;
                } else {
                    if ($1.val_type == FLOAT_TYPE && $3.val_type == FLOAT_TYPE) {
                        $$.val_float = $1.val_float + $3.val_float;
                    } else if ($1.val_type == FLOAT_TYPE && $3.val_type == INT_TYPE) {
                        $$.val_float = (float) $1.val_float + $3.val_int;
                    } else {
                        $$.val_float = (float) $1.val_int + $3.val_float;
                    }
                    $$.val_type = FLOAT_TYPE;
                }
            }
    }
    | expr_op MINUS expr_term {
        // Verify that are numbers
        if (($1.val_type == INT_TYPE || $1.val_type == FLOAT_TYPE) &&
            ($3.val_type == INT_TYPE || $3.val_type == FLOAT_TYPE)) {
                if ($1.val_type == INT_TYPE && $3.val_type == INT_TYPE) {
                    $$.val_int = ($1.val_int - $3.val_int);
                    $$.val_type = INT_TYPE;
                } else {
                    if ($1.val_type == FLOAT_TYPE && $3.val_type == FLOAT_TYPE) {
                        $$.val_float = $1.val_float - $3.val_float;
                    } else if ($1.val_type == FLOAT_TYPE && $3.val_type == INT_TYPE) {
                        $$.val_float = (float) $1.val_float - $3.val_int;
                    } else {
                        $$.val_float = (float) $1.val_int - $3.val_float;
                    }
                    $$.val_type = FLOAT_TYPE;
                }
            }
    }
    ;

expr_term:
    expr_pow
    | expr_term MULT expr_pow {
        // Verify that are numbers
        if (($1.val_type == INT_TYPE || $1.val_type == FLOAT_TYPE) &&
            ($3.val_type == INT_TYPE || $3.val_type == FLOAT_TYPE)) {
                if ($1.val_type == INT_TYPE && $3.val_type == INT_TYPE) {
                    $$.val_int = ($1.val_int * $3.val_int);
                    $$.val_type = INT_TYPE;
                } else {
                    if ($1.val_type == FLOAT_TYPE && $3.val_type == FLOAT_TYPE) {
                        $$.val_float = $1.val_float * $3.val_float;
                    } else if ($1.val_type == FLOAT_TYPE && $3.val_type == INT_TYPE) {
                        $$.val_float = (float) $1.val_float * $3.val_int;
                    } else {
                        $$.val_float = (float) $1.val_int * $3.val_float;
                    }
                    $$.val_type = FLOAT_TYPE;
                }
            }
    }
    | expr_term DIV expr_pow {
        // Verify that are numbers
        if (($1.val_type == INT_TYPE || $1.val_type == FLOAT_TYPE) &&
            ($3.val_type == INT_TYPE || $3.val_type == FLOAT_TYPE)) {
                $$.val_type = FLOAT_TYPE;
                if ($1.val_type == INT_TYPE && $3.val_type == INT_TYPE) {
                    $$.val_float = (float) ($1.val_int / $3.val_int);
                } else {
                    if ($1.val_type == FLOAT_TYPE && $3.val_type == FLOAT_TYPE) {
                        $$.val_float = $1.val_float / $3.val_float;
                    } else if ($1.val_type == FLOAT_TYPE && $3.val_type == INT_TYPE) {
                        $$.val_float = (float) $1.val_float / $3.val_int;
                    } else {
                        $$.val_float = (float) $1.val_int / $3.val_float;
                    }
                }
            }
    }
    | expr_term MOD expr_pow {
        // Verify that both operands are integers
        if ($1.val_type == INT_TYPE && $3.val_type == INT_TYPE) {
            $$.val_type = INT_TYPE;
            $$.val_int = $1.val_int % $3.val_int;
        } else {
            yyerror("Type error: Modulus operation is only allowed between integers");
            $$.val_type = UNKNOWN_TYPE;
        }
    }
    ;

expr_pow:
    factor_arithmetic {
        // Simply propagate the value and type of factor_arithmetic
        $$.val_type = $1.val_type;
        $$.val_int = $1.val_int;
        $$.val_float = $1.val_float;
        $$.val_bool = $1.val_bool;
        strncpy($$.val_str, $1.val_str, STR_MAX_LENGTH - 1);
        $$.val_str[STR_MAX_LENGTH - 1] = '\0';
    }
    | expr_pow POW factor_arithmetic {
        // Verify that both operands are numeric (int or float)
        if (($1.val_type == INT_TYPE || $1.val_type == FLOAT_TYPE) &&
            ($3.val_type == INT_TYPE || $3.val_type == FLOAT_TYPE)) {
            
            // Perform the power operation based on the operand types
            if ($1.val_type == FLOAT_TYPE || $3.val_type == FLOAT_TYPE) {
                // Convert to float if either operand is float
                $$.val_type = FLOAT_TYPE;
                $$.val_float = pow(
                    ($1.val_type == INT_TYPE) ? (float)$1.val_int : $1.val_float,
                    ($3.val_type == INT_TYPE) ? (float)$3.val_int : $3.val_float
                );
            } else {
                // If both are integers, keep the integer type
                $$.val_type = INT_TYPE;
                $$.val_int = (int)pow($1.val_int, $3.val_int);
            }
        } else {
            yyerror("Type error: Power operation is only allowed between numeric values");
            $$.val_type = UNKNOWN_TYPE;
        }
    }
    ;

factor_arithmetic: 
    ID {
        value_info value;
        if (sym_lookup($1.lexema, &value) == SYMTAB_NOT_FOUND) {
            yyerror("Variable not found");
        } else {
            if (value.val_type != INT_TYPE && value.val_type != FLOAT_TYPE) {
                yyerror("Type error: Arithmetic operation requires numeric values");
                $$.val_type = UNKNOWN_TYPE;
            } else {
                $$.val_type = value.val_type;
                $$.val_int = value.val_int;
                $$.val_float = value.val_float;
                $$.val_bool = value.val_bool;
                strncpy($$.val_str, value.val_str, STR_MAX_LENGTH - 1);
                $$.val_str[STR_MAX_LENGTH - 1] = '\0';
            }
        }
    }
    | INTEGER {
        $$.val_type = INT_TYPE;
        $$.val_int = $1;
    }
    | REAL {
        $$.val_type = FLOAT_TYPE;
        $$.val_float = $1;
    }
    | STRING {
        $$.val_type = STR_TYPE;
        strncpy($$.val_str, $1, STR_MAX_LENGTH - 1);
        $$.val_str[STR_MAX_LENGTH - 1] = '\0'; 
    }
    | PI {
        $$.val_type = FLOAT_TYPE;
        $$.val_float = 3.141592653589793;
    }
    | E {
        $$.val_type = FLOAT_TYPE;
        $$.val_float = 2.718281828459045;
    }
    | '(' expression ')' {
        // Simply inherit the type and value from the subexpression
        $$.val_type = $2.val_type;
        $$.val_int = $2.val_int;
        $$.val_float = $2.val_float;
        $$.val_bool = $2.val_bool;
        strncpy($$.val_str, $2.val_str, STR_MAX_LENGTH - 1);
        $$.val_str[STR_MAX_LENGTH - 1] = '\0';
    }
    ;

expr_arithmetic_boolean:
    expr_arithmetic GT expr_arithmetic {
        if (($1.val_type == INT_TYPE || $1.val_type == FLOAT_TYPE) && 
            ($3.val_type == INT_TYPE || $3.val_type == FLOAT_TYPE)) {
                $$.val_type = BOOL_TYPE;
                if ($1.val_type == FLOAT_TYPE || $3.val_type == FLOAT_TYPE) {
                    $$.val_bool = ($1.val_type == INT_TYPE ? (float)$1.val_int : $1.val_float) > 
                        ($3.val_type == INT_TYPE ? (float)$3.val_int : $3.val_float);
                } else {
                    $$.val_bool = $1.val_int > $3.val_int;
                }
        } else {
            yyerror("Type error: Comparison requires numeric types");
            $$.val_type = UNKNOWN_TYPE;
        }
    }
    | expr_arithmetic LT expr_arithmetic {
        if (($1.val_type == INT_TYPE || $1.val_type == FLOAT_TYPE) && 
            ($3.val_type == INT_TYPE || $3.val_type == FLOAT_TYPE)) {
                $$.val_type = BOOL_TYPE;
                if ($1.val_type == FLOAT_TYPE || $3.val_type == FLOAT_TYPE) {
                    $$.val_bool = ($1.val_type == INT_TYPE ? (float)$1.val_int : $1.val_float) < 
                        ($3.val_type == INT_TYPE ? (float)$3.val_int : $3.val_float);
                } else {
                    $$.val_bool = $1.val_int < $3.val_int;
                }
        } else {
            yyerror("Type error: Comparison requires numeric types");
            $$.val_type = UNKNOWN_TYPE;
        }
    }
    | expr_arithmetic GE expr_arithmetic {
        if (($1.val_type == INT_TYPE || $1.val_type == FLOAT_TYPE) && 
            ($3.val_type == INT_TYPE || $3.val_type == FLOAT_TYPE)) {
                $$.val_type = BOOL_TYPE;
                if ($1.val_type == FLOAT_TYPE || $3.val_type == FLOAT_TYPE) {
                    $$.val_bool = ($1.val_type == INT_TYPE ? (float)$1.val_int : $1.val_float) >= 
                        ($3.val_type == INT_TYPE ? (float)$3.val_int : $3.val_float);
                } else {
                    $$.val_bool = $1.val_int >= $3.val_int;
                }
        } else {
            yyerror("Type error: Comparison requires numeric types");
            $$.val_type = UNKNOWN_TYPE;
        }
    }
    | expr_arithmetic LE expr_arithmetic {
        if (($1.val_type == INT_TYPE || $1.val_type == FLOAT_TYPE) && 
            ($3.val_type == INT_TYPE || $3.val_type == FLOAT_TYPE)) {
                $$.val_type = BOOL_TYPE;
                if ($1.val_type == FLOAT_TYPE || $3.val_type == FLOAT_TYPE) {
                    $$.val_bool = ($1.val_type == INT_TYPE ? (float)$1.val_int : $1.val_float) <= 
                        ($3.val_type == INT_TYPE ? (float)$3.val_int : $3.val_float);
                } else {
                    $$.val_bool = $1.val_int <= $3.val_int;
                }
        } else {
            yyerror("Type error: Comparison requires numeric types");
            $$.val_type = UNKNOWN_TYPE;
        }
    }
    | expr_arithmetic EQ expr_arithmetic {
        if (($1.val_type == INT_TYPE || $1.val_type == FLOAT_TYPE) && 
            ($3.val_type == INT_TYPE || $3.val_type == FLOAT_TYPE)) {
                $$.val_type = BOOL_TYPE;
                if ($1.val_type == FLOAT_TYPE || $3.val_type == FLOAT_TYPE) {
                    $$.val_bool = ($1.val_type == INT_TYPE ? (float)$1.val_int : $1.val_float) == 
                        ($3.val_type == INT_TYPE ? (float)$3.val_int : $3.val_float);
                } else {
                    $$.val_bool = $1.val_int == $3.val_int;
                }
        } else {
            yyerror("Type error: Comparison requires numeric types");
            $$.val_type = UNKNOWN_TYPE;
        }

    }
    | expr_arithmetic NE expr_arithmetic {
         if (($1.val_type == INT_TYPE || $1.val_type == FLOAT_TYPE) && 
            ($3.val_type == INT_TYPE || $3.val_type == FLOAT_TYPE)) {
                $$.val_type = BOOL_TYPE;
                if ($1.val_type == FLOAT_TYPE || $3.val_type == FLOAT_TYPE) {
                    $$.val_bool = ($1.val_type == INT_TYPE ? (float)$1.val_int : $1.val_float) != 
                        ($3.val_type == INT_TYPE ? (float)$3.val_int : $3.val_float);
                } else {
                    $$.val_bool = $1.val_int != $3.val_int;
                }
        } else {
            yyerror("Type error: Comparison requires numeric types");
            $$.val_type = UNKNOWN_TYPE;
        }
    }
    | expr_boolean
    ;

expr_boolean:
    expr_boolean_not
    ;

expr_boolean_not:
    expr_boolean_and
    | NOT expr_boolean_not {
        $$.val_type = BOOL_TYPE;
        $$.val_bool = !$2.val_bool; // Perform logical NOT on the operand
    }
    ;

expr_boolean_and:
    expr_boolean_or
    | expr_boolean_and AND expr_boolean_or {
        $$.val_type = BOOL_TYPE;
        $$.val_bool = $1.val_bool && $3.val_bool; // Perform logical AND between the two operands
    }
    ;

expr_boolean_or:
    factor_boolean
    | expr_boolean_or OR factor_boolean {
        $$.val_type = BOOL_TYPE;
        $$.val_bool = $1.val_bool || $3.val_bool; // Perform logical OR between the two operands
    }
    ;

factor_boolean:
    ID {
        value_info value;
        if (sym_lookup($1.lexema, &value) == SYMTAB_NOT_FOUND) {
            yyerror("Variable not found");
        } else {
            if (value.val_type != BOOL_TYPE) {
                yyerror("Type error: Boolean operation requires boolean values");
                $$.val_type = UNKNOWN_TYPE;
            } else {
                $$.val_type = value.val_type;
                $$.val_int = value.val_int;
                $$.val_float = value.val_float;
                $$.val_bool = value.val_bool;
                strncpy($$.val_str, value.val_str, STR_MAX_LENGTH - 1);
                $$.val_str[STR_MAX_LENGTH - 1] = '\0';
            }
        }
    }
    | BOOLEAN {
        $$.val_type = BOOL_TYPE;
        $$.val_bool = $1;
    }
    | '(' expr_boolean ')' {
        // Simply inherit the type and value from the subexpression
        $$.val_type = $2.val_type;
        $$.val_int = $2.val_int;
        $$.val_float = $2.val_float;
        $$.val_bool = $2.val_bool;
        strncpy($$.val_str, $2.val_str, STR_MAX_LENGTH - 1);
        $$.val_str[STR_MAX_LENGTH - 1] = '\0';
    }
    ;

expr_trig:
    SIN '(' expression ')' {
        // Verify if the parameter is a number
        if ($3.val_type == INT_TYPE) {
            $$.val_int = sin($3.val_int);
            $$.val_type = INT_TYPE;
        } else if ($3.val_type == FLOAT_TYPE) {
            $$.val_float = sin($3.val_float);
            $$.val_type = FLOAT_TYPE;
        } else {
            yyerror("The sine function only applies to numbers.");
            $$.val_type = UNKNOWN_TYPE;
        }
    }
    | COS '(' expression ')' {
        if ($3.val_type == INT_TYPE) {
            $$.val_int = cos($3.val_int);
            $$.val_type = INT_TYPE;
        } else if ($3.val_type == FLOAT_TYPE) {
            $$.val_float = cos($3.val_float);
            $$.val_type = FLOAT_TYPE;
        } else {
            yyerror("The cosine function only applies to numbers.");
            $$.val_type = UNKNOWN_TYPE;
        }
        
    }
    | TAN '(' expression ')' {
        if ($3.val_type == INT_TYPE) {
            $$.val_int = tan($3.val_int);
            $$.val_type = INT_TYPE;
        } else if ($3.val_type == FLOAT_TYPE) {
            $$.val_float = tan($3.val_float);
            $$.val_type = FLOAT_TYPE;
        } else {
            yyerror("The tangent function only applies to numbers.");
            $$.val_type = UNKNOWN_TYPE;
        }
    }
    ;
    
expr_len:
    LEN '(' STRING ')' {
        $$.val_int = strlen($3);
        $$.val_type = INT_TYPE;
    }
    | LEN '(' ID ')' {
        value_info value;
        if (sym_lookup($3.lexema, &value) == SYMTAB_NOT_FOUND) {
            yyerror("Variable not found");
            $$.val_type = UNKNOWN_TYPE;
        } else {
            if (value.val_type != STR_TYPE) {
                yyerror("The len function only applies to strings.");
                $$.val_type = UNKNOWN_TYPE;
            } else {
                $$.val_int = strlen(value.val_str);
                $$.val_type = INT_TYPE;
            }
        }
    }
    ;

expr_substr:
    SUBSTR '(' STRING ';' expression ';' expression ')' {
        // Verify if the indexes are integers
        if ($5.val_type == INT_TYPE && $7.val_type == INT_TYPE) {
            $$.val_str = substr_wrapper($3, $5.val_int, $7.val_int);
            $$.val_type = STR_TYPE;
        } else {
            yyerror("Substrings indexes must be integers.");
            $$.val_type = UNKNOWN_TYPE;
        }
    }
    | SUBSTR '(' ID ';' expression ';' expression ')' {
        value_info value;
        if (sym_lookup($3.lexema, &value) == SYMTAB_NOT_FOUND) {
            yyerror("Variable not found");
            $$.val_type = UNKNOWN_TYPE;
        } else {
            if (value.val_type != STR_TYPE) {
                yyerror("The substr function only applies to strings.");
                $$.val_type = UNKNOWN_TYPE;
            } else {
                if ($5.val_type == INT_TYPE && $7.val_type == INT_TYPE) {
                    $$.val_str = substr_wrapper(value.val_str, $5.val_int, $7.val_int);
                    $$.val_type = STR_TYPE;
                } else {
                    yyerror("Substrings indexes must be integers.");
                    $$.val_type = UNKNOWN_TYPE;
                }
            }
        }
    }
    ;

%%
