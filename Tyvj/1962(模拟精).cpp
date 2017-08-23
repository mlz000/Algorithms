#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1300;
long long c[N];//数值 
int a[N],b[N];//蜡烛数量 
bool v[N][110];
int main()
{ 
    int i,j,k,l,m,n;
    for(i=0;i<1024;++i)
    {
	    for(j=9;j>=0;--j)
	     if(i>>j&1) {c[i]=c[i]*10+j;b[i]++;}
	    for(j=0;j<=9;++j) 
	     if(i>>j&1) v[i][j]=true;//含数字j,一位数 
		for(j=0;j<=9;++j)
		 for(k=0;k<=9;++k)
		  if((i>>j&1) && (i>>k&1) && j!=k) v[i][j+k]=v[i][j*10+k]=true;//两位数
		for(j=0;j<=9;++j) if(i>>j&1)
		 for(k=0;k<=9;++k) if((i>>k&1) && k!=j)
		  for(l=0;l<=9;++l) if((i>>l&1) && l!=j && l!=k)
		  {
		    if(j*10+k+l<=100) v[i][j*10+k+l]=true;
		    for(m=0;m<=9;++m) if((i>>m&1)&& m!=j && m!=k && m!=l)
		    if(j*10+k+l*10+m<=100) v[i][j*10+k+l*10+m]=true;
		  }       
	}
	int t=0;
	while(scanf("%d",&n)&&n)
	{
	    int num=100;
	   long long tmp=1000000000;
	   for(i=1;i<=n;++i)
	    scanf("%d",&a[i]);
	   for(i=1;i<1024;++i)
	   {
		 for(j=1;j<=n;++j) if(!v[i][a[j]]) break;
	     if(j>n &&(b[i]<num || (b[i]==num && c[i]<tmp))) {num=b[i];tmp=c[i];}
	   }
	  printf("Case %d: %lld\n",++t,tmp);
	} 
    return 0;
}

