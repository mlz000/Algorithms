#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<time.h>
#define N 100001
using namespace std;
queue<int>x;
bool vi[N];
int st[N];
int bfs(int n,int k)
{
	int head,next;
	x.push(n);
	vi[n]=true;
    st[n]=0;
	while(!x.empty())
	{
		head=x.front();
		x.pop();
		for(int i=0;i<3;i++)
		{
			if(i==0) next=head-1;
			else if(i==1) next=head+1;
			else next=head*2;
			if( next>N || next<0) continue;
			if(!vi[next])   //Î´·ÃÎÊ
			{
				x.push(next);
				st[next]=st[head]+1;
				vi[next]=true;
			}
			if(next==k) return st[next];
		}
	}
}
int main()
{
	int n,k;
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	printf("%d%d",rand()%100001,rand()%100001);
	if(n>=k) printf("%d\n",n-k);
	else
	{
		printf("%d\n",bfs(n,k));
	}
	return 0;
}

