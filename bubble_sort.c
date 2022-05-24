#include <stdio.h>
void bubbleSort(int arr[], int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1;j++){
			if(arr[j]>arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main(){
	int i,n,arr[n];
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	bubbleSort(arr,n);
	printf("Sorted array: \n");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
