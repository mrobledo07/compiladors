#include "include/data.h"
#include <stdio.h>

int main() {
    for (int i = 0; i < 1000; i++) {
    char *temp_var = generate_temp_var();
    printf("Temp var: %s\n", temp_var);
    }
    return 0;
}