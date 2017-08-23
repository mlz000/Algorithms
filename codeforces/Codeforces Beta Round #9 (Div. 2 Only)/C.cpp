#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int x;
long long ans;
void calc(int a)
{
	if(a>x)	return ;
	ans++;
	calc(10*a);
	calc(10*a+1);
}
int main()
{
	scanf("%d",&x);
	calc(1);
	printf("%I64d\n",ans);
	return 0;
}
