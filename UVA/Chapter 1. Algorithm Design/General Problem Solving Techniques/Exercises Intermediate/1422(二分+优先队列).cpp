#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int N=10005;
double last;
struct data{
	double r,d,w;
	bool operator <(const data &x)	const{
		return d>x.d;
	}
}a[N];
int n;
bool cmp(const data &x,const data &y){
	return x.r<y.r||(x.r==y.r && x.d<y.d);
}
bool check(double s){
	priority_queue<data> q;
	double now=a[1].r,next;
	int i=1;
	while(1){
		for(;i<=n && a[i].r<=now;++i)	q.push(a[i]);
		next=i<=n?a[i].r:last;
		data tmp=q.top();
		q.pop();
		double finish=now+tmp.w/s;
		if(finish>tmp.d)	return false;
		if(finish>next){
			finish=next;
			tmp.w-=s*(finish-now);
			q.push(tmp);
		}
		now=finish;
		if(q.empty()){
			if(i==n+1)	return true;
			else now=next;
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		last=0.0;
		for(int i=1;i<=n;++i)	scanf("%lf%lf%lf",&a[i].r,&a[i].d,&a[i].w),last=max(last,a[i].d);
		sort(a+1,a+n+1,cmp);
		int l=1,r=20001;
		while(l<=r){
			if(l==r)	break;
			int mid=(l+r)>>1;
			if(check(mid))	r=mid;
			else l=mid+1;
		}
		printf("%d\n",r);
	}
	return 0;
}


