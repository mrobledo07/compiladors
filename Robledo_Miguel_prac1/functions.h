#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int init_analisi_lexica(char *);
int end_analisi_lexica();

int init_analisi_sintactica(char *);
int end_analisi_sintactica(void);

int analisi_semantica(void);

void yyerror(char *explanation);

float sin_wrapper(float x);
float cos_wrapper(float x);
float tan_wrapper(float x);
int len_wrapper(char *str);
char *substr_wrapper(char *str, int start, int length);


#endif
