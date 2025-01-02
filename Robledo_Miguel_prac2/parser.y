%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <string.h>
    extern int yylex();
    extern int yylineno;
    void yyerror(char *s);
    extern FILE *yyout;
%}

%code requires {
    #include "../include/data.h"
    #include "../include/functions.h"
    #include "../include/symtab.h"
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
%token <ident> INTEGER
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
%token LPAREN RPAREN
%token COMMA
%token COMMENT
%token REPEAT
%token DO
%token DONE

%type <ident> expression
%type <ident> expr_arithmetic
%type <ident> expr_term
%type <ident> expr_pow
%type <ident> factor
%type <ident> expr_trig
%type <ident> expr_len
%type <ident> expr_substr
%type <ident> expr_unary

%left OR
%left AND
%left EQ NE
%left GT GE LT LE
%left PLUS MINUS
%left MULT DIV MOD
%right POW
%right NOT

%start program

%%
program:
    statement_list
    ;

statement_list:
    statement ENDLINE statement_list
    | statement
    ;

statement:
    assignment
    | expression {
        // Print the result of the expression
        fprintf(yyout, "PRODUCTION Expression %s\n", value_info_to_str($1.id_val));
        printf("Expression result: %s\n", value_info_to_str($1.id_val));
    }
    | statement COMMENT
    | repeat_statement
    |
    ;

repeat_statement:
    REPEAT expression DO statement_list DONE {
        if ($2.val_type != INT_TYPE) {
            yyerror("Repeat count must be an integer");
        } else {
            int repeat_count = $2.val_int;
            fprintf(yyout, "PRODUCTION Repeat %d times\n", repeat_count);
            printf("IF $t06 LTI $t05 GOTO 13 times\n");
        }
    }
    ;

assignment:
    ID ASSIGN expression {
        fprintf(yyout, "PRODUCTION Assignment %s := %s\n", $1.lexema, value_info_to_str($3));
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
            int symtab_status = sym_enter($1.lexema, &value);
            if (symtab_status == SYMTAB_OK || symtab_status == SYMTAB_DUPLICATE) {
                printf("%s := %s\n", $1.lexema, value_info_to_str($1.id_val));
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
    ;

expr_arithmetic:
    expr_unary
    | expr_arithmetic PLUS expr_unary {
        fprintf(yyout, "PRODUCTION expr_arithmetic %s + %s\n", value_info_to_str($1.id_val), value_info_to_str($3.id_val));
        // Verify that are numbers
        if (($1.val_type == INT_TYPE || $1.val_type == FLOAT_TYPE) &&
            ($3.val_type == INT_TYPE || $3.val_type == FLOAT_TYPE)) {
                if ($1.val_type == INT_TYPE && $3.val_type == INT_TYPE) {
                    $$.id_val.val_int = ($1.val_int + $3.val_int);
                    $$.id_val.val_type = INT_TYPE;
                    char *temp_var = generate_temp_var();
                    printf("%s := %s ADDI %s\n", temp_var, $1.lexema, $3.lexema);
                } else {
                    if ($1.val_type == FLOAT_TYPE && $3.val_type == FLOAT_TYPE) {
                        $$.id_val.val_float = $1.val_float + $3.val_float;
                        char *temp_var = generate_temp_var();
                        printf("%s := %s ADDF %s\n", temp_var, $1.lexema, $3.lexema);
                    } else if ($1.val_type == FLOAT_TYPE && $3.val_type == INT_TYPE) {
                        $$.id_val.val_float = (float) $1.val_float + $3.val_int;
                        char *new_temp_var = generate_temp_var();
                        char *temp_var = generate_temp_var();
                        printf("%s := I2F %s\n", new_temp_var, $3.lexema);
                        printf("%s := %s ADDF %s\n", temp_var, $1.lexema, new_temp_var);
                    } else {
                        $$.id_val.val_float = (float) $1.val_int + $3.val_float;
                        char *new_temp_var = generate_temp_var();
                        char *temp_var = generate_temp_var();
                        printf("%s := I2F %s\n", new_temp_var, $1.lexema);
                        printf("%s := %s ADDF %s\n", temp_var, new_temp_var, $3.lexema);
                    }
                    $$.id_val.val_type = FLOAT_TYPE;
                }
            } else if (($1.val_type != UNKNOWN_TYPE && $3.val_type != UNKNOWN_TYPE) && 
                        ($1.val_type == STR_TYPE || $3.val_type == STR_TYPE)) {
                // Concatenate strings
                $$.val_str = concat(value_to_str($1), value_to_str($3));    
                $$.val_type = STR_TYPE;
                char *temp_var = generate_temp_var();
                printf("%s := %s CONCAT %s\n", temp_var, $1.lexema, $3.lexema);
            }
            else {
                yyerror("Type error: Unknown type in addition operation");
                $$.val_type = UNKNOWN_TYPE;
            }
            $$.lexema = temp_var;
    }
    | expr_arithmetic MINUS expr_unary {
        fprintf(yyout, "PRODUCTION expr_arithmetic %s - %s\n", value_info_to_str($1), value_info_to_str($3));
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
            } else {
                yyerror("Type error: Subtraction operation is only allowed between numeric values");
                $$.val_type = UNKNOWN_TYPE;
            }
    }
    | expr_arithmetic OR expr_unary {
        fprintf(yyout, "PRODUCTION expr_arithmetic %s OR %s\n", value_info_to_str($1), value_info_to_str($3));
        // Verify that are booleans
        if ($1.val_type == BOOL_TYPE && $3.val_type == BOOL_TYPE) {
            $$.val_bool = $1.val_bool || $3.val_bool;
            $$.val_type = BOOL_TYPE;
        } else {
            yyerror("Type error: Logical OR operation is only allowed between boolean values");
            $$.val_type = UNKNOWN_TYPE;
        }
    }
    ;

expr_unary:
    expr_term
    | PLUS expr_unary {
        fprintf(yyout, "PRODUCTION expr_unary + %s\n", value_info_to_str($2));
        // Verify its a number
        if ($2.val_type == INT_TYPE || $2.val_type == FLOAT_TYPE) {
            if ($2.val_type == INT_TYPE) {
                $$.val_int = $2.val_int;
                $$.val_type = INT_TYPE;
            } else {
                $$.val_float = $2.val_float;
                $$.val_type = FLOAT_TYPE;
            }
        } else {
            yyerror("Type error: Unary plus operation is only allowed on numeric values");
            $$.val_type = UNKNOWN_TYPE;
        }
    }
    | MINUS expr_unary {
        fprintf(yyout, "PRODUCTION expr_unary - %s\n", value_info_to_str($2));
        // Verify its a number
        if ($2.val_type == INT_TYPE || $2.val_type == FLOAT_TYPE) {
            if ($2.val_type == INT_TYPE) {
                $$.val_int = $2.val_int * -1;
                $$.val_type = INT_TYPE;
            } else {
                $$.val_float = $2.val_float * -1;
                $$.val_type = FLOAT_TYPE;
            }
        } else {
            yyerror("Type error: Unary minus operation is only allowed on numeric values");
            $$.val_type = UNKNOWN_TYPE;
        }
    }
    | expr_unary AND expr_term {
        fprintf(yyout, "PRODUCTION expr_unary %s AND %s\n", value_info_to_str($1), value_info_to_str($3));
        // Verify that are booleans
        if ($1.val_type == BOOL_TYPE && $3.val_type == BOOL_TYPE) {
            $$.val_bool = $1.val_bool && $3.val_bool;
            $$.val_type = BOOL_TYPE;
        } else {
            yyerror("Type error: Logical AND operation is only allowed between boolean values");
            $$.val_type = UNKNOWN_TYPE;
        }
    }
    ;

expr_term:
    expr_pow
    | expr_term MULT expr_pow {
        fprintf(yyout, "PRODUCTION expr_term %s * %s\n", value_info_to_str($1), value_info_to_str($3));
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
            } else {
                yyerror("Type error: Multiplication operation is only allowed between numeric values");
                $$.val_type = UNKNOWN_TYPE;
            }
    }
    | expr_term DIV expr_pow {
        fprintf(yyout, "PRODUCTION expr_term %s / %s\n", value_info_to_str($1), value_info_to_str($3));
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
            } else {
                yyerror("Type error: Division operation is only allowed between numeric values");
                $$.val_type = UNKNOWN_TYPE;
            }
    }
    | expr_term MOD expr_pow {
        fprintf(yyout, "PRODUCTION expr_term %s %% %s\n", value_info_to_str($1), value_info_to_str($3));
        // Verify that both operands are integers
        if ($1.val_type == INT_TYPE && $3.val_type == INT_TYPE) {
            $$.val_type = INT_TYPE;
            $$.val_int = $1.val_int % $3.val_int;
        } else {
            yyerror("Type error: Modulus operation is only allowed between integers");
            $$.val_type = UNKNOWN_TYPE;
        }
    }
    | NOT expr_term {
        fprintf(yyout, "PRODUCTION NOT %s\n", value_info_to_str($2));
        // Verify that the operand is a boolean
        if ($2.val_type == BOOL_TYPE) {
            $$.val_type = BOOL_TYPE;
            $$.val_bool = !$2.val_bool;
        } else {
            yyerror("Type error: Logical NOT operation is only allowed on boolean values");
            $$.val_type = UNKNOWN_TYPE;
        }
    }
    ;

