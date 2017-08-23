#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
const int N=1000005;
char s[N];
int main()
{
	scanf("%s",s);
	int l=strlen(s);
	int tot=0,ans=0;
	for(int i=l-1;i>=0;--i)
	{
		if(s[i]=='M')	
		{
			if(tot)	ans=max(ans+1,tot);
		}
		else tot++;
	}
	printf("%d",ans);
	return 0;
}

