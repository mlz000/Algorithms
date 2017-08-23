#include<cstdio>
#include<queue>
#include<iostream>
#include<cstring>
#include<bitset>
using namespace std;
const int N=1001;
bool v[N];
int dis[N];
int n;
char s[N];
bitset<1001> b[1001];
void spfa()
{
    int i;
    queue<int> q;
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    q.push(1);
    while(q.size())
    {
      int x=q.front();
      q.pop();
      v[x]=false;
      for(i=1;i<=n;++i)
      {
        if(!b[x][i]) continue;
        if(dis[x]+b[x][i]<dis[i])
        {
          dis[i]=dis[x]+b[x][i];
          if(!v[i])
          {
            q.push(i);
            v[i]=true;
          }
        }
      }
    }
}
int main()
{
     int i,j;
     scanf("%d",&n);
     for(i=1;i<=n;++i)
     {
       scanf("%s",s);
       for(j=0;j<n;++j)
        b[i][j+1]=s[j]-'0';
     }
     spfa(); 
     printf("%d",dis[n]); 
     //system("pause");  
     return 0;
}
