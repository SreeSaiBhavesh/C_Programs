#include<stdio.h>
int main(){
	int n,i,count = 0,time;
	printf("Enter the number of process: ");
	scanf("%d",&n);
	int a[n], arr_ser[n][2], wait_time[n], tat[n], pri[n], temp[n];
	float wait=0, turnAround=0, avg_wait, avg_ta;
	printf("Enter arrival time, service time, and priority\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr_ser[i][0]);
		scanf("%d",&arr_ser[i][1]);
		scanf("%d",&pri[i]);
	}
	for(i=0;i<n;i++){
		temp[i] = arr_ser[i][1];
	}
	int w=n-1;
	pri[w]=999;
	for(time = 0;count!=n;time++){
		int short_p = n-1;
		
		for(i=0;i<n;i++){
			if(pri[short_p]>pri[i] && arr_ser[i][0]<=time && arr_ser[i][1]>0){
				short_p = i;
			}
		}
		arr_ser[short_p][1] = arr_ser[short_p][1] -1;
		if(arr_ser[short_p][1]==0){
			count++;
			wait_time[short_p] = time-arr_ser[short_p][0]-temp[short_p];
			tat[short_p] = time-arr_ser[short_p][0];
			wait = wait+wait_time[short_p];
			turnAround = turnAround+tat[short_p];
		}
	}
	avg_wait = wait/(float)n;
	avg_ta= turnAround/(float)n;
	printf("Average waiting time of the process is %.2f\n",avg_wait);
	printf("Average Turn around time of the process is %.2f\n",avg_ta);
	return 0;
}
