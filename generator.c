#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "stack.h"
#include "science_publication.h"
#define T SciencePublication

const char capitals[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char literals[] = "abcdefghijklmnopqrstuvwxyz";
char* generate_string(int maxlength) {
    const short length = rand()%(maxlength - 2) + 3;
    char* str = (char*)malloc((length + 2) * sizeof(char));
    if (str == NULL) {exit(-1);}
    str[0] = capitals[rand()%26];
    for (int i = 1; i <= length; i++) {
        str[i] = literals[rand()%26];
    }
    str[length + 1] = '\0';
    return str;
}

char* generate_initials() {
    char* init = (char*)malloc(5 * sizeof(char));
    if (init == NULL) {exit(-1);}
    init[0] = capitals[rand()%26];
    init[1] = '.';
    init[2] = capitals[rand()%26];
    init[3] = '.';
    init[4] = '\0';
    return init;
}

T generate_line() {
    T line;
    line.year = (short)(rand()%55 + 1970); // publication year (1970 - 2024)
    line.volume = rand()%60 + 1; // magazine volume
    line.rinc = rand() % 2; //bool is in RINC?
    line.pages = rand()%420 + 3; // number of pages
    line.cites = rand()%1270; // number of this work cites
    char* temp_name = generate_string(90);
    char* temp_surname = generate_string(60);
    char* temp_init = generate_initials();
    char* temp_magazine = generate_string(75);
    snprintf(line.name, sizeof(line.name), temp_name);
    snprintf(line.author_surname, sizeof(line.author_surname), temp_surname);
    snprintf(line.author_initials, sizeof(line.author_initials), temp_init);
    snprintf(line.magazine_name, sizeof(line.magazine_name), temp_magazine);
    free(temp_init);
    free(temp_magazine);
    free(temp_name);
    free(temp_surname);
    return line;
}

Stack* generate_data(int N) {
    Stack* container = stack_initialize(N);
    for (int i = 0; i < N; i++) {
        stack_push(container, generate_line());
    }
    return container;
}


