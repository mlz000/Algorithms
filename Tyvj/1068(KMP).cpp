#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=200005;
char a[N],b[N];
int p[N],q[N],ans[N],len;
int main()
{
    int i,j,n,m,k;
   // scanf("%d%d%d",&n,&m,&k);
    scanf("%s",&a+1);
    scanf("%s",&b+1);
   // for(i=1;i<=k;++i)
    // scanf("%d",&q[i]);
    j=0;p[1]=0;
    int lb=strlen(b);
    for(i=2;i<=lb;++i)
    {
	  while(j>0 && b[j+1]!=b[i]) j=p[j];
	  if(b[j+1]==b[i]) j=j+1;
	  p[i]=j;
	}
    
    system("pause"); 
    return 0;
}
