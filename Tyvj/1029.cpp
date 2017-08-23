#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=90;
char x[N],y[N];
int a[N],b[N];
int main()
{
    int i,j,i2,j2,s2=0,s=0;
    scanf("%s",x);
    scanf("%s",y);
    int a=strlen(x);
    int b=strlen(y);
for(i=0;i<a;i++)
 {
 for(j=0;j<b;j++)
    {
    j2=j;
    i2=i;
    s2=0;
    while((x[i2]==y[j2])&&(j2<b)&&(i2<a))
     {
      s2++;
      i2++;
      j2++;
     }
     if(s2>s)
     s=s2;
     }
}
cout<<s<<endl;
return 0;
}
