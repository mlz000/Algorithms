#include<iostream>//Mobius-inversion+ÈÝ³â
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
long long work(int a,int b){
	if(a>b)	swap(a,b);
	long long tmp=0ll;
	for(int i=1,last;i<=a;i=last+1){
		last=min(a/(a/i),b/(b/i));
		tmp+=(long long)(mu[last]-mu[i-1])*(a/i)*(b/i);
	}
	return tmp;
}
int main(){
	init();
	int n,a,b,c,d,k;
	scanf("%d",&n);
	while(n--){
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		long long ans=work(b/k,d/k);
		ans-=work((a-1)/k,d/k);
		ans-=work(b/k,(c-1)/k);
		ans+=work((a-1)/k,(c-1)/k);
		printf("%lld\n",ans);
	}
	return 0;
}

