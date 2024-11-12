#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int init_lexical_analysis(char *);
int end_lexical_analysis();

int init_syntactic_analysis(char *);
int end_syntactic_analysis(void);

int semantic_analysis(void);

void yyerror(char *explanation);
char *substr_wrapper(char *str, int start, int length);


#endif
