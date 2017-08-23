#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=105;
int n,d,r,a[N],b[N];
int main(){
	while(scanf("%d%d%d",&n,&d,&r)&&n&&d&&r){
		for(int i=1;i<=n;++i)	scanf("%d",&a[i]);
		for(int i=1;i<=n;++i)	scanf("%d",&b[i]);
		sort(a+1,a+n+1),sort(b+1,b+n+1,greater<int>());
		int ans=0;
		for(int i=1;i<=n;++i){
			int sum=a[i]+b[i];
			if(sum>d)	ans+=(sum-d)*r;
		}
		printf("%d\n",ans);
	}
	return 0;
}
