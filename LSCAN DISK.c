#include<stdio.h>
#include<math.h>
int n,a[100],G[100],S[100],v[100],in,end,s=0,st,h=0,k=0,sm=0,gr=0,minv;
void check();
void sort();
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
	sort();
	check();
}
void sort(){
	int temp;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1-i;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
    }
		printf("after sorting :");
		for(int i=0;i<n;i++){
			printf("%d ",a[i]);
		}
}
void check(){
	int i;
	for(i=0;i<n;i++){
		if(a[i]>st){
			G[gr]=a[i];
			gr++;
		}
		else{
			S[sm]=a[i];
			sm++;
		}
	}
	printf("\nGreater array :");
	for(i=0;i<gr;i++){
		printf("%d ",G[i]);
	}
	printf("\n");
	printf("Smaller array :");
	for(i=sm-1;i>=0;i--){
		printf("%d ",S[i]);
	}
	printf("\n");
	printf("order of sequence :");
	printf("%d ",minv);
	for( i=sm-1;i>=0;i--){
		printf("%d ",S[i]);
	}
	printf("%d ",in);
	for(int i=0;i<gr;i++){
		printf("%d ",G[i]);
	}
	for( i=sm-1;i>=0;i--){
		h=h+(minv-S[i]);
		minv=S[i];
	}
	h=h+abs(minv-in);
	minv=in;
	for( i=0;i<gr;i++){
		h=h+abs(minv-G[i]);
		minv=G[i];
}

	printf("\nnumber of heads moments:  ");
	printf("%d ",h);
}
/*
ex:
8
0
199
176 79 34 60 92 11 114 41
head track:50
op:226
ex4:
8
0
199
98 137 122 183 14 133 65 78
head track:54
op:237

*/
	
