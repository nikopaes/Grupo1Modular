#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

int main(void){
/*
	void *v;
	int a = 10;
	int b;
	char c = 'A';
	v = &a;
	b = (int*) v;
	printf("%d\n", b);
*/
	List *l;
	int a=3;
	int b=2;
	char c = 'C';
	int *ptA = NULL;
	int *ptB = NULL;

	createList(&l);
	push_front(l, &a);
	//push_front(l, &c);
	//push_front(l, &b);
	printf("inseri\n");
	//list_size(l, (void*) ptB);
	get_val_cursor(l, (void**) &ptA);
	printf("retirei\n");
	//next(l);
	printf("%d\n", *ptA);
	//printf("%d\n", d);
	//printf("next\n");
	//push_front(l, &c);
	//get_val_cursor(l, (void*) &c);
	//printf("retirei\n");
	//printf("%c\n", c);
	//free(d);
	printf("FIM\n");
	return 0;
}
