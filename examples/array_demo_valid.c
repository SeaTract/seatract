#include "seatract.h"
#include <stdio.h>

typedef struct {
    int data[10];
    int size;
} IntArray;

int get_element(IntArray *array, int index) {
	/*
		RECONDITIONS:
		Index must be within the current logical size
	*/
	Require(array != NULL);
	Require(index >= 0);
	Require(index <= array->size);

	int val = array->data[index];
	
	/*
		POSTCONDITION:
		Ensure we aren't returning uninitialized-style data
		(Example logic: our array only stores positive integers)
	*/
	Ensure(val >= 0);
	
	return val;
}

int main() {
		IntArray myArr = {{ 10, 20, 30, 40, 50, 60, 70, 80, 90, 100}, 5};
		//int i;

		for (int i=1; i<= myArr.size; i++) {
			int x = get_element(&myArr, i-1);
			printf("Element number %d:\t%d\n", i,x);

		}
		return 0;
}

