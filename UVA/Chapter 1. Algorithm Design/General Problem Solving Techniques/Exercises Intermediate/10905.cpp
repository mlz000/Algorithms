#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const int N=55;
string s[N];
bool cmp(const string &p,const string &q)
{
    if(p.size()==q.size()) return p>q;
    return p+q>q+p;
}
int main()
{
      int i,n;
      while(scanf("%d",&n)&&n)
      {
        for(i=0;i<n;++i)
         cin>>s[i];
        sort(s,s+n,cmp);
        for(i=0;i<n;++i)
         cout<<s[i];
        printf("\n"); 
      }
      //system("pause");
      return 0;
}
