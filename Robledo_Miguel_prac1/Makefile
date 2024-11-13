######################################################################
#
#                           Compiladors
#
######################################################################

CC = gcc
LEX = flex
YACC = bison
LIB = -lfl
MATH_LIB = -lm

SRC_LEX = lexer.l
SRC_YACC = parser.y

LEX_OUT = build/lex.yy.c
YACC_OUT_C = build/parser.tab.c
YACC_OUT_H = build/parser.tab.h
YACC_OUT = $(YACC_OUT_C) $(YACC_OUT_H)

OTHERS = compiler.output
OBJ = build/*.o

SRC = src/main.c
BIN = bin/compiler

SRC_EXTRA = src/data.c src/functions.c

SYMTAB = src/symtab.c

YFLAGS = -d -v -Wcounterexamples
CFLAGS = -Wall -g -O0


######################################################################

all : build_dir yacc lex
	$(CC) -o $(BIN) $(CFLAGS) $(SRC) $(SRC_EXTRA) $(SYMTAB) $(YACC_OUT_C) $(LEX_OUT) $(LIB) $(MATH_LIB)

# Create build directory if it does not exist
build_dir:
	mkdir -p build bin

yacc : $(SRC_YACC)
	$(YACC) $(YFLAGS) $(SRC_YACC) -o $(YACC_OUT_C)

lex : $(SRC_LEX)
	$(LEX) $(LFLAGS) -o $(LEX_OUT) $(SRC_LEX)

clean :
	rm -f *~ $(BIN) $(OBJ) $(YACC_OUT) $(LEX_OUT) $(OTHERS) build/parser.output
	rm -rf build bin