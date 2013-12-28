#ifndef _ITERATOR_
#define _ITERATOR_

typedef struct iterator{
        int position;
        void* tree;
        void* (*next)(struct iterator *it);
        int (*hasNext)(struct iterator *it);
} Iterator;

#endif