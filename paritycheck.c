#include<stdio.h>
#define bool int

bool getParity(unsigned int n)
{
	bool parity = 0;
	while(n)
	{
		parity = !parity;
		n = n & (n-1);
	}
	
	return parity;
}
int main()
{
	unsigned int n;
	printf("Enter any integer: ");
	scanf("%d", &n);
	printf("Parity of no ");
	printf("%d", n);
	printf(" = ");
	printf(getParity(n)? "odd": "even");
	
	getchar();
	return 0;
}
