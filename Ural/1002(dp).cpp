#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=105,M=50005;
int len[M],f[M],pre[M]; 
char s[N],ss[M][N],ans[M][N],b[300];
inline bool check(int pos,int num,int l)
{
     for(int i=1;i<=l;++i)
     if(s[pos+i]!=b[ss[num][i]])  return false;
     return true; 
}
int main()
{
    int i,j,n;
   	b['i']=b['j']='1',b['a']=b['b']=b['c']='2';b['d']=b['e']=b['f']='3';
	b['g']=b['h']='4';b['k']=b['l']='5';b['m']=b['n']='6';
	b['p']=b['r']=b['s']='7';b['t']=b['u']=b['v']='8';b['w']=b['x']=b['y']='9';b['o']=b['q']=b['z']='0';
    while(scanf("%s",s))
    {
         if(s[0]=='-')  break;
         int L=strlen(s);
         for(i=L;i>=1;--i)     s[i]=s[i-1];    
         scanf("%d\n",&n);
         for(i=1;i<=n;++i)  
         {
           scanf("%s",ss[i]);
           len[i]=strlen(ss[i]);
           for(j=len[i];j>=1;--j)     ss[i][j]=ss[i][j-1];         
         }
         for(i=0;i<=L;++i)   f[i]=10000000; 
         f[0]=0;
         for(i=0;i<=L;++i)
          for(j=1;j<=n;++j)       
          {
            if(i+len[j]<=L && f[i]+1<f[i+len[j]] && check(i,j,len[j]))                                                          
            {
               f[i+len[j]]=f[i]+1; 
               pre[i+len[j]]=j;
            }
          }
         int tot=0;
         if(f[L]==10000000)              {printf("No solution.\n");continue;}
         for(i=L;i>=1;)
         {
             ++tot;
             for(j=0;j<len[pre[i]];++j)  ans[tot][j]=ss[pre[i]][j+1];              
             i=i-len[pre[i]];            
         }
         for(i=tot;i>=1;--i)             printf("%s ",ans[i]);
         printf("\n");
    }
    return 0;
} 
