#include<stdio.h>
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
	printf("Max value of 0/1knapsack: %d",knapsack(wt,weight,value,n));
	return 0;
	
}

int max(int a, int b){
	return (a>b)? a:b;
}

int knapsack(int wt, int weight[], int value[], int n){
	int i,q;
	int a[n+1][wt+1];
	for(i=0;i<=n;i++){
		for(q=0;q<=wt;q++){
			if(i==0||q==0){
				a[i][q]=0;
			}
			else if(weight[i-1]<=q){
				a[i][q] = max(value[i-1]+a[i-1][q-weight[i-1]],a[i-1][q]);
			}
			else{
				a[i][q] = a[i-1][q];
			}
		}
	}
	return a[n][wt];
}
