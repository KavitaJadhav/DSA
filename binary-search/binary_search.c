#include "binary_search.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void* search_generic(void* array,void* key,int length,int elementSize,compareFunction* compare){
   int first = 0,middle,result;
   int last = length - 1;
   // qsort(array, length,elementSize,compare);
   while(first <= last ){
      middle = (first+last)/2;
      result = compare(key,array+(middle*elementSize));
      if(result == 0)
         return (array+(middle*elementSize));
      if(result < 0)
         last = middle-1;
      else 
         first = middle+1;
   }
   return 0; 
} 