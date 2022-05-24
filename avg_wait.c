#include<stdio.h>
int main(){
	int i,j,n,burst=0;
	float total=0,avg_wait,avg_ta;
	printf("Enter the number of process: ");
	scanf("%d",&n);
	int arr_ser[n][2],comp_time,turnard_time[n],wait_time[n];
	for(i=0;i<n;i++){
		printf("Enter the arrival time %d: ",i);
		scanf("%d",&arr_ser[i][0]);
		printf("Enter the service time %d: ",i);
		scanf("%d", &arr_ser[i][1]);
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(arr_ser[i][0]>arr_ser[j][0]){
				int temp = arr_ser[i][0];
				int some = arr_ser[i][1];
				arr_ser[i][0]=arr_ser[j][0];
				arr_ser[i][1]=arr_ser[j][1];
				arr_ser[j][0]= temp;
				arr_ser[j][1]= some;
			}
		}
	}
		
	
	for(i=0;i<n;i++){
		if(i==0){
			wait_time[i]=arr_ser[i][0];
		}
		else{
			wait_time[i]=burst-arr_ser[i][0];
		}
		burst+=arr_ser[i][1];
		total+=wait_time[i];
	}
	
	avg_wait=total/n;

	comp_time=0;
	float tot =0;
	for(i=0;i<n;i++){
		comp_time+=arr_ser[i][1];
		turnard_time[i]=comp_time-arr_ser[i][0];
		tot+=turnard_time[i];
	}
	avg_ta = tot/n;
	printf("The Average wait time is: %.2f",avg_wait);
	printf("The Average turn around time is: %.2f",avg_ta);
	return 0;
}
