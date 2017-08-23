#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int N=32005;
int n,sum[N],c[N];
void ins(int x)
{
	for(;x<=N;x+=x&-x)	++c[x];	
}
int get(int x)
{
	int tmp=0;
	for(;x;x-=x&-x)	tmp+=c[x];
	return tmp;
}
int main()
{
	int x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&x,&y);
		++x;
		sum[get(x)]++;
		ins(x);
	}
	for(int i=0;i<n;++i)	printf("%d\n",sum[i]);
	return 0;
}
