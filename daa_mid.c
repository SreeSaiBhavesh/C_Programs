#include<stdio.h>
int main(){
	int n=6,i,j,k;
	int arr[n][n];
	printf("Enter the values of the matrix: ");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	 
	for(i=0;i<n;i++){
		int high_row = 0;
		for(j=0;j<n;j++){
			if(arr[i][j]>high_row){
				high_row = arr[i][j];
			}
		}
		printf("Highest number in %d row is: %d\n",i,high_row);
	}
	for(i=0;i<n;i++){
		int high_col = 0;
		for(j=0;j<n;j++){
			if(arr[j][i]>high_col){
				high_col = arr[i][j];
			}
		}
		printf("Highest number in %d column is: %d\n",i,high_col);
	}
	
	printf ("After arranging the columns in ascending order \n");
 
	for (j=0;j<n;++j) {
 
		for (i=0;i<n;++i) {
 
			for (k=i+1;k<n;++k) {
 
				if (arr[i][j] > arr[k][j]) {
					int a;
 
					a = arr[i][j];
 
					arr[i][j] = arr[k][j];
 
					arr[k][j] = a;
 
				}
 
			}
 
		}
 
	}
 
 
	for (i=0;i<n;++i) {
 
		for (j=0;j<n;++j) {
 
			printf (" %d",arr[i][j]);
 
		}
 
		printf ("\n");
 
	}
	
	printf ("After arranging the columns in descending order \n");
 
	for (j=0;j<n;++j) {
 
		for (i=0;i<n;++i) {
 
			for (k=i+1;k<n;++k) {
 
				if (arr[i][j] < arr[k][j]) {
					int a;
 
					a = arr[i][j];
 
					arr[i][j] = arr[k][j];
 
					arr[k][j] = a;
 
				}
 
			}
 
		}
 
	}
 
	for (i=0;i<n;++i) {
 
		for (j=0;j<n;++j) {
 
			printf (" %d",arr[i][j]);
 
		}
 
		printf ("\n");
 
	}
 
	
	return 0;
	
}
