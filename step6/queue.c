/* 
 * Daniel Jeon, Bill Zheng, Dhruv Chandra, Walker Ball
 * Module 3: Queue Module
 * 
 * Implements the queue.h
 */
#include <stdint.h>
#include <stdbool.h>
#include "queue.h"
#include <stdlib.h>

/* must use nodes unless the test has specific nodes that have the variable "next" */
typedef struct node{
    void* data;
    struct node* next;
} node_t;

/* the queue representation is hidden from users of the module */
struct queue{
    void* front;
    void* back;
} 

/* create an empty queue */
queue_t* qopen(void) {
    queue_t* queue = malloc(sizeof(struct queue));
    queue->front = NULL;
    queue->back = queue->front;
    return queue;
}

/* deallocate a queue, frees everything in it */
void qclose(queue_t *qp){
    void *monke; //data
    node_t *temp;  //temporary node
    while (qp->front != NULL) {
        temp = qp->front;
        monke = temp->data;
        qp->front = temp->next;
        free(monke); //watch out for this; freeing the object or the pointer?
        free(temp); //assuming temp, the node has been allocated for in our add function
        monke = NULL;
        temp = NULL;
    }
}   

/* put element at the end of the queue
 * returns 0 is successful; nonzero otherwise 
 */
int32_t qput(queue_t *qp, void *elementp){
    node_t *new = malloc(sizeof(node_t));
    if (new->data = elementp) {
        return 0;
    }
    //if unsuccessful
    else {
        return 1;
    }
} 

/* get the first first element from queue, removing it from the queue */
void* qget(queue_t *qp){
    node_t * monke;
    void data;
    if (qp->front == NULL) {
        printf("Error: Nothing in the queue.\n");
        return NULL;
    }
    else {
        monke = qp->front;
        qp->front = qp->front->next;
        data = *(monke->data); //review this portion
        free(qp->front->data);
        free(qp->front);
        return &data;
    }
}

/* apply a function to every element of the queue */
void qapply(queue_t *qp, void (*fn)(void* elementp)){
    node_t temp;
    for(temp = qp->front; temp != NULL; temp = temp->next){
        fn(temp->data);
    }
}

/* search a queue using a supplied boolean function
 * skeyp -- a key to search for
 * searchfn -- a function applied to every element of the queue
 *          -- elementp - a pointer to an element
 *          -- keyp - the key being searched for (i.e. will be 
 *             set to skey at each step of the search
 *          -- returns TRUE or FALSE as defined in bool.h
 * returns a pointer to an element, or NULL if not found
 */
void* qsearch(queue_t *qp, bool (*searchfn)(void* elementp,const void* keyp), const void* skeyp){
    node_t temp;
    for(temp = qp->front; temp != NULL; temp = temp->next){
        if (searchfn(temp->data, skeyp)) {
            return temp->data;
        }
    }
    return NULL;
}

/* search a queue using a supplied boolean function (as in qsearch),
 * removes the element from the queue and returns a pointer to it or
 * NULL if not found
 */
void* qremove(queue_t *qp, bool (*searchfn)(void* elementp,const void* keyp), const void* skeyp) {
    node_t temp;
    node_t monke;
    void * data;
    for(temp = qp->front; temp != NULL; temp = temp->next){
        if (searchfn(temp->data, skeyp)) {
            monke = temp;
            temp = temp->next;
            data = *(monke->data); //review this portion
            free(qp->front->data);
            free(qp->front);
            return &data;
        }
    }
    return NULL;
}

/* concatenates elements of q2 into q1
 * q2 is deallocated, closed, and unusable upon completion 
 */
void qconcat(queue_t *q1p, queue_t *q2p){
    node_t* loop = q2p->front;
    while (loop != NULL) {
        qput(q1p, qget(q2p));
    }
}
