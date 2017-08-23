#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long LL;
#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
const int N=55;
int n,a[N];
LL f[N][2][2];
LL dp(int x,bool p,bool q)//位置 逆串 逆反串
{
	LL &tmp=f[x][p][q];
	if(~tmp)	return tmp;
	if(x*2>=n)	return (tmp=1ll);
	tmp=0;
	for(int i=0;i<2;++i)
	{
		if(a[x]<0||a[x]==i)
		for(int j=0;j<2;++j)
		{
			if(a[n-1-x]<0||a[n-1-x]==j)
				if((i==j || x*2+1!=n) && (p||i<=j) && (q||i<=1-j))//小于等于逆序、逆反
					tmp+=dp(x+1,p||i<j,q||i<1-j);
		}
	}
	return tmp;
}
int main()	
{
	long long k;
	cin>>n>>k;
	k++;
	clr(f,-1);
	clr(a,-1);
	if(dp(0,0,0)<k)	{printf("-1");return 0;}
	for(int i=0;i<n;++i)
	{
		clr(f,-1);
		a[i]=0;
		if(dp(0,0,0)<k)	{a[i]=1;k-=dp(0,0,0);}
		printf("%d",a[i]);
	}
	return 0;
}


