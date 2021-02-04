#include<stdio.h>
#define N 50

int arr[N];
int  flag = 0;
void createArray(){

	int n;

	printf("\nEnter Number of Element want to insert: ");
	scanf("%d",&n);
	printf("\nEnter Element: ");
	for(int i=0;i<n;i++){

		scanf("%d",&arr[i]);
		flag++;
	}
}

void displayArray(){

	printf("\nArray: ");
	for(int i=0;i<flag;i++){

		printf("%d ",arr[i]);
	}
	printf("\n");

}

void linearSearch(){
	int n,ele,cnt=0;

	printf("\nEnter Number to Be Search: ");
	scanf("%d",&n);

	for(int i=0;i<flag;i++){

		if(arr[i]==n){
			ele = i;	
			cnt = 1;
		}
	}
	if(cnt==1){
		printf("\nElement Found At: %d",ele);
	}
	else{
		printf("\nElement Not Found");
	}
}

void main(){

	int ch,n;
	do{

		printf("\n1.Create Array");
		printf("\n2.Display Array");
		printf("\n3.Search Array Element");
		printf("\nEnter Your Choice: ");
		scanf("%d",&n);
		switch(n){

			case 1:
				createArray();
				break;

			case 2:
				displayArray();
				break;
			case 3:
				linearSearch();
				break;
			default:
				printf("\nWrong Choice.");
		}

		printf("\nDo you Want Continue(0/1)?: ");
		scanf("%d",&ch);

	}while(ch==1);
}


