#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=15;
char s[N][N];
int main()
{
      int i,j,k,T,n;
      scanf("%d",&T);
      for(i=1;i<=T;++i)
      {
         scanf("%d",&n);
         memset(s,0,sizeof(s));
         for(j=0;j<n;++j)
          scanf("%s",s[j]);
         for(j=0;j<n;++j)
          for(k=0;k<n;++k)
          {
           if(s[j][k]=='.')
           {
            for(char c='A';c<='Z';c++)
            {
             bool flag=true;
             if(j>0 && s[j-1][k]==c) flag=false;
             if(j<n-1 && s[j+1][k]==c) flag=false;
             if(k>0 && s[j][k-1]==c) flag=false;
             if(k<n-1 && s[j][k+1]==c) flag=false;
             if(flag) {s[j][k]=c;break;}
            }
           }
         }
         printf("Case %d:\n",i);
         for(j=0;j<n;++j)
          printf("%s\n",s[j]);   
      } 
      //system("pause");
      return 0;
}
