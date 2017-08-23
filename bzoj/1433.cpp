#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue> 
using namespace std;
const int N=60;
int stu[N],sta[N],c[N*2][N*2],f[N*2][N*2],pre[N*2],l[N*2];
int know[N][N];
bool v[N];
int S,T,n;
int getT(int x){return x<<1;}
int getS(int x){return (x<<1)-1;}
void EK()
{	
    int i,j,x;
    memset(f,0,sizeof(f));
    while(1)
	{
		queue <int> q;
		memset(pre,0,sizeof(pre));
        memset(l,0,sizeof(l));
        memset(v,false,sizeof(v));
		 l[S]=9999999;
         q.push(S);
         v[S]=true;
		while (!q.empty())
       {
          x=q.front();
          q.pop();
          for (i=S;i<=T;i++)
          {
              if (!l[i]&&f[x][i]<c[x][i])
              {
                  pre[i]=x;
                  l[i]=min(l[x],c[x][i]-f[x][i]);
                  q.push(i);
              }
		  }
       }
    if(l[T]==0) break;
     i=T;
	for(i=T;i!=S;i=pre[i])
	{
	  f[pre[i]][i]+=l[T];
	  f[i][pre[i]]-=l[T];
	}
  }
}
int main()
{
       int t,i,j,ans,flow;
       scanf("%d",&t);
     while(t--)
    {
        memset(c,0,sizeof(c));
        scanf("%d",&n);
        ans=n;
        S=0;
        T=2*n+1;
        for(i=1;i<=n;i++)
        scanf("%d",&stu[i]);
        for(i=1;i<=n;i++)
        scanf("%d",&sta[i]);
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        scanf("%d",&know[i][j]),know[i][j]|=(i==j);
        for(i=1;i<=n;i++)
        if(stu[i])c[getT(i)][T]=1;
        for(i=1;i<=n;i++)
        if(stu[i]&&sta[i])ans--;
        for(i=1;i<=n;i++)
        if(!sta[i]||(!stu[i]))c[S][getS(i)]=1;
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        if(know[i][j])
        c[getS(i)][getT(j)]=1;
        flow=0;
        EK();
          for(i=1;i<=T;++i)
           flow+=f[0][i];
          if(flow==ans) printf("%c%c%c\n",94,95,94);
          else printf("%c%c%c\n",84,95,84);
     }
       //system("pause");
       return 0;
}
