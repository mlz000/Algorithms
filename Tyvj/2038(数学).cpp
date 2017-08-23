#include<cstdio>//平方平均》=算数平均 解二元一次方程 
#include<iostream> 
#include<climits>
#include<queue> 
#include<cstring> 
#include<algorithm> 
#include<cmath> 
using namespace std;
int n;
double x,y; 
double delt()
{
  return x*x-n*(x*x-y*(n-1)); 
} 
int main()
{
     int i,t; 
     scanf("%d",&t);
     for(i=1;i<=t;++i) 
     {
       scanf("%d%lf%lf",&n,&x,&y); 
       if(n==1 && x*x!=y) printf("WA RE CE TLE MLE OLE\n");  
       else if(delt()<0) printf("WA RE CE TLE MLE OLE\n"); 
       else printf("%.6lf\n",(double)(x*x-y*(n-1))/n); 
     } 
     //system("pause"); 
     return 0; 
} 
