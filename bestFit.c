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
	int job[n],allocated[n];
	for(i=1;i<n+1;i++){
		printf("Enter the size of the job %d: ",i);
		scanf("%d",&job[i]);
	}
	
	
	for(i=1;i<n+1;i++){
		int index = -1;
		for(j=1;j<nm+1;j++){
			if(job[i]<=mem[j]){
				if(index==-1){
					index = j;
				}
				else if(mem[j]<mem[index]){
					index = j;
				}
			}
		}
		if(index!=-1){
			printf("Job %d is allocated to memory block %d\n",i,index);
			mem[index]-=job[i];
		}
		else{
			printf("Process not allocated it needs to wait.\n");
		}
	}
}
