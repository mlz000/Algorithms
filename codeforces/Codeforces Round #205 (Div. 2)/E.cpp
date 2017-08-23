#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
const int N=1000005;
int set[N]={1};
char s[N];
int main()
{
	scanf("%s",s);
	int l=strlen(s);
	int tot=0;
	for(int i=1;i<l;++i)
	{
    	if(s[i]==s[i-1])	set[tot]++;
		else set[++tot]=1;
	}
	if(s[l-1]==s[0])	set[0]+=set[tot--];
	int tmp=0,ans=0;
	for(int i=0;i<=tot;++i)
	{
		if(set[i]==1)	++tmp;
		else ans+=1+tmp/2,tmp=0;
	}
	ans+=tmp/2;
	printf("%d\n",ans);
	return 0;
}


