%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <string.h>
    extern int yylex();
    extern int yylineno;
    void yyerror(char *s);
    extern FILE *yyout;

    #define MAX_STACK_SIZE 100

    char *repeat_stack[MAX_STACK_SIZE];
    int stack_top = -1;  

    void push_repeat_stack(char *temp_var) {
        if (stack_top < MAX_STACK_SIZE - 1) {
            repeat_stack[++stack_top] = temp_var;
        } else {
            printf("Error: Stack overflow.\n");
        }
    }

    char *pop_repeat_stack() {
        if (stack_top >= 0) {
            return repeat_stack[stack_top--];
        } else {
            printf("Error: Stack empty.\n");
            return NULL;
        }
    }

    int instruction_counter = 1;

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
        int is_literal;
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
%token LPAREN RPAREN
%token COMMA
%token COMMENT
%token <ident> REPEAT
%token DO
%token DONE

%type <ident> expression
%type <ident> repeat_expression
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
        fprintf(yyout, "PRODUCTION Expression %s\n", value_to_str($1.id_val));
        printf("PARAM %s\n", $1.lexema);
        if ($1.id_val.val_type == INT_TYPE) {
            printf("CALL PUTI, 1\n");
        } else if ($1.id_val.val_type == FLOAT_TYPE) {
            printf("CALL PUTF, 1\n");
        } else if ($1.id_val.val_type == STR_TYPE) {
            printf("CALL PUTC, %d\n", $1.lenght);
        } else {
            yyerror("Unknown type in expression");
        }
        instruction_counter += 2;
    }
    | statement COMMENT
    | repeat_statement
    |
    ;

repeat_statement:
    REPEAT repeat_expression DO statement_list DONE {
        if ($2.id_val.val_type != INT_TYPE) {
            yyerror("Repeat count must be an integer");
        } else {
            int repeat_count = $2.id_val.val_int;
            char *repeat_line_number = pop_repeat_stack();
            char *repeat_counter_name = pop_repeat_stack();
            char *repeat_expression_name = pop_repeat_stack();
            fprintf(yyout, "PRODUCTION Repeat %d times\n", repeat_count);
            printf("%s := %s ADDI 1\n", repeat_counter_name, repeat_counter_name);
            printf("IF %s LTI %s GOTO %s\n", repeat_counter_name, repeat_expression_name, repeat_line_number);
            instruction_counter += 2;
        }
    }
    ;

repeat_expression:
    expression {
        if ($1.is_literal) {
            char *new_var = generate_temp_var();
            printf("%s := %s\n", new_var, $1.lexema);
            instruction_counter++;
        } 
        char *temp_var = generate_temp_var();
        printf("%s := 0\n", temp_var);
        instruction_counter++;
        char * repeat_counter_name = temp_var;
        // store the previous temp var in repeat_expression_name
        int previous_number = atoi(temp_var + 2) - 1;
        char *previous_temp_var = (char *)malloc(14);
        sprintf(previous_temp_var, "$t%02d", previous_number);
        char *repeat_expression_name = previous_temp_var;
        push_repeat_stack(repeat_expression_name);
        push_repeat_stack(repeat_counter_name);
        char *line_number = (char *)malloc(10); 
        sprintf(line_number, "%d", instruction_counter);
        push_repeat_stack(line_number);
    }
    ;

