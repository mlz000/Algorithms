#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
char s1[2010],s2[2010];
int f[2010][2010];
int main()
{
	int i,j,n,m,l1,l2;
	scanf("%s",s1);
	scanf("%s",s2);
	l1=strlen(s1);
	l2=strlen(s2);
	for(i=1;i<=l1;i++)
   {
		 for(j=1;j<=l2;j++)
	 {
	    if(s1[i-1]==s2[j-1]) 
	    f[i][j]=f[i-1][j-1]+1;
	    else f[i][j]=max(f[i-1][j],f[i][j-1]);
	 } 
   }
   printf("%d",f[l1][l2]);
   return 0;
} 
