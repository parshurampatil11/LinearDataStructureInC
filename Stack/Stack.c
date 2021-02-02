#include<stdio.h>
#define N 5
int stack[N];
int top = -1;

void push(int x){

	if(top==N-1){

		printf("\nStack is OverFlow");
	}
	else{
		top++;
		stack[top] = x;
	}
}

void pop(){

	if(top==-1){

		printf("\nStack is UnderFlow");
	}
	else{
		printf("\nPop: %d ",stack[top]);
		top--;
		printf("\n");
	}
}

void display(){
	
	for(int i=top;i>=0;i--){
		
		printf("%d ",stack[i]);
	}
	printf("\n");
}

void main(){
	
	push(10);
	push(20);
	push(30);
	push(40);
	display();
	pop();
	pop();
	display();
	pop();
	push(60);
	push(70);
	display();

}
