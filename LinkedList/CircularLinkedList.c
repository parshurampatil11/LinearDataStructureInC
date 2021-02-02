#include<stdio.h>
#include<stdlib.h>

struct node{

	int data;
	struct node *prev;
	struct node *next;
}*head,*tail;


void createList(){
	
	struct node *newnode;

	head = 0;

	int ch = 1;

	do{
		printf("Enter Data to insert: ");
		newnode = (struct node*)malloc(sizeof(struct node));
		scanf("%d",&newnode->data);
		newnode->prev = 0;
		newnode->next = 0;

		if(head==0){

			head = tail = newnode;
			head->prev = newnode;
			head->next = newnode;
		}
		else{
			newnode->prev = tail;
			tail->next = newnode;
			newnode->next = head;
			head->prev = newnode;
			tail = newnode;
		}

		printf("Do you want Add more Records(0/1): ");
		scanf("%d",&ch);
	}while(ch==1);

}	

void displayList(){
	
	struct node *tmp;
	tmp = head;

	while(tmp->next!=head){

		printf("%d->",tmp->data);
		tmp = tmp->next;
	}
	printf("%d",tmp->data);

}

void insertBeg(){
	
	struct node *newnode;
	printf("Insert At Beg: ");
	newnode = (struct node*)malloc(sizeof(struct node));
	scanf("%d",&newnode->data);
	newnode->prev = 0;
	newnode->next = 0;
	if(head==0){

		head = tail = newnode;
		head->prev = newnode;
		head->next = newnode;
	}
	else{
		newnode->next = head;
		head->prev = newnode;
		newnode->prev = tail;
		tail->next = newnode;
		head = newnode;
	}
}

void insertEnd(){

	struct node *newnode;
	printf("Insert Last: ");
	newnode = (struct node*)malloc(sizeof(struct node));
	scanf("%d",&newnode->data);
	newnode->prev = 0;
	newnode->next = 0;
	if(head==0){

		head = tail = newnode;
		head->next = newnode;
		head->prev = newnode;
	}
	else{
		newnode->prev = tail;
		tail->next = newnode;
		newnode->next = head;
		head->prev = newnode;
		tail = newnode;
	}
}

void insertGiven(){
	
	struct node *newnode,*tmp;

	int pos,i=1;
	printf("\nEnter Position: ");
	scanf("%d",&pos);
	printf("\nInsert Given: ");
	newnode = (struct node*)malloc(sizeof(struct node));
	scanf("%d",&newnode->data);
	newnode->prev = 0;
	newnode->next = 0;
	if(pos == 1){

		newnode->next = head;
		head->prev = newnode;
		newnode->prev = tail;
		tail->next = newnode;
		head = newnode;
	}
	else{
		tmp = head;
		while(i<pos-1){

			tmp = tmp->next;
			i++;
		}	
		newnode->prev = tmp;
		newnode->next = tmp->next;
		tmp->next->prev = newnode;
		tmp->next = newnode;
	}		
}

void deleteBeg(){
	
	struct node *tmp;
	tmp = head;

	head->next->prev = head->next;
	tail->next = head->next;
	head = head->next;
	free(tmp);
}

void deleteEnd(){
	
	struct node *tmp;
	tmp = tail;

	tail->prev->next = tail->next;
	head->prev = tail->prev;
	tail = tail->prev;
	free(tmp);

}

void deleteGiven(){
	struct node *tmp;
	tmp = head;	
	int pos,i=1;

	printf("Enter Position to Delete: ");
	scanf("%d",&pos);
	
	if(pos==1){
		deleteBeg();
	}
	else{

		while(i<pos){
			
			tmp = tmp->next;
			i++;
		}
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		if(tmp->next==head){
			tail = tmp->next;
			free(tmp);
		}
		else{
			free(tmp);
		}
	}
}

void main(){
	
	int ch,n;

	do{
		printf("\n1. Create List");
		printf("\n2. Display List");
		printf("\n3. Insert Begnning");
		printf("\n4. Insert End");
		printf("\n5. Insert Given");
		printf("\n6. Delete Begnning");
		printf("\n7. Delete End");
		printf("\n8. Delete Given");
		printf("\nEnter Your Choice: ");
		scanf("%d",&n);

		switch(n){

			case 1 :
				createList();
				break;
			case 2 :
				displayList();
				break;
			case 3 :
				insertBeg();
				break;
			case 4 :
				insertEnd();
				break;
			case 5 :
				insertGiven();
				break;
			case 6 :
				deleteBeg();
				break;
			case 7 :
				deleteEnd();
				break;
			case 8 :
				deleteGiven();
				break;
			default :
				printf("\nWrong Choice");

		}

		printf("\nDo you want Continue(0/1): ");
		scanf("%d",&ch);
	}while(ch==1);

}
