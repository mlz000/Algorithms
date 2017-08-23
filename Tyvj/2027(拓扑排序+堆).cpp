#include<cstdio>
#include<iostream> 
#include<cstring>
#include<queue> 
#include<algorithm> 
#include<cmath> 
using namespace std;
const int N=30005,M=1000005;
int cnt,h[N],ru[N],ans[N],g[N][100]; 
bool v[N]; 
void down()//È¡×îÐ¡ 
{
   int y,z,v;
   y=1;z=y*2;v=h[1];
   while(z<=cnt)
   {
     if(z<cnt) {if(h[z+1]<h[z]) z=z+1;} 
     if(h[z]>v) break; 
     h[y]=h[z];y=z;z=y*2; 
   } 
   h[y]=v; 
} 
void shift(int p)
{
   int y,z,v;
   y=p;z=y/2;v=h[y];
   while(h[z]>v && z>=1)
   {
     h[y]=h[z];
     y=z;z=y/2; 
   } 
   h[y]=v; 
} 
int main()
{ 
      int i,j,k,n,x,y; 
      scanf("%d",&n);
      for(i=1;i<=n;++i)
      {
        scanf("%d",&x);
        for(j=1;j<=x;++j)
        {
          scanf("%d",&y);
          g[i][0]++;
          g[i][g[i][0]]=y;
          ru[y]++; 
        } 
      } 
     cnt=0;
     for(i=1;i<=n;++i)
     {
        if(ru[i]==0) 
        {
            cnt++;
            h[cnt]=i;
        } 
     } 
     for(i=1;i<=n;++i)
     {
        k=h[1];
        if(v[k]) {printf("no solution");return 0;}
        v[k]=true;
        ans[i]=k;
        h[1]=h[cnt]; cnt--;down(); 
        for(j=1;j<=g[k][0];++j)
        {
          if(v[g[k][j]]) {printf("no solution");return 0;}
          else 
          {
             ru[g[k][j]]--;
             if(ru[g[k][j]]==0)
             {
               cnt++;
               h[cnt]=g[k][j];
               shift(cnt); 
             } 
          } 
        } 
     } 
      printf("%d\n",n); 
      for(i=1;i<n;++i)   
        printf("%d ",ans[i]);  
      printf("%d",ans[n]);  
     // system("pause"); 
      return 0;
}
