#include<stdio.h>
#define size 5
int que[size];
int f = -1;
int r = -1;

void enque(){
	int x;
	if(r==size-1){

		printf("\nQueue is Full");
	}
	
	
	else{	
		if(f == -1)
		f = 0;

		printf("\nEnter Element: ");
		scanf("%d",&x);
		r = r+1;
		que[r] = x;
	}
}

void displayQue(){
	
	for(int i=f;i<r+1;i++){

		printf("%d ",que[i]);
	}
	printf("\n");
}

void deque(){

	if(f==-1 ||  f>r){

		printf("\nQueue is Empty");
	}
	else{
		printf("\nDeque Element: %d",que[f]);
		f = f+1;
	}
}

void peek(){

	if(f==-1 || f>r){

		printf("\nQueue Empty");
	}
	else{
		printf("\nPeek Element: %d",que[f]);
	}
}

void main(){
	
	int ch = 1;
	int n; 

	do{
		
		printf("\n1. EnQueue");
		printf("\n2. Display Queue");
		printf("\n3. DeQueue");
		printf("\n4. Peek");
		printf("\nEnter Your Choice: ");
		scanf("%d",&n);

		switch(n){

			case 1:
				enque();
				break;
			case 2:
				displayQue();
				break;
			case 3:
				deque();
				break;
			case 4:
				peek();
				break;
			default:
				printf("\nWrong Choice");
		}
		printf("\nDo you want Continue: ");
		scanf("%d",&ch);
	}while(ch==1);
}
