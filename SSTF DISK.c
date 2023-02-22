#include<stdio.h>
#include<math.h>
int n,a[100],b[100],c[100],v[100],in,end,s=0,st,h=0,k=0,minv;
void check();
void check2();
int main(){	
	//printf("enter number of tracks");
	scanf("%d",&n);
//	printf("starting track position");
	scanf("%d",&in);
	//printf("ending track position");
	scanf("%d",&end);
	while(s<n){
		//printf("enter %d track",s+1);
		scanf("%d",&a[s]);
		if(a[s]>in&&a[s]<end){
			s++;
		}
		
	}
	printf("head track");
	scanf("%d",&st);
	minv=st;
	for(int i=0;i<n;i++){
		v[i]=0;
	}
	check2();
	check();
}
void check2(){
printf("\n");
	for(int i=0;i<n;i++){
		if(v[i]==0){
		b[i]=abs(st-a[i]);
		printf("%d ",b[i]);
	}
	}
}
void check(){
	int i,min;
	while(k<n){
		min=10000;
    	for(i=0;i<n;i++){
		if(b[i]<=min&&v[i]==0){
			min=b[i];
			//minv=b[i];
			c[k]=i;
		}
	}
//	printf("%d",c[k]);
	//min=a[c[k]];
	v[c[k]]=1;
	st=a[c[k]];
	k++;
	check2();
}
	for(i=0;i<n;i++){
		printf("%d ",c[i]);
	}
	printf("\n%d",min);
	printf("order of sequence :");
	printf("%d ",minv);
	for(int i=0;i<n;i++){
		printf("%d ",a[c[i]]);
	}
	for(int i=0;i<n;i++){
		h=h+abs(minv-a[c[i]]);
		minv=a[c[i]];
	}

	printf("\nnumber of heads moments:  ");
	printf("%d ",h);
}
/*
8
0
199
176 79 34 60 92 11  41 114
head track50
op:204
*/
	
