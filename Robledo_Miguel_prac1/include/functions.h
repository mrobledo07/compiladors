#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int init_lexical_analysis(char *);
int end_lexical_analysis();

int init_syntactic_analysis(char *);
int end_syntactic_analysis(void);

int semantic_analysis(void);

void yyerror(char *explanation);
char *substr(char *str, int start, int length);
char *concat(char *s1, char *s2);

#endif
