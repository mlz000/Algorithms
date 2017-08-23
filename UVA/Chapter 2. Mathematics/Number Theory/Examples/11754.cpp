#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
typedef long long LL;
const int N=15,Lim=10000;
int c,s,a[N],x[N],k[N],y[N][105];
set<int>v[N];
vector<LL>ans;
void solve1(){//枚举 tmp=ix+y
	int best=0;
	for(int i=0;i<c;++i)	if(x[i]*k[best]<x[best]*k[i])	best=i;
	for(int i=0;i<c;++i)	if(i!=best){
		v[i].clear();	
		for(int j=0;j<k[i];++j)	v[i].insert(y[i][j]);
	}
	for(int i=0;s;++i)
		for(int b=0;b<k[best];++b){
			bool flag=true;
			LL tmp=(LL)i*x[best]+y[best][b];
			if(!tmp)	continue;
			for(int j=0;j<c;++j)
				if(j!=best && !v[j].count(tmp%x[j]))	{flag=false;break;}
			if(flag){
				printf("%lld\n",tmp);
				if(--s==0)	break;
			}
		}
}
void gcd(LL a,LL b,LL &d,LL &x,LL &y){
	if(!b){d=a;x=1;y=0;return;}
	gcd(b,a%b,d,y,x),y-=x*(a/b);
}
LL china(int n,int a[],int m[]){
	LL M=1ll,d,y,x=0ll;
	for(int i=0;i<n;++i)	M*=m[i];
	for(int i=0;i<n;++i){
		LL w=M/m[i];
		gcd(m[i],w,d,d,y);
		x=(x+y*w*a[i])%M;
	}
	return (x+M)%M;
}
void dfs(int dep){
	if(dep==c)	{ans.push_back(china(c,a,x));return;}
	for(int i=0;i<k[dep];++i){
		a[dep]=y[dep][i];
		dfs(dep+1);
	}
}
void solve2(){//中国剩余定理
	ans.clear();
	dfs(0);
	sort(ans.begin(),ans.end());
	LL M=1ll;
	for(int i=0;i<c;++i)	M*=x[i];
	for(int i=0;s;++i)
		for(int j=0;j<ans.size();++j){
			LL tmp=M*i+ans[j];
			if(tmp){
				printf("%lld\n",tmp);
				if(--s==0)	break;
			}
		}
}
int main(){
	while(scanf("%d%d",&c,&s)&&c&&s){
		long long tot=1ll;
		for(int i=0;i<c;++i){
			scanf("%d%d",&x[i],&k[i]);
			for(int j=0;j<k[i];++j)	scanf("%d",&y[i][j]);
			tot*=k[i];
			sort(y[i],y[i]+k[i]);
		}
		if(tot>Lim)	solve1();
		else solve2();
		printf("\n");
	}
	return 0;
}

