#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
const int N=105;
using namespace std;
vector<int> g[N];
bool v[N];
int du[N];
int main()
{
	int n;
	scanf("%d",&n);
	int x;
	for(int i=1;i<=n;++i)
	{
		while(scanf("%d",&x)&&x)	g[i].push_back(x),du[x]++;
	}
	queue<int> q;
	for(int i=1;i<=n;++i)	if(du[i]==0) q.push(i);
	while(q.size())
	{
	    x=q.front();
		q.pop();
		printf("%d ",x);
		for(int i=0;i<g[x].size();++i)
		{
			int V=g[x][i];
			du[V]--;
			if(du[V]==0)	q.push(V);
		}
	}
	return 0;
}


