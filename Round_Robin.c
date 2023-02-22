 #include<stdio.h>
int queue[100];
int st=-1,end=-1;
int e=0;
int find_min(int n,int arr[][6],int i,int vis[])
{
	int min=9999,flag;
	int j;
	for(j=1;j<=n;j++)
	{
		if(arr[j][1]<min && vis[j]==-1)
		{
			min=arr[j][1];
			flag=j;
		}
	}
	return flag;
}
int find_min1(int n,int arr[][6],int visit[],int ct)
{
	int i,min=9999,flag=-1;
	for(i=1;i<=n;i++)
	{
		if(arr[i][1]<min && arr[i][1]<=ct && visit[i]==-1)
		{
			min=arr[i][1];
			flag=i;
		}
	}
	return flag;
}
int find_process(int n,int arr[][6],int visit[],int ct)
{
	int p=find_min1(n,arr,visit,ct);
	while(p!=-1)
	{
		enque(p);
		visit[p]=1;
		e++;
		p=find_min1(n,arr,visit,ct);
	}
}
int enque(int p)
{
	if(st==-1)
	{
		st=0;
		end=0;
		queue[end]=p;
	}
	else{
		end++;
		queue[end]=p;
	}
}
int deque()
{
	if(st==-1)
	{
		return -1;
	}
	if(st==end)
	{
		int r=queue[st];
		st=-1;
		end=-1;
		return r;
	}
	else{
		int r=queue[st];
		st++;
		return  r;
	}
}
int main()
{
	int n,i,ct=0,j,TQ;
	printf("enter the number of procesors: ");
	scanf("%d",&n);
	int arr[n][6],gantt_chart[100],visit[n],vis[n];
	int bt[n];
	printf("enter the time quantum value: ");
	scanf("%d",&TQ);
	//P	AT	BT	CT	TAT	WT

	for(i=1;i<=n;i++)
	{
		arr[i][0]=i;
		visit[i]=-1;
		vis[i]=-1;
	}
	printf("enter the values: \n");
	for(i=1;i<=n;i++)
	{
		printf("enter AT && BT values: ");
		scanf("%d %d",&arr[i][1],&arr[i][2]);
		bt[i]=arr[i][2];
	}
	int p=-1,l=0,k=0;
	int min=999;
	for(i=1;i<=n;i++)
	{
		if(min>arr[i][1])
		{
			min=arr[i][1];
		}
	}
	ct=0;
	if(min!=0)
	{
		ct=min;
		gantt_chart[l]=-1;
		l++;
	}
	find_process(n,arr,visit,ct);
	p=deque();
	gantt_chart[l]=p;
	l++;
	if(arr[p][2]>TQ)
	{
		arr[p][2]=(arr[p][2]-TQ);
		ct=ct+TQ;
	}
	else{
		ct=ct+arr[p][2];
		arr[p][3]=ct;
		arr[p][2]=0;
		vis[p]=1;
		k++;
	}
	while(k!=n)
	{
		if(e!=n)
		{
			find_process(n,arr,visit,ct);
			if(arr[p][2]!=0)
			{
				enque(p);
			}
		}
		p=deque();
		if(p==-1)
		{
			gantt_chart[l]=-1;
			l++;
			p=find_min(n,arr,1,vis);
			ct=arr[p][1];
			find_process(n,arr,visit,ct);
			p=deque();
		}
		if(gantt_chart[l-1]!=p)
		{
			gantt_chart[l]=p;
			l++;
		}
		if(arr[p][2]>TQ)
		{
			arr[p][2]=arr[p][2]-TQ;
			ct=ct+TQ;
			if(e==n)
			{
				enque(p);
			}
		}
		else{
			ct=ct+arr[p][2];
			arr[p][3]=ct;
			arr[p][2]=0;
			vis[p]=1;
			k++;
		}
	}
	float sum_wt=0,sum_tat=0;
	for(i=1;i<=n;i++)
	{
		arr[i][4]=arr[i][3]-arr[i][1];
		arr[i][5]=arr[i][4]-bt[i];
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
		arr[i][2]=bt[i];
		for(j=1;j<6;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	
	printf("\naverage waiting time: %.2f",sum_wt/n);
	printf("\naverage turn around time : %.2f",sum_tat/n);
	
}
