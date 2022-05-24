
#include<stdio.h>
#define N 10
/** Declaring array of size N **/
int a[N];
int min,max;
/** function to find min and max element in array **/
void findMaxMin(int a[], int start, int end){
	int MAX,MIN;
	/** when only one element in the array **/
	if(start == end){
		max = a[start];		
		min = a[start];
	}
	else{
		/** when only 2 elements in the array **/
		if(start-end == 1 || end-start==1){
			/** comparing the 2 elements **/
			
			if(a[start]>a[end]){
				max = a[start];
				min = a[end];
			}
			else{
				max = a[end];
				min = a[start];
			}
		}
		else{
			/** mid is the array mid element **/
			int mid = (start+end)/2;
			/** making large arrays divide into small parts by calling the function **/
			findMaxMin(a,start,mid);
			
			MAX = max;
			MIN = min;
			findMaxMin(a,mid+1,end);
			
			/** updating max and min **/
			if(max<MAX){
				max = MAX;
			}
			if(min>MIN){
				min = MIN;
			}
			
		}
	}
}

int main(){
	int n,i;
	printf("Enter the Number of Numbers in the array: ");
	scanf("%d",&n);
	printf("Enter the numbers: \n");
	
	/** Adding numbers to the array **/
	
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	
	/** initialising max and min element with the first element of the array **/
	max = a[0];
	min = a[0];
	findMaxMin(a,1,n);
	printf("The minimum number in the array: %d\n",min);
	printf("The maximum number in the array: %d",max);
	return 0;
}
