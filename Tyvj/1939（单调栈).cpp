#include<cstdio>   //单调栈 
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1005; 
int d[N][N],st[N],t[N]; 
int main()
{
    int i,j,n,m; 
    char s[5]; 
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i) 
     for(j=1;j<=m;++j)
      {
        scanf("%s",s);
        if(s[0]=='F') d[i][j]=d[i-1][j]+1; //矩形高度 
       } 
   int ans=0; 
   int wi,top,h; 
   for(i=1;i<=n;++i)
   {
     st[0]=-1;top=0; 
     for(j=1;j<=m;++j)
     {
       wi=0;  h=d[i][j];//累加宽度 
       while(st[top]>h)
       {
          wi=wi+t[top];//累加
          if(wi*st[top]>ans) ans=wi*st[top];
          top--; 
       } 
       top++;
       st[top]=h;
       t[top]=wi+1;//合并成一个新矩形入栈  
     }   
    wi=0;
    while(top>0)
    {
       wi=wi+t[top];
       if(wi*st[top]>ans) ans=wi*st[top];
       top--; 
    }  
   } 
    printf("%d\n",ans*3);
    return 0;
}
