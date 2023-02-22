#include<stdio.h>
int pagefound(int page,int frames[],int l)
{
	int i;
	for(i=0;i<l;i++)
	{
		if(frames[i]==page)
		{
			return 1;
		}
	}
	return  0;
}
void print(int l,int frames[])
{
	int i;
	for(i=0;i<l;i++)
	{
		printf("%d  ",frames[i]);
	}
}
int check(int i,int pages[],int frame,int n)
{
	int j;
	for(j=i;j<=n;j++)
	{
		if(pages[j]==frame)
		{
			return j;
		}
	}
	return 999;
}
int main()
{
	int n;
	printf("enter the number of pages: ");
	scanf("%d",&n);
	int pages[n];
	printf("enter the pages: \n");
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&pages[i]);
	}
	printf("enter the number of frames: ");
	int f;
	scanf("%d",&f);
	int frames[f];
	int empty=f;
	int hit=0,fault=0;
	int l=0;
	printf("\n\n");
	for(i=1;i<=n;i++)
	{
		printf("%d  Frames: ",pages[i]);
		if(empty!=0)
		{
			if(pagefound(pages[i],frames,l)==0)
			{
				frames[l]=pages[i];
				fault++;
				l++;
				empty--;
			}
			else
			{
				hit++;
			}
		}
		else{
			
			if(pagefound(pages[i],frames,l)==0)
			{
				int visit[f],j;
				for(j=0;j<f;j++)
				{
					visit[j]=check(i+1,pages,frames[j],n);
				}
				int max=visit[0],q=0;
				for(j=1;j<f;j++)
				{
					if(max<visit[j])
					{
						max=visit[j];
						q=j;
					}
				}
				frames[q]=pages[i];
				fault++;
			}
			else
			{
				hit++;
			}
		}
		print(l,frames);
		printf("\n");
	}
	printf("\n\n");
	printf("hit==%d\nfault==%d",hit,fault);
	printf("\n");
	printf("Hit Ratio==%f\nMiss Ratio==%f",(float)hit/n,(float)fault/n);
}
//3 2 1 3 4 1 6 2 4 3 4 2 1 4 5 2 1 3 4
//7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
//4 7 6 1 7 6 1 2 7 2
