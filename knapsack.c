#include <stdio.h>
 
int main(){
	int n,i,wt;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	int weight[n], value[n];
	printf("Enter the knapsack capacity: ");
	scanf("%d",&wt);
	for(i=0;i<n;i++){
		scanf("%d",&weight[i]);
		scanf("%d",&value[i]);
	}
	printf("Max Value in 0/1knapsack: %d",knapsack(wt,weight,value,n));
	return 0;
}

int max(int a, int b){
	return (a>b)?a:b;
}

int knapsack(int wt, int weight[], int value[], int n){
	if(n==0||wt==0){
		return 0;
	}
	else if(weight[n-1]>wt){
		return knapsack(wt,weight,value,n-1);
	}
	else{
		return max(value[n-1]+knapsack(wt - weight[n-1],weight,value,n-1), knapsack(wt,weight,value,n-1));
	}
}
