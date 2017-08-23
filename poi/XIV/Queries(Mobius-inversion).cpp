#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=50005;
int tot,p[N],mu[N];
bool check[N];
void init(){
	mu[1]=1;
	for(int i=2;i<=50000;++i){
		if(!check[i])	p[++tot]=i,mu[i]=-1;
		for(int j=1;j<=tot;++j){
			if(i*p[j]>50000)	break;
			check[i*p[j]]=true;
			if(i%p[j]==0){
				mu[i*p[j]]=0;
				break;
			}
			else mu[i*p[j]]=-mu[i];
		}
	}
	for(int i=2;i<=50000;++i)	mu[i]+=mu[i-1];
}		
int main(){
	init();
	int n;
	scanf("%d",&n);
	while(n--){
		int a,b,d;
		scanf("%d%d%d",&a,&b,&d);
		if(a>b)	swap(a,b);
		a/=d,b/=d;
		long long ans=0ll;
		for(int i=1,last;i<=a;i=last+1){
			last=min(a/(a/i),b/(b/i));
			ans+=(long long)(mu[last]-mu[i-1])*(a/i)*(b/i);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

