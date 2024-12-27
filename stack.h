#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include "science_publication.h"

#define T SciencePublication

typedef struct Stack {
    T *data;
    size_t size;
    size_t cap;
} Stack;

Stack* stack_initialize(size_t capacity);
void stack_remove(Stack* stack);
void stack_capincr(Stack* stack);
void stack_capdecr(Stack* stack);
int get_size(Stack* stack);
T get_element(Stack* stack, size_t index);
T* get_start(Stack* stack);
T* get_end(Stack* stack);
T* get_previous(Stack* stack, size_t index);
T* get_next(Stack* stack, size_t index);
void stack_push(Stack* stack, T element);
T stack_pop(Stack* stack);
void stack_add(Stack* stack, T element, size_t index);
void stack_delete(Stack* stack, size_t index);
void stack_swap(Stack* stack, size_t index1, size_t index2);
T* stack_to_array(Stack* stack);
Stack* array_to_stack(T* array, size_t array_size);


#endif