#include<cstdio>//ÓÃÄãÃÃµÎÁÚ½Ó±í 
#include<iostream>
#include<algorithm>
using namespace std;
const int N=10005;
int f[N];
struct data
{
    int beg;
    int t;
}ti[N];
int main()
{
       int i,j,k,n,m,x,y;
       int M=-1;
       bool flag=false;
       scanf("%d%d",&n,&k);
       for(i=1;i<=k;++i)
        {
          scanf("%d%d",&x,&y);
          ti[i].beg=x;
          ti[i].t=y;
        }    
       for(i=n;i>=1;--i)
       {
          M=-1; 
          for(j=1;j<=k;++j)
           {
             if(ti[j].beg==i) 
             {
                 flag=true;
                 if(f[i+ti[j].t]>M) 
                 {
                        M=f[i+ti[j].t];
                        f[i]=M;
                 }
             }
           } 
          if(!flag)
          {
                   f[i]=f[i+1]+1;
          }
          flag=false;
       }
    printf("%d",f[1]);
    //system("pause");
    return 0;
}

 
