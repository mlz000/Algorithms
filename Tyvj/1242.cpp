#include<cstring>
#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=4005,M=4005;
int f[N];
int find(int x)
{
    if(f[x]==x) return f[x];
    else return f[x]=find(f[x]);
}
int main()
{
       int i,j,n,m,num1=0,num2=0;
       scanf("%d%d",&n,&m);
       for(i=1;i<=n;++i)
       f[i]=i;
       int a,b,c,fa,fb,fc;
       for(i=1;i<=m;++i)
       {
           scanf("%d%d",&a,&b);
           fa=find(a);
           fb=find(b);
           if(fa!=fb) f[fb]=fa;
       }
       scanf("%d",&c);
       fc=find(c);
       bool flag=false;
       for(i=1;i<=n;++i)
       {
           if(find(i)==fc)
           {
               if(i==2) num2++;
               if(i==1) num1++;
               if(i!=1 && i!=2)
               {
                   for(j=2;j<=sqrt(i);++j)
                   {
                       if(i%j==0) {num1++;break;flag=true;}
                   }
                   if(!flag) num2++;
               }
           }
           flag=false;
       }
       printf("%d",min(num1,num2));
       return 0;
}
