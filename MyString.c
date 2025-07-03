#include "MyString.h"

string_t concatenation(string_t *first_string, string_t *second_string){
    string_t result;
    result.size = first_string->size + second_string->size;
    result.array = (char *)malloc((result.size + 1) * sizeof(char));
    if(result.size != 0){
        memcpy(result.array, first_string->array, first_string->size);
        memcpy(result.array + first_string->size, second_string->array, second_string->size);
    }else{
        result.array[0] = '\0';
    }

    return result;
}

string_t substring(string_t *input_string, int first_position, int second_position){
    string_t result;

    if(first_position < 0 || second_position < 0 || second_position < first_position || second_position > input_string-> size){

        result.size = 0;
        result.array = (char *)malloc(sizeof(char));
        result.array[0] = '\0';
    }else{

        result.size = second_position - first_position;
        result.array = (char *)malloc((result.size + 1) * sizeof(char));
        memcpy(result.array, input_string->array+ first_position, result.size);
        result.array[result.size] = '\0'; 
    }
    return result;
}

int lenstr(string_t *input_string){
    return input_string->size;
}

char* my_strchr(string_t *input_string, char desired_symbol){
    for(int i = 0; i < input_string->size; i++){
        if(input_string->array[i] == desired_symbol){
            return &input_string->array[i];
        }
    }
    return NULL;
} 

char* my_strrchr(string_t *input_string, char desired_symbol){
    for(int i = input_string->size - 1; i >= 0; i--){
        if(input_string->array[i] == desired_symbol){
            return &input_string->array[i];
        }
    }
    return NULL;
}

int my_strcmp(string_t *first_string, string_t *second_string) {

    int min_size = (first_string->size < second_string->size) ? first_string->size : second_string->size;

    for (int i = 0; i < min_size; i++) {
        if (first_string->array[i] < second_string->array[i]) {
            return -1;
        } else if (first_string->array[i] > second_string->array[i]) {
            return 1;
        }
    }

    if (first_string->size == second_string->size) {
        return 0;
    } else if (first_string->size < second_string->size) {
        return -1;
    } else {
        return 1;
    }
}

void free_split_result(string_t *array_after_split, int size) {
    for (int i = 0; i < size; i++) {
        free(array_after_split[i].array);
    }
    free(array_after_split); 
}

void free_correctPos(correctPos *correctpos) {
    free(correctpos->array_pos);
}

correctPos find_correct_segment(string_t *string, char separator) {
    int cnt_segment = 0;

    for (int i = 0; i < string->size; i++) {
        if (string->array[i] != separator) {
            if (i == 0 || string->array[i - 1] == separator) {
                cnt_segment++;
            }
        }
    }

    correctPos returnValue;
    returnValue.size = cnt_segment;
    returnValue.array_pos = (pair *)malloc(cnt_segment * sizeof(pair));

    int start = -1;
    int pos = 0;

    for (int i = 0; i <= string->size; i++) {
        if (i == string->size || string->array[i] == separator) {
            if (start != -1) {
                returnValue.array_pos[pos].first = start;
                returnValue.array_pos[pos].second = i - 1;
                pos++;
                start = -1;
            }
        } else if (start == -1) {
            start = i;
        }
    }

    return returnValue;
}

string_t* my_split(string_t *string, char separator, int *size) {
    correctPos found_pos_of_segment = find_correct_segment(string, separator);

    string_t *array_after_split = (string_t*)malloc(found_pos_of_segment.size * sizeof(string_t));

    for(int i = 0; i < found_pos_of_segment.size; i++) {
        array_after_split[i].size = found_pos_of_segment.array_pos[i].second - found_pos_of_segment.array_pos[i].first + 1;

        array_after_split[i].array = (char*)malloc((array_after_split[i].size + 1) * sizeof(char));
        memcpy(array_after_split[i].array, &string->array[found_pos_of_segment.array_pos[i].first], array_after_split[i].size);
        array_after_split[i].array[array_after_split[i].size] = '\0';
    }

    *size = found_pos_of_segment.size;
    free_correctPos(&found_pos_of_segment);

    return array_after_split;
}