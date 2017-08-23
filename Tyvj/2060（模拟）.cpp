#include<iostream>
#include<stack> 
#include<cstdio> 
#include<cstring> 
#include<climits> 
#include<algorithm>
using namespace std; 
const int N=10005;
char s[100]; 
long long a[300],sum[N]; 
int main()
{
     int i,j,n; 
     long long t; 
     scanf("%I64d%d",&t,&n);
     for(i=1;i<=26;++i)
      {
        scanf("%d",&a[i]);
        a[i+'a'-'A']=a[i];
      }
     for(i=1;i<=n;++i)
     {
       scanf("%s",s);
       for(j=0;j<strlen(s);++j)
          sum[i]+=a[s[j]-'A'+1]; 
     } 
     long long tot=0;int ans=0;
     sort(&sum[1],&sum[n+1]);
     for(i=1;i<=n;++i)
     {
       tot+=sum[i];
       if(tot>t) break; 
       ans++; 
     } 
     if(tot>t) printf("No\n%d",ans);
     else printf("Yes\n%I64d",t-tot); 
     //system("pause"); 
     return 0;
}

