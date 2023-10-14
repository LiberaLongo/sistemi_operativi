
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AOS_LENSTEP 8

struct array_of_strings {
    char **strings;
    size_t currentlength; 
    size_t arraylength;
};

typedef struct array_of_strings array_of_strings;

void array_of_strings_add(array_of_strings *arrayOfStrings, char *string) {
    if (arrayOfStrings->currentlength >= arrayOfStrings->arraylength) {
        size_t newlength = arrayOfStrings->arraylength + AOS_LENSTEP;
        char **new_string = realloc(arrayOfStrings->strings, newlength * sizeof(arrayOfStrings->strings[0]));
        if (new_string != NULL) {
            arrayOfStrings->arraylength = newlength;
            arrayOfStrings->strings = new_string;
        }
    }
    if (arrayOfStrings->currentlength < arrayOfStrings->arraylength)
        arrayOfStrings->strings[arrayOfStrings->currentlength++] = strdup(string);
}

void array_of_strings_print(array_of_strings *v) {
    size_t i;
    for (i = 0; i < v->currentlength; i++)
        printf("[%3lu]: %s\n", i, v->strings[i]);
}

static int alphasort(const void *a, const void *b) {
    return strcmp(*(char **) a, *(char **) b);
}

void array_of_strings_sort(array_of_strings *v) {
    qsort(v->strings, v->currentlength, sizeof(v->strings[0]), alphasort);
}

void array_of_strings_free(array_of_strings *v) {
    size_t i;
    for (i = 0; i < v->currentlength; i++)
        free(v->strings[i]);
    if (v->arraylength > 0)
        free(v->strings);
}

int main(int argc, char *argv[]) {
    char* line = NULL;
    size_t lineLength = 0;
    ssize_t numberOfCharactersRead;
    static array_of_strings arrayOfStrings;
    if (argc != 1)
        exit(1);
    while ((numberOfCharactersRead = getline(&line, &lineLength, stdin)) >= 0) {
        if (line[numberOfCharactersRead - 1] == '\n')
            line[numberOfCharactersRead - 1] = 0;
        array_of_strings_add(&arrayOfStrings, line);
    }

    free(line);
    array_of_strings_sort(&arrayOfStrings);
    array_of_strings_print(&arrayOfStrings);
    array_of_strings_free(&arrayOfStrings);
}

