#include<stdio.h>
int n,r;
int allocation[100][100],max[100][100],need[100][100],available[100];
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
int printing(int sequence[])
{
	int i;
	for(i=1;i<=n;i++)
	{
		printf("p%d\t",sequence[i]);
	}
	printf("\n");
}
int Safety_sequence(int sequence[],int finish[],int work[],int k)
{
	int i,j;
	if(k>n)
	{
		printing(sequence);
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
	int finish[n],work[r],sequence[n];
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
	//here starts logic
	printf("These are the possible sequences: \n\n");
	Safety_sequence(sequence,finish,work,k);
}
