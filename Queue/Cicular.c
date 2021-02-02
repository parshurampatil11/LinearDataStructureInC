#include<stdio.h>
#define N 5
int que[N];
int f = -1;
int r = -1;

void enque(int x){
	if(f==-1 && r==-1){
		f=r=0;
		que[r] = x;
	}
	else if(((r+1)%N)==f){

		printf("Queue is Full");
	}
	else{
		r = (r+1)%N;
		que[r] = x;
	}
	printf("\n");
}

void deque(){
	if(f==-1 && r==-1){

		printf("\nQueue is empty");
	}
	else if(f==r){

		f=r=-1;
	}
	else{
		printf("\n%d",que[f]);
		f = (f+1)%N;
	}
	printf("\n");
}

void display(){

	if(f==-1 && r==-1){

		printf("\nQueue is Empty");
	}
	else{
		int i = f;
		while(i!=r){
			printf("%d ",que[i]);
			i = (i+1)%N;
		}
		printf("%d ",que[i]);
	}
}


void main(){
	enque(10);
	enque(20);
	enque(30);
	enque(40);
	enque(50);
	display();
	deque();
	deque();
	enque(60);
	display();
}
