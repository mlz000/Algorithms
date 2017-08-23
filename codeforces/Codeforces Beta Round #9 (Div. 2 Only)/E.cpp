#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
int g[55];
int deg[55];
int FIND(int x) 
{
	return g[x]==g[g[x]]?g[x]:g[x]=FIND(g[x]);
}
void UNION(int x, int y) 
{
	g[FIND(x)] = FIND(y);
}
int main() 
{
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	for(i=1;i<=n;i++)	g[i] = i;
	int cycledetcted=0;
	for(i=0;i<m;i++) 
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if(FIND(x)==FIND(y))	cycledetcted++;
		else	UNION(x, y);
		deg[x]++;
		deg[y]++;
	}
	for(i=1;i<=n;i++)	if(deg[i]>2)	break;
	if(i<=n || cycledetcted > 1 || cycledetcted==1 && m!=n)
	{
		puts("NO");
		return 0;
	} 
	else 
	{
		printf("YES\n%d\n", n-m);
		while(m<n)
		{
			++m;
			if(m==n)
			{
				for(i=1;i<=n;i++)
					if(deg[i]==0) 
					{
						printf("%d %d\n", i, i);
						break;
					}
					else if(deg[i]==1) 
					{
						for(j=i+1;j<=n;j++)	if(deg[j]==1)	break;
						printf("%d %d\n", i, j);
						break;
					}
			} 
			else 
			{
				for(i=1;i<=n;i++)
					for(j=i;j<=n;j++)
						if(deg[i]<2 && deg[j]<2 && FIND(i)!=FIND(j)) 
						{
							printf("%d %d\n", i, j);
							UNION(i, j);
							++deg[i];
							++deg[j];
						}
			}
		}
	}
	return 0;
}


