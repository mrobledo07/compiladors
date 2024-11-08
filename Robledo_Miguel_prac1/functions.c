#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "functions.h"

extern int yyparse();
extern FILE *yyin;
extern FILE *yyout;
extern int yylineno;


int init_lexical_analysis(char *filename)
{
  int error;
  yyin = fopen(filename,"r");
  if(yyin == NULL) {
    error = EXIT_FAILURE;
  } else {
    error = EXIT_SUCCESS;
  }
  return error;
}


int end_lexical_analysis()
{
  int error;
  error = fclose(yyin);
  if (error == 0) {
    error = EXIT_SUCCESS;
  } else {
    error = EXIT_FAILURE;
  }
  return error;
}


int init_syntactic_analysis(char* filename)
{
  int error = EXIT_SUCCESS;
  yyout = fopen(filename,"w");
  if (yyout == NULL) {
    error = EXIT_FAILURE;
  }
  return error;
}


int end_syntactic_analysis(void)
{
  int error;

  error = fclose(yyout);

  if(error == 0) {
    error = EXIT_SUCCESS;
  } else {
    error = EXIT_FAILURE;
  }
  return error;
}


int semantic_analysis(void)
{
  int error;

  if (yyparse() == 0) {
    error =  EXIT_SUCCESS;
  } else {
    error =  EXIT_FAILURE;
  }
  return error;
}


void yyerror(char *explanation)
{
  fprintf(stderr, "Error: %s , in line %d\n", explanation, yylineno);
}

float sin_wrapper(float x)
{
  return sin(x);  
}

float cos_wrapper(float x)
{
  return cos(x);
}

float tan_wrapper(float x)
{
  return tan(x);
}

int len_wrapper(char *str)
{
  return strlen(str);
}

char *substr_wrapper(char *str, int start, int length) {
    if (start < 0 || length < 0 || start > length) {
        yyerror("Invalid arguments for substr, returning empty string");
        return strdup("");
    }
    char *result = (char *)malloc(length + 1);
    strncpy(result, str + start, length);
    result[length] = '\0';
    return result;
}
