#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
unsigned long int a[200002];
int main()
{
     int i,j,m,n,num=1;
     scanf("%d",&n);
     for(i=1;i<=n;i++)
     {
       scanf("%ld",&a[i]);
     }
     sort(a,a+n+1);
     for(i=1;i<=n;i++)
     {
       if(a[i]==a[i+1]) num++;
       else {printf("%ld %d\n",a[i],num);num=1;}
     }
     //system("pause");
     return 0;
} 
