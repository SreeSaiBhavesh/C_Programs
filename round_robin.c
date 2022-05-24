#include<stdio.h>

int main(){
	int i,j,n,x,arr_ser[n][2],sum=0,no=0,ser[n],comp_time,turn[n],wait_time[n],time,temp[n];
	float avg_wait,avg_ta,wait=0,tat=0;
	printf("Enter the number of process: ");
	scanf("%d",&n);
	if(n<=0){
		printf("Enter the validate number of processes.\n");
	}
	printf("Enter the time slice: ");
	scanf("%d",&time);
	x=n;
	
	for(i=0;i<n;i++){
		printf("Enter the arrival time %d: ",i);
		scanf("%d",&arr_ser[i][0]);
		printf("Enter the service time %d: ",i);
		scanf("%d", &arr_ser[i][1]);
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
		temp[i]=arr_ser[i][1];
	}
	
	
	for(sum=0,i=0;x!=0;){
		if(temp[i]<=time && temp[i]>0){
			sum+=temp[i];
			temp[i]=0;
			no=1;
		}
		else if(temp[i]>0){
			temp[i]-=time;
			sum+=time;
		}
		
		if(temp[i]==0 && no==1){
			x--;
			wait=wait+sum-arr_ser[i][0]-arr_ser[i][1];
			tat = tat+sum-arr_ser[i][0];
			no=0;
		}
		if(i==n-1){
			i=0;
		}
		else if(arr_ser[i+1][0]<=sum){
			i++;
		}
		else{
			i=0;
		}
	}
	avg_wait = wait/n;
	avg_ta = tat/n;
	printf("\n Average Turn Around time: %.2f",avg_wait);
	printf("\n Average Waiting time: %.2f",avg_ta);
	return 0;
	
}
