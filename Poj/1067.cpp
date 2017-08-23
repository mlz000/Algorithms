//http://apps.hi.baidu.com/share/detail/34689283 Wythoff Game Betty∂®¿Ì£¨µ∞Ã€ 
#include<iostream>
#include<algorithm>
#include<cmath> 
using namespace std;
int main() 
{
       int i,j,n;
       int a,b;
       double x=(1+sqrt(5.0))/2;
       double y=(3+sqrt(5.0))/2;
       while(scanf("%d%d",&a,&b)!=EOF)
       {
	       if(a>b) swap(a,b);
		   n=ceil(b/y);
		   int big;
		   big=n*y;
		   int sm;
		   sm=n*x;
		   if(sm==a && big==b)
		   printf("0\n");
		   else printf("1\n");
	   }
       return 0;
}
