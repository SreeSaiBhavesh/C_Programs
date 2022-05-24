#include<stdio.h>

 
// function that calculates
// the minimum no. of resources
int Resources(int process, int need)
{
    int minResources = 0;
 
    // Condition so that deadlock
    // will not occur
    minResources = process * (need - 1) + 1;
 
    return minResources;
}
 
// Driver code
int main()
{
    int process = 3, need[]= {3,4,6};
 
    int sum= Resources(process, need[0])+ Resources(process, need[1])+ Resources(process,need[2]);
    printf("R >=",sum/3);
    return 0;
}
