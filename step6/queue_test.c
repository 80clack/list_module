/* 
 * queue_test.c --- 
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
#include "queue.h"

typedef struct car {
	char plate[MAXREG];
	double price;
	int year;
} car_t;

car_t* make_car(char* cplate, double price, int year){                          
  car_t* cc;                                                                    
                                                                                
  if(!(cc = (car_t*)malloc(sizeof(car_t)))){                                    
    printf("[Error: malloc failed allocating car]\n");                          
    return NULL;                                                                
  }                                                               
  strcpy(cc->plate, cplate);                                                    
  cc->price = price;                                                            
  cc->year = year;                                                              
  return cc;                                                                    
}

void print_car(car_t *cp){

	if (cp==NULL){
		printf("List is empty.");
		return;
	}
  printf("Car plate=%s, Price=%.2lf, Year=%d\n",
				 cp->plate, cp->price, cp->year);
	
}

void double_price(car_t *cp){
	cp->price *= 2.0;
}

int main(){

	//change for queue!
	queue_t *queue = qopen();
	car_t *c1 = make_car("c1",20000.0,2003);

	car_t *c2 = make_car("c2",40000.0,2020);

	qput(queue, c1);
	qapply(queue, print_car);
	qput(queue, c2);
	qapply(queue, print_car);

	qapply(queue, double_price);
	qapply(queue, print_car);

	car_t gotten_car = *qget(queue);
	printf("Got car with plate %s\n", gotten_car.plate);
	
	qapply(print_car);

	car_t *c3 = make_car("c3",10000.0,2010);

	car_t *c4 = make_car("c4",5000.0,2000);

	qput(queue, c3);
	qput(queue, c4);

	qapply(queue, print_car);

	char *car3 = "c3";
	
	car_t *removed_car = qremove(queue, car3);
	printf("Removed car with plate %s\n", (*removed_car).plate);
	
	qapply(queue, print_car);
	
	return 0;
}
