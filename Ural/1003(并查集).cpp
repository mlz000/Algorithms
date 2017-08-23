#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=10,MOD=10000;
int Hash[MOD],f[MOD*2];
char s[N];
void init()
{
     memset(Hash,-1,sizeof(Hash));
     for(int i=0;i<MOD*2;++i)   f[i]=i;
}
int hash(int x)
{
    int key=x%MOD;
    while(Hash[key]!=-1 && Hash[key]!=x)  key=(key+1)%MOD;
    Hash[key]=x;
    return key;      
}
int find(int x)
{
    if(f[x]==x)      return f[x];
    else  return f[x]=find(f[x]);
}
void Union(int x,int y)
{
     int fx=find(x);
     int fy=find(y);
     if(fx!=fy)     f[fx]=fy; 
}
int main()
{
    int n,m;
    while(scanf("%d",&n)&&n!=-1)
    {
        init();
        scanf("%d",&m);
        int i,x,y;
        for(i=0;i<m;++i)
        {
           scanf("%d %d %s",&x,&y,s);
           int hx=hash(x-1);
           int hy=hash(y);
           if(strcmp(s,"even")==0)
           {
              if(find(hx)==find(hy+MOD))    break;
              Union(hx,hy);
              Union(hx+MOD,hy+MOD);
           }                      
           else 
           {
               if(find(hx)==find(hy))       break;
               Union(hx,hy+MOD);
               Union(hx+MOD,hy); 
           }
        }
        for(int j=i+1;j<m;++j)   scanf("%d %d %s",&x,&y,s);
        printf("%d\n",i);
    }
    return 0;
} 
