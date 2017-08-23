#include<cstdio>
#include<iostream>
#include<string> 
#include<algorithm>
using namespace std;
int main()
{
   long long n,ans;
   cin>>n; 
   ans= (1+n*n)*(n*n)/2/n;
   cout<<ans<<endl;
   //system("pause");
   return 0; 
} 
