#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;
const int N=205;
const char t[5]={' ','W','I','N','G'};
int h[N],num[5];
bool dp[N][N][5];
char s[N];
vector<int> a[5][5];
int main()
{
    int i,j,k,n,p,q,r;
    h['W']=1,h['I']=2,h['N']=3,h['G']=4;
    for(i=1;i<=4;++i)   scanf("%d",&num[i]);
    for(i=1;i<=4;++i)
     for(j=1;j<=num[i];++j)
     {
        scanf("%s",s+1);
        a[h[s[1]]][h[s[2]]].push_back(h[t[i]]); 
     }
    scanf("%s",s+1);
    n=strlen(s+1);
    for(i=1;i<=n;++i)   dp[i][i][h[s[i]]]=true;
    for(j=2;j<=n;++j)
     for(i=1;i+j-1<=n;++i)
      for(k=i;k<i+j-1;++k)
       for(p=1;p<=4;++p)
        if(dp[i][k][p])
         for(q=1;q<=4;++q)
          if(dp[k+1][i+j-1][q])
           for(r=0;r<a[p][q].size();++r)
           dp[i][i+j-1][a[p][q][r]]=true; 
    bool flag=false;       
    for(i=1;i<=4;++i) if(dp[1][n][i])   flag=true,printf("%c",t[i]);       
    if(!flag)   printf("The name is wrong!");
    return 0;
}
