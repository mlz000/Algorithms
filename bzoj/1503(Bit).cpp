#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
priority_queue<int,vector<int>,greater<int> > q;
const int N=100005*2,INC=10001;
int n;
int MAX;
struct Bit
{
	int n,m,c[N];
    inline void init(int s)
	{
		m=(int)(log(n=s)/log(2));
		memset(c,0,sizeof(c));
	}
	inline void add(int x,int k)
	{
		for(;x<=N;x+=x&-x)
		c[x]+=k;	
	}
	int select(int x)	
	{
		int p=0,tmp=0;
		for(int i=(1<<m);i;i=(i>>1))
		 if(p+i<N && tmp+c[p+i]<x) {p+=i;tmp+=c[p];}
		return p+1; 
	}
}bit;
int main()
{
	long long MIN;
	int delta=0;
	scanf("%d%lld",&n,&MIN);
	int cnt=0;
	bit.init(N);
	for(int i=1;i<=n;++i)
	{
		int x;char s[20];
		scanf("%s%d",s,&x);
		if(s[0]=='I')	
		{
			if(x>=MIN)	
			{
				bit.add(x-delta+INC,1);
				q.push(x-delta);
			}
		}
		else if(s[0]=='A') {delta+=x;}
		else if(s[0]=='S')
		{
			delta-=x;
			while(q.size())
			{
				if(q.top()+delta>=MIN)	break;
				bit.add(q.top()+INC,-1);
				q.pop();
				cnt++;
			}
		}
		else if(s[0]=='F')	
		{
			if(x>q.size()) printf("-1\n");
			else printf("%d\n",bit.select(q.size()-x+1)+delta-INC);
		}
	}
	printf("%d\n",cnt);
	return 0;
}
