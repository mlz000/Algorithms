#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1005;
int a[N][N];
int main(){
	int n;
	scanf("%d",&n);
	for(int j=0;j<n;++j){
		int t=(j+j)%(n-1);
		for(int i=j;i<n;++i){
			if(i==n-1 && j!=0)	a[i][j]=t;
			else if(j==i)	a[i][j]=0;
			else a[i][j]=(i+j-1)%(n-1)+1;
			a[j][i]=a[i][j];
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j)	printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}
	
