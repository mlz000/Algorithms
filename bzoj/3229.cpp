#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath> 
#include<cstring>
using namespace std;
const int N=40005;
int a[N],m,ans;
void work(int x)
{
      int tmp=a[x-1]+a[x],j=x-1,d;
      for(int i=x;i<m;++i)    a[i]=a[i+1];
      --m;  
      while(j>=2 && a[j-1]<tmp)  a[j]=a[j-1],--j;
      ans+=(a[j]=tmp);
      while(j>=3 && a[j-2]<=a[j])   d=m-j,work(j-1),j=m-d;  
} 
int main()
{
      int i,j,n,k;
      scanf("%d",&n);
      for(i=1;i<=n;++i) scanf("%d",&a[i]);
      m=1;
      for(i=2;i<=n;++i)
      {
         a[++m]=a[i];   
         while(m>=3 && a[m-2]<=a[m])      work(m-1);  
      } 
      while(m>=2)    work(m);
      printf("%d",ans);
      //system("pause");
      return 0; 
} 
