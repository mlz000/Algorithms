#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long n;
    scanf("%I64d",&n);
    long long num=0;
    while(n>0)
    {
	  num=num+n/5;
      n=n/5;	  
	}
    printf("%I64d",num);
    //system("pause");
    return 0;
}
