#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=500005;
struct data{
	int a,b,c;
	friend bool operator<(data p,data q){
		return (p.a!=q.a)?(p.a>q.a):p.b<q.b;
	}
}rec[N];
int n,h[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)	scanf("%d",&rec[i].a);
	for(int i=1;i<=n;++i)	scanf("%d",&rec[i].b),h[i]=rec[i].b;
	for(int i=1;i<=n;++i)	scanf("%d",&rec[i].c);
	sort(&rec[1],&rec[n+1]);
	sort(&h[1],&h[n+1]);
	for(int i=1;i<=n;++i)	rec[i].b=n-(lower_bound(&h[1],&h[n+1],rec[i].b)-&h[1]);
	memset(h,-1,sizeof(h));
	int ans=0;
	for(int i=1;i<=n;++i){
		int tmp=-100;
		for(int j=rec[i].b-1;j;j-=j&-j)	tmp=max(tmp,h[j]);
		if(tmp>rec[i].c)	ans++;
		for(int j=rec[i].b;j<=n;j+=j&-j)	h[j]=max(h[j],rec[i].c);
	}
	printf("%d\n",ans);
	return 0;
}
	
