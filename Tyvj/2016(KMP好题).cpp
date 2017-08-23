#include<cstdio> 
#include<iostream>
#include<algorithm>
#include<cstring> 
using namespace std; 
const int N=10010;
char s[N];
char st[205][N]; 
int l[N],r[N],ll[N],p[N]; 
int main()
{ 
      int i,j,k,m; 
      int ans=0; 
      scanf("%s",s+1);
      int len=strlen(s+1);
      scanf("%d",&m);
      for(i=1;i<=m;++i)
      {
        scanf("%s",st[i]+1);
        ll[i]=strlen(st[i]+1); 
        ll[i+m]=ll[i]; 
        k=1; 
        for(j=ll[i];j>=1;--j)
         st[i+m][k++]=st[i][j];//逆串 
      } 
      for(i=1;i<=m;++i)
      {
        if(ll[i]==1) continue;
        j=0;
        for(k=2;k<=ll[i];++k)
        {
          while(j>0 && st[i][j+1]!=st[i][k]) j=p[j];
          if(st[i][j+1]==st[i][k]) j++;
          p[k]=j; 
        } 
        j=0;
        for(k=1;k<=len;++k)
        {
          while(j>0 && st[i][j+1]!=s[k]) j=p[j];
          if(st[i][j+1]==s[k]) j++;
          l[k]=j; 
        } 
        j=0; 
        for(k=2;k<=ll[i+m];++k)
        {
          while(j>0 && st[i+m][j+1]!=st[i+m][k]) j=p[j];
          if(st[i+m][j+1]==st[i+m][k]) j++;
          p[k]=j; 
        } 
        j=0; 
        for(k=len;k>=1;--k)
        {
          while(j>0 && st[i+m][j+1]!=s[k]) j=p[j];
          if(st[i+m][j+1]==s[k]) j++;
          r[k]=j; 
        }
        for(k=1;k<=len;++k)
         l[k]=max(l[k],l[k-1]);//向左匹配最大
        for(k=len;k>=1;--k)
         r[k]=max(r[k],r[k+1]);//向右匹配最大
        for(k=1;k<=len-1;++k)
         if(l[k]+r[k+1]>=ll[i]) {ans++;break;}  
      } 
      printf("%d",ans); 
      //system("pause");  
      return 0; 
} 

