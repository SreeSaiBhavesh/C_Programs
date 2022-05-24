#include<stdio.h>
int matrix[20];
int i,j,np,nr;
int main(){
	
	

	int alloc[10][10],request[10][10],avail[10],size_res[10],w[10],mark[20];
	
	printf("\nEnter the no of process: ");
	scanf("%d",&np);
	printf("\nEnter the no of resources: ");
	scanf("%d",&nr);
	for(i=0;i<nr;i++)
	{
		printf("\nTotal Amount of the Resource R%d: ",i+1);
		scanf("%d",&size_res[i]);
	}
	
	
	
	
	printf("\nEnter the request matrix:");
	
	for(i=0;i<np;i++)
		for(j=0;j<nr;j++)
			scanf("%d",&request[i][j]);
	
	printf("\nEnter the allocation matrix:");
	for(i=0;i<np;i++)
		for(j=0;j<nr;j++)
			scanf("%d",&alloc[i][j]);
	/*Available Resource calculation*/
	for(j=0;j<nr;j++)
	{
		avail[j]=size_res[j];
		for(i=0;i<np;i++)
		{
			avail[j]-=alloc[i][j];
	
		}
	}
	
	//marking processes with zero allocation
	
	for(i=0;i<np;i++)
	{
		int count=0;
	 	for(j=0;j<nr;j++)
	   	{
			if(alloc[i][j]==0)
	        	count++;
	      	else
	        	break;
	    }
	 	if(count==nr)
	 		mark[i]=1;
	 	else{
	 		mark[i]=0;
		 }
	}
	// initialize W with avail
	
	for(j=0;j<nr;j++)
	    w[j]=avail[j];
	
	//mark processes with request less than or equal to W
	for(i=0;i<np;i++)
	{
		int proceed=0;
	 	if(mark[i]!=1)
		{
	   		for(j=0;j<nr;j++)
	    	{
	      		if(request[i][j]<=w[j]){
	        		proceed=1;
	        	}
	      		else
	         	{
	         		proceed=0;
	         		break;
	          	}
	     	}
			if(proceed==1)
			{
				mark[i]=1;
	
				for(j=0;j<nr;j++)
					w[j]+=alloc[i][j];
			}
		}
	}
	
	//checking for unmarked processes
	int deadlock=0;
	for(i=0;i<np;i++)
		if(mark[i]!=1)
			deadlock=1;
		else{
			deadlock=0;
			break;
		}
	
	
	if(deadlock==1)
		printf("\n Deadlock detected");
	else
		printf("\n No Deadlock possible");


	
}


