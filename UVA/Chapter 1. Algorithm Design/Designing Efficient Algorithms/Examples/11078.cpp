#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=100005;
int n,T,a[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int ans=-(1<<25),Max=-(1<<25);
		for(int i=1;i<=n;++i)	scanf("%d",&a[i]);
		for(int i=2;i<=n;++i){
			Max=max(Max,a[i-1]);
			ans=max(ans,Max-a[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}

