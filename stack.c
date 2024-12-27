#include <stdlib.h>
#include "science_publication.h"
#include "stack.h"

#define INIT_SIZE 1
#define STACK_OVERFLOW -100
#define STACK_UNDERFLOW -101
#define MEMORY_ALLOCATION_ERROR -102
#define INDEX_OUT_OF_RANGE -103
#define T SciencePublication

Stack* stack_initialize(size_t capacity) {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {exit(MEMORY_ALLOCATION_ERROR);} // if malloc fails
    stack->data = (T*)malloc(capacity * sizeof(T));
    if (stack->data == NULL) {exit(MEMORY_ALLOCATION_ERROR);} // if malloc fails
    stack->size = 0;
    stack->cap = capacity;
    return stack;
}

void stack_remove(Stack *stack) {
    if (stack != NULL) {free(stack->data); free(stack);}
}

void stack_capincr(Stack* stack) {
    stack->cap++;
    T *future_data = realloc(stack->data, stack->cap * sizeof(T));
    if (future_data == NULL) {stack_remove(stack); exit(MEMORY_ALLOCATION_ERROR);} // if realloc fails, else it frees the memory automatically
    stack->data = future_data;
}

void stack_capdecr(Stack* stack) {
    if (stack->size == stack->cap || stack->cap <= 1) {exit(STACK_OVERFLOW);}
    stack->cap--;
    T *future_data = realloc(stack->data, stack->cap * sizeof(T));
    if (future_data == NULL) {stack_remove(stack); exit(MEMORY_ALLOCATION_ERROR);} // if realloc fails, else it frees the memory automatically
    stack->data = future_data;
}

int get_size(Stack* stack) {
    return (int)stack->size;
}

T get_element(Stack* stack, size_t index) {
    if (stack == NULL) {
        exit(STACK_UNDERFLOW);
    }
    else if (index < 0 || index >= stack->size) {
        exit(INDEX_OUT_OF_RANGE);    
    }
    else {return stack->data[index];}

}

T* get_start(Stack* stack) {
    return stack->data;
}
T* get_end(Stack* stack) {
    return stack->data + stack->cap;
}

T* get_previous(Stack* stack, size_t index) {
    if (index <= 0 || index >= stack->size) {
        exit(INDEX_OUT_OF_RANGE);    
    }
    return &stack->data[index - 1];
}
T* get_next(Stack* stack, size_t index) {
    if (index < 0 || index >= stack->size - 1) {
        exit(INDEX_OUT_OF_RANGE);    
    }
    return &stack->data[index + 1];
}

void stack_push(Stack* stack, T element) {
    if (stack->size == stack->cap) {
        exit(STACK_OVERFLOW);
    }
    stack->data[stack->size] = element;
    stack->size++;
}

T stack_pop(Stack* stack) {
    if (stack->size == 0) {exit(STACK_UNDERFLOW);}
    stack->size--;
    T head = stack->data[stack->size];
    return head;
}

void stack_add(Stack* stack, T element, size_t index) {
    if (stack->size + 1 > stack->cap) {exit(STACK_OVERFLOW);}
    if (index < 0 || index > stack->size) {exit(INDEX_OUT_OF_RANGE);}
    Stack* temp = stack_initialize(stack->size - index); // we will put elements to another stack, then we will append new element to our stack and return other elements
    for (size_t i = 0; i < temp->cap; i++) {
        stack_push(temp, stack_pop(stack));
    }
    stack_push(stack, element);
    for (size_t i = 0; i < temp->cap; i++) {
        stack_push(stack, stack_pop(temp));
    }
    stack_remove(temp);
}

void stack_delete(Stack* stack, size_t index) {
    if (stack->size == 0) {exit(STACK_UNDERFLOW);}
    if (stack->size <= index || index < 0) {exit(INDEX_OUT_OF_RANGE);}
    Stack* temp = stack_initialize(stack->size - 1 - index);
    for (size_t i = 0; i < temp->cap; i++) {
        stack_push(temp, stack_pop(stack));
    }
    stack_pop(stack);
    for (size_t i = 0; i < temp->cap; i++) {
        stack_push(stack, stack_pop(temp));
    }
    stack_remove(temp);
}

void stack_swap(Stack* stack, size_t index1, size_t index2) {
    if (index1 > stack->size - 1 || index2 > stack->size - 1) {exit(INDEX_OUT_OF_RANGE);}
    T temp = stack->data[index2];
    stack->data[index2] = stack->data[index1];
    stack->data[index1] = temp;
}

T* stack_to_array(Stack* stack) {
    T* array = (T*)malloc(stack->size * sizeof(T));
    if (array == NULL) {exit(MEMORY_ALLOCATION_ERROR);}
    for (size_t i = 0; i < stack->size; i++) {
        array[i] = get_element(stack, i);
    }
    stack_remove(stack);
    return array;
}

Stack* array_to_stack(T* array, size_t array_size) {
    Stack* stack = stack_initialize(array_size);
    for (size_t i = 0; i < array_size; i++) {
        stack_push(stack, array[i]);
    }
    return stack;
}