#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
long long sg(long long x){
	if(x%2==0)	return x/2;
	else return sg(x/2);
}
int main(){
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		long long ans=0ll,v;
		for(int i=1;i<=n;++i){
			scanf("%lld",&v);
			ans^=sg(v);
		}
		if(!ans)	printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
