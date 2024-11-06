#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "data.h"


char *type_to_str(data_type val_type)
{
  if (val_type == UNKNOWN_TYPE) {
    return strdup("Unknown type");
  } else if (val_type == INT_TYPE) {
    return strdup("Integer");
  } else if (val_type == FLOAT_TYPE) {
    return strdup("Float");
  } else if (val_type == BOOL_TYPE) {
    return strdup("Bool");
  } else if (val_type == STR_TYPE) {
    return strdup("String");
  } else {
    return strdup("Error: incorrect value for 'val_type'");
  }
}

char *value_info_to_str(value_info value) 
{
    char buffer[STR_MAX_LENGTH];
    if (value.val_type == INT_TYPE) {
        sprintf(buffer, "Integer: %d", value.val_int);
    } else if (value.val_type == FLOAT_TYPE) {
        sprintf(buffer, "Float: %f", value.val_float);
    } else if (value.val_type == BOOL_TYPE) {
        if (value.val_bool == false) {
            sprintf(buffer, "Bool: false");
        } else {
            sprintf(buffer, "Bool: true");
        }
    } else if (value.val_type == STR_TYPE) {
        sprintf(buffer, "String: %s", value.val_str);
    } else {
        sprintf(buffer, "Error: incorrect value for 'value.val_type'");
    }
    return strdup(buffer);
}
