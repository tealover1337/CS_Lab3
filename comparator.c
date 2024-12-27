#include <stdbool.h>
#include "science_publication.h"
#define T SciencePublication

// compares by year of publication, if they're same compares by pages;
bool comparator(T elem1, T elem2) {
    if (elem1.year > elem2.year || (elem1.year == elem2.year && elem1.pages >= elem2.pages)) {return 1;}
    return 0;
}