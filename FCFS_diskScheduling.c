#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i;
	printf("enter the number of requests: ");
	scanf("%d",&n);
	int request[n];
	printf("enter the requests: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&request[i]);
	}
	int m;
	printf("enter the position of readwrite track: ");
	scanf("%d",&m);
	printf("%d-->",m);
	for(i=0;i<n;i++)
	{
		printf("%d-->",request[i]);
	}
	int THM=0;
	THM=THM+abs(request[0]-m);
	for(i=1;i<n;i++)
	{
		THM+=abs(request[i]-request[i-1]);
	}
	printf("\n\nTotal head moments: %d",THM);
	
}
