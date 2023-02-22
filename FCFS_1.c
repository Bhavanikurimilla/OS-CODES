#include<stdio.h>
int find_min(int n,int arr[][6],int i,int visit[])
{
	int min=9999,flag;
	int j;
	for(j=1;j<=n;j++)
	{
		if(arr[j][1]<min && visit[j]==-1)
		{
			min=arr[j][i];
			flag=j;
		}
	}
	return flag;
}
int main()
{
	int n,i,ct=0,j;
	printf("enter the number of procesors: ");
	scanf("%d",&n);
	int arr[n][6],gantt_chart[100],visit[n];
	//P	AT	BT	CT	TAT	WT

	for(i=1;i<=n;i++)
	{
		arr[i][0]=i;
		visit[i]=-1;
	}
	printf("enter the values: \n");
	for(i=1;i<=n;i++)
	{
		printf("enter AT && BT values: ");
		scanf("%d %d",&arr[i][1],&arr[i][2]);
	}
	int p=-1,l=0,k=0;
	for(i=1;i<=n;i++)
	{
		if(arr[i][1]==0)
		{
			p=i;
			break;
		}
	}
	if(p==-1)
	{
		gantt_chart[l]=-1;
		l++;
		p=find_min(n,arr,1,visit);
		gantt_chart[l]=p;
		l++;
		visit[p]=1;
		arr[p][3]=arr[p][1]+arr[p][2];
		ct=arr[p][3];
		k++;
	}
	else
	{
		gantt_chart[l]=p;
		l++;
		k++;
		visit[p]=1;
		arr[p][3]=arr[p][2];
		ct=arr[p][3];
	}
	while(1)
	{
		p=find_min(n,arr,1,visit);
		if(arr[p][1]>ct)
		{
			gantt_chart[l]=-1;
			l++;
			ct=arr[p][1];
		}
		visit[p]=1;
		k++;
		gantt_chart[l]=p;
		l++;
		arr[p][3]=ct+arr[p][2];
		ct=arr[p][3];
		if(k==n)
		{
			break;
		}
	}
	int sum_wt=0,sum_tat=0;
	for(i=1;i<=n;i++)
	{
		arr[i][4]=arr[i][3]-arr[i][1];
		arr[i][5]=arr[i][4]-arr[i][2];
		sum_wt+=arr[i][5];
		sum_tat+=arr[i][4];
	}
	printf("Gantt_Chart is: ");
	for(i=0;i<l;i++)
	{
		if(gantt_chart[i]==-1)
		{
			printf("idle ");
		}
		else
			printf("p%d ",gantt_chart[i]);
	}
	printf("\n");
	printf("P\tAT\tBT\tCT\tTAT\tWT\n");
	for(i=1;i<=n;i++)
	{
		printf("p%d	",i);
		for(j=1;j<6;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	
	printf("\naverage waiting time: %d\n",sum_wt/n);
	printf("average Turn around time: %d",sum_tat/n);
}
