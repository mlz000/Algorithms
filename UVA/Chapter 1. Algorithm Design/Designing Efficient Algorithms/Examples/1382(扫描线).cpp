#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N=105;
struct data{
	int x,y;
	friend bool operator<(const data &p,const data &q){
		return p.x<q.x;
	}
}a[N];
int ca,n,x[N],y[N],on[N],on2[N],l[N];
int solve(){
	sort(a+1,a+n+1);
	sort(y+1,y+n+1);
	int m=unique(y+1,y+n+1)-(y+1);
	if(m<=2)	return n;
	int ans=0;
	for(int i=1;i<=m;++i)
		for(int j=i+1;j<=m;++j){
			int ymin=y[i],ymax=y[j];
			int k=0;
			for(int i=1;i<=n;++i){
				if(i==1 || a[i].x!=a[i-1].x){
					k++;
					on[k]=on2[k]=0;
					l[k]=l[k-1]+on2[k-1]-on[k-1];
				}
				if(a[i].y>ymin && a[i].y<ymax)	on[k]++;
				if(a[i].y>=ymin && a[i].y<=ymax)	on2[k]++;
			}
			if(k<=2)	return n;
			int tmp=0;
			for(int i=1;i<=k;++i){
				ans=max(ans,l[i]+on2[i]+tmp);
				tmp=max(tmp,on[i]-l[i]);
			}
		}
	return ans;
}
int main(){
	while(scanf("%d",&n)&&n){
		ca++;
		printf("Case %d: ",ca);
		for(int i=1;i<=n;++i)	scanf("%d%d",&a[i].x,&a[i].y),x[i]=a[i].x,y[i]=a[i].y;
		printf("%d\n",solve());
	}
	return 0;
}