assignment:
    ID ASSIGN expression {
        fprintf(yyout, "PRODUCTION Assignment %s := %s\n", $1.lexema, value_to_str($3.id_val));
        // Assign only if the type is compatible or if it has not been initialized
        if ($1.id_val.val_type == UNKNOWN_TYPE || $1.id_val.val_type == $3.id_val.val_type) {
            $1.id_val.val_type = $3.id_val.val_type;
            if ($3.id_val.val_type == INT_TYPE) {
                $1.id_val.val_int = $3.id_val.val_int;
            } else if ($3.id_val.val_type == FLOAT_TYPE) {
                $1.id_val.val_float = $3.id_val.val_float;
            } else if ($3.id_val.val_type == STR_TYPE) {
                $1.id_val.val_str = $3.id_val.val_str;
            } else if ($3.id_val.val_type == BOOL_TYPE) {
                $1.id_val.val_bool = $3.id_val.val_bool;
            }
            value_info value = {
                .val_type = $3.id_val.val_type,
                .val_int = $3.id_val.val_int,
                .val_float = $3.id_val.val_float,
                .val_bool = $3.id_val.val_bool,
                .val_str = $3.id_val.val_str
            };
            int symtab_status = sym_enter($1.lexema, &value);
            if (symtab_status == SYMTAB_OK || symtab_status == SYMTAB_DUPLICATE) {
                printf("%s := %s\n", $1.lexema, $3.lexema);
                instruction_counter++;
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
        fprintf(yyout, "PRODUCTION expr_arithmetic %s + %s\n", value_to_str($1.id_val), value_to_str($3.id_val));
        char *temp_var = NULL;
        // Verify that are numbers
        if (($1.id_val.val_type == INT_TYPE || $1.id_val.val_type == FLOAT_TYPE) &&
            ($3.id_val.val_type == INT_TYPE || $3.id_val.val_type == FLOAT_TYPE)) {
                if ($1.id_val.val_type == INT_TYPE && $3.id_val.val_type == INT_TYPE) {
                    $$.id_val.val_int = ($1.id_val.val_int + $3.id_val.val_int);
                    $$.id_val.val_type = INT_TYPE;
                    temp_var = generate_temp_var();
                    printf("%s := %s ADDI %s\n", temp_var, $1.lexema, $3.lexema);
                    instruction_counter++;
                } else {
                    if ($1.id_val.val_type == FLOAT_TYPE && $3.id_val.val_type == FLOAT_TYPE) {
                        $$.id_val.val_float = $1.id_val.val_float + $3.id_val.val_float;
                        temp_var = generate_temp_var();
                        printf("%s := %s ADDF %s\n", temp_var, $1.lexema, $3.lexema);
                        instruction_counter++;
                    } else if ($1.id_val.val_type == FLOAT_TYPE && $3.id_val.val_type == INT_TYPE) {
                        $$.id_val.val_float = (float) $1.id_val.val_float + $3.id_val.val_int;
                        char *new_temp_var = generate_temp_var();
                        temp_var = generate_temp_var();
                        printf("%s := I2F %s\n", new_temp_var, $3.lexema);
                        printf("%s := %s ADDF %s\n", temp_var, $1.lexema, new_temp_var);
                        instruction_counter += 2;
                    } else {
                        $$.id_val.val_float = (float) $1.id_val.val_int + $3.id_val.val_float;
                        char *new_temp_var = generate_temp_var();
                        temp_var = generate_temp_var();
                        printf("%s := I2F %s\n", new_temp_var, $1.lexema);
                        printf("%s := %s ADDF %s\n", temp_var, new_temp_var, $3.lexema);
                        instruction_counter += 2;
                    }
                    $$.id_val.val_type = FLOAT_TYPE;
                }
            } else if (($1.id_val.val_type != UNKNOWN_TYPE && $3.id_val.val_type != UNKNOWN_TYPE) && 
                        ($1.id_val.val_type == STR_TYPE || $3.id_val.val_type == STR_TYPE)) {
                // Concatenate strings
                $$.id_val.val_str = concat(value_to_str($1.id_val), value_to_str($3.id_val));    
                $$.id_val.val_type = STR_TYPE;
                temp_var = generate_temp_var();
                printf("%s := %s CONCAT %s\n", temp_var, $1.lexema, $3.lexema);
                instruction_counter++;
            }
            else {
                yyerror("Type error: Unknown type in addition operation");
                $$.id_val.val_type = UNKNOWN_TYPE;
            }
            $$.lexema = temp_var;
            $$.is_literal = 0;
    }
    | expr_arithmetic MINUS expr_unary {
        fprintf(yyout, "PRODUCTION expr_arithmetic %s - %s\n", value_to_str($1.id_val), value_to_str($3.id_val));
        char *temp_var = NULL;
        // Verify that are numbers
        if (($1.id_val.val_type == INT_TYPE || $1.id_val.val_type == FLOAT_TYPE) &&
            ($3.id_val.val_type == INT_TYPE || $3.id_val.val_type == FLOAT_TYPE)) {
                if ($1.id_val.val_type == INT_TYPE && $3.id_val.val_type == INT_TYPE) {
                    $$.id_val.val_int = ($1.id_val.val_int - $3.id_val.val_int);
                    $$.id_val.val_type = INT_TYPE;
                    temp_var = generate_temp_var();
                    printf("%s := %s SUBI %s\n", temp_var, $1.lexema, $3.lexema);
                    instruction_counter++;
                } else {
                    if ($1.id_val.val_type == FLOAT_TYPE && $3.id_val.val_type == FLOAT_TYPE) {
                        $$.id_val.val_float = $1.id_val.val_float - $3.id_val.val_float;
                        temp_var = generate_temp_var();
                        printf("%s := %s SUBF %s\n", temp_var, $1.lexema, $3.lexema);
                        instruction_counter++;
                    } else if ($1.id_val.val_type == FLOAT_TYPE && $3.id_val.val_type == INT_TYPE) {
                        $$.id_val.val_float = (float) $1.id_val.val_float - $3.id_val.val_int;
                        char *new_temp_var = generate_temp_var();
                        temp_var = generate_temp_var();
                        printf("%s := I2F %s\n", new_temp_var, $3.lexema);
                        printf("%s := %s SUBF %s\n", temp_var, $1.lexema, new_temp_var);
                        instruction_counter += 2;
                    } else {
                        $$.id_val.val_float = (float) $1.id_val.val_int - $3.id_val.val_float;
                        char *new_temp_var = generate_temp_var();
                        temp_var = generate_temp_var();
                        printf("%s := I2F %s\n", new_temp_var, $1.lexema);
                        printf("%s := %s SUBF %s\n", temp_var, new_temp_var, $3.lexema);
                        instruction_counter += 2;
                    }
                    $$.id_val.val_type = FLOAT_TYPE;
                }
            } else {
                yyerror("Type error: Subtraction operation is only allowed between numeric values");
                $$.id_val.val_type = UNKNOWN_TYPE;
            }
            $$.lexema = temp_var;$$.is_literal = 0;
            $$.is_literal = 0;
    }
    | expr_arithmetic OR expr_unary {
        yyerror("C3A generator does not support logical OR operation");
    }
    ;

expr_unary:
    expr_term
    | PLUS expr_unary {
        fprintf(yyout, "PRODUCTION expr_unary + %s\n", value_to_str($2.id_val));
        char *temp_var = NULL;
        // Verify its a number
        if ($2.id_val.val_type == INT_TYPE || $2.id_val.val_type == FLOAT_TYPE) {
            if ($2.id_val.val_type == INT_TYPE) {
                $$.id_val.val_int = $2.id_val.val_int;
                $$.id_val.val_type = INT_TYPE;
                temp_var = generate_temp_var();
                printf("%s := %s\n", temp_var, $2.lexema);
                instruction_counter++;
            } else {
                $$.id_val.val_float = $2.id_val.val_float;
                $$.id_val.val_type = FLOAT_TYPE;
                temp_var = generate_temp_var();
                printf("%s := %s\n", temp_var, $2.lexema);
                instruction_counter++;
            }
        } else {
            yyerror("Type error: Unary plus operation is only allowed on numeric values");
            $$.id_val.val_type = UNKNOWN_TYPE;
        }
    }
    | MINUS expr_unary {
        fprintf(yyout, "PRODUCTION expr_unary - %s\n", value_to_str($2.id_val));
        char *temp_var = NULL;
        // Verify its a number
        if ($2.id_val.val_type == INT_TYPE || $2.id_val.val_type == FLOAT_TYPE) {
            if ($2.id_val.val_type == INT_TYPE) {
                $$.id_val.val_int = $2.id_val.val_int * -1;
                $$.id_val.val_type = INT_TYPE;
                temp_var = generate_temp_var();
                printf("%s := CHSI %s\n", temp_var, $2.lexema);
                instruction_counter++;
            } else {
                $$.id_val.val_float = $2.id_val.val_float * -1;
                $$.id_val.val_type = FLOAT_TYPE;
                temp_var = generate_temp_var();
                printf("%s := CHSF %s\n", temp_var, $2.lexema);
                instruction_counter++;
            }
        } else {
            yyerror("Type error: Unary minus operation is only allowed on numeric values");
            $$.id_val.val_type = UNKNOWN_TYPE;
        }
        $$.lexema = temp_var;
        $$.is_literal = 0;
    }
    | expr_unary AND expr_term {
        yyerror("C3A generator does not support logical AND operation");
    }
    ;

expr_term:
    expr_pow
    | expr_term MULT expr_pow {
        fprintf(yyout, "PRODUCTION expr_term %s * %s\n", value_to_str($1.id_val), value_to_str($3.id_val));
        char *temp_var = NULL;
        // Verify that are numbers
        if (($1.id_val.val_type == INT_TYPE || $1.id_val.val_type == FLOAT_TYPE) &&
            ($3.id_val.val_type == INT_TYPE || $3.id_val.val_type == FLOAT_TYPE)) {
                if ($1.id_val.val_type == INT_TYPE && $3.id_val.val_type == INT_TYPE) {
                    $$.id_val.val_int = ($1.id_val.val_int * $3.id_val.val_int);
                    $$.id_val.val_type = INT_TYPE;
                    temp_var = generate_temp_var();
                    printf("%s := %s MULI %s\n", temp_var, $1.lexema, $3.lexema);
                    instruction_counter++;
                } else {
                    if ($1.id_val.val_type == FLOAT_TYPE && $3.id_val.val_type == FLOAT_TYPE) {
                        $$.id_val.val_float = $1.id_val.val_float * $3.id_val.val_float;
                        temp_var = generate_temp_var();
                        printf("%s := %s MULF %s\n", temp_var, $1.lexema, $3.lexema);
                        instruction_counter++;
                    } else if ($1.id_val.val_type == FLOAT_TYPE && $3.id_val.val_type == INT_TYPE) {
                        $$.id_val.val_float = (float) $1.id_val.val_float * $3.id_val.val_int;
                        char *new_temp_var = generate_temp_var();
                        temp_var = generate_temp_var();
                        printf("%s := I2F %s\n", new_temp_var, $3.lexema);
                        printf("%s := %s MULF %s\n", temp_var, $1.lexema, new_temp_var);
                        instruction_counter += 2;
                    } else {
                        $$.id_val.val_float = (float) $1.id_val.val_int * $3.id_val.val_float;
                        char *new_temp_var = generate_temp_var();
                        temp_var = generate_temp_var();
                        printf("%s := I2F %s\n", new_temp_var, $1.lexema);
                        printf("%s := %s MULF %s\n", temp_var, new_temp_var, $3.lexema);
                        instruction_counter += 2;
                    }
                    $$.id_val.val_type = FLOAT_TYPE;
                }
            } else {
                yyerror("Type error: Multiplication operation is only allowed between numeric values");
                $$.id_val.val_type = UNKNOWN_TYPE;
            }
            $$.lexema = temp_var;
            $$.is_literal = 0;
    }
    | expr_term DIV expr_pow {
        fprintf(yyout, "PRODUCTION expr_term %s / %s\n", value_to_str($1.id_val), value_to_str($3.id_val));
        char *temp_var = NULL;
        // Verify that are numbers
        if (($1.id_val.val_type == INT_TYPE || $1.id_val.val_type == FLOAT_TYPE) &&
            ($3.id_val.val_type == INT_TYPE || $3.id_val.val_type == FLOAT_TYPE)) {
                $$.id_val.val_type = FLOAT_TYPE;
                if ($1.id_val.val_type == INT_TYPE && $3.id_val.val_type == INT_TYPE) {
                    $$.id_val.val_float = (float) ($1.id_val.val_int / $3.id_val.val_int);
                    temp_var = generate_temp_var();
                    printf("%s := %s DIVI %s\n", temp_var, $1.lexema, $3.lexema);
                    instruction_counter++;
                } else {
                    if ($1.id_val.val_type == FLOAT_TYPE && $3.id_val.val_type == FLOAT_TYPE) {
                        $$.id_val.val_float = $1.id_val.val_float / $3.id_val.val_float;
                        temp_var = generate_temp_var();
                        printf("%s := %s DIVF %s\n", temp_var, $1.lexema, $3.lexema);
                        instruction_counter++;
                    } else if ($1.id_val.val_type == FLOAT_TYPE && $3.id_val.val_type == INT_TYPE) {
                        $$.id_val.val_float = (float) $1.id_val.val_float / $3.id_val.val_int;
                        char *new_temp_var = generate_temp_var();
                        temp_var = generate_temp_var();
                        printf("%s := I2F %s\n", new_temp_var, $3.lexema);
                        printf("%s := %s DIVF %s\n", temp_var, $1.lexema, new_temp_var);
                        instruction_counter += 2;
                    } else {
                        $$.id_val.val_float = (float) $1.id_val.val_int / $3.id_val.val_float;
                        char *new_temp_var = generate_temp_var();
                        temp_var = generate_temp_var();
                        printf("%s := I2F %s\n", new_temp_var, $1.lexema);
                        printf("%s := %s DIVF %s\n", temp_var, new_temp_var, $3.lexema);
                        instruction_counter += 2;
                    }
                }
            } else {
                yyerror("Type error: Division operation is only allowed between numeric values");
                $$.id_val.val_type = UNKNOWN_TYPE;
            }
            $$.lexema = temp_var;
            $$.is_literal = 0;
    }
    | expr_term MOD expr_pow {
        fprintf(yyout, "PRODUCTION expr_term %s %% %s\n", value_to_str($1.id_val), value_to_str($3.id_val));
        char *temp_var = NULL;
        // Verify that both operands are integers
        if ($1.id_val.val_type == INT_TYPE && $3.id_val.val_type == INT_TYPE) {
            $$.id_val.val_type = INT_TYPE;
            $$.id_val.val_int = $1.id_val.val_int % $3.id_val.val_int;
            temp_var = generate_temp_var();
            printf("%s := %s MODI %s\n", temp_var, $1.lexema, $3.lexema);
            instruction_counter++;
        } else {
            yyerror("Type error: Modulus operation is only allowed between integers");
            $$.id_val.val_type = UNKNOWN_TYPE;
        }
        $$.lexema = temp_var;
        $$.is_literal = 0;
    }
    | NOT expr_term {
        yyerror("C3A generator does not support logical NOT operation");
    }
    ;

expr_pow:
    factor 
    | expr_pow POW factor {
        yyerror("C3A generator does not support exponentiation operation");
    }
    | expr_pow GT factor {
        yyerror("C3A generator does not support greater than operation");
    }
    | expr_pow LT factor {
        yyerror("C3A generator does not support less than operation");
    }
    | expr_pow GE factor {
        yyerror("C3A generator does not support greater or equal operation");
    }
    | expr_pow LE factor {
        yyerror("C3A generator does not support less or equal operation");
    }
    | expr_pow EQ factor {
        yyerror("C3A generator does not support equal operation");
    }
    | expr_pow NE factor {
        yyerror("C3A generator does not support not equal operation");
    }
    ;

factor: 
    ID {
        fprintf(yyout, "PRODUCTION ID Factor %s\n", $1.lexema);
        value_info value;
        if (sym_lookup($1.lexema, &value) == SYMTAB_NOT_FOUND) {
            yyerror("Variable not found");
        } else {
                $$.id_val = value;
                $$.lexema = $1.lexema;
                if (value.val_type == STR_TYPE) {
                    $$.lenght = strlen(value.val_str);
                }
                $$.is_literal = 1;
            }
    }
    | INTEGER {
        fprintf(yyout, "PRODUCTION INTEGER Factor %d\n", $1);
        $$.id_val.val_type = INT_TYPE;
        $$.id_val.val_int = $1;
        // store value as a string
        $$.lexema = (char *)malloc(12);
        sprintf($$.lexema, "%d", $1);
        $$.is_literal = 1;
    }
    | STRING {
        fprintf(yyout, "PRODUCTION STRING Factor %s\n", $1);
        $$.id_val.val_type = STR_TYPE;
        $$.id_val.val_str = substr($1, 1, strlen($1) - 2);
        $$.lexema = $1;
        $$.lenght = strlen($1) - 2;
    }
    | BOOLEAN {
        fprintf(yyout, "PRODUCTION BOOLEAN Factor %d\n", $1);
        $$.id_val.val_type = BOOL_TYPE;
        $$.id_val.val_bool = $1;
        $$.lexema = $1 ? "true" : "false";
    }
    | REAL {
        fprintf(yyout, "PRODUCTION REAL Factor %f\n", $1);
        $$.id_val.val_type = FLOAT_TYPE;
        $$.id_val.val_float = $1;
        // store value as a string
        $$.lexema = (char *)malloc(12);
        sprintf($$.lexema, "%f", $1);
    }
    | PI {
        fprintf(yyout, "PRODUCTION PI Factor\n");
        $$.id_val.val_type = FLOAT_TYPE;
        $$.id_val.val_float = 3.141592653589793;
        // store value as a string
        $$.lexema = "3.141592653589793";
    }
    | E {
        fprintf(yyout, "PRODUCTION E Factor\n");
        $$.id_val.val_type = FLOAT_TYPE;
        $$.id_val.val_float = 2.718281828459045;
        // store value as a string
        $$.lexema = "2.718281828459045";
    }
    | LPAREN expression RPAREN {
        fprintf(yyout, "PRODUCTION LPAREN expression RPAREN %s\n", value_to_str($2.id_val));
        $$ = $2;
    }
    | expr_trig
    | expr_len
    | expr_substr
    ;

expr_trig:
    SIN LPAREN expression RPAREN {
        yyerror("C3A generator does not support trigonometric functions");
    }
    | COS LPAREN expression RPAREN {
       yyerror("C3A generator does not support trigonometric functions");
    }
    | TAN LPAREN expression RPAREN {
        yyerror("C3A generator does not support trigonometric functions");
    }
    ;
    
expr_len:
    LEN LPAREN STRING RPAREN {
        yyerror("C3A generator does not support string length function");
    }
    | LEN LPAREN ID RPAREN {
        yyerror("C3A generator does not support string length function");
    }
    ;

expr_substr:
    SUBSTR LPAREN STRING COMMA expression COMMA expression RPAREN {
        yyerror("C3A generator does not support substring function");
    }
    | SUBSTR LPAREN ID COMMA expression COMMA expression RPAREN {
        yyerror("C3A generator does not support substring function");
    }
    ;

%%
