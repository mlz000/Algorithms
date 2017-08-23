#include<iostream>
#include<cstdio>
#include<queue> 
#include<cstring>
#include<cmath> 
#include<climits> 
#include<algorithm>
using namespace std;
const int N=50; 
int j,b[N],ans[N],m,n,MIN,num,now;
bool flag,v[N][N],can[N]; 
struct data
{
   int pos;
   int w; 
}a[N]; 
bool cmp(const data p,const data q) {return p.w<q.w;} 
void init()
{
    int i; 
    scanf("%d%d",&m,&n);
    for(i=1;i<=n;++i)
     scanf("%d%d",&a[i].pos,&a[i].w);
    sort(&a[1],&a[n+1],cmp); 
    memset(v,true,sizeof(v)); 
    int x,y; 
    while(scanf("%d%d",&x,&y)&&x&&y)
     v[x][y]=v[y][x]=false; 
}
void dfs(int x)
{
      int i; 
      for(i=x;i<=n;++i)
      {
       flag=true;
       for(j=1;j<=now;++j)
        if(!v[a[i].pos][b[j]]) {flag=false;break;} 
       if(!flag) continue;
       if(m-a[i].w>=0)
       {
         m-=a[i].w; 
         now++; 
         b[now]=a[i].pos; 
         if((now>num) || ((now==num) && (m<=MIN))) 
         {
            num=now;
            MIN=m;
            for(j=1;j<=now;++j) ans[j]=b[j];  
         } 
         dfs(i+1); 
         m+=a[i].w; 
         now--; 
       }
       else return ; 
     } 
} 
int main()
{  
    now=0;num=0;MIN=100000; 
    init(); 
    dfs(1); 
    if(m-MIN<0) {printf("0 0");return 0;} 
    printf("%d %d\n",num,m-MIN);
    sort(&ans[1],&ans[num+1]);
    int i; 
    for(i=1;i<=num;++i)
     printf("%d\n",ans[i]);  
   // system("pause"); 
    return 0;
}

