#include<stdio.h>
#define n 6

void lcsAlgo() {
	int m,q,S1,S2,i,j;
  m = strlen(S1);
  q = strlen(S2);

  
  for (i = 0; i <= m; i++)
    LCS_table[i][0] = 0;
  for (i = 0; i <= q; i++)
    LCS_table[0][i] = 0;


  for (i = 1; i <= m; i++)
    for (j = 1; j <= q; j++) {
      if (S1[i - 1] == S2[j - 1]) {
        LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
      } else if (LCS_table[i - 1][j] >= LCS_table[i][j - 1]) {
        LCS_table[i][j] = LCS_table[i - 1][j];
      } else {
        LCS_table[i][j] = LCS_table[i][j - 1];
      }
    }

  int index = LCS_table[m][q];
  char lcsAlgo[index + 1];
  lcsAlgo[index] = '\0';

  int i = m, j = q;
  while (i > 0 && j > 0) {
    if (S1[i - 1] == S2[j - 1]) {
      lcsAlgo[index - 1] = S1[i - 1];
      i--;
      j--;
      index--;
    }

    else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
      i--;
    else
      j--;
  }


  printf("S1 : %s \nS2 : %s \n", S1, S2);
  printf("LCS: %s", lcsAlgo);
}

int main(){
	int i,j,k,q,store[100][100];
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
    	int ran[6];
    	for(i=0;i<6;i++){
    		ran[i]=0;
		}
    	for(j=0;j<n-3;j++){
    		a=a+1;
			b=b+1;
			
    		for(k=c;k<d;k++){
    			for(q=a;q<b;q++){
    				ran[q]=mat[k][q];
				}
				printf("\n");
			}
			printf("\n");
		}
	}
	
	
	
}
