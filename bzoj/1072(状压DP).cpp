#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char S[15];
int T,x,l,d[15],f[1<<10][1005];
bool v[1<<10][1005]; 
int calc(int s,int k)
{
      if(!s)      
      {
            if(!k)     return 1;
            else return 0;
      } 
      if(v[s][k]) return f[s][k];
      v[s][k]=true;
      int tmp=0;
      for(int i=1;i<=l;++i) if(s&d[i])    tmp+=calc(s^d[i],(k*10+S[i]-'0')%x);  
      return (f[s][k]=tmp);
}
int main()
{
      for(int i=1;i<=11;++i)    d[i]=1<<(i-1);  
      scanf("%d",&T);
      while(T--)
      {
            memset(v,false,sizeof(v));
            scanf("%s %d",S+1,&x);
            l=strlen(S+1);
            sort(S+1,S+l+1);
            int t1=1,t2=1;
            for(int i=1;i<=l;++i)
            {
                  if(S[i]==S[i+1])  {t2++;t1*=t2;}
                  else t2=1;
            }
            printf("%d\n",calc((1<<l)-1,0)/t1);
      }   
	return 0;
}
