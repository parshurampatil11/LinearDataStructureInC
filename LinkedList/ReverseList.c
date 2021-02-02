#include<stdio.h>
#include<stdlib.h>
struct node{

	int data;
	struct node *next;

}*head;

void reverse(){

	struct node *prev,*nextnode,*curr;
	nextnode = curr = head;
	prev =  0;
	while(nextnode!=0){

		nextnode = nextnode->next;
		curr->next = prev;
		prev = curr;
		curr = nextnode;
	}
	head = prev;

}
void display(){
	struct node *tmp1;
	
	tmp1 = head;

	while(tmp1->next != 0){

		printf("%d-> ",tmp1->data);
		tmp1 = tmp1->next;
	}
	printf("%d ",tmp1->data);
}

void create(){

	struct node *newnode, *tmp;
	head = 0;
	int ch = 1;
	
	do{
		printf("Enter Data: ");
		newnode = (struct node*)malloc(sizeof(struct node));
		scanf("%d",&newnode->data);
		newnode->next = 0;
		if(head == 0){

			head = tmp = newnode;
		}
		else{
			tmp->next = newnode;
			tmp = newnode;
		}
		printf("want continue: ");
		scanf("%d",&ch);
	}while(ch==1);
}

void main(){
	
	create();

	display();	

	reverse();

	display();	

}