expr_pow:
    factor 
    | expr_pow POW factor {
        fprintf(yyout, "PRODUCTION expr_pow %s ** %s\n", value_info_to_str($1), value_info_to_str($3));
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
    | expr_pow GT factor {
        fprintf(yyout, "PRODUCTION expr_pow %s > %s\n", value_info_to_str($1), value_info_to_str($3));
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
    | expr_pow LT factor {
        fprintf(yyout, "PRODUCTION expr_pow %s < %s\n", value_info_to_str($1), value_info_to_str($3));
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
    | expr_pow GE factor {
        fprintf(yyout, "PRODUCTION expr_pow %s >= %s\n", value_info_to_str($1), value_info_to_str($3));
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
    | expr_pow LE factor {
        fprintf(yyout, "PRODUCTION expr_pow %s <= %s\n", value_info_to_str($1), value_info_to_str($3));
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
    | expr_pow EQ factor {
        fprintf(yyout, "PRODUCTION expr_pow %s == %s\n", value_info_to_str($1), value_info_to_str($3));
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
    | expr_pow NE factor {
        fprintf(yyout, "PRODUCTION expr_pow %s != %s\n", value_info_to_str($1), value_info_to_str($3));
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
            fprintf(yyout, "PRODUCTION ERROR expr_pow %s != %s\n", value_info_to_str($1), value_info_to_str($3));
            $$.val_type = UNKNOWN_TYPE;
        }
    }
    ;

factor: 
    ID {
        fprintf(yyout, "PRODUCTION ID Factor %s\n", $1.lexema);
        value_info value;
        if (sym_lookup($1.lexema, &value) == SYMTAB_NOT_FOUND) {
            yyerror("Variable not found");
        } else {
                $$ = value;
            }
    }
    | INTEGER {
        fprintf(yyout, "PRODUCTION INTEGER Factor %d\n", $1);
        $$.id_val.val_type = INT_TYPE;
        $$.id_val.val_int = $1;
        // store value as char in lexema
        $$.id_val.lexema = (char *)malloc(10);
        sprintf($$.id_val.lexema, "%d", $1);
    }
    | STRING {
        fprintf(yyout, "PRODUCTION STRING Factor %s\n", $1);
        $$.val_type = STR_TYPE;
        $$.val_str = substr($1, 1, strlen($1) - 2);
    }
    | BOOLEAN {
        fprintf(yyout, "PRODUCTION BOOLEAN Factor %d\n", $1);
        $$.val_type = BOOL_TYPE;
        $$.val_bool = $1;
    }
    | REAL {
        fprintf(yyout, "PRODUCTION REAL Factor %f\n", $1);
        $$.val_type = FLOAT_TYPE;
        $$.val_float = $1;
    }
    | PI {
        fprintf(yyout, "PRODUCTION PI Factor\n");
        $$.val_type = FLOAT_TYPE;
        $$.val_float = 3.141592653589793;
    }
    | E {
        fprintf(yyout, "PRODUCTION E Factor\n");
        $$.val_type = FLOAT_TYPE;
        $$.val_float = 2.718281828459045;
    }
    | LPAREN expression RPAREN {
        fprintf(yyout, "PRODUCTION LPAREN expression RPAREN %s\n", value_info_to_str($2));
        $$ = $2;
    }
    | expr_trig
    | expr_len
    | expr_substr
    ;

expr_trig:
    SIN LPAREN expression RPAREN {
        // Verify if the parameter is a number
        fprintf(yyout, "PRODUCTION SIN %s\n", value_info_to_str($3));
        if ($3.val_type == INT_TYPE) {
            $$.val_float = sin($3.val_int);
            $$.val_type = FLOAT_TYPE;
        } else if ($3.val_type == FLOAT_TYPE) {
            $$.val_float = sin($3.val_float);
            $$.val_type = FLOAT_TYPE;
        } else {
            yyerror("The sine function only applies to numbers.");
            $$.val_type = UNKNOWN_TYPE;
        }
    }
    | COS LPAREN expression RPAREN {
        fprintf(yyout, "PRODUCTION COS %s\n", value_info_to_str($3));
        if ($3.val_type == INT_TYPE) {
            $$.val_float = cos($3.val_int);
            $$.val_type = FLOAT_TYPE;
        } else if ($3.val_type == FLOAT_TYPE) {
            $$.val_float = cos($3.val_float);
            $$.val_type = FLOAT_TYPE;
        } else {
            yyerror("The cosine function only applies to numbers.");
            $$.val_type = UNKNOWN_TYPE;
        }
        
    }
    | TAN LPAREN expression RPAREN {
        fprintf(yyout, "PRODUCTION TAN %s\n", value_info_to_str($3));
        if ($3.val_type == INT_TYPE) {
            $$.val_float = tan($3.val_int);
            $$.val_type = FLOAT_TYPE;
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
    LEN LPAREN STRING RPAREN {
        fprintf(yyout, "PRODUCTION STRING LEN %s\n", $3);
        $$.val_int = strlen($3);
        $$.val_type = INT_TYPE;
    }
    | LEN LPAREN ID RPAREN {
        fprintf(yyout, "PRODUCTION ID LEN %s\n", $3.lexema);
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
    SUBSTR LPAREN STRING COMMA expression COMMA expression RPAREN {
        fprintf(yyout, "PRODUCTION STRING SUBSTR %s\n", $3);
        // Verify if the indexes are integers
        if ($5.val_type == INT_TYPE && $7.val_type == INT_TYPE) {
            $$.val_str = substr($3, $5.val_int, $7.val_int);
            $$.val_type = STR_TYPE;
        } else {
            yyerror("Substrings indexes must be integers.");
            $$.val_type = UNKNOWN_TYPE;
        }
    }
    | SUBSTR LPAREN ID COMMA expression COMMA expression RPAREN {
        fprintf(yyout, "PRODUCTION ID SUBSTR %s\n", $3.lexema);
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
                    $$.val_str = substr(value.val_str, $5.val_int, $7.val_int);
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
