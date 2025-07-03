#include "MyString.h"

int main() {
    char* test = ",,,,,,,,,,,,,one,,three,,two,,,one,,,,,,,three,,five,";
    string_t input = {strlen(test), test};
    int size = 0;

    string_t *result = my_split(&input, ',', &size);

    free_split_result(result, size);
}