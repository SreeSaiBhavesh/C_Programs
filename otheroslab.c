#include<stdio.h>
int main(){
	int i,j,n,m,pos,count=0,number=0,addup=0,pagefault=0;
	printf("Size of the memory: ");
	scanf("%d",&n);
	printf("\nNo of page requests: ");
	scanf("%d",&m);
	int memory[n], input[m];
	printf("Entering the page requests: \n");
	for(i=0;i<m;i++){
		scanf("%d",&input[i]);
	}
	printf("Enter the memory values: ");
	for(i=0;i<n;i++){
		scanf("%d",&memory[i]);
	}
	
	for(i=0;i<m;i++){
		//if(memory[0] == input[i] && memory[1]==input[i+1] && memory[2]==input[i+2]){
			for(j=i;j<m;j++){
				if(input[j]==memory[0]){
					count+=1;
				}
				else if(input[j]==memory[1]){
					number+=1;
				}
				else if(input[j]==memory[2]){
					addup+=1;
				}
			}
			if(count<number){
				if(count<addup){
					memory[0]=input[i+3];
					pagefault+=1;
				
				}
				else{
					if(memory[0]<memory[2]){
						memory[0]=input[i+3];
						pagefault+=1;
					
					}
					memory[2]=input[i+3];
					pagefault+=1;
				
				}
			}
			else if(number<addup){
				if(memory[1]<memory[0]){
					memory[1]=input[i+3];
					pagefault+=1;
		
				}
				else{
					memory[0]=input[i+3];
					pagefault+=1;
		
				}
			}
		//}
	}
	
	printf("No of Page faults: %d",pagefault-1);
}
