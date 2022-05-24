#include<stdio.h>
#include<string.h>
#define n 8
#define INF 999

void floydWarshall(int graph[][n]) {
  int matrix[n][n], i, j, k;

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      matrix[i][j] = graph[i][j];
  for (k = 0; k < n; k++) {
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
  }
  printMatrix(matrix);
}


void printMatrix(int matrix[][n]) {
	int i,j;
	printf("The Final graph with minimum distances: \n");
    for (i = 0; i < n; i++) {
    	for (j = 0; j < n; j++) {
        	if (matrix[i][j] == "INF")
            	printf("%4s", "INF");
      		else
        		printf("%4d", matrix[i][j]);
    	}
    	printf("\n");
  	}
}


int main(){
	int i,j;
	printf("No of vertices of the graph %d: \n",n);
	char s[100];
	char other[] = "vellore";
	printf("Enter you name: ");
	scanf("%s",s);
	if(strlen(s)<10){
		strcat(s, other);
	}
	printf("Our final word is : %s\n",s);
	printf("No of letters in our final word is equal to number of edges i.e, %d\n",strlen(s));
	int graph[n][n];
	printf("\n Remember! While entering the graph values use 999 for INF \n\n");
	printf("Enter the graph values: \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&graph[i][j]);
		}	
	}
	floydWarshall(graph);
	return 0;
}

