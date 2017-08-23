#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#define MAX_INT 99999999
using namespace std;
int f[202][202],c[202][202];
int pre[202],l[202];
bool v[202];
int n,m,maxflow;
void EK()
{	
    int i,j,x;
    while(1)
	{
		queue <int> q;
		memset(pre,0,sizeof(pre));
        memset(l,0,sizeof(l));
        memset(v,false,sizeof(v));
		 l[1]=MAX_INT;
         q.push(1);
         v[1]=true;
		while (!q.empty())
       {
          x=q.front();
          q.pop();
          for (i=1;i<=n;i++)
          {
              if (!l[i]&&f[x][i]<c[x][i])
              {
                  pre[i]=x;
                  l[i]=min(l[x],c[x][i]-f[x][i]);
                  q.push(i);
              }
		  }
       }
    if(l[n]==0) break;
     i=n;
	for(i=n;i!=1;i=pre[i])
	{
	  f[pre[i]][i]+=l[n];
	  f[i][pre[i]]-=l[n];
	}
  }
}
int main()
{
    int i,j,t1,t2,t3;
    while (scanf("%d%d",&m,&n)!=EOF)
    {
    memset(c,0,sizeof(c));
    memset(f,0,sizeof(f));
    maxflow=0;
    for (i=1;i<=m;i++)
    {
        scanf("%d%d%d",&t1,&t2,&t3);
        c[t1][t2]+=t3;
    }
    EK();
	for (i=1;i<=n;i++)
	{
		maxflow+=f[1][i];
	}
	printf("%d\n",maxflow);
    }
	//system("pause");
	return 0;
}


