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

void insertFirst(){
	
	struct node *newnode;

	printf("Enter Data insert to First: ");
	newnode = (struct node*)malloc(sizeof(struct node));
	scanf("%d",&newnode->data);
	newnode->next = 0;

	if(head == 0){

		head = newnode;
	}
	else{
		newnode->next = head;
		head = newnode;
	}

}

void insertLast(){
	struct node *newnode,*tmp;
	tmp = head;
	printf("Enter data want to Last: ");
	newnode = (struct node*)malloc(sizeof(struct node));
	scanf("%d",&newnode->data);
	newnode->next = 0;
	if(head == 0){

		head = tmp = newnode;
	}
	else{
		while(tmp->next !=0){
			
			tmp = tmp->next;

		}
		tmp->next = newnode;
		tmp = newnode;
	}
}

void insertMiddle(){
	
	struct node *newnode,*tmp;
	tmp = head;
	int pos,i = 1;
	printf("Enter Position to be Added: ");
	scanf("%d",&pos);
	printf("Enter data Given Pos: ");
	newnode = (struct node*)malloc(sizeof(struct node));
	scanf("%d",&newnode->data);
	newnode->next=0;
	if(pos==1){

		newnode->next = tmp->next;
		tmp->next = newnode;
		head = newnode;
	}
	else{
		while(i<pos-1){
			tmp = tmp->next;
			i++;
		}
		newnode->next = tmp->next;
		tmp->next = newnode;
	}

}

void deleteFirst(){
	
	struct node *tmp;
	tmp = head;

	head = tmp->next;

	free(tmp);

}

void deleteLast(){
	
	struct node *tmp,*prevnode;
	tmp = head;

	while(tmp->next!=0){
		prevnode = tmp;
		tmp = tmp->next;

	}
	prevnode->next = 0;
	free (tmp);
}

void deleteMiddle(){
	
	struct node *tmp,*curr;
	tmp = head;
	int pos,i=1;
	printf("Enter Position to be Delete: ");
	scanf("%d",&pos);
	if(pos==1){

		deleteFirst();
	}
	else{
		while(i < pos-1){
			tmp = tmp->next;
			i++;
		}
		curr = tmp->next;
		tmp->next = curr->next;
		free(curr);
	}
}

void main(){
	
	struct node *head, *newnode, *tmp;
	head = 0;
	int n;
	int ch;

	do{
		printf("\n1. Create");
		printf("\n2. Display");
		printf("\n3. InsertFirst");
		printf("\n4. InsertLast");
		printf("\n5. InsertMiddle");
		printf("\n6. DeleteFirst");
		printf("\n7. DeleteLast");
		printf("\n8. DeleteMiddle");
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
				insertFirst();
				break;
			case 4 :
				insertLast();
				break;
			case 5 :
				insertMiddle();
				break;
			case 6 :
				deleteFirst();
				break;
			case 7 :
				deleteLast();
				break;
			case 8 :
				deleteMiddle();
				break;
			default:
				printf("\nWrong Choice");
		}
		
		printf("\nDo you want Continue (0/1): ");
		scanf("%d",&ch);
	}while(ch==1);
	
}
