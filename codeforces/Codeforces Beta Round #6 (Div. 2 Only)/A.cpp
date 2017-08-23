#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	int a[4];
	for(int i=0;i<4;++i)	scanf("%d",&a[i]);
	sort(a,a+4);
	int ans=max(a[0]+a[1]-a[2],a[1]+a[2]-a[3]);
	if(ans>0)	printf("TRIANGLE");
	else if(ans==0)	printf("SEGMENT");
	else printf("IMPOSSIBLE");
	return 0;
}
