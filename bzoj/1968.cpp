#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	int n;
	long long ans=0ll;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)	ans+=n/i;
	printf("%lld",ans);
	return 0;
}
