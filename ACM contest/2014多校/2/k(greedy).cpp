#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=1e5+5;
struct data{
	int x,y;
}a[N];
bool cmp(const data &p,const data &q){
	return p.x*q.y<q.x*p.y;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)	scanf("%d",&a[i].x);
	for(int i=1;i<=n;++i)	scanf("%d",&a[i].y);
	sort(a+1,a+n+1,cmp);
	long long ans=0ll;
	long long tot=0ll;
	for(int i=1;i<=n;++i){
		ans+=(tot+a[i].x)*a[i].y;
		tot+=a[i].x;
	}
	printf("%I64d\n",ans);
	return 0;
}
