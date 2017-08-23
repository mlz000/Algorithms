#include<cstdio>
#include<algorithm>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const int N=6005;
const int INF=-999999;
int a[N][3],h[N],f[N];
int n;
int dfs(int node,int flag) //flag=0 stay flag=1 go
{
	 if(a[node][flag]!=INF) return a[node][flag];
     int i;
     a[node][flag]=h[node]*flag;
     for(i=1;i<=n;++i)
      {
	    if(f[i]==node)
	     {
		    int tmp=a[node][flag]+dfs(i,!flag);
		    if(!flag)
		    {
			  int tmp2=a[node][flag]+dfs(i,flag);//both stay
			  if(tmp<tmp2) tmp=tmp2;
			}
			a[node][flag]=max(a[node][flag],tmp);
		 }
	  }
	  return a[node][flag];
}
int main()
{
  	int i,j;
  	scanf("%d",&n);
  	for(i=1;i<=n;++i)
  	 {
		 scanf("%d",&h[i]);
	     a[i][0]=a[i][1]=INF;
	 }
  	int l,k;
  	 for(i=2;i<=n;++i)
  	  {s
		  scanf("%d%d",&l,&k);
		  f[l]=k;
	  }
	 int MAX;int ans=-1; 
	 for(i=1;i<=n;++i)
	  for(j=0;j<=1;++j)
	  {
	    MAX=dfs(i,j);
	    if(MAX>ans) ans=MAX;
	  } 
	printf("%d\n",ans);
    return 0;
}
