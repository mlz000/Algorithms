#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
const int N=30;
int l,w,n,ca,totm,totl,totr,ans[N][2];
double ll,lr,rl,rr;
struct data{
	int p,w;
	double ll,lr,rl,rr;
}ml[N],mr[N];
bool can;
bool cmpl(const data &a,const data &b)	{return a.ll<b.ll;}
bool cmpr(const data &a,const data &b)	{return a.rr<b.rr;}
void dfs(double ll,double lr,double rr,double rl,int numm,int numl,int numr){
	if(ll>lr || rr>rl || can)	return ;
	if(numm>n)	{can=true;return ;}
	ans[numm][0]=ml[numl].p;
	ans[numm][1]=ml[numl].w;
	if(numl<=totl){
		dfs(ll+ml[numl].ll,lr,rr,rl+ml[numl].rl,numm+1,numl+1,numr);
		if(can)	return ;
	}
	if(numr<=totr){
		ans[numm][0]=mr[numr].p;
		ans[numm][1]=mr[numr].w;
		dfs(ll,lr+mr[numr].lr,rr+mr[numr].rr,rl,numm+1,numl,numr+1);
		if(can)	return ;
	}
}	
int main(){
	while(scanf("%d%d%d",&l,&w,&n)&&l&&w&&n){
		++ca;
		totm=totl=totr=0;
		printf("Case %d:\n",ca);
		ll=rr=(l-3)*(l-3)*w/4.0/l;
		lr=rl=(l+3)*(l+3)*w/4.0/l;
		for(int i=1,a,b;i<=n;++i){
			scanf("%d%d",&a,&b);
			a<<=1;
			if(abs(a)<=3){
				ans[++totm][0]=(a>>1);
				ans[totm][1]=b;
				lr+=(3+a)*b*1.0;
				rl+=(3-a)*b*1.0;
			}
			else{
				if(a<0){
					ml[++totl].p=(a>>1);
					ml[totl].w=b;
					ml[totl].ll=(-a-3)*b*1.0;
					ml[totl].rl=(-a+3)*b*1.0;
				}
				else{
					mr[++totr].p=(a>>1);
					mr[totr].w=b;
					mr[totr].rr=(a-3)*b*1.0;
					mr[totr].lr=(a+3)*b*1.0;
				}
			}
		}
		sort(ml+1,ml+totl+1,cmpl);
		sort(mr+1,mr+totr+1,cmpr);
		can=false;
		dfs(ll,lr,rr,rl,totm+1,1,1);
		if(!can)	{printf("Impossible\n");continue;}
		for(int i=n;i>=1;--i)	printf("%d %d\n",ans[i][0],ans[i][1]);
	}
	return 0;
}
								
	
			
