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
priority_queue<int,vector<int>,greater<int> >q;  
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
        if(ru[i]==0) q.push(i); 
     } 
     if(q.size()==0)  {printf("no solution");return 0;}
     for(i=1;i<=n;++i)
     {
        k=q.top();
        q.pop(); 
        if(v[k]) {printf("no solution");return 0;}
        v[k]=true;
        ans[i]=k;
        for(j=1;j<=g[k][0];++j)
        {
          if(v[g[k][j]]) {printf("no solution");return 0;}
          else 
          {
             ru[g[k][j]]--;
             if(ru[g[k][j]]==0) q.push(g[k][j]); 
          } 
        } 
     } 
      printf("%d\n",n); 
      for(i=1;i<n;++i)   
        printf("%d ",ans[i]);  
      printf("%d",ans[n]);  
    //  system("pause"); 
      return 0;
}
