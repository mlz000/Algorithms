#include<iostream>
#include<cstdio>
#include<queue> 
#include<cstring>
#include<cmath> 
#include<climits> 
#include<algorithm>
using namespace std;
const int N=100;
int n,w,tot,ans,cnt1[N],cnt2[N],t[N][N],gs[N][N],hash[N]; 
bool v[N][N],can[N]; 
int judge(int x,int y)
{
  int i; 
  if(cnt1[x]==cnt1[y])
  {
    for(i=1;i<=n;++i)
    {if(v[x][i]^v[y][i]==1) return 0;} 
  } 
  if(cnt1[x]==cnt1[y]) return y;
  if(cnt1[x]<cnt1[y]) swap(x,y);//x人能做的题更多 
  for(i=1;i<=n;++i)
    if(!v[x][i] && v[y][i]) return 0; 
  return y;//x做的题完全包括y,可把y删去  
} 
void del(int x,int y)
{
  int i,pos; 
  for(i=1;i<=cnt2[y];++i)
   if(t[y][i]==x) {pos=i;break;}
  for(i=pos;i<=cnt2[y]-1;++i)
   t[y][i]=t[y][i+1];//第x人被删去
  cnt2[y]--;  
} 
void init()
{
   int i,j,k,x,p; 
   scanf("%d%d",&n,&w);
   for(i=1;i<=w;++i)
   {
     scanf("%d",&tot);
     cnt1[i]=tot;//第i个人能做出tot道题
     for(j=1;j<=tot;++j)
     {
       scanf("%d",&x);
       cnt2[x]++;//能做出x题的人数 
       gs[i][j]=x;//第i个人做出的第j道题是x 
       t[x][cnt2[x]]=i;//题目x第几次被i做 
       v[i][x]=true; //第i个人能做出x题 
     }      
   } 
   for(i=1;i<=w;++i)
   {
     if(!can[i]) 
     for(j=i+1;j<=w;++j)
       if(!can[j]) 
       {
         p=judge(i,j); 
         if(p!=0)
         {
          can[p]=true;
          for(k=1;k<=cnt1[p];++k) 
           del(p,gs[p][k]);//把第p个人所能做的所有题删去 
         } 
       } 
   } 
   tot=0; 
   for(i=1;i<=n;++i)
    if(cnt2[i]==1) 
    {
      if(!hash[i]) 
      {
        tot++;//只有一个人能做此题，他必做
        for(j=1;j<=cnt1[t[i][1]];++j)
          hash[gs[t[i][1]][j]]=1; 
      } 
    } 
    ans=INT_MAX/10; 
} 
void dfs(int x,int now)//第x道题 
{
  int i,j; 
  if(x>n)
  {
    ans=min(ans,now);
    return ; 
  } 
  if(now>=ans+1 && hash[x]==0) return; 
  if(hash[x]>0) dfs(x+1,now);
  else
  { 
     for(i=1;i<=cnt2[x];++i)
     {
        for(j=1;j<=cnt1[t[x][i]];++j)
           hash[gs[t[x][i]][j]]++; 
        dfs(x+1,now+1); 
        for(j=1;j<=cnt1[t[x][i]];++j)
           hash[gs[t[x][i]][j]]--;         
     } 
  } 
} 
int main()
{ 
    init(); 
    dfs(1,0); 
    printf("%d",ans+tot); 
    //system("pause"); 
    return 0;
}

