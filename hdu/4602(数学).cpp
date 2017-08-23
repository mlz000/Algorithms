#include<iostream>//(n-k+3)*2^(n-k-2)
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MOD=1000000007;
int T;	
long long n,k;
long long calc(long long x,int y){
	long long tmp=1ll;
	for(;y;y>>=1){
		if(y&1)	tmp=tmp*x%MOD;
		x=x*x%MOD;
	}
	return tmp;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%I64d%I64d",&n,&k);
		if(n==k)	printf("1\n");
		else if(n==k+1)	printf("2\n");
		else if(n<k)	printf("0\n");
		else	printf("%I64d\n",(((n-k+3)%MOD)*calc(2,n-k-2))%MOD);	
	}
	return 0;
}
