#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=55;
int n,k,b[N],g[N];
char s[N];
int main()
{
      scanf("%d%d",&n,&k);
      for(int i=1;i<=n;++i)
      {
         scanf("%s",s+1);
         for(int j=1;j<=n;++j) if(s[j]=='Y') b[i]++,g[j]++;  
      } 
      int ans=10000;
      for(int i=1;i<=n;++i)   ans=min(ans,min(b[i],g[i]));
      printf("%d",min(ans+k,n));
      system("pause");
      return 0;
}
