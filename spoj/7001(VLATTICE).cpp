#include<iostream>//Mobius-inversion
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e6+5;
int tot,p[N],mu[N];
bool check[N];
inline long long cube(long long x){
	return x*x*x;
}
inline long long sqr(long long x){
	return x*x;
}
void init(){
	mu[1]=1;
	for(int i=2;i<=1e6;++i){
		if(!check[i])	p[++tot]=i,mu[i]=-1;
		for(int j=1;j<=tot;++j){
			if(i*p[j]>1e6)	break;
			check[i*p[j]]=true;
			if(i%p[j]==0){
				mu[i*p[j]]=0;
				break;
			}
			else mu[i*p[j]]=-mu[i];
		}
	}
}		
int main(){
	init();
	int n,T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		long long ans=3ll;
		for(int i=1;i<=n;++i)	ans+=mu[i]*(cube(n/i)+3*sqr(n/i));
		printf("%lld\n",ans);
	}
	return 0;
}

