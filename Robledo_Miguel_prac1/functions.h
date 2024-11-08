#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int init_lexical_analysis(char *);
int end_lexical_analysis();

int init_syntactic_analysis(char *);
int end_syntactic_analysis(void);

int semantic_analysis(void);

void yyerror(char *explanation);

float sin_wrapper(float x);
float cos_wrapper(float x);
float tan_wrapper(float x);
int len_wrapper(char *str);
char *substr_wrapper(char *str, int start, int length);


#endif
