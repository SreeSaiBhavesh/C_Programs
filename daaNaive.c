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
n
	int i,j;
	for(i=0;i<=c-p;i++){
		for(j=0;j<p;j++){
			if(character[i+j]!=pattern[j])
				break;
		}
		if(j==p){
			printf("Pattern matches at index %d \n",i);
		}
	}
	return 0;
}



