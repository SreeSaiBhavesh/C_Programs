#include<stdio.h>

int req[100][100];
int alloc[100][100];
int need[100][100];
int avail[100];
int n,r;
void input();

void cal();
int main()
{
    int i,j;
    printf("Deadlock Detection Algorithm\n");
    input();
    cal();

    return 0;
}
void input()
{
    int i,j;
    printf("Enter the no of Processes ");
    scanf("%d",&n);
    printf("Enter the no of resource instances ");
    scanf("%d",&r);
    printf("Enter the Request Matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<r;j++)
        {
            scanf("%d",&req[i][j]);
        }
    }
    printf("Enter the Allocation Matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<r;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("Enter the available Resources\n");
    for(j=0;j<r;j++)
    {
        scanf("%d",&avail[j]);
    }
}

void cal()
{
    int done[100],temp,need[100][100],flag=1,k,c1=0;
    int dead[100];
    int safe[100];
    int i,j;
    for(i=0;i<n;i++)
    {
    	done[i]=0;
    }
               
    for(i=0;i<n;i++)
    {
        for(j=0;j<r;j++)
        {
            need[i][j]=req[i][j]-alloc[i][j];
        }
    }
    while(flag)
    {
        flag=0;
        for(i=0;i<n;i++)
    	{
            int c=0;
            for(j=0;j<r;j++)
            {
                if((done[i]==0)&&(need[i][j]<=avail[j]))
                {
                    c++;
                    if(c==r)
            		{
                        for(k=0;k<r;k++)
                        {
                            avail[k]+=alloc[i][j];
                            done[i]=1;
                            flag=1;
                        }
                                       
                        if(done[i]==1)
                        {
                            i=n;
                        }
            		}
                }
            }
        }
    }
	j=0;
    flag=0;
    for(i=0;i<n;i++)
    {
        if(done[i]==0)
        {
            dead[j]=i;
            j++;
            flag=1;
        }
    }
    if(flag==1)
    {
        printf("\n\nSystem is in Deadlock and the Deadlock process are\n");
        for(i=0;i<n;i++)
    	{
            printf("P%d\t",dead[i]);
        }
    }
    else
    {
        printf("\nNo Deadlock Occur");
    }  
}
