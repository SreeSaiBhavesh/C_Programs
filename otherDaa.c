#include<stdio.h>


int main(){
	int n=6,m=3,i,j,k;
	int arr1[n][n], arr2[n][n], arr3[n][n];
	printf("Enter the values of the matrix1: ");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&arr1[i][j]);
		}
	}
	
	printf("Enter the values of the matrix2: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&arr2[i][j]);
		}
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			arr3[i][j] = arr1[i][j];
		}
		for(j=m;j<n;j++){
			arr3[i][j] = arr2[j-3][i];
		}
	}
	printf("Resultant matrix: ");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",arr3[i][j]);
		}
		printf("\n");
	}
	
	
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1;j++){
			printf("%d  %d\n",arr3[i][j], arr3[i][j+1]);
			printf("%d  %d\n",arr3[i+1][j], arr3[i+1][j+1]);
			printf("\n");
			
		}
	}
	
}
