#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
char s[100001][3];
int main()
{
     int i,j,m,t,u,f,d,sum=0;
     scanf("%d%d%d%d%d",&m,&t,&u,&f,&d);
     for(i=1;i<=t;i++)
     {
       scanf("%s",s[i]);               
     }
     for(i=1;i<=t;i++)
     {
       if(s[i][0]=='f')           
       sum=sum+f+f;
       else sum=sum+u+d;
       if(sum>m) break;
     }
     printf("%d",i-1);  
     //system("pause");
     return 0;
}
