#include<stdio.h>
#include<math.h>
int n,a[100],G[100],S[100],v[100],in,end,s=0,st,h=0,k=0,sm=0,gr=0,minv;
int i,j;
void check();
void sort();
int main(){	
	printf("enter number of tracks");
	scanf("%d",&n);
printf("starting track position");
	scanf("%d",&in);
	printf("ending track position");
	scanf("%d",&end);
	while(s<n){
		printf("enter %d track",s+1);
		scanf("%d",&a[s]);
		if(a[s]>in&&a[s]<end){
			s++;
		}
		
	}
	printf("head track");
	scanf("%d",&st);
	minv=st;
	for( i=0;i<n;i++){
		v[i]=0;
	}
	sort();
	check();
}
void sort(){
	int temp;
	for(i=0;i<n;i++){
		for( j=0;j<n-1-i;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
    }
		printf("after sorting :");
		for( i=0;i<n;i++){
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
	for( i=0;i<gr;i++){
		printf("%d ",G[i]);
	}
	printf("%d ",end);
	for( i=sm-1;i>=0;i--){
		printf("%d ",S[i]);
	}
	for( i=0;i<gr;i++){
		h=h+abs(minv-G[i]);
		minv=G[i];
	}
	h=h+abs(minv-end);
	minv=end;
	for( i=sm-1;i>=0;i--){
		h=h+(minv-S[i]);
		minv=S[i];
	}

	printf("\nnumber of heads moments:  ");
	printf("%d ",h);
}
/*9
1
100
45
20
90
10
50
60
80
25
70
head track:50
op:140
ex2:
8
0
200
30
85
90
100
105
110
135
145
head track:100
op:270
ex3:
8
0
199
98
183
41
122
14
124
65
67
head track:53
op:331

*/
	
