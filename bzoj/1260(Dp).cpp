#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=55,inf=10000000;
int f[N][N];
char s[N];
int dp(int l,int r)
{
	if(l==r)	return 1;
	if(l>r)	return 0;
	if(f[l][r])	return f[l][r];
	f[l][r]=inf;
	for(int i=l;i<=r;++i)	f[l][r]=min(dp(l,r),dp(l,i)+dp(i+1,r));
	if(s[l]==s[r])	f[l][r]--;
	return f[l][r];
}
int main()
{
	scanf("%s",s);
	int l=strlen(s);
	printf("%d\n",dp(0,l-1));
	return 0;
}
