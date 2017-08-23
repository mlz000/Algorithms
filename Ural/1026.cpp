#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
const int N=100005;
int a[N];
int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)	scanf("%d",&a[i]);
	sort(&a[1],&a[n+1]);
	char s[10];
	scanf("%s",s);
	scanf("%d",m);
	int x;
	for(int i=1;i<=m;++i)	scanf("%d",&x),printf("%d\n",a[x]);
	return 0;
}
