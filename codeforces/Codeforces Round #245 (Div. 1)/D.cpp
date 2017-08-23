#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
long long ans=1e12;
struct data{
	long long x,y;
}a[N],b[N];
bool cmpx(const data &p,const data &q){
	return (p.x<q.x)||(p.x==q.x && p.y<q.y);
}
bool cmpy(const data &p,const data &q){
	return p.y<q.y;
}
void update(data p,data q){
	ans=min(ans,(p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y));
}
void work(int l,int r){
	if(r-l<4){
		for(int i=l;i<=r;++i)
			for(int j=i+1;j<=r;++j)
				update(a[i],a[j]);
		sort(a+l,a+r+1,cmpy);
		return ;
	}
	int mid=(l+r)>>1;
	int midx=a[mid].x;
	work(l,mid),work(mid+1,r);
	merge(a+l,a+mid+1,a+mid+1,a+r+1,b,cmpy);
	copy(b,b+r-l+1,a+l);
	int tot=0;
	for(int i=l;i<=r;++i)
		if((a[i].x-midx)*(a[i].x-midx)<=ans){
			for(int j=tot-1;j>=0 && (a[i].y-b[j].y)*(a[i].y-b[j].y)<=ans;--j)
				update(a[i],b[j]);
			b[tot++]=a[i];
		}
}
int main(){
	int n;
	scanf("%d",&n);
	long long sum=0;
	for(int i=0,x;i<n;++i){
		scanf("%d",&x);
		sum+=x;
		a[i].x=i,a[i].y=sum;
	}
	sort(a,a+n,cmpx);
	work(0,n-1);
	printf("%I64d\n",ans);
	return 0;
}
