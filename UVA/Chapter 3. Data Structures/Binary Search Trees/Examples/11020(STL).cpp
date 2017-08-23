#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
struct Point{
	int x,y;
	friend bool operator<(const Point &p,const Point &q){
		return p.x<q.x || (p.x==q.x && p.y<q.y);
	}
};
multiset<Point>S;
multiset<Point>::iterator it;
int main(){
	int T;
	scanf("%d",&T);
	for(int tt=1;tt<=T;++tt){
		if(tt>1)	printf("\n");
		printf("Case #%d:\n",tt);
		int n,x,y;
		S.clear();
		scanf("%d",&n);
		while(n--){
			scanf("%d%d",&x,&y);
			Point p=(Point){x,y};
			it=S.lower_bound(p);
			if(it==S.begin() || (--it)->y>y){
				S.insert(p);
				it=S.upper_bound(p);
				while(it!=S.end() && it->y>=y)	S.erase(it++);
			}
			printf("%d\n",S.size());
		}
	}
	return 0;
}
