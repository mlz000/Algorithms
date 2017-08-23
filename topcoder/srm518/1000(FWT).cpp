#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1<<16,M=1000000007;
ll a[N],inv2;
ll P(ll x,ll y){
	ll tmp=1ll;
	for(;y;y>>=1){
		if(y&1)	tmp=tmp*x%M;
		x=x*x%M;
	}
	return tmp;
}
void trans(int l,int r){
	if(l==r-1)	return ;
	int len=(r-l)/2;
	int mid=l+len;
	trans(l,mid),trans(mid,r);
	for(int i=l;i<mid;++i){
		ll x1=(a[i]-a[i+len]+M)%M,x2=(a[i]+a[i+len])%M;
		a[i]=x1,a[i+len]=x2;
	}
}
void reverse(int l,int r){
	if(r-l==1)	return ;
	int len=(r-l)/2;
	int mid=l+len;
	for(int i=l;i<mid;++i){
		ll x1=a[i],x2=a[i+len];
		a[i]=(x1+x2)*inv2%M;
		a[i+len]=(x2-x1)*inv2%M;
	}
	reverse(l,mid),reverse(mid,r);
}
class Nim{
        public:
        int count(int K, int L){
            inv2=P(2,M-2);
			for(int i=2;i<=L;++i)
				if(!a[i])
					for(int j=i+i;j<=L;j+=i)	a[j]=1;
			for(int i=2;i<=L;++i)	a[i]^=1;
			int Log=1;
			while(Log<=L)	Log<<=1;
			trans(0,Log);
			for(int i=0;i<Log;++i)	a[i]=P(a[i],K);
			reverse(0,Log);
			return a[0];
        }
}
