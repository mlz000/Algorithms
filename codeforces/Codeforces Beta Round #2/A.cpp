#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
const int N=1005;
map<string,int>f,g;
string s[N];
int a[N];
int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)   cin>>s[i]>>a[i],f[s[i]]+=a[i];
    int MAX=0;
    for(i=1;i<=n;++i)   if(MAX<f[s[i]]) MAX=f[s[i]];
    for(i=1;f[s[i]]<MAX || (g[s[i]]+=a[i])<MAX;++i);
    cout<<s[i];
    return 0;
} 
