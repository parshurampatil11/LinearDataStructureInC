#include<stdio.h>
# define N 5 
int deque[N];
int f = -1;
int r = -1;

void enqueR(int x){

	if(f==0 && r==N-1){

		printf("\nQueue is Full");
	}
	else if(f==-1 && r==-1){
		f=r=0;
		deque[r] = x;
	}
	else if(r==N-1){
		r = 0;
		deque[r] = x;
	}
	else{
		r++;
		deque[r] = x;
	}
}

void enqueF(int x){

	if(f==0 && r==N-1){

		printf("Queue is Full");
	}
	else if(f==-1 && r==-1){
		f=r=0;
		deque[f] = x;
	}
	else if(f==0){
		f=N-1;
		deque[f] = x;
	}
	else{
		f--;
		deque[f]=x;
	}
}

void deqR(){
	
	if(f==-1 && r==-1){

		printf("\nQueue is Empty");
	}
	else if(f==r){
		f=r=-1;
	}
	else if(r==0){
		printf("Delete Element: %d",deque[r]);
		r=N-1;
	}
	else{

		printf("Delete Element: %d",deque[r]);
		r--;
	}
	printf("\n");

}

void deqF(){

	if(f==-1 && r==-1){
		printf("Queue is Empty");
	}
	else if(f==r){

		f=r=-1;
	}
	else if(f==N-1){

		printf("Delete Element: %d",deque[f]);
		f++;
	}
	else{

		printf("Delete Element: %d",deque[f]);
		f++;
	}
	printf("\n");
}
	

void display(){

	int i = f;
	while(i!=r){
		printf("%d ",deque[i]);
		i = (i+1)%N;
	}
	printf("%d ",deque[i]);
	printf("\n");
}

void main(){
	
	enqueR(10);
	enqueR(20);
	enqueF(30);
	enqueF(40);
	enqueF(77);
	display();
	deqR();
	deqF();
	display();
}
