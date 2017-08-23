#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int N=100005;
int n,q,L,R,d[N][20],a[N],num[N],l[N],r[N];
vector<int> v;
void init(){
	v.clear();
	for(int i=1;i<=n;++i)	scanf("%d",&a[i]);
	a[n+1]=a[n]+1;
	int st=1;
	for(int i=1;i<=n+1;++i){
		if(a[i]>a[st]){
			v.push_back(i-1);
			for(int j=st;j<i;++j){
				num[j]=v.size();
				l[num[j]]=st;
				r[num[j]]=i-1;
			}
			st=i;
		}
	}
	n=v.size();
	for(int i=1;i<=n;++i)	d[i][0]=r[i]-l[i]+1;
	for(int j=1;(1<<j)<=n;++j)
		for(int i=1;i+(1<<j)-1<=n;++i)
			d[i][j]=max(d[i][j-1],d[i+(1<<(j-1))][j-1]);
}
int ask(int L,int R){
	int k=0;
	while((1<<(k+1))<=R-L+1)	k++;
	return max(d[L][k],d[R-(1<<k)+1][k]);
}
void solve(int L,int R){
	if(num[L]==num[R])	{printf("%d\n",R-L+1);return;}
	int ans=max(r[num[L]]-L+1,R-l[num[R]]+1);
	if(num[R]-num[L]>=2)	ans=max(ans,ask(num[L]+1,num[R]-1));
	printf("%d\n",ans);
}
int main(){
	while(scanf("%d%d",&n,&q)&&n){
		init();
		while(q--){
			scanf("%d%d",&L,&R);
			solve(L,R);
		}
	}
	return 0;
}
