#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int N=1005;
struct data
{
    int v;
    int l;
};
vector <data> d[N*2];
int fa[N],dis[N],sum;
bool vi[N];
void dfs(int u)
{
    if(d[u].empty()) return;
    for(int i=0;i<d[u].size();++i)
    {
	  data p;
	  p=d[u][i];
	  if(vi[p.v]) continue;
	  sum+=p.l;
	  dis[p.v]=sum;
	  fa[p.v]=u;
	  vi[p.v]=true;
	  dfs(p.v);
	  vi[p.v]=false;
	  sum-=p.l;
	}
}
int main()
{ 
     int i,n,q;
     scanf("%d%d",&n,&q);
     int a,b,c;
     for(i=1;i<n;++i)
     {
	   data p;
	   scanf("%d%d%d",&a,&b,&p.l);
	   p.v=b;d[a].push_back(p);
	   p.v=a;d[b].push_back(p); 
	 }
     fa[1]=fa[0]=1;//1Îª¸ù
     vi[1]=true;
	 dfs(1);
	 for(i=1;i<=q;++i)
	 { 
	   bool flag=false;		
       scanf("%d%d",&a,&b);
	   int p,p1=a,p2;
	   do
	   { 
	      p2=b;
		  do
		  {
		     if(p1==p2) {p=p1;flag=true;break;}
		      p2=fa[p2];
		     if(p1==p2) {p=p1;flag=true;break;}
		  }while(p2!=1);  
		  if(flag) break;
		  p1=fa[p1];
		  if(p1==p2) {p=p1;break;}
	   }while(p1!=1);
	   printf("%d\n",dis[a]+dis[b]-2*dis[p]);
	 }
	 return 0;
}
