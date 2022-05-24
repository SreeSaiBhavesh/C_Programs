#include<stdio.h>
void FIFO(int temp[], int referenceString[] ,int nf, int n){
	int m, j,pageFaults=0;
	for(m = 0; m < n; m++)
      {
            int s = 0;
            for(j = 0; j< nf; j++)
            {
                  if(referenceString[m] == temp[j])
                  {
                        s++;
                        pageFaults--;
                  }
            }     
            pageFaults++;
            if((pageFaults <= nf) && (s == 0))
            {
                  temp[m] = referenceString[m];
            }   
            else if(s == 0)
            {
                  temp[(pageFaults - 1) % nf] = referenceString[m];
            }
            printf("\n");
            for(j = 0; j < nf; j++)
            {     
                  printf("%d\t", temp[j]);
            }
      } 
      printf("\nTotal Page Faults for FIFO:\t%d\n", pageFaults);
}
int findLRU(int time[], int n){
int i, minimum = time[0], pos = 0;
for(i = 1; i < n; ++i){
if(time[i] < minimum){
minimum = time[i];
pos = i;
}
}
return pos;
}

int main()
{
    int temp[10], flag1, flag2, flag3,pos, counter=0, time[10];
    int nf, n, i,j,k, faults = 0, pageFaults = 0;
    
    printf("Enter number of frames: ");
    scanf("%d", &nf);
    
    printf("Enter number of pages: ");
    scanf("%d", &n);
    int pages[n], frames[nf];
    printf("Enter page reference string: ");
    
    for(i = 0; i < n; ++i){
        scanf("%d", &pages[i]);
    }
    
    for(i = 0; i < nf; ++i){
        frames[i] = -1;
    }
    
    FIFO(frames, pages, nf, n);
    for(i = 0; i < nf; ++i){
        frames[i] = -1;
    }
    
    int other[10], max;
	
	for(i = 0; i < n; ++i){
        flag1 = flag2 = 0;
        
        for(j = 0; j < nf; ++j){
            if(frames[j] == pages[i]){
                   flag1 = flag2 = 1;
                   break;
               }
        }
        if(flag1 == 0){
            for(j = 0; j < nf; ++j){
                if(frames[j] == -1){
                    faults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }    
        }
        if(flag2 == 0){
         flag3 =0;
        
            for(j = 0; j < nf; ++j){
             other[j] = -1;
            
             for(k = i + 1; k < n; ++k){
             if(frames[j] == pages[k]){
             other[j] = k;
             break;
             }
             }
            }
            
            for(j = 0; j < nf; ++j){
             if(other[j] == -1){
             pos = j;
             flag3 = 1;
             break;
             }
            }
            if(flag3 ==0){
             max = other[0];
             pos = 0;
            
             for(j = 1; j < nf; ++j){
             if(other[j] > max){
             max = other[j];
             pos = j;
             }
             }            
            }
frames[pos] = pages[i];
faults++;
        }
        printf("\n");
        
        for(j = 0; j < nf; ++j){
            printf("%d\t", frames[j]);
        }
    }
    
    printf("\n\nTotal Page Faults for Optimal= %d", faults);
    int error = 0;
    for(i = 0; i < nf; ++i){
        frames[i] = -1;
    }
	for(i = 0; i < n; ++i){
     flag1 = flag2 = 0;
    
     for(j = 0; j < nf; ++j){
     if(frames[j] == pages[i]){
     counter++;
     time[j] = counter;
   flag1 = flag2 = 1;
   break;
   }
     }
    
     if(flag1 == 0){
for(j = 0; j < nf; ++j){
     if(frames[j] == -1){
     counter++;
     error++;
     frames[j] = pages[i];
     time[j] = counter;
     flag2 = 1;
     break;
     }
     }
     }
    
     if(flag2 == 0){
     pos = findLRU(time, nf);
     counter++;
     error++;
     frames[pos] = pages[i];
     time[pos] = counter;
     }
     printf("\n");
    
     for(j = 0; j < nf; ++j){
     printf("%d\t", frames[j]);
     }
}
printf("\n\nTotal Page Faults for LRU= %d", error);
    return 0;
}
   
