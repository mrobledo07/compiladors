#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/data.h"
#include <stdarg.h>

#define MAX_CODE_LINES 100000
#define MAX_LINE_LENGTH 10000
char code[MAX_CODE_LINES][MAX_LINE_LENGTH];

int temp_var_counter = 1;
int if_counter = 1;

int n_instructions = 1;

char *type_to_str(data_type val_type)
{
  if (val_type == UNKNOWN_TYPE) {
    return strdup("Unknown type");
  } else if (val_type == INT_TYPE) {
    return strdup("Integer");
  } else if (val_type == FLOAT_TYPE) {
    return strdup("Float");
   } else if (val_type == BOOL_TYPE) {
    return strdup("Boolean");
  } else if (val_type == STR_TYPE) {
    return strdup("String");
  } else if (val_type == ARRAY_TYPE) {
    return strdup("Array");
  } else {
    return strdup("Error: incorrect value for 'val_type'");
  }
}

char *value_info_to_str(value_info value) 
{
    char buffer[STR_MAX_LENGTH+100];
    if (value.val_type == INT_TYPE) {
        snprintf(buffer, sizeof(buffer), "Integer: %d", value.val_int);
    } else if (value.val_type == FLOAT_TYPE) {
        snprintf(buffer, sizeof(buffer), "Float: %f", value.val_float);
    } else if (value.val_type == BOOL_TYPE) {
        snprintf(buffer, sizeof(buffer), "Boolean: %d", value.val_bool);
    } else if (value.val_type == STR_TYPE) {
        snprintf(buffer, sizeof(buffer), "String: \"%s\"", value.val_str);    
    } else if (value.val_type == ARRAY_TYPE) {
        snprintf(buffer, sizeof(buffer), "Array: size=%d", value.val_int);
  } else {
        snprintf(buffer, sizeof(buffer), "Error: incorrect value for 'value.val_type'");
    }
    return strdup(buffer);
}

char *value_to_str(value_info value) 
{
    char buffer[STR_MAX_LENGTH+100];
    if (value.val_type == INT_TYPE) {
        snprintf(buffer, sizeof(buffer), "%d", value.val_int);
    } else if (value.val_type == FLOAT_TYPE) {
        snprintf(buffer, sizeof(buffer), "%.1f", value.val_float);
    } else if (value.val_type == BOOL_TYPE) {
        snprintf(buffer, sizeof(buffer), "%d", value.val_bool);
    } else if (value.val_type == STR_TYPE) {
        snprintf(buffer, sizeof(buffer), "%s", value.val_str);    
    } else if (value.val_type == ARRAY_TYPE) {
        snprintf(buffer, sizeof(buffer), "Array: size=%d", value.val_int);
  } else {
        snprintf(buffer, sizeof(buffer), "Error: incorrect value for 'value.val_type'");
    }
    return strdup(buffer);
}

char *generate_temp_var()
{
    char buffer[6];
    snprintf(buffer, sizeof(buffer), "$t%02d", temp_var_counter);
    temp_var_counter++;
    return strdup(buffer);
}

char *generate_fi_if() {
    char buffer[6];
    snprintf(buffer, sizeof(buffer), "fi_%02d", if_counter);
    if_counter++;
    return strdup(buffer);
}




// Crea una nueva lista con una única instrucción
instruction_list* makelist(int instruction) {
    instruction_list* new_list = (instruction_list*)malloc(sizeof(instruction_list));
    if (new_list == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for the instruction list.\n");
        exit(1);
    }
    new_list->instruction = instruction;
    new_list->next = NULL;
    return new_list;
}

// Combina dos listas en una sola
instruction_list* merge(instruction_list* list1, instruction_list* list2) {
    // Si una lista está vacía, retorna la otra
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    
    // Encuentra el final de la primera lista
    instruction_list* temp = list1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    // Concatena la segunda lista al final de la primera
    temp->next = list2;
    return list1;
}

void backpatch(instruction_list* list, int target_instruction) {
    instruction_list* current = list;

    while (current != NULL) {
        // Accede a la instrucción en la posición especificada por el índice
        char* old_instruction = code[current->instruction];

        // Busca el marcador "____" en la instrucción
        char* blank_pos = strstr(old_instruction, "____");
        if (blank_pos != NULL) {
            // Calcula la nueva instrucción reemplazando "____" por target_instruction
            char new_instruction[MAX_LINE_LENGTH];
            int prefix_len = blank_pos - old_instruction; // Longitud de la parte antes de "____"
            
            // Copia la parte inicial de la instrucción antes de "____"
            strncpy(new_instruction, old_instruction, prefix_len);
            new_instruction[prefix_len] = '\0'; // Asegura terminación de la cadena
            
            // Añade el número de la instrucción destino
            char target_str[20];
            sprintf(target_str, "%d", target_instruction);
            strcat(new_instruction, target_str);

            // Añade el resto de la instrucción después de "____"
            strcat(new_instruction, blank_pos + 4); // Salta "____" (4 caracteres)

            // Actualiza la instrucción en el array de código
            strcpy(code[current->instruction], new_instruction);
        } else {
            printf("Error: Could not find marker '____' in instruction %d\n", current->instruction);
        }

        // Avanza al siguiente nodo en la lista
        current = current->next;
    }
}


void emit(char* format,...) {
    va_list args;
    va_start(args, format);
    vsnprintf(code[n_instructions], MAX_LINE_LENGTH, format, args);
    va_end(args);
    n_instructions++;
}

void print_code() {
    for (int i = 0; i < n_instructions; i++) {
        printf("%s", code[i]);
    }
}

void clear_code() {
    for (int i = 0; i < n_instructions; i++) {
        code[i][0] = '\0';
    }
    n_instructions = 0;
}