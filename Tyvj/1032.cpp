#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
struct f
{
    int a;
    int b;
}w[21];
bool cmp(const struct f &c,const struct f &d)
{
  return c.a<d.a;
}
int main()
{
    int i,j,n,c,num;
    scanf("%d%d",&n,&c);
    for(i=1;i<=n;i++)
    {
     scanf("%d%d",&w[i].a,&w[i].b);
    }
    sort(&w[1],&w[n+1],cmp);
    if(n==1) {printf("%d",w[1].b);return 0;}
    
      
     printf("%d",num); 
     system("pause");
     return 0;     
    }                                  
}
