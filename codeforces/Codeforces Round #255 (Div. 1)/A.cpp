#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N],b[N],c[N];
int main(){
	int n,ans=0;
	scanf("%d",&n);
	a[n+1]=1000000005;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		b[i]=a[i-1]<a[i]?b[i-1]+1:1;
		ans=max(ans,b[i]);
	}
	if(ans<n)	++ans;
	for(int i=n;i>=1;--i){
		c[i]=a[i]<a[i+1]?c[i+1]+1:1;
		if(a[i+1]>a[i-1]+1)	ans=max(ans,b[i-1]+c[i+1]+1);
	}
	printf("%d\n",ans);
	return 0;
}
