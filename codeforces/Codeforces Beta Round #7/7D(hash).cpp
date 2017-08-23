#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=5000005;
long long a,b,t=1,ans,f[N];
string s;
int main()
{
	cin>>s;
	s=" "+s;
	int l=s.size();
	for(int i=1;i<l;++i)
	{
		a=a*131+s[i],b+=s[i]*t,t*=131;
		if(a==b)	ans+=(f[i]=f[i/2]+1);
	}
	printf("%I64d",ans);
	return 0;
}
