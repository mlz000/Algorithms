#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;
const int N=100005;
struct data{
	int x,y;
}a[N],b[N];
bool cmp(const data &p,const data &q){
	return p.x>q.x||(p.x==q.x && p.y>q.y);
}
map<int,int>mp;
int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;++i)	scanf("%d%d",&a[i].x,&a[i].y);
		for(int i=1;i<=m;++i)	scanf("%d%d",&b[i].x,&b[i].y);
		sort(a+1,a+n+1,cmp),sort(b+1,b+m+1,cmp);
		mp.clear();
		int j=1;
		int ans1=0;
		long long ans2=0;
		for(int i=1;i<=m;++i){
			while(j<=n && a[j].x>=b[i].x){
				mp[a[j].y]++;
				++j;
			}
			map<int,int>::iterator it=mp.lower_bound(b[i].y);
			if(it!=mp.end()){
				++ans1;
				ans2+=b[i].x*500+b[i].y*2;
				mp[it->first]--;
				if(mp[it->first]==0)	mp.erase(it->first);
			}
		}
		printf("%d %I64d\n",ans1,ans2);
	}
	return 0;
}
