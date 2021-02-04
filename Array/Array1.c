#include<stdio.h>
#define N 50

int arr[N];

int flag = 0;

void insertEnd(){
	int n;
	printf("Enter Data: ");
	scanf("%d",&n);
	
	arr[++flag] = n;
	
}

void createArray(){
	
	int n,e;

	printf("\nNumber of Element to insert: ");
	scanf("%d",&e);
	for(int i=1;i<=e;i++){
		
		printf("Enter Data: ");
		scanf("%d",&arr[i]);
		flag++;
	}
}

void insertBegin(){
	
	int n;
	printf("\nEnter Element to Begin: ");
	scanf("%d",&n);
	for(int i=flag;i>=0;i--){
		
		arr[i+1] = arr[i];
	}
	arr[0] = n;
	flag++;
}

void insertAtPos(){
	
	int n,pos;
	printf("\nEnter Element to Pos: ");
	scanf("%d",&n);
	printf("\nEnter Position: ");
	scanf("%d",&pos);

	for(int i=flag;i>=pos;i--){

		arr[i+1] = arr[i];
	}
	arr[pos] = n;
	flag++;
}

void deleteAtEnd(){
	
	arr[flag] = 0;
	--flag;
}

void deleteAtBegin(){
	
	for(int i=0;i<=flag;i++){

		arr[i] = arr[i+1];
	}
	--flag;

}

void deleteAtPos(){
	
	int pos;

	printf("\nEnter Position to delete: ");
	scanf("%d",&pos);

	for(int i=pos;i<=flag;i++){

		arr[i] = arr[i+1];
	}
	--flag;
}

void display(){

	for(int i=1;i<=flag;i++){

		printf("%d ",arr[i]);
	}
}


void main(){

	int n,ch;

	do{
		printf("\n1. Create Array");
		printf("\n2. Display");
		printf("\n3. InsertAtEnd");
		printf("\n4. InsertAtBegin");
		printf("\n5. InsertAtPos");
		printf("\n6. DeleteAtEnd");
		printf("\n7. DeleteAtBegin");
		printf("\n8. DeleteAtPos");
		printf("\nEnter Your Choice: ");
		scanf("%d",&n);
		switch(n){

			case 1 :
				createArray();
				break;
			case 2 :
				display();
				break;
			case 3 :
				insertEnd();
				break;
			case 4 :
				insertBegin();
				break;
			case 5 :
				insertAtPos();
				break;
			case 6 :
				deleteAtEnd();
				break;
			case 7 :
				deleteAtBegin();
				break;
			case 8 :
				deleteAtPos();
				break;
			default :
				printf("\nWrong Choice");
		}

		printf("\nDo u want Continue(0/1): ");
		scanf("%d",&ch);
	}while(ch==1);
}
