#include<stdio.h>
#define n 6
int main(){
	int i,j,k,q;
	char mat[n][n],store[100][100];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("Enter the matrix[%d][%d]: ",i,j);
			scanf("%s",&mat[i][j]);
		}
	}
	
    int c=-1,d=3;
    for(i=0;i<n-3;i++){
    	c=c+1;
    	d=d+1;
    	int a=-1,b=3;
    	for(j=0;j<n-3;j++){
    		a=a+1;
			b=b+1;
			
    		for(k=c;k<d;k++){
    			for(q=a;q<b;q++){
    			
    				printf("%c ",mat[k][q]);
				}
				printf("\n");
			}
			printf("\n");
		}
	}
	
}

