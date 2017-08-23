#include<cstring>
#include<cstdio>
#include<climits>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=200005;
int a[N],f[N],d[N];//d means the num of different nums
int main()
{
     int i,j,n,m;
     scanf("%d%d",&n,&m);
     for(i=1;i<=n;++i)
		scanf("%d",&a[i]);
      f[a[1]]++;
      i=1;j=1;
      int sum=1;int MIN=INT_MAX;
      while(j<=n)
      {
	     while(sum<m)
	     {
		     j++;
		     if(f[a[j]]==0) sum++;
		     f[a[j]]++;
		 }
		 if(j-i+1<MIN) MIN=j-i+1;
		 if(f[a[i]]==1) sum--;
		 f[a[i]]--;
		 i++;
	  }    
	 if(MIN<=n) printf("%d",MIN);
	 else printf("NO"); 
    return 0;
}
