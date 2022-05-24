#include<stdio.h>
  
int main()
{
    
  
  int n, m, i, j, k;
  n = 4; 
  m = 3; 
  int arr[4][3] = { { 1, 0, 0 }, 
                     { 1, 1, 0 }, 
                     { 0, 1, 0}, 
                     { 0, 0, 1 }, 
                      }; 
  
  int max[4][3] = { { 0, 1, 0 }, 
                   { 0, 0, 1 },
                   { 1, 0, 0 }, 
                   { 0, 1, 0 },
                    }; 
  
  int resor[3] = { 3, 3, 2 }; // resorable Resources
  
  int f[n], ans[n], ind = 0;
  for (k = 0; k < n; k++) {
    f[k] = 0;
  }
  int need[n][m];
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++)
      need[i][j] = max[i][j] - arr[i][j];
  }
  int y = 0;
  for (k = 0; k < 4; k++) {
    for (i = 0; i < n; i++) {
      if (f[i] == 0) {
  
        int flag = 0;
        for (j = 0; j < m; j++) {
          if (need[i][j] > resor[j]){
            flag = 1;
            break;
          }
        }
  
        if (flag == 0) {
          ans[ind++] = i;
          for (y = 0; y < m; y++)
            resor[y] += arr[i][y];
          f[i] = 1;
        }
      }
    }
  }
  
  printf("SAFE Sequence is: ");
  for (i = 0; i < n - 1; i++)
    printf(" P: %d ->", ans[i]);
 printf(" P: %d",ans[n - 1]);
  
return 0;
}
