#include <stdio.h>

int main(){
	int n;
	printf("Enter the number of the elements in the array: ");
	scanf("%d",&n);
	int arr[n],i,j,temp;
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1;j++){
			if(arr[j]>arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	printf("Sorted array is: ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
