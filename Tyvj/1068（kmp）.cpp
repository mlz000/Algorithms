#include<cstring>//KMP好题 
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=200005;
char a[N],b[N];
int cnt[N],p[N],ans[N],len[N];
int main()
{
    int i,j,n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    scanf("%s",a+1);
    scanf("%s",b+1); 
    int la=strlen(a+1); 
    int lb=strlen(b+1);
    j=0; 
    for(i=2;i<=lb;++i)//自匹配 
    {
	  while(j>0 && b[j+1]!=b[i]) j=p[j];
	  if(b[j+1]==b[i]) j=j+1;
	  p[i]=j;
	}
    j=0;
    for(i=1;i<=la;++i) 
    {
      while(j>0 && b[j+1]!=a[i]) j=p[j];
      if(b[j+1]==a[i]) {j++;len[i]=j;}//a字符串到第i位置能匹配长度   
    } 
    for(i=1;i<=n;++i)
     cnt[len[i]]++; //匹配长度为len[i]的个数 
    for(i=n;i>=1;--i)
     cnt[p[i]]+=cnt[i]; //长度i可匹配，长度p[i]必可以匹配 
     int x; 
    for(i=1;i<=k;++i)
    {
      scanf("%d",&x);
      printf("%d\n",cnt[x]-cnt[x+1]); //cnt[x]包括cnt[x+1] 
    } 
    //system("pause"); 
    return 0;
}
