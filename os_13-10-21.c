#include<stdio.h>
int main(){
	int np,i, pd[20],sum=0,check;
	printf("No of processes: ");
	scanf("%d",&np);
	for(i=0;i<np;i++){	
		printf("Peak demand of the process %d: ",i);
		scanf("%d",&pd[i]);
		sum+=pd[i];
	}
	printf("Value to check whether deadlock occur or not: ");
	scanf("%d",&check);
	if(check>=sum){
		printf("Deadlock will not occur.\n");
	}
	else{
		printf("Deadlock occurs.\n");
	}
}
