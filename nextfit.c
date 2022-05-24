#include<stdio.h>
int main(){
	int nm,n,i,j;
	printf("No of memory blocks: ");
	scanf("%d",&nm);
	int mem[nm];
	for(i=1;i<nm+1;i++){
		printf("Enter the size of the memory block %d: ",i);
		scanf("%d",&mem[i]);
	}
	printf("No of processes: ");
	scanf("%d",&n);
	int job[n];
	for(i=1;i<n+1;i++){
		printf("Enter the size of the job %d: ",i);
		scanf("%d",&job[i]);
	}
	for(i=1;i<n+1;i++){
		for(j=nm;j>=1;j--){
			if(job[i]<=mem[j]){
				printf("Job %d is allocated to memory block %d.\n",i,j);
				mem[j]-=job[i];
				break;
			}
			if(j==1){
				printf("Process %d is not allocated\n",i);
			}
		}
		
	}
	
}
