#ifndef SCIENCE_PUBLICATION_H
#define SCIENCE_PUBLICATION_H

#include <stdbool.h>
typedef struct SciencePublication {
    char name[127];
    char author_surname[127];
    char author_initials[63];
    char magazine_name[127];
    short year;
    int volume;
    bool rinc;
    int pages;
    int cites;    
} SciencePublication;

#endif