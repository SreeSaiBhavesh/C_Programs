#include<stdio.h>
#include <stdlib.h>
#include<string.h>


void classfull(char ip_address[]){
	int bit[4];
	int i = 0;
    char *num = strtok(ip_address, ".");
    while (num != NULL)
    {
    	bit[i]=atoi(num); 
        num = strtok(NULL, ".");
        i++;
    }  
	int x = bit[0];   
    
    if (x >=1 && x <= 126){
		printf("\nClass : A");
		printf("\nNetwork ID : %d.0.0.0",bit[0]);
		printf("\nHost ID : 0.%d.%d.%d",bit[1],bit[2],bit[3]);
		printf("\nRange : 1.0.0.1 to 126.255.255.254");
	}
    
    else if (x >= 128 && x <= 191){
		printf("\nClass : B");
		printf("\nNetwork ID : %d.%d.0.0",bit[0],bit[1]);
		printf("\nHost ID : 0.0.%d.%d",bit[2],bit[3]);
		printf("\nRange : 128.0.0.1 to 191.255.255.254");
	}
    else if (x >= 192 && x <= 223){
    	printf("\nClass : C");
		printf("\nNetwork ID : %d.%d.%d.0",bit[0],bit[1],bit[2]);
		printf("\nHost ID : 0.0.0.%d",bit[3]);
		printf("\nRange : 192.0.0.1 to 223.255.255.254");
	}
    
    else if (x >= 224 && x <= 239){
    	printf("\nClass : D");
    	printf("\nIn class D, IP Address is not divided into Network and Host ID");
	}
    else{
    	printf("\nClass : E");
    	printf("\nIn class E, IP Address is not divided into Network and Host ID");
	}
        
}


void classless(char ip_address[]){
	int bit[4];
	int i = 0;
    char *num = strtok(ip_address, ".");
    while (num != NULL)
    {
    	bit[i]=atoi(num); 
        num = strtok(NULL, ".");
        i++;
    } 
    int a=3;
	
	
    int bin;
    if(a==1)
		bin = 128;
    else if(a==2)
		bin = 192;
	else if(a==3)
		bin = 224;
	else if(a==4)
		bin = 240;
	else if(a==5)
		bin = 248;
	else if(a==6)
		bin = 252;
	else if(a==7)
		bin = 254;
	else
		bin = 255;
		
    int FA = bit[3] & bin;
    printf("\nFirst Address: %d.%d.%d.%d",bit[0],bit[1],bit[2],FA);
    printf("\nLast Address: %d.%d.%d.%d",bit[0],bit[1],bit[2],FA+31);
}

int main(){
	
	char ip_address[20];
	
	printf("Enter IP Address : ");
	scanf("%s",&ip_address);
	
	
	if(ip_address[strlen(ip_address)-3] == '/'){
		printf("Classless addressing");
		classless(ip_address);
	}
	else{
		printf("Classfull addressing");
		classfull(ip_address);
	}
	
}
