#include<stdio.h>
#include<string.h>
int main(){
	int c, p;
	printf("Enter the size of the text: ");
	scanf("%d",&c);
	printf("Enter the size of the pattern: ");
	scanf("%d",&p);
	char character[c], pattern[p], array[c];
	printf("Enter the character: ");
	scanf("%s",character);
	printf("Enter the Pattern: ");
	scanf("%s",pattern);
	int i,charIndex,prime = 5,h=1;
	for(i=0;i<p-1;i++){
		h = (h*p)%prime;
	}
	int pathash=0,strhash=0,index=-1;
	for(i=0;i<p;i++){
		pathash = (p*pathash+pattern[i])%prime;
		strhash = (p*strhash+character[i])%prime;
	}
	
	for(i=0;i<=c-p;i++){
		if(pathash == strhash){
			for(charIndex=0;charIndex<p;charIndex++){
				if(character[i+charIndex]!=pattern[charIndex])
					break;
			}
			if(charIndex == p){
				index++;
				array[index]=i;
			}
		}
		if(i<c-p){
			strhash = (p*(strhash - character[i]*h)+character[i+p])%prime;
			if(strhash<0){
				strhash+=prime;
			}
		}
	}
	for(i=0;i<=index;i++){
		printf("Pattern found at position : %d \n",array[i]);
	}
}
