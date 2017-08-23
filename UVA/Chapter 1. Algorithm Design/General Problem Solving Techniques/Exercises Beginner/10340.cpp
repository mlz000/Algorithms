#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int N=100005;
char s[N],t[N];
int main()
{
      while(scanf("%s%s",s,t)!=EOF)
      {
        int ls=strlen(s);
        int lt=strlen(t);
        int flag=0;    
        for(int i=0;i<lt;++i)
        {
          if(flag==ls) break;
          else if(s[flag]==t[i]) flag++; 
        }
        if(flag==ls) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
      }
      //system("pause");
      return 0;
}
