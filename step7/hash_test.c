/* 
 * hash_test.c --- 
 * 
 * Author: Bill Zheng, Daniel Jeon, Dhruv Chandra, Walker Ball
 * Created: 10-11-2023
 * Version: 1.0
 * 
 * Description: 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "hash.h"

void add_one(void *i) {
    *((int *) i)+=1;
}

bool searchfn(void* elementp, const void* searchkeyp) {
    if (*((int*) elementp) == 2) return true;
    else return false;
}

int main(void) {
    int i = 1;
    char k = 'd';
    int j;

    hashtable_t* head = hopen(10);

    printf("open complete\n");
    hput(head, &i, "yuh", 3);

    printf("put complete\n");
    happly(head, add_one);
    printf("apply complete\n");

    j = *((int *)hsearch(head, searchfn, "yuh", 3));
    printf("finding this integer: %d\n", j);
        hput(head, &i, "yuh", 3);
    hput(head, &k, "jeez", 4);
    happly(head, add_one);

    hclose(head);

    //edge cases
    /*
        1) if hashtable_t is empty, run all other functions -- check the requirements on the comments above the functions
        2) if hashtable_t is not NULL (it has queues BUT no elements), then none of the methods should give you an error. Instead, 
        it should give you a warning or a number (e.g. -1)
        3) Try with multiple objects (and different types)
        4) Check for collision behavior.
    */
   return 0;
}
