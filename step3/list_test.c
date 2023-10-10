
/* 
 * list_test.c --- 
 * 
 * Author: Bill Zheng, Daniel Jeon, Dhruv Chandra, Walker Ball
 * Created: 10-09-2023
 * Version: 1.0
 * 
 * Description: 
 * 
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "list.h"

void test_lput() {
    car_t car1, car2;
		int result1, result2;

		strcpy(car1.plate, "ABC123");
    car1.price = 10000.0;
    car1.year = 2020;

    strcpy(car2.plate, "XYZ789");
    car2.price = 15000.0;
    car2.year = 2021;

    result1 = lput(&car1);
    result2 = lput(&car2);

    printf("Test lput(): Result1=%d, Result2=%d\n", result1, result2);
}

void test_lget() {
    car_t *car1 = lget();
    car_t *car2 = lget();

    printf("Test lget(): Car1 plate=%s, Car2 plate=%s\n",
           car1 ? car1->plate : "NULL", car2 ? car2->plate : "NULL");
}

void test_lapply(car_t *cp) {

    void sample_function(car_t *cp) {
        cp->price += 1000.0;
    }

    lapply(sample_function);

    printf("Test lapply(): Car plate=%s, Price=%.2lf\n",
           cp->plate, cp->price);
}

void test_lremove() {

    car_t *removed_car = lremove("ABC123");

    printf("Test lremove(): Removed Car plate=%s\n",
           removed_car ? removed_car->plate : "NULL");
}

int main() {
    // Initialize your list or list-related resources here

	car_t *c1 = make_car("abc123",20000,2003);
	car_t *c2 = make_car("c2",40000,2020);

	lput(&c1);
	lput(&c2);

	test_lapply(&c1);


	
	//    test_lput();
	// test_lget();

	//car_t car_for_apply;
	//strcpy(car_for_apply.plate, "DEF456");
	//car_for_apply.price = 12000.0;
	//car_for_apply.year = 2019;

	//test_lapply(&car_for_apply);

	//test_lremove();

    return 0;
}
