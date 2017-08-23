#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=3005;
struct data{
	int x,y,w;
}a[N];
int n,f[N],x[N],sz[N];
bool cmp(const data &p,const data &q){
	return p.w<q.w;
}
int find(int x){return f[x]==x?f[x]:find(f[x]);}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;++i)	scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w);
	sort(a+1,a+n,cmp);
	int sum=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&x[i]);
		sum+=x[i];
		f[i]=i;
		sz[i]=1;
	}
	bool flag=false;
	for(int i=1;i<n;++i){
		int fx=find(a[i].x),fy=find(a[i].y);
		f[fx]=fy,x[fy]+=x[fx],sz[fy]+=sz[fx];
		if(sz[fy]>sum-x[fy]){
			printf("%d\n",a[i].w);
			flag=true;
			break;
		}
	}
	if(!flag)	puts("0");
	return 0;
}
