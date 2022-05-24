#include<stdio.h>
#include<string.h>
int main(){
	int c, p;
	printf("Enter the size of the text: ");
	scanf("%d",&c);
	printf("Enter the size of the pattern: ");
	scanf("%d",&p);
	char character[c], pattern[p];
	printf("Enter the character: ");
	scanf("%s",character);
	printf("Enter the Pattern: ");
	scanf("%s",pattern);

	int i,j,count=0;
	for(i=0;i<=c-p;i++){
		if(character[i]==pattern[0]){
			count++;
		}
	}
	if(count==0){
		printf("No pattern found in text.\n");
	}
	else{
		for(i=0;i<=c-p;i++){
			for(j=1;j<p;j++){
				if(character[i+j]!=pattern[j])
					break;
			}
			if(j==p){
				printf("Pattern matches at index %d \n",i);
			}
		}
	}
	
	return 0;
}

