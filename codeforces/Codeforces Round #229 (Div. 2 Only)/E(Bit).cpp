#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=4000005;
struct BIT{
	int n;
	LL s1[N],s2[N];
	void add(int x,LL c){for(int i=x;i<=n;i+=i&-i)	s1[i]+=c*x,s2[i]+=c;}
	void Add(int l,int r,LL c){
		add(l,c);
		add(r+1,-c);
	}
	LL get(int x){
		LL tmp=0ll;
		for(int i=x;i;i-=i&-i)	tmp+=(x+1)*s2[i]-s1[i];
		return tmp;
	}
}X,Y;
int main(){
	int n,m,w,o,x1,x2,y1,y2,v;
	scanf("%d%d%d",&n,&m,&w);
	X.n=n+1,Y.n=m+1;
	LL all=0ll;
	while(w--){
		scanf("%d%d%d%d%d",&o,&x1,&y1,&x2,&y2);
		if(o)	printf("%I64d\n",X.get(x2)-X.get(x1-1)+Y.get(y2)-Y.get(y1-1)-all);
		else{
			scanf("%d",&v);
			all+=(x2-x1+1)*(y2-y1+1)*v;
			X.Add(x1,x2,1ll*(y2-y1+1)*v);
			Y.Add(y1,y2,1ll*(x2-x1+1)*v);
		}
	}
	return 0;
}
