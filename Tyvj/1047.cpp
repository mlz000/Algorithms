#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;
char s[44];
long long a[44];
long long b[44][44],f[44][44];
int main()
{
    int i,j,k,h,l,n;
    scanf("%d%d",&n,&h);
    scanf("%s",s);
    l=strlen(s);
    j=1;
    for(i=0;i<l;++i)
  {
    a[j]=s[i]-'0';
    j++;
  }
    for(i=1;i<=n;i++)
     for(j=i;j<=n;j++)
     {
        b[i][j]=b[i][j-1]*10+a[j]; 
     } 
     for(i=1;i<=n;++i)
     f[i][0]=b[1][i];
   for(i=1;i<=n;i++)
     for(j=1;j<=h;j++)
       for(k=1;k<=i;k++)
     {
        f[i][j]=max(f[i][j],f[k][j-1]*b[k+1][i]);//Çø¼ä£Ä£Ð 
     }
     printf("%d",f[n][h]);
     //system("pause");
     return 0;
}
