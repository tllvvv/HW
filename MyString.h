#ifndef MYSTRING_H
#define MYSTRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct string{
    int size;
    char *array;
} string_t;

typedef struct pair{
     int first;
     int second;
}pair;

typedef struct correctPos{
     int size;
     pair *array_pos;   
}correctPos;

string_t concatenation(string_t *first_string, string_t *second_string);
string_t substring(string_t *input_string, int first_position, int second_position);
string_t* my_split(string_t *string, char separator, int *size);
int lenstr(string_t *input_string);
char* my_strchr(string_t *input_string, char desired_symbol);
char* my_strrchr(string_t *input_string, char desired_symbol);
int my_strcmp(string_t *first_string, string_t *second_string);
void free_split_result(string_t *array_after_split, int size);

void free_correctPos(correctPos *correctpos);
correctPos find_correct_segment(string_t *string, char separator);


#define strchr(input_string, desired_symbol) _Generic((input_string), \
        string_t*: my_strchr, \
        char*: strchr \
)(input_string, desired_symbol)

#define strrchr(input_string, desired_symbol) _Generic((input_string), \
        string_t*: my_strrchr, \
        char*: strrchr \
)(input_string, desired_symbol)
#define strcmp(first_string, second_string) _Generic((first_string), \
        string_t*: my_strcmp, \
        char*: strcmp \
)(first_string, second_string)
#define split(string, separator) _Generic((string) \
        string_t*: my_split, \
        char*: split \
)(string, separator)

#endif
