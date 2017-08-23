#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int a[N],b[N],c[N];
int main(){
	int n,T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)	scanf("%d",&a[i]);
		int l=1,r=n;
		while(a[l]==0)	++l;
		while(a[r]==1)	--r;
		if(l>r){
			printf("0.000000\n");
			continue;
		}
		int k=1;
		while(l<=r){
			b[k]=c[k]=0;
			while(a[l]==1)	c[k]++,l++;
			while(a[l]==0 && l<=r)	b[k]++,l++;
			while(k>=2 && (long long)c[k]*b[k-1]<c[k-1]*b[k]){
				b[k-1]+=b[k];
				c[k-1]+=c[k];
				k--;
			}
			k++;
		}
		double ans=0.0;
		for(int i=1;i<k;++i){
			double t=(double)c[i]/(b[i]+c[i]);
			ans+=(t-1)*(t-1)*c[i]+t*t*b[i];
		}
		printf("%.6lf\n",ans);
	}
	return 0;
}
