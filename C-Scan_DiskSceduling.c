#include<stdio.h>
#include<stdlib.h>
int sort(int arr[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
			{
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
int main()
{
	int n,i;
	printf("enter the number of requests: ");
	scanf("%d",&n);
	int request[n+2];
	printf("enter the requests: ");
	for(i=1;i<n+1;i++)
	{
		scanf("%d",&request[i]);
	}
	request[0]=0;
	int m;
	printf("enter the position of readwrite track: ");
	scanf("%d",&m);
	int t;
	printf("enter the total number of tracks: ");
	scanf("%d",&t);
	request[n+1]=t-1;
	sort(request,n+2);;
	int index;
	for(i=0;i<n+2;i++)
	{
		if(request[i]>m)
		{
			break;
		}
	}
	index=i;
	printf("enter the direction(R/L): ");
	char c[1];
	scanf("%s",c);
	printf("%d-->",m);
	for(i=index;i<n+2;i++)
	{
		printf("%d-->",request[i]);
	}
	for(i=0;i<index;i++)
	{
		printf("%d-->",request[i]);
	}
	int thm=0;
	thm+=abs(request[index]-m);
	for(i=index+1;i<n+2;i++)
	{
		thm+=abs(request[i]-request[i-1]);
	}
	thm+=abs(request[i-1]-0);
	for(i=0;i<index-1;i++)
	{
		thm+=abs(request[i]-request[i+1]);
	}
	printf("\nTotal head moments: %d",thm);
	
}
//98 183 41 122 14 124 65 67
