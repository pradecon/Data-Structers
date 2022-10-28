/*
 * main.c
 *
 *  Created on: Oct 29, 2022
 *      Author: mfcan
 */
#include <stdio.h>
#define STACK_SIZE 10
typedef struct{
	char data[STACK_SIZE];
	int top;
} stack;
void reset(stack* stk){
	stk->top=-1;
}
void pushSystem(char c,stack* stk){
	if(stk->top!=STACK_SIZE-1){
		stk->top++;
		stk->data[stk->top]=c;
	}else{
		printf("Stack is full!\n");
	}
}
char popSystem(stack* stk){
	if(stk->top==-1){
		printf("Stack is empty\n");
		return 'E';
	}else{
		return stk->data[stk->top--];
	}
}
void push(char c,stack* stk){
	switch(c){
	case '(':
		pushSystem(c,stk);
		break;
	case '[':
		pushSystem(c,stk);
		break;
	case '{':
		pushSystem(c,stk);
		break;
	case ')':
		if(stk->data[stk->top]=='('){
			printf("%c%c\n",popSystem(stk),c);
			break;
		}else{
			printf("Expected: )\n");
			return;
		}
	case ']':
			if(stk->data[stk->top]=='['){
				printf("%c%c\n",popSystem(stk),c);
				break;
			}else{
				printf("Expected: ]\n");
				return;
			}
	case '}':
			if(stk->data[stk->top]=='{'){
				printf("%c%c\n",popSystem(stk),c);
				break;
			}else{
				printf("Expected: }\n");
				return;
			}
	default :
		return;
	}
}
int main(){
	stack n;
	FILE *f=fopen("text.txt","r");
	char c;
	do{
		c=fgetc(f);
		push(c,&n);
	}while(c!=EOF);
	if(n.top!=0)
		printf("There is unclosed %c bracket",n.data[n.top]);
}

