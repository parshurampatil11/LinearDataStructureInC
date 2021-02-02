#include<stdio.h>
#include<stdlib.h>

struct node{

	int data;

	struct node *next;

}*head;

void createList(){
	
	struct node *newnode, *tmp;

	int ch = 1;
	head = 0;

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

		printf("Do you want Continue Create List(0/1)\n");
		scanf("%d",&ch);
	}while(ch==1);

}

void displayList(){

	struct node *tmp;	
	
	tmp = head;

	while(tmp->next != 0){
		
		printf("%d->",tmp->data);
		tmp = tmp->next;
	}
	printf("%d",tmp->data);

}

void reverseList(){
	
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


void main(){
	
	struct node *head, *newnode, *tmp;
	head = 0;
	int n;
	int ch;

	do{
		printf("\n1. Create");
		printf("\n2. Display");
		printf("\n3. ReverseList");
		printf("\nEnter your Choice: ");
		scanf("%d",&n);
		
		switch(n){

			case 1 : 
				createList();
				break;
			case 2 :	
				displayList();
				break;
			case 3 :
				reverseList();
				break;
			default:
				printf("\nWrong Choice");
		}
		
		printf("\nDo you want Continue (0/1): ");
		scanf("%d",&ch);
	}while(ch==1);
	
}
