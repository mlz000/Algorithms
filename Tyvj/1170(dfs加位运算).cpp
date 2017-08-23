#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stdio.h>
#include <cstring>
using namespace std; 
int n,ans;
long long s=1;
bool check(int l)
{
      int k=1;
      long long ss,s1,s2,s3;
      while(k*3<=l)
      {
        ss=s;    
        s1=ss&((1<<k)-1);ss>>=k;
        s2=ss&((1<<k)-1);ss>>=k;
        s3=ss&((1<<k)-1);
        if(s1==s2 && s2==s3) return false;
        k++;
      }
      return true;
}
void dfs(int x)
{
   if(!check(x)) return ;
   if(x==n) {ans++;return;}
   s<<=1;s++;
   dfs(x+1);
   s--;
   dfs(x+1);
   s>>=1;
}
int main()
{ 
    scanf("%d",&n);
    dfs(1);
    printf("%d",ans*2);
    //system("pause");
    return 0;
}
