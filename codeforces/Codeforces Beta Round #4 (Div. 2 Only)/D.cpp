#include <iostream>
using namespace std;
#define N 50050

struct node{
	int w,h;
};

int dp[N],next[N];
node p[N];
int n;

int dfs(int c)
{
	if(dp[c]) return dp[c];
	for(int i=0;i<=n;i++)
	{
		if(p[i].w>p[c].w&&p[i].h>p[c].h)
		{
			int k=dfs(i);
			if(dp[c]<=k)
			{
				dp[c]=k+1;
				next[c]=i;
			}
		}
	}
	return dp[c];
}

void print(int b)
{
	if(next[b]==0)
	{
		return;
	}
	else
	{
		cout << next[b] << " ";
		print(next[b]);
	}
}

int main()
{
	cin >> n;
	for(int i=0;i<=n;i++)
	{
		cin >> p[i].w >> p[i].h;
		dp[i]=0;
		next[i]=0;
	}
	int k=dfs(0);
	cout << k << endl;
	print(0);
	return 0;
}

