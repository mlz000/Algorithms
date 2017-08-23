#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int N=755;
int n,a[N][N];
struct data{
	int s,b;
	data(int ss, int bb):s(ss), b(bb){}  
	friend bool operator<(const data &p,const data &q){
		return p.s>q.s;
	}
};
void merge(int *A,int *B,int k){
	priority_queue<data> PQ;
	for(int i=0;i<k;++i)	PQ.push(data(A[i]+B[0],0));
	for(int i=0;i<n;++i){
		data tmp=PQ.top();
		PQ.pop();
		A[i]=tmp.s;
		int b=tmp.b;
		if(b+1<k)	PQ.push(data(tmp.s-B[b]+B[b+1],b+1));
	}
}	
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j)	scanf("%d",&a[i][j]);
			sort(a[i],a[i]+n);
		}
		for(int i=1;i<n;++i)	merge(a[0],a[i],n);
 		for(int i=0;i<n-1;++i)    printf("%d ",a[0][i]);
        printf("%d\n",a[0][n-1]); 
	}
	return 0;
}
