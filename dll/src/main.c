/*
 * main.c
 *
 *  Created on: Oct 21, 2022
 *      Author: mfcan
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

void menu(struct node*);
struct node* create(struct node*);
void print(struct node*);
int count(struct node*);
struct node* addfront(struct node*);
struct node* addend(struct node*);
struct node* addbetween(struct node*,int);
struct node* delete(struct node*,int);
struct node* destroy(struct node*);



int main(){
	struct node *head=NULL;
	menu(head);
}




struct node* create(struct node* head){
	head=(struct node*)malloc(sizeof(struct node));
	struct node* iter=head;
	printf("Enter the number of elements you want to create: ");
	int n=0,counter=1;
	scanf("%d",&n);
	while(n!=0){
		printf("Enter data of %d. elementh's data: ",counter);
		scanf("%d",&iter->data);
		if(counter==1){
			iter->prev=NULL;
		}
		iter->next=(struct node*)malloc(sizeof(struct node));
		iter->next->prev=iter;
		counter++;
		n--;
		iter=iter->next;
	}
	iter=iter->prev;
	free(iter->next);
	iter->next=NULL;
	return head;
}
void print(struct node* head){
	int counter=1;
	system("clear");
	if(head==NULL){
		printf("List is empty\n");
		sleep(2);
		return;
	}
	while(head!=NULL){
		printf("%d. element's data: %d\n",counter,head->data);
		counter++;
		head=head->next;
	}
	sleep(5);
}
int count(struct node* head){
	int counter=0;
	while(head!=NULL){
		counter++;
		head=head->next;
	}
	return counter;
}
void menu(struct node* head){
	int selection = 1;
	while(selection!=3){
		system("clear");
		printf("1- create\n2- print\n3- exit\n4- add to front\n5- add to end\n6- add to between\n7- delete\n8- destroy\n9- count\n");
		scanf("%d",&selection);
		switch(selection){
		case 1:
			head=create(head);
			break;
		case 2:
			print(head);
			break;
		case 4:
			head=addfront(head);
			break;
		case 5:
			head=addend(head);
			break;
		case 6:

			{
				printf("Enter the data of element that you want to add after: ");
				int data=0;
				scanf("%d",&data);
				head=addbetween(head,data);
			}
			break;
		case 7:
			{
				printf("Enter the data of element that you want to delete: ");
				int data;
				scanf("%d",&data);
				head=delete(head,data);
			}
			break;
		case 8:
			head=destroy(head);
			break;
		case 9:
			system("clear");
			printf("Number of element(s): %d\n",count(head));
			sleep(2);
			break;
		}
		system("clear");
	}
}
struct node* addfront(struct node* head){
	struct node *new=(struct node*)malloc(sizeof(struct node));
	new=create(new);
	while(new->next!=NULL){
		new=new->next;
	}
	new->next=head;
	head->prev=new;
	while(new->prev!=NULL){
		new=new->prev;
	}
	return new;
}
struct node* addend(struct node* head){
	struct node *new=(struct node*)malloc(sizeof(struct node));
	new=create(new);
	while(head->next!=NULL)
		head=head->next;
	head->next=new;
	new->prev=head;
	while(head->prev!=NULL)
		head=head->prev;
	return head;
}
struct node* addbetween(struct node* head,int data){
	struct node *new=(struct node*)malloc(sizeof(struct node));
	new=create(new);
	while(head->data!=data){
		head=head->next;
		if(head==NULL){
			printf("data couldn't found\n");
			while(head->prev==NULL)
				head=head->prev;
			return head;
		}
	}
	new->prev=head;
	head=head->next;
	head->prev->next=new;
	while(new->next!=NULL)
		new=new->next;
	new->next=head;
	head->prev=new;
	while(head->prev!=NULL)
		head=head->prev;
	return head;
}
struct node* delete(struct node* head,int data){
	struct node* temp;
	while(head->data!=data){
		head=head->next;
		if(head==NULL){
			printf("data couldn't found\n");
			while(head->prev!=NULL)
				head=head->prev;
			return head;
		}
	}
	temp=head;
	while(head->prev!=NULL)
		head=head->prev;
	if(temp->prev!=NULL)
		temp->prev->next=temp->next;
	if(temp->next!=NULL)
		temp->next->prev=temp->prev;
	free(temp);
	if(temp==head)
		head=NULL;
	return head;
}
struct node* destroy(struct node* head){
	if(head==NULL)
		return head;
	struct node* temp=head;
	while(head->next!=NULL){
		head=head->next;
		free(temp);
		temp=head;
	}
	free(temp);
	return NULL;
}
