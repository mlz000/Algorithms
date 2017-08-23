#include<cstdio>
#include<iostream>
#include<string> 
#include<algorithm>
using namespace std;
const int N=10005;
int a[N];
string s[N]; 
int main()
{
   int i,j,n,k;
   scanf("%d",&n);
   for(i=1;i<=n;++i)
	cin>>s[i]; 
   for(i=1;i<=n;++i)
    scanf("%d",&a[i]);
   sort(&a[1],&a[n+1]);
  sort(&s[1],&s[n+1]);
   for(i=1;i<=n;++i)
    cout<<s[i]<<' '<<a[i]<<endl; 
	//system("pause");
	return 0;		 
} 
