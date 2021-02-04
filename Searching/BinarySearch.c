#include<stdio.h>
#define N 5
int arr[N];
int flag = 0;

void createArray(){

	int n;

	printf("\nEnter Number of Array Element want to Insert: ");
	scanf("%d",&n);
	
	printf("\nEnter Array: ");
	for(int i=0;i<n;i++){

		scanf("%d",&arr[i]);
		flag++;
	}
}

void displayArray(){
	
	printf("\nArray Is: ");
	for(int i=0;i<flag;i++){

		printf("%d ",arr[i]);
	}
}

int binarySearch(int data){
	
	int l = 0,r = flag-1,mid;
	while(l<=r){
		
		mid = (l+r)/2;

		if(data==arr[mid]){
			return mid;
		}
		else if(data<arr[mid]){
			r = mid-1;
		}
		else{
			l = mid+1;
		}
	}
	return -1;
}

void main(){

	int n,ch,ele,data;

	do{	
		printf("\n1.Create Array");
		printf("\n2.Display Array");
		printf("\n3.Binary Search Array Element");
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
				printf("Enter Element To be Search: ");
				scanf("%d",&data);
				ele = binarySearch(data);
				printf("Element At: %d",ele);
				break;
			default:
				printf("\nWrong Choice.");
		}
		printf("\nDo you Want Continue(0/1)?: ");
		scanf("%d",&ch);
	}while(ch==1);
}
