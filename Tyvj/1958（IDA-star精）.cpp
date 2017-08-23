#include<cstdio>  //IDA* 好题 
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath> 
using namespace std;
const int N=10;
int a[N][N],v[N][N],f[N];
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
int ans,n; 
int left()
{
    int i,j; 
    int k=0; 
    memset(f,0,sizeof(f));
    for(i=1;i<=n;++i)
     for(j=1;j<=n;++j)
     {
        if(f[a[i][j]]==0 && v[i][j]!=1)
        {
            f[a[i][j]]++; 
            k++;
        } 
     } 
     return k; 
} 
void fill1(int x,int y,int c) 
{
    int i;
    v[x][y]=1;
    for(i=0;i<4;++i)
    {
       int xx=x+dx[i];
       int yy=y+dy[i];
       if(xx<1 || xx>n || yy<1 || yy>n || v[xx][yy]==1) continue;
       v[xx][yy]=2;//左上角联通快外面一圈设为2 
       if(a[xx][yy]==c) fill1(xx,yy,c);
    }
}
int fill2(int c)
{
    int i,j; 
    int t=0; 
    for(i=1;i<=n;++i)
     for(j=1;j<=n;++j)
     {
       if(a[i][j]==c && v[i][j]==2)//如果联通块外一圈颜色改为相同 
       {
          ++t;
          fill1(i,j,c); 
       }   
     }
     return t; 
} 
bool IDA(int dep)   //IDA*搜索 假设dep 
{
   int i; 
   int t=left();//计算剩余颜色
   if(dep+t>ans) return false;
   if(!t) return true;//颜色相同 
   int b[N][N];  
   for(i=0;i<=5;++i)
   { 
    memcpy(b,v,sizeof(v));
    if(fill2(i) && IDA(dep+1)) return true; //有颜色修改切不超深度 
    memcpy(v,b,sizeof(b)); 
   } 
   return false; 
} 
int main()
{
     int i,j; 
     while(scanf("%d",&n) &&n)
     {
        ans=0;
        memset(a,0,sizeof(a));
        memset(v,0,sizeof(v));
        for(i=1;i<=n;++i)
         for(j=1;j<=n;++j)
          scanf("%d",&a[i][j]);
       fill1(1,1,a[1][1]);
       for(ans=0;;++ans)
       {
        if(IDA(0)) break;//IDA* 
       }
       printf("%d\n",ans);   
     }
     return 0;
}
