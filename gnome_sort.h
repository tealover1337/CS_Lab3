#ifndef GNOME_SORT_H
#define GNOME_SORT_H

#include "stack.h"
#include "science_publication.h"
#include "comparator.h"
#include <stdbool.h>
#define T SciencePublication

void gnome_sort(Stack* container, bool comparator(T elem1, T elem2), short type);

#endif