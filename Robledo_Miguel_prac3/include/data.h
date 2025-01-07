#ifndef DATA_H
#define DATA_H

#define STR_MAX_LENGTH 200

typedef enum {
  UNKNOWN_TYPE = 1,
  INT_TYPE,
  FLOAT_TYPE,
  BOOL_TYPE,
  STR_TYPE,
  ARRAY_TYPE
} data_type;

typedef struct {
  data_type val_type;
  int val_int;
  float val_float;
  int val_bool;
  char *val_str;
} value;

typedef struct {
  data_type val_type;
  data_type val_array_type;
  int val_int;
  float val_float;
  int val_bool;
  char *val_str;
  value *val_array;
} value_info;


char *type_to_str(data_type val_type);
char *value_info_to_str(value_info value);
char *value_to_str(value_info value);

char *generate_temp_var();
char *generate_fi_if();

#endif