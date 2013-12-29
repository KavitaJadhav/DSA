#ifndef _ITERATOR_
#define _ITERATOR_

typedef struct iterator{
        int position;
        void* tree;
        void* (*getSibling)(struct iterator *it);
        int (*hasSibling)(struct iterator *it);
} Iterator;

#endif