#ifndef GENERATOR_H
#define GENERATOR_H

#include <stdlib.h>
#include "stack.h"
#include "science_publication.h"
#define T SciencePublication

Stack* generate_data(int N);
T generate_line();
char* generate_string(int maxlength);
char* generate_initials();

#endif
