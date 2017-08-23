#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath> 
using namespace std;
const int N=10; 
char s[N];; 
int main()
{
    int x,y,t; 
    scanf("%d",&t);
    while(t--)
    {
 
       scanf("%*s%*s%*s");
       scanf("%s",s);
       scanf("%*s%*s");
       scanf("%d",&x);
       scanf("%*s%*s%*s");
       scanf("%d",&y);
       scanf("%*s");
       if(s[0]=='h')
       {
           int a=x,b=y;
           int c=y-x;
           if(c<b) c++;
           printf("%d ",max(c,0));
           c=b+30-a; 
           if(c>b) c--; 
           printf("%d\n",min(30,c)); 
       } 
       else 
       {
           printf("%d ",max(y-x,0));
           printf("%d\n",max(min(30+y-x,30),0)); 
       } 
    } 
   // system("pause"); 
    return 0;
}
