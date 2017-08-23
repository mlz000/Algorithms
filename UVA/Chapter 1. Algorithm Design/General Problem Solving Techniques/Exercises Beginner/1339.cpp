#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=105;
int a[26],b[26];
char s1[N],s2[N];
bool cmp(const char p,const char q)
{
     return p>q;
}
int main(void)
{
     int i;
     while(scanf("%s%s",s1,s2)!=EOF)
     {
         int len;
         len=strlen(s1);
         memset(a,0,sizeof(a));
         memset(b,0,sizeof(b));
         for(i=0; i<len; i++)
         {
             a[s1[i]-'A']++;
             b[s2[i]-'A']++;
         }
         sort(&a[0],&a[26],cmp);
         sort(&b[0],&b[26],cmp);
         if(!memcmp(a,b,sizeof(a)))
         printf("YES\n");
         else
         printf("NO\n");
     }
    // system("pause");
     return 0;
}
