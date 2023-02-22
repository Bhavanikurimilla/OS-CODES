#include<stdio.h>
int find_min_at(int n,int arr[][7],int i,int visit[])
{
	int min=9999,flag,ct=0;
	int j;
	for(j=1;j<=n;j++)
	{
		if((min>arr[i][2] || (min==arr[i][2] && (arr[flag][1]>arr[i][1] ||(arr[flag][1]==arr[i][1] && arr[flag][3]>arr[i][3])))) && visit[j]==-1)
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
		if((arr[j][i]<min || (arr[j][i]==min && (arr[j][3]<arr[flag][3] || (arr[j][3]==arr[flag][3] && arr[j][2]<arr[flag][2])))) && visit[j]==-1 && arr[j][2]<=ct)
		{
			min=arr[j][i];
			flag=j;
		}
	}
	if(flag==-1)
	{
		return -1;
	}
	else
	{
		return flag;
	}
		
}
int main()
{
	int n,i,ct=0,j;
	printf("enter the number of procesors: ");
	scanf("%d",&n);
	int arr[n][7],gantt_chart[100],visit[n];
	int bt[n];
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
		arr[i][4]=0;
		bt[i]=arr[i][3];
	}
	int p=-1,l=0,k=0;
	int min=999;
	for(i=1;i<=n;i++)
	{
		if(min>arr[i][2] || (min==arr[i][2] && (arr[p][1]>arr[i][1] ||(arr[p][1]==arr[i][1] && arr[p][3]>arr[i][3]))))
		{
			min=arr[i][2];
			p=i;
		}	
	}
	ct=0;
	if(min!=0)
	{
		ct=min;
		gantt_chart[l]=-1;
		l++;
		gantt_chart[l]=p;
		l++;
		ct++;
		arr[p][3]--;
		arr[p][4]=ct;
	}
	else
	{
		gantt_chart[l]=p;
		l++;
		arr[p][3]--;
		ct++;
		arr[p][4]=ct;
	}
	if(arr[p][3]==0)
	{
		k++;
		visit[p]=1;
	}
//		printf("%d\n",ct);
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
		arr[p][3]--;
		if(gantt_chart[l-1]==p)
		{
			ct++;
			arr[p][4]=ct;
		}
		else
		{
			gantt_chart[l]=p;
			l++;
			ct++;
			arr[p][4]=ct;
			
		}
		if(arr[p][3]==0)
		{
			visit[p]=1;
			k++;
		}
	}
	float sum_wt=0,sum_tat=0;
	for(i=1;i<=n;i++)
	{
		arr[i][5]=arr[i][4]-arr[i][2];
		arr[i][6]=arr[i][5]-bt[i];
		sum_wt+=arr[i][6];
		sum_tat+=arr[i][5];
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
	printf("P\tPrior\tAT\tBT\tCT\tTAT\tWT\n");
	for(i=1;i<=n;i++)
	{
		printf("p%d	",i);
		arr[i][3]=bt[i];
		for(j=1;j<7;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\nThe avearge waiting time is: %.2f",sum_wt/n);
	printf("\nThe turn around time: %.2f",sum_tat/n);
}
