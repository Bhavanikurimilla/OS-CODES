#include<stdio.h>
int n,r,l=0;
int allocation[100][100],max[100][100],need[100][100],available[100];
int check2(int i,int request[],int req_arr[][r])
{
	int j,flag=1;
	for(j=1;j<=r;j++)
	{
		if(req_arr[i][j]>need[request[i]][j])
		{
			flag=0;
			break;
		}
	}
	return flag;
}
int check(int i,int n,int r,int work[])
{
	int j,flag=-1;
	for(j=1;j<=r;j++)
	{
		if(work[j]<need[i][j])
		{
			flag=1;
			break;
		}
	}
	return flag;
}
int printing(int sequence[],int k)
{
	int i;
	for(i=1;i<k;i++)
	{
		printf("p%d\t",sequence[i]);
	}
	printf("\n");
}
int Safety_sequence(int sequence[],int finish[],int work[],int k)
{
	int i,j;
	if(k>l+n)
	{
		printing(sequence,k);
		return;
	}
	for(i=1;i<=n;i++)
	{
		int p;
		p=check(i,n,r,work);
		if(p==-1 && finish[i]==-1)
		{
			sequence[k]=i;
			finish[i]=1;
			for(j=1;j<=r;j++)
			{
				work[j]=work[j]+allocation[i][j];
			}
			Safety_sequence(sequence,finish,work,k+1);
			for(j=1;j<=r;j++)
			{
				work[j]=work[j]-allocation[i][j];
			}	
			finish[i]=-1;
		}
	}
	
}
int main()
{
	int i,j;
	printf("enter the number of process: ");
	scanf("%d",&n);
	printf("enter the number of resorces: ");
	scanf("%d",&r);
	int finish[n],work[r],sequence[100];
	printf("enter the allocation matrix: \n");
	for(i=1;i<=n;i++)
	{
		finish[i]=-1;
		printf("process-%d Allocation: ",i);
		for(j=1;j<=r;j++)
		{
			scanf("%d",&allocation[i][j]);
		}
	}
	printf("enter the max need of process: \n");
	for(i=1;i<=n;i++)
	{
		printf("process-%d max need: ",i);
		for(j=1;j<=r;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=r;j++)
		{
			need[i][j]=max[i][j]-allocation[i][j];
		}
	}
	printf("enter the available instances: ");
	int k=1;
	for(i=1;i<=r;i++)
	{
		scanf("%d",&available[i]);
		work[i]=available[i];
	}
	printf("enter number of the requesting process: ");
	int c;
	scanf("%d",&c);
	int request[c],req_arr[c][r];
	printf("enter the requesting processes: ");
	for(i=1;i<=c;i++){
		scanf("%d",&request[i]);
	}
	printf("enter the process request instances: ");
	for(i=1;i<=c;i++)
	{
		printf("request of process %d:",request[i]);
		for(j=1;j<=r;j++)
		{
			scanf("%d",&req_arr[i][j]);
		}
	}
	//resource request process alogorithem;
	for(i=1;i<=c;i++)
	{
		if(check2(i,request,req_arr) && check(i,n,r,work))
		{
			sequence[k]=request[i];
			k++;
			for(j=1;j<=r;j++)
			{
				available[j]-=req_arr[i][j];
				allocation[request[i]][j]+=req_arr[i][j];
				need[request[i]][j]-=req_arr[i][j];
			}
			for(j=1;j<=r;j++)
			{
				if(need[request[i]][j]!=0)
				{
					break;
				}
			}
			if(j>r)
			{
				int t=1;
				for(t=1;t<=r;t++)
				{
					available[t]+=allocation[request[i]][t];
				}
				finish[request[i]]=1;
				l++;
			}
		}
	}
	//here starts logic
	printf("The possibe safety sequences: \n\n");
	Safety_sequence(sequence,finish,work,k);
}
