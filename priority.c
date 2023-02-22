#include<stdio.h>
int find_min_at(int n,int arr[][7],int i,int visit[])
{
	int min=9999,flag,ct=0;
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
int find_min_priority(int n,int arr[][7],int i,int visit[],int ct)
{
	int min=9999,flag=-1;
	int j;
	for(j=1;j<=n;j++)
	{
		if((arr[j][i]<min || (arr[j][i]==min && arr[j][2]<arr[flag][2])) && visit[j]==-1 && arr[j][2]<=ct)
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
	int arr[n][7],gantt_chart[100],visit[n];
	//P	PRIORITY AT	BT	CT	TAT	WT

	for(i=1;i<=n;i++)
	{
		arr[i][0]=i;
		visit[i]=-1;
	}
	printf("enter the values: \n");
	for(i=1;i<=n;i++)
	{
		printf("enter Priority && AT && BT values: ");
		scanf("%d %d %d",&arr[i][1],&arr[i][2],&arr[i][3]);
	}
	int p=-1,l=0,k=0;
	int min=999;
	for(i=1;i<=n;i++)
	{
		if(min>arr[i][2] || (min==arr[i][2] && arr[p][1]>arr[i][1]))
		{
			min=arr[i][2];
			p=i;
		}	
	}
	ct=min;
//	printf("%d\n",ct);
	if(min!=0)
	{
//		printf("%d\n",p);
		gantt_chart[l]=-1;
		l++;
		gantt_chart[l]=p;
		printf("%d\n",gantt_chart[l]);
		l++;
		visit[p]=1;
		arr[p][4]=ct+arr[p][3];
		ct=arr[p][4];
		k++;
	}
	else
	{
		gantt_chart[l]=p;
		l++;
		k++;
		visit[p]=1;
		arr[p][4]=arr[p][3];
		ct=arr[p][4];
	}
	while(k!=n)
	{
		p=find_min_priority(n,arr,1,visit,ct);
		if(p==-1)
		{
			gantt_chart[l]=-1;
			l++;
			p=find_min_at(n,arr,2,visit);
			ct=arr[p][2];
			p=find_min_priority(n,arr,1,visit,ct);
		}
		visit[p]=1;
		k++;
		gantt_chart[l]=p;
		l++;
		arr[p][4]=ct+arr[p][3];
		ct=arr[p][4];
	}
	printf("Gantt_Chart is: ");
	for(i=0;i<l;i++)
	{
		if(gantt_chart[i]==-1)
		{
			printf("idle ");
		}
		else
		{
			printf("p%d ",gantt_chart[i]);
		}
	}
	float sum_wt=0,sum_tat=0;
	for(i=1;i<=n;i++)
	{
		arr[i][5]=arr[i][4]-arr[i][2];
		arr[i][6]=arr[i][5]-arr[i][3];
		sum_wt+=arr[i][6];
		sum_tat+=arr[i][5];
		
	}
	printf("\n");
	printf("P\tPrior\tAT\tBT\tCT\tTAT\tWT\n");
	for(i=1;i<=n;i++)
	{
		printf("p%d	",i);
		for(j=1;j<7;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	
	printf("\naverage waiting time: %f",sum_wt/n);
	printf("\naverage Turn around time: %f",sum_tat/n);
}

//0 2 7 1 4 3 3 7 5 2 5 1 4 6 9
