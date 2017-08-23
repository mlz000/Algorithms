#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=100010;
int a[N];
int main()
{
    int i,n,L;
    __int64 sum;
    scanf("%d%d",&n,&L);
    if(n&1) sum=(n-1)/2*n;
    else sum=n/2*(n-1);
	for(i=1;i<=n;++i)
	 scanf("%d",&a[i]);
	sort(&a[1],&a[n+1]);
	__int64 ans=0;
	int l=0,r=n+1;
	a[n+1]=100000000;
	for(i=1;i<r;++i)
	{
	   while(l<=r)
	   {
	      if(l==r) break;
		  int mid=(l+r)>>1;
		  if(i!=mid && a[i]+a[mid]>L) {r=mid;}
		  else l=mid+1;
	   } 
	   l=0;
	   ans+=r-i-1;
	}
	double cnt=(double)ans/(double)sum;
	printf("%.2f",cnt);
	//system("pause");  
    return 0;
}

