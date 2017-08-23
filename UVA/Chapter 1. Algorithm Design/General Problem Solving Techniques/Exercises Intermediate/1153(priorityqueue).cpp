#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int N=800005;
struct data{
	int q,d;
	friend bool operator<(const data &a,const data &b){
		return a.q<b.q;
	}
}a[N];
bool cmp(const data &a,const data &b){
	return a.d<b.d;
}
int T,n,tmp,ans;
int main(){
	scanf("%d",&T);
	while(T--){
		tmp=ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)	scanf("%d%d",&a[i].q,&a[i].d);
		sort(a+1,a+n+1,cmp);
		priority_queue<data> Q;
		for(int i=1;i<=n;++i){
			tmp+=a[i].q;
			Q.push(a[i]);
			++ans;
			if(tmp>a[i].d){
				data t=Q.top();
				Q.pop();
				--ans;
		 		tmp-=t.q;
			}
		}
		printf("%d\n",ans);
		if(T)	printf("\n");
	}
	return 0;
}
