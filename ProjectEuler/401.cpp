#include<iostream>//281632621
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const long long M=1e9;
long long f(long long X){
	long long x=X,y=X+1,z=2*X+1;
	if(x%2==0)	x/=2;
	else y/=2;
	if(x%3==0)	x/=3;
	else if(y%3==0)	y/=3;
	else z/=3;
	return (((x%M)*(y%M)%M)*(z%M))%M;
}
int main(){
	long long n=1e15;
	long long p=(long long)sqrt(n);
	long long ans=0ll;
	for(long long i=1;i<=n/(p+1);++i)	ans=(ans+((i*i%M)*(n/i)%M))%M;
	for(long long i=1;i<=p;++i)	ans=(ans+i%M*((f(n/i)-f(n/(i+1)))%M)%M)%M;
	printf("%d\n",ans%M);
	return 0;
}

