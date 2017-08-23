#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
long long phi(long long x){
	if(x==1)	return 1ll;
	long long tmp=1ll;
	for(long long i=2;i*i<=x;++i){
		if(x%i==0){
			int cnt=0;
			while(x%i==0)	cnt++,x/=i;
			tmp*=i-1;
			for(int j=1;j<cnt;++j)	tmp*=i;
		}
	}
	if(x>1)	tmp*=x-1;
	return tmp;
}
int main(){
	long long n;
	scanf("%lld",&n);
	long long ans=0ll;
	for(long long i=1ll;i*i<=n;++i){
		if(n%i==0){
			ans+=i*phi(n/i);
			if(i*i<n)	ans+=(n/i)*phi(i);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
