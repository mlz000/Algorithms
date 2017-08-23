#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=100005;
int n,m,a[N],c[N],num[N],ans[N];
struct data{
	int l,r,id;
}q[N];
bool operator <(const data &x,const data &y){
	return x.l<y.l;
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
	int T;
	scanf("%d",&T);
	while(T--){
		memset(c,0,sizeof(c));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)	scanf("%d",&a[i]),num[a[i]]=i;
		num[0]=num[n+1]=N;
		for(int i=1;i<=n;++i){
			if(i<num[a[i]-1] && i<num[a[i]+1])	add(i,1);
			else if(i>num[a[i]-1] && i>num[a[i]+1])	add(i,-1);
		}
		for(int i=1;i<=m;++i)	scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
		sort(q+1,q+m+1);
		for(int i=1,j=1;j<=m;++j){
			while(i<=n && i<q[j].l){
				if(i<num[a[i]-1] && i<num[a[i]+1]){
					add(i,-1);
					add(num[a[i]-1],1);
					add(num[a[i]+1],1);
				}
				else if(i>num[a[i]-1] && i>num[a[i]+1])	add(i,-1);
				else if(i<num[a[i]-1])	add(i,-1),add(num[a[i]-1],1);
				else add(i,-1),add(num[a[i]+1],1);
				++i;
			}
			ans[q[j].id]=get(q[j].r);
		}
		for(int i=1;i<=m;++i)	printf("%d\n",ans[i]);
	}
	return 0;
}
