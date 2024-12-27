#include "stack.h"
#include <stdbool.h>
#include "science_publication.h"
#define T SciencePublication

// type = asc or dsc (0 or 1); ik I could persist dry principle but I'm too lazy to use boolean algebra basics
void gnome_sort(Stack* container, bool comparator(T elem1, T elem2), short type) {
    size_t pos = 1;
    while (pos < get_size(container)) {
        if (pos == 0) {pos = 1;}
        if (type == 0) {
            if (comparator(get_element(container, pos), get_element(container, pos - 1))) {
                ++pos;
            }
            else {
                stack_swap(container, pos, pos - 1);
                --pos;
            }
        }
        else {
            if (comparator(get_element(container, pos), get_element(container, pos - 1))) {
                stack_swap(container, pos, pos - 1);
                --pos;
            }
            else {
                ++pos;
            }
        }
    }
}