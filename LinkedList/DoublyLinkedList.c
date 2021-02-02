#include<stdio.h>
#include<stdlib.h>
struct node{

	int data;
	struct node *prev;
	struct node *next;
}*head,*tail;

void createList(){
	
	struct node *newnode;
	int ch =1;
	head = 0;

	do{
		printf("Enter data: ");
		newnode = (struct node*)malloc(sizeof(struct node));
		scanf("%d",&newnode->data);
		newnode->prev = 0;
		newnode->next = 0;
		if(head==0){
			head = tail = newnode;
		}
		else{
			tail->next = newnode;
			newnode->prev = tail;
			tail = newnode;
		}
		printf("You want add more (/01): ");
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

void insertBeg(){

	struct node *newnode;
	
	printf("Enter data Begnning: ");
	newnode = (struct node*)malloc(sizeof(struct node));
	scanf("%d",&newnode->data);
	newnode->prev = 0;
	newnode->next = 0;

	if(head == 0){
		
		head = tail = newnode;
	}
	else{
		newnode->next = head;
		head->prev = newnode;
		head = newnode;
	}
}

void insertLast(){

	struct node *newnode;

	printf("Enter Data to add Last: ");
	newnode = (struct node*)malloc(sizeof(struct node));
	scanf("%d",&newnode->data);
	newnode->prev = 0;
	newnode->next = 0;

	if(head==0){

		head = tail = newnode;
	}
	else{
		newnode->prev = tail;
		tail->next = newnode;
		tail = newnode;
	}
}

void insertGiven(){
	struct node *newnode,*tmp;
	tmp = head;
	int pos,i=1;
	printf("Enter Position: ");
	scanf("%d",&pos);
	printf("\nInsert data Given Pos: ");
	newnode = (struct node*)malloc(sizeof(struct node));
	scanf("%d",&newnode->data);
	newnode->prev = 0;
	newnode->next = 0;
	if(head==0){
		head = tail = newnode; 
	}
	else if(pos==1){

		newnode->next = head;
		head->prev = newnode;
		head = newnode;
	}
	else {
		while(i<pos-1){
			
			tmp = tmp->next;
			i++;
		}
		newnode->prev = tmp->next->prev;
		newnode->next = tmp->next;
		tmp->next->prev = newnode;
		tmp->next = newnode;
		
	}


}

void delFirst(){
	
	struct node *tmp;
	tmp = head;

	head->next->prev = 0;
	head = head->next;

	free(tmp);

}

void delLast(){
	
	struct node *tmp;
	if(tail==0){
		printf("\nEmpty");
	}
	else{
		tmp = tail;

		tail->prev->next = 0;
		tail = tail->prev;
		free(tmp);
	}


}

void delGiven(){

	struct node *tmp;
	tmp = head;
	int pos,i=1;
	printf("\nEnter pos to del: ");	
	scanf("%d",&pos);
	
	if(pos==1){

		head->next->prev = 0;
		head = head->next;
	}
	else{
		while(i<pos){

			tmp = tmp->next;
			i++;
		}
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		free(tmp);
	}

}

void main(){
		
	int ch,n;
	
	do{	
		printf("\n1. Create Double List");
		printf("\n2. Display");
		printf("\n3. Insert Beg");
		printf("\n4. Insert Last");
		printf("\n5. Insert Given");
		printf("\n6. Delete First");
		printf("\n7. Delete Last");
		printf("\n8. Delete Given");
		printf("\nEnter your Choice: ");
		scanf("%d",&n);
		switch(n){

			case 1:
				createList();
				break;
			case 2:
				displayList();
				break;
			case 3:
				insertBeg();
				break;
			case 4:
				insertLast();
				break;
			case 5:
				insertGiven();
				break;
			case 6:
				delFirst();
				break;
			case 7:
				delLast();
				break;
			case 8:
				delGiven();
				break;
			default:
				printf("Wrong Choice");
		}
		printf("\nDo you want Continue(0/1): ");
		scanf("%d",&ch);
	}while(ch==1);
}
