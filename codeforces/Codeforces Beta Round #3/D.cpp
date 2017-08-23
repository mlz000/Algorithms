#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int N=50005;
char s[N];
struct data
{
	int pos;
	int w;
}a[N];
priority_queue<data> q;
bool operator<(const data x,const data y)
{
	return x.w<y.w;
}
int main()
{
	scanf("%s",s);
	int l=strlen(s);
	int in=0;
	long long ans=0ll;
	for(int i=0;i<l;++i)
	{
		if(s[i]=='(') ++in;
		else if(s[i]==')') --in;
		else 
		{
			int l,r;
			scanf("%d%d",&l,&r);
			s[i]=')';
			--in;
			ans+=r;
			data tmp;
			tmp.pos=i,tmp.w=r-l;
			q.push(tmp);
		}
		if(in<0)
		{
			if(q.empty()) break;
			data tmp=q.top();
			q.pop();
			s[tmp.pos]='(';
			in+=2;
			ans-=tmp.w;
		}
	}
	if(in!=0)	printf("-1");
	else
	{
		printf("%lld\n",ans);
		printf("%s",s);
	}
	return 0;
}

