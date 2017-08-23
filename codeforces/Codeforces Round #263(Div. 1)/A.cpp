#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,a[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)	scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	long long ans=0;
	for(int i=1;i<n;++i)	ans+=(long long)a[i]*(i+1);
	ans+=(long long)a[n]*n;
	printf("%I64d\n",ans);
	return 0;
}
