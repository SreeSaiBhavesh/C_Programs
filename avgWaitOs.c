#include<stdio.h>
int main(){
	int i;
	int no_pg,burst=0;
	float total=0,avg_wait, avg_ta;
	int comp_time,arr_time[no_pg],ser_time[no_pg],turnard_time[no_pg],wait_time[no_pg];
	printf("Enter the numbr of processes\n");
	scanf("%d",&no_pg);
	for(i=0;i<no_pg;i++){
		printf("Arrival Times %d\n",i);
		scanf("%d",&arr_time[i]);
		printf("service Time %d\n",i);
		scanf("%d",&ser_time[i]);
	}
	
	for(i=0;i<no_pg;i++){
		if(i==0){
			wait_time[i]=arr_time[i];
		}
		else{
			wait_time[i]=burst-arr_time[i];
		}
		burst+=ser_time[i];
		total+=wait_time[i];
	}
	
	avg_wait=total/no_pg;

	comp_time=0;
	int tot =0;
	for(i=0;i<no_pg;i++){
		comp_time+=ser_time[i];
		turnard_time[i]=comp_time-arr_time[i];
		tot+=turnard_time[i];
	}
	avg_ta = tot/no_pg;
	printf("The Average wait time is: %.2f",avg_wait);
	printf("The Average turn around time is: %.2f",avg_ta);
	return 0;
}

