#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=105;
int a[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)	scanf("%d",&a[i]);
	sort(&a[1],&a[n+1]);
	int ans=0;
	for(int i=1;i<=n/2+1;++i)
	ans+=a[i]/2+1;
	printf("%d\n",ans);
	return 0;
}
