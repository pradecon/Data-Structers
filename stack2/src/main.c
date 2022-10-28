/*
 * main.c
 *
 *  Created on: Oct 28, 2022
 *      Author: mfcan
 */
#include <stdio.h>
#define STACK_SIZE 4
typedef struct{
	int data[STACK_SIZE];
	int top;
} stack;
void reset(stack* stk){
	stk->top=-1;
}
void pushSystem(int c,stack* stk){
	if(stk->top!=STACK_SIZE-1){
		stk->top++;
		stk->data[stk->top]=c;
	}else{
		printf("Stack is full!\n");
	}
}
int popSystem(stack* stk){
	if(stk->top==-1){
		printf("Stack is empty\n");
		return -100;
	}else{
		return stk->data[stk->top--];
	}
}
int main(){
	stack n;int x;
	reset(&n);


	push(4,&n);
	push(5,&n);
	push(3,&n);
	push(2,&n);
	push(1,&n);

	x=pop(&n);

	push(11,&n);

	x=pop(&n);
	x=pop(&n);
	x=pop(&n);

	push(3,&n);
	push(2,&n);

	x=pop(&n);
	printf("Last Value of x: %d",x);
}

