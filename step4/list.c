/* 
 * list.c --- 
 * 
 * Author: Daniel J. Jeon, Bill Zheng, Dhruv Chandra, Walker Ball
 * Created: 10-08-2023
 * Version: 1.0
 * 
 * Description: Implements list.h
 * 
 */
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAXREG 10

static car_t *front=NULL;

/* put(): place a car at the beginning of the list
 * returns 0 if successful; nonzero otherwise 
 */
int32_t lput(car_t *cp) {
    car_t *temp;
    if (front == NULL) {
        front = cp;
    }
    else {
        temp = front;
        front = cp;
        cp->next = temp;
    }
    return 0;
}

/* get(): remove and return the first car in the list;
 * return NULL if the list is empty
 */
car_t *lget() {
    car_t * temp;
    if (front == NULL) {
        return NULL;
    }
    else {
        temp = front;
        front = front->next;
        return temp;
    }
}

/* apply a function to every car in the list */
void lapply(void (*fn)(car_t *cp)){
    car_t *temp = front;

		for(temp = front; temp != NULL; temp = temp->next){
			fn(temp);
		}
}

/* remove(): find, remove, and return any car with
 * the designated plate; return NULL if not present
 */
car_t *lremove(char *platep){
    car_t *temp;
    car_t *huff;
    if (platep == front->plate) {
        return front; //should return a car with its next pointers pointing to other cars?
    }
    else {
        temp = front;
        huff = temp;
        while ((temp=temp->next) != NULL) {
            if (platep == temp->plate) {
                huff->next = temp->next;
                return temp; //should return a car with its next pointers pointing to other cars?
            }
            huff = huff->next;
        }
    }
    //if car pointer is not returned in the loop
    return NULL;
}

car_t* make_car(char* cplate, double price, int year){
	car_t* cc;

	if(!(cc = (car_t*)malloc(sizeof(car_t)))){
		printf("[Error: malloc failed allocating car]\n");
		return NULL;
	}
	cc->next = NULL;
	strcpy(cc->plate, cplate);
	cc->price = price;
	cc->year = year;
	return cc;
}
