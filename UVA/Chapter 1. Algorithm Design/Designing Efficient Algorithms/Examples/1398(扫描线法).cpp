#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N=100005;
int w,h,n,T;
struct event{
	double x;int type;
	friend bool operator<(const event &p,const event & q){
		return p.x<q.x || p.x==q.x && p.type>q.type;
	}
};
void update(int x,int a,int w,double &L,double &R){
	if(a==0){
		if(x<=0 || x>=w)	R=L-1;
	}
	else if(a>0){
		L=max(L,-(double)x/a);
		R=min(R,(double)(w-x)/a);
	}
	else{
		L=max(L,(double)(w-x)/a);
		R=min(R,-(double)x/a);
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		vector<event>g;
		scanf("%d%d%d",&w,&h,&n);
		for(int i=1;i<=n;++i){
			int x,y,a,b;
			scanf("%d%d%d%d",&x,&y,&a,&b);
			double L=0.0,R=1e9;
			update(x,a,w,L,R);
			update(y,b,h,L,R);
			if(R>L){
				g.push_back((event){L,0});
				g.push_back((event){R,1});
			}
		}
		sort(g.begin(),g.end());
		int cnt=0,ans=0;
		for(int i=0;i<g.size();++i){
			if(g[i].type==0)	ans=max(ans,++cnt);
			else --cnt;
		}
		printf("%d\n",ans);
	}
	return 0;
}
