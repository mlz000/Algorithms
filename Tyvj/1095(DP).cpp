#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=105;
int a[N];
float f[N][2]; //f[][1] dollar f[][0] mark
int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
	  scanf("%d",&a[i]);
     f[0][1]=100;
    for(i=1;i<=n;++i) 
     {
	    f[i][0]=max(f[i-1][0],f[i-1][1]*a[i]/100);
	    f[i][1]=max(f[i-1][1],f[i-1][0]*100/a[i]);
	 }
	 printf("%.2f",f[n][1]);
    return 0;
}
