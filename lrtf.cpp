#include<stdio.h>

int find_index(int at[],int bt[],int visit[],int time,int n)
{
	int min=0,index=-1;
	for(int i=0;i<n;i++)
	{
		if(bt[i]>min &&at[i]<=time && visit[i]==0 )
		{
			min=bt[i];
			index=i;
		}
	}
	if(index!=-1)
	{
		return index;
	}
	else
	{   int minarrival=1000;
		for(int i=0;i<n;i++)
		{
			if(at[i]<minarrival && at[i]>time && visit[i]==0)
			{ minarrival=at[i];
			  index=i;
			}
		}
		
		return index;
	}
	
}
bool completed(int bt[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(bt[i]!=0)
		   return false;
	}
	return true;
}
int sjf(int at[],int bt[],int ct[],int n)
{   int visit[n];
    for(int i=0;i<n;i++)
    {
    	visit[i]=0;
	}
	int time=0;
	int a;
	while(!completed( bt,n))
	{ a=find_index(at,bt,visit,time,n);
	  visit[a]=1;
	  if(at[a]>time)
	  {
	  	printf(" %d idle %d ",time,at[a]);
	  	time=at[a];
	  }
	  printf(" %d P:%d  %d ",time,a+1,time+1);
	  time=time+1;
	  bt[a]--;
	  if(bt[a]==0)
	  {ct[a]=time;
      }
      else
      {
      	visit[a]=0;
	  }
	}
}



int main()
{
	int n;
	printf("enter no of process");
	scanf("%d",&n);
	int at[n],bt[n],ct[n],att[n],btt[n];
	printf("enter at bt ");
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&at[i],&bt[i]);
		att[i]=at[i];
		btt[i]=bt[i];
	}
	sjf(att,btt,ct,n);
	int total_turnaround_time=0;
	int tat[n];
	for(int i=0;i<n;i++)
	{
		tat[i]=ct[i]-at[i];
		total_turnaround_time+=tat[i];
	}
	int total_waiting_time=0;
	int wt[n];
	for(int i=0;i<n;i++)
	{
		wt[i]=tat[i]-bt[i];
		total_waiting_time+=wt[i];
	}
	
	printf("the chart after \n");
	printf("process 	   	 at		 bt		 ct		 tat		wt \n");
	for(int i=0;i<n;i++)
	{
	  printf("process  :%d		 %d		 %d		 %d		 %d		 %d \n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);	
	}
	
	printf("total turn around time is %d  and avg turnaround time is %f  \n\n\n ",total_turnaround_time,float(total_turnaround_time)/float(n));
	printf("total waiting time is %d  and avg waiting time is %f \n",total_waiting_time,float(total_waiting_time)/float(n));

	
}
