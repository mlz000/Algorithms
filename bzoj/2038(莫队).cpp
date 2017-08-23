#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=50005;
struct P{
	int l,r,p;
}c[N];
int unit,n,m,a[N];
long long cnt[N];
pair<long long,long long>ans[N];
inline int from(P a)	{return (a.l-1)/unit+1;}
bool cmp(const P &a,const P &b){
	if(from(a)==from(b))	return a.r<b.r;
	return from(a)<from(b);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)	scanf("%d",&a[i]);
	for(int i=1;i<=m;++i)	scanf("%d%d",&c[i].l,&c[i].r),c[i].p=i;
	unit=sqrt(n);
	sort(c+1,c+m+1,cmp);
	long long t=0ll;
	int L=1,R=0;
	for(int i=1;i<=m;++i){
		while(R<c[i].r){
			++R;
			t-=cnt[a[R]]*(cnt[a[R]]-1);
			cnt[a[R]]++;
			t+=cnt[a[R]]*(cnt[a[R]]-1);
		}
		while(R>c[i].r){
			t-=cnt[a[R]]*(cnt[a[R]]-1);
			cnt[a[R]]--;
			t+=cnt[a[R]]*(cnt[a[R]]-1);
			--R;
		}
		while(L<c[i].l){
			t-=cnt[a[L]]*(cnt[a[L]]-1);
			cnt[a[L]]--;
			t+=cnt[a[L]]*(cnt[a[L]]-1);
			++L;
		}
		while(L>c[i].l){
			--L;
			t-=cnt[a[L]]*(cnt[a[L]]-1);
			cnt[a[L]]++;
			t+=cnt[a[L]]*(cnt[a[L]]-1);
		}
		if(t==0)	ans[c[i].p].first=0;
		else{
			long long t2=__gcd(t,(long long)(c[i].r-c[i].l+1)*(c[i].r-c[i].l));
			ans[c[i].p].first=t/t2;
			ans[c[i].p].second=(long long)(c[i].r-c[i].l+1)*(c[i].r-c[i].l)/t2;
		}
	}
	for(int i=1;i<=m;++i){
		if(!ans[i].first)	printf("0/1\n");
		else printf("%lld/%lld\n",ans[i].first,ans[i].second);
	}
	return 0;
}
