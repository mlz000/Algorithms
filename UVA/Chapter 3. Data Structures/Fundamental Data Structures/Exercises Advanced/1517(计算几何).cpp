#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
using namespace std;
struct point{
	int x,y;
	point(int p=0,int q=0):x(p),y(q) {}
};
struct Line{
	point x,y;
	Line(point _x=point(),point _y=point()):x(_x),y(_y) {}
};
int sgn(int x){
	if(x==0)	return 0;
	return x<0?-1:1;
}
int operator *(point p,point q){
	return p.x*q.x+p.y*q.y;
}
int operator ^(point p,point q){
	return p.x*q.y-p.y*q.x;
}
point operator -(point p,point q){
	return point(p.x-q.x,p.y-q.y);
}
bool operator< (point p, point q){ 
	return p.x!=q.x ? p.x<q.x : p.y<q.y; 
}
bool inter(point a1,point a2,point b1,point b2){
	if(((a2-a1).x==0 && (a2-a1).y==0) || ((b2-b1).x==0 && (b2-b1).y==0))	return false;
	int c1=(a2-a1)^(b1-a1),c2=(a2-a1)^(b2-a1),c3=(b2-b1)^(a1-b1),c4=(b2-b1)^(a2-b1);
	if(((a2-a1)^(b2-b1))!=0)	return (sgn(c1)*sgn(c2)<=0 && sgn(c3)*sgn(c4)<=0);
	if(((a2-a1)^(b1-a1))!=0)	return false;
	int p1=a1*(a2-a1);
	int p2=a2*(a2-a1);
	if(p1>p2)	swap(p1,p2);
	int q1=b1*(a2-a1);
	int q2=b2*(a2-a1);
	if(q1>q2)	swap(q1,q2);
	if(p1==q1)	return true;
	if(p1>q1){
		swap(p1,q1);
		swap(p2,q2);
	}
	return p2>=q1;
}
int main(){
	int T,s,r,w,p;
	scanf("%d",&T);
	while(T--){
		point a;
		Line b;
		set<point> S;
		vector<Line> V;
		scanf("%d%d%d%d",&s,&r,&w,&p);
		for(int i=1;i<=s;++i){
			scanf("%d%d",&a.x,&a.y);
			S.insert(a);
		}
		for(int i=1;i<=w;++i){
			scanf("%d%d%d%d",&b.x.x,&b.x.y,&b.y.x,&b.y.y);
			V.push_back(b);
		}
		while(p--){
			point t;
			vector<point> ans;
			scanf("%d%d",&a.x,&a.y);
			for(t.x=a.x-r;t.x<=a.x+r;++t.x)
				for(t.y=a.y-r;t.y<=a.y+r;++t.y){
					double d=sqrt((t-a)*(t-a));
					if(d<=r && S.count(t)){
						for(int i=0;i<V.size();++i)
							if(inter(t,a,V[i].x,V[i].y))
								d++;
						if(d<=r)	ans.push_back(t);
					}
				}
			printf("%d",ans.size());
			for(int i=0;i<ans.size();++i)	printf(" (%d,%d)",ans[i].x,ans[i].y);
			printf("\n");
		}
	}
	return 0;
}


