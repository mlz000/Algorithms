#include<iostream>
#include<cstdio>
#include<queue> 
#include<cstring>
#include<cmath> 
#include<climits> 
#include<algorithm>
using namespace std;
const int N=30005;
int f[N],be[N],sum[N]; 
char s[10]; 
int find(int x)
{
  if(f[x]==x) return f[x];
  else
  {
   int m=find(f[x]);
   be[x]=be[x]+be[f[x]];
   f[x]=m; 
  } 
  return f[x]; 
}
int main()
{ 
    int t,i,j; 
    int x,y; 
    scanf("%d",&t);
    for(i=1;i<=30000;++i)
     {
            f[i]=i; 
            sum[i]=1;
     } 
    for(i=1;i<=t;++i)
    {
     scanf("%s",s);
     scanf("%d%d\n",&x,&y);
     int fx=find(x);
     int fy=find(y); 
     if(s[0]=='M')
     {
       f[fx]=fy; 
       be[fx]=sum[fy];
       sum[fy]=sum[fy]+sum[fx]; 
     } 
     if(s[0]=='C')
     {
            if(fx!=fy) printf("-1\n");
            else printf("%d\n",abs(be[x]-be[y])-1); 
     } 
    } 
    system("pause"); 
    //return 0;
}

