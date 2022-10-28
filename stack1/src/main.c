#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 3
typedef struct node{
	int data;
	struct node* next;
} node;
typedef struct{
	int cnt;
	node* top;
} stack;
void init(stack *stk){
	stk->cnt=0;
	stk->top=NULL;
}
void push(stack *stk,int c){
	if(stk->cnt==STACK_SIZE){
		printf("\nStack is full\n");
	}else{
		node *temp=(node*)malloc(sizeof(node));
		temp->data=c;
		temp->next=stk->top;
		stk->top=temp;
		stk->cnt++;
	}
}
int pop(stack *stk){
	if(stk->cnt==0){
		printf("\nStack is empty");
	}else if(stk->cnt>0){
		int x=stk->top->data;
		node* temp=stk->top;
		stk->top=stk->top->next;
		free(temp);
		stk->cnt--;
		return x;
	}
	return -100;
}
int main(){
	stack test;
	init(&test);
	push(&test,4);
	push(&test,14);
	push(&test,41);
	push(&test,6);
	printf(" %d\t",pop(&test));
	printf(" %d\t",pop(&test));
	printf(" %d\t",pop(&test));
	printf(" %d\t",pop(&test));
}
