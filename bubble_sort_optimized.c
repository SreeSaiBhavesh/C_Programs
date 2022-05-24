#include<stdio.h>
void bubbleSort(int arr[], int n){
	int i,j;
	for(i=0;i<n-1;i++){
		int flag=0;
		for(j=0;j<n-1-i;j++){
			if(arr[j]>arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				flag=1;
			}
		}
		if(flag==0){
			break;
		}
	}
}

int main(){
	int i,n;
	printf("Enter the number of the elements: ");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	bubbleSort(arr,n);
	printf("Sorted array: \n");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
