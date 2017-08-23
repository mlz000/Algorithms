#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=100005;
struct data{
	int l,r,h,id;
}a[N],q[N];
int n,m,c[N],ans[N];
bool operator <(const data &x,const data &y){
	return x.h<y.h;
}
void add(int x,int y){
	for(;x<=n;x+=x&-x)	c[x]+=y;
}
int get(int x){
	int tmp=0;
	for(;x;x-=x&-x)	tmp+=c[x];
	return tmp;
}
int main(){
	int tt,T;
	scanf("%d",&T);
	for(int tt=1;tt<=T;++tt){
		memset(c,0,sizeof(c));
		printf("Case %d:\n",tt);
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)	scanf("%d",&a[i].h),a[i].id=i;
		for(int i=1;i<=m;++i)	scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].h),q[i].id=i;
		sort(a+1,a+n+1),sort(q+1,q+m+1);
		for(int i=1,j=1;j<=m;++j){
			while(i<=n && a[i].h<=q[j].h){
				add(a[i].id,1);
				++i;
			}
			ans[q[j].id]=get(q[j].r+1)-get(q[j].l);
		}
		for(int i=1;i<=m;++i)	printf("%d\n",ans[i]);
	}
	return 0;
}
