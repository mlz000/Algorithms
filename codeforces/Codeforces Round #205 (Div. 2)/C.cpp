#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
const int N=100005;
char s[N];
int a[N],sum[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)	
	{
		scanf("%d",&a[i]);
		sum[0]=a[0];
		if(i>=1)
		sum[i]=sum[i-1]+a[i];
	}
	scanf("%s",s);
	int l=strlen(s);
	int all=0,MAX=0;
	for(int i=l-1;i>=0;--i)
	{
		if(s[i]=='0')	continue;
		MAX=max(MAX,all+sum[i-1]);
		all+=a[i];
	}
	MAX=max(MAX,all);
	printf("%d\n",MAX);
	return 0;
}



