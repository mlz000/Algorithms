#include<cstdio>   //DP
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=2005;
char a[N],b[N];
int f[N][N];
int main()
{
    int i,j,k;
    scanf("%s",a);
    scanf("%s",b);
    scanf("%d",&k);
    int l1=strlen(a);
    int l2=strlen(b);
    for(i=1;i<=l1;++i)
     f[i][0]=i*k;
    for(j=1;j<=l2;++j)
     f[0][j]=j*k; 
    for(i=1;i<=l1;++i)
     for(j=1;j<=l2;++j)
     {
	   f[i][j]=min(min(f[i][j-1]+k,f[i-1][j]+k),f[i-1][j-1]+abs(a[i-1]-b[j-1]));
	 }
     printf("%d\n",f[l1][l2]);
     //system("pause");
	 return 0;
}
