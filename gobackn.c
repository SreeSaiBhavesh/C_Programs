#include<stdio.h>
int main()
{
	int ws,sent=0,ack,i;
	printf("enter window size\n");
	scanf("%d",&ws);
	while(1)
	{
		for( i = 0; i < ws; i++)
			{
				printf("Frame %d has been transmitted.\n",sent);
				sent++;
				if(sent == ws)
					break;
			}
			printf("\nPlease enter the last Acknowledgement received.\n");
			scanf("%d",&ack);
			
			if(ack == ws)
				break;
			else
				sent = ack;
	}
return 0;
}
