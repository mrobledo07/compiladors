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

LEX_OUT = lex.yy.c
YACC_OUT_C = parser.tab.c
YACC_OUT_H = parser.tab.h
YACC_OUT = $(YACC_OUT_C) $(YACC_OUT_H)

OTHERS = compiler.output
OBJ = *.o

SRC = main.c
BIN = compiler.exe

SRC_EXTRA = data.c functions.c

SYMTAB = symtab.c

LFLAGS =
YFLAGS = -d -v
CFLAGS = -Wall -g -O0

EG_IN = input_file.txt
EG_OUT = output_file.txt



######################################################################

all : yacc lex
	$(CC) -o $(BIN) $(CFLAGS) $(SRC) $(SRC_EXTRA) $(SYMTAB) $(YACC_OUT_C) $(LEX_OUT) $(LIB) $(MATH_LIB)

yacc : $(SRC_YACC)
	$(YACC) $(YFLAGS) $(SRC_YACC)

lex : $(SRC_LEX)
	$(LEX) $(LFLAGS) $(SRC_LEX)

clean :
	rm -f *~ $(BIN) $(OBJ) $(YACC_OUT) $(LEX_OUT) $(OTHERS) $(EG_OUT)

eg : $(EG_IN)
	./$(BIN) $(EG_IN) $(EG_OUT)
	cat $(EG_OUT)
