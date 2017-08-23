#include<cstdio>  //可以DP的水模拟 
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath> 
using namespace std;
const int N=100005;
int a[N];
char s[N];
int main()
{
    int i,j,n,m,ans=0; 
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    a[0]=-1; 
    for(i=1;i<=n;++i)
     a[i]=s[i-1]-'A'; 
    if(m==2)
    {
      int j=1; 
      for(i=1;i<=n;++i)
       {
            if(a[i]==a[i-1]) j++;
            else {ans+=(j%2) ? j/2 : j/2+1 ;j=1;} 
       } 
    } 
    if(m>2)
    {
       int j=1; 
       for(i=1;i<=n;++i)
        {
            if(a[i]==a[i-1])  j++;
            else {ans+=j/2;j=1;} 
        } 
        ans+=j/2; 
    } 
    printf("%d",ans);
    //system("pause"); 
    return 0;
}
