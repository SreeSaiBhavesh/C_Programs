#include<stdio.h>
int main(){
	int n,i,j,sho = 0,wait_time=0;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	if(n<=0){
		printf("Enter the validate number of processes.\n");
	}
	
	int arr_ser[n][2],temp[n];
	for(i=0;i<n;i++){
		printf("\nEnter the Arrival time %d: ",i);
		scanf("%d",&arr_ser[i][0]);
		printf("Enter the services time %d: ",i);
		scanf("%d",&arr_ser[i][1]);
	}
	for(i=0;i<n;i++){
		if(arr_ser[i][0] <0){
			printf("Enter validate arrival time %d: \n",i);
			scanf("%d",&arr_ser[i][0]);
		}
		if(arr_ser[i][1]<=0){
			printf("Enter validate service time %d: \n",i);
			scanf("%d",&arr_ser[i][1]);
		}
	}
	
	int wait[n], tat[n], wait_total=0, tat_total=0;
	for(i=0;i<n;i++){
		temp[i]=arr_ser[i][1];
	}
	
	int pro_done=0, time=0, min = 1000, finish_time, check = 0;
	while(pro_done!=n){
		for(j=0;j<n;j++){
			if((arr_ser[j][0]<=time) && (temp[j]<min) && temp[j]>0){
				min = temp[j];
				sho = j;
				check = 1;
			}			
		}
		if(check == 0){
			time++;
			continue;
		}
				
		temp[sho]--;
		min = temp[sho];
		if(min==0){
			min = 1000;
		}
		if(temp[sho]==0){
			pro_done++;
			check = 0;
			finish_time = time+1;
			wait[sho] = finish_time-arr_ser[sho][1]-arr_ser[sho][0];
			if(wait[sho]<0){
				wait[sho]=0;
			}
		}
		time++;		
	}
	
	for(i=0;i<n;i++){
		tat[i]=arr_ser[i][1]+wait[i];
		wait_total = wait_total + wait[i];
		tat_total = tat_total + tat[i];
	}
	float a = wait_total / (float)n;
	float b = tat_total / (float)n;
	printf("Average Waiting time = %.2f",a);
	printf("\nAverage Turn around time = %.2f",b);
	return 0;
	
}
	




