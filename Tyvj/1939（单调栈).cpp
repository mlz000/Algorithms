#include<cstdio>   //����ջ 
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
        if(s[0]=='F') d[i][j]=d[i-1][j]+1; //���θ߶� 
       } 
   int ans=0; 
   int wi,top,h; 
   for(i=1;i<=n;++i)
   {
     st[0]=-1;top=0; 
     for(j=1;j<=m;++j)
     {
       wi=0;  h=d[i][j];//�ۼӿ�� 
       while(st[top]>h)
       {
          wi=wi+t[top];//�ۼ�
          if(wi*st[top]>ans) ans=wi*st[top];
          top--; 
       } 
       top++;
       st[top]=h;
       t[top]=wi+1;//�ϲ���һ���¾�����ջ  
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
