#include<stdio.h>
int dis[20][20],temp[20][20],n,i,j,k,x;


void dvr()
{
	for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
            	for (k = 0; k < n; k++)
                	if (dis[i][k] + dis[k][j] < dis[i][j])
                	{
                    	dis[i][j] = dis[i][k] + dis[k][j];
                    	temp[i][j] = k;
               		}
               		
	for(i=0;i<n;i++)
        {
            printf("\n\nState value for router %d is \n",i+1);
            for(j=0;j<n;j++)
                printf("\t\nnode %d via %d Distance%d",j+1,temp[i][j]+1,dis[i][j]);
        }   
    printf("\n\n");

}

int main()
{
    printf("\nEnter the number of nodes : ");
    scanf("%d",&n);
    printf("\nEnter the distance matrix :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {   
            scanf("%d",&dis[i][j]);
            dis[i][i]=0;
            temp[i][j]=j;
        }
        printf("\n");
	}
    dvr();
     printf("Enter the value of i & j:");
     scanf("%d",&i);
	 scanf("%d",&j);   
	 printf("Enter the New Cost: ");
	 scanf("%d",&x);   
	 dis[i][j]=x;
	 printf("After update\n\n");	 	  
     dvr();
	 return 0; 
}
