#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/functions.h"
#include "../include/data.h"


int main(int argc, char *argv[])
{
  int error;

  if (argc == 3) {
    error = init_lexical_analysis(argv[1]);

    if (error == EXIT_SUCCESS) {
      error = init_syntactic_analysis(argv[2]);

      if (error == EXIT_SUCCESS) {
        error = semantic_analysis();

        if (error == EXIT_SUCCESS) {
          print_code();
          printf("HALT\n");
        } else {
          printf("ERROR");
        }

        error = end_syntactic_analysis();
        if (error == EXIT_FAILURE) {
          printf("The output file can not be closed\n");
        }

        error = end_lexical_analysis();
        if (error == EXIT_FAILURE) {
          printf("The input file can not be closed\n");
        }
      } else {
        printf("The output file %s can not be created\n",argv[2]);
      }
    } else {
      printf("The input file %s can not be opened\n",argv[1]);
    }
  } else {
    printf("\nUsage: %s INPUT_FILE OUTPUT_FILE\n",argv[0]);
  }
  return EXIT_SUCCESS;
}