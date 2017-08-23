#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define MAXN 1005
int sum[26];
char f[MAXN];
char s[55][MAXN];
int main(void)
{
     int i,j,k,m,n,r,ans;
     scanf("%d",&n);
     while(n--)
     {
         int maxs;
         char ch;
         scanf("%d%d",&m,&k);
         for(i=0; i<m; i++)
         {
             scanf("%s",&s[i]);
             getchar();
         }
         ans=0;
         for(i=0; i<k; i++)
         {
             memset(sum,0,sizeof(sum));
             maxs=0;
             for(j=0; j<m; j++)
                 sum[s[j][i]-'A']++;
             for(r=0; r<26; r++)
                 if(sum[r]>maxs)
                 {
                     maxs=sum[r];
                     ch='A'+r;
                 }
             ans+=m-maxs;
             f[i]=ch;
         }
         for(i=0; i<k; i++)
             printf("%c",f[i]);
         printf("\n");
         printf("%d\n",ans);
     }
     //system("pause");
     return 0;
}
