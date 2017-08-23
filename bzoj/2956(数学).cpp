#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const LL MOD=19940417ll;
inline LL sumsqr(int x){
	LL a=x,b=x+1,c=2*x+1;
	if(a%3==0)	a/=3;
	else if(b%3==0)	b/=3;
	else c/=3;
	return (LL)a*b/2%MOD*c%MOD;
}
LL calc1(int n,int k){
	LL tmp=0ll;
	for(LL i=1,q;i<=k;i=q+1){
		int p=n/i;q=min(k,n/p);
		tmp=(tmp+(LL)(q-i+1)*(i+q)/2%MOD*p%MOD)%MOD;
	}
	return tmp;
}
LL calc2(int n,int m,int k){
	LL tmp=0ll;
	for(int i=1,q;i<=k;i=q+1){
		int p1=n/i,p2=m/i;q=min(n/p1,min(k,m/p2));
		tmp=(tmp+(sumsqr(q)-sumsqr(i-1)+MOD)%MOD*p1%MOD*p2%MOD)%MOD;
	}
	return tmp;
}
int main(){
	LL n,m;
	cin>>n>>m;
	if(n>m)	swap(n,m);//n<m
	LL ans=(n*n-calc1(n,n))%MOD*((m*m-calc1(m,m))%MOD)%MOD;
	ans-=((n*n%MOD*m%MOD-n*calc1(m,n)%MOD-m*calc1(n,n)%MOD+calc2(n,m,n))%MOD+MOD)%MOD;
	ans=(ans+MOD)%MOD;
	cout<<ans<<endl;
	return 0;
}

