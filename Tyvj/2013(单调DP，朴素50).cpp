#include<cstdio> 
#include<iostream>
#include<algorithm>
#include<cstring> 
using namespace std; 
const int N=100005;
unsigned long long a[N],b[N],f[N]; 
int main()
{ 
      int i,j,n; 
      scanf("%d",&n);
      for(i=1;i<=n;++i)
       scanf("%d",&a[i]); 
      for(i=1;i<=n;++i)
       scanf("%d",&b[i]);
       unsigned long long MAX=0;  
      for(i=1;i<=n;++i) //BÅä¶ÔÇ°i¸ö 
       for(j=1;j<=i-1;++j)
        {
            f[i]=max(max(f[i],f[i-1]),f[j-1]+a[j]*b[i]); 
            MAX=max(MAX,f[i]); 
        } 
      cout<<MAX; 
     // system("pause");  
      return 0; 
} 

