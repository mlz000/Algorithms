#include<cstdio>
#include<iostream>
#include<string> 
#include<algorithm>
#include<cstring> 
using namespace std;
const int N=205,K=205;
int a[N]; 
int main()
{
	 int i,j,n,k;
     int m=0;  
	 scanf("%d%d",&n,&k);
	 int x; 
	 for(i=1;i<=n;++i)
	 {
	   int num=0; 
	   while(1) 
	   {
			scanf("%d",&x);
	        if(x!=0) 
			 {
               num++; 
			 } 
			else break;						
	   } 
	   if(num>=k) m++; 
	 } 
        printf("%d",m); 
	//	system("pause");
		return 0; 
} 
