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
    int j;
    hashtable_t* head = hopen(10);
    printf("open complete\n");
    hput(head, &i, "yuh", 3);
    printf("put complete\n");
    happly(head, add_one);
    printf("apply complete\n");
    j = *((int *)hsearch(head, searchfn, "yuh", 3));
    printf("finding this integer: %d\n", j);

    j = *((int *)hremove(head, searchfn, "yuh", 3));
    printf("removed this integer: %d\n", j);
    hclose(head);
    return 0;
}
