#include<cstdio>
#include<set> 
#include<iostream>
const int N=100005;
bool flag1,flag2;
using namespace std;
int main()
{
	 set<int> s1; 
     set<int> s2; 
     int a,i,j,n,m;
     scanf("%d",&n);
     for(i=1;i<=n;++i)
     {
	   scanf("%d",&a);
	   s1.insert(a);
	 }
	 scanf("%d",&n);
	 for(i=1;i<=n;++i)
     {
	   scanf("%d",&a);
	   s2.insert(a);
	 }
	 set<int>::iterator it1,it2;
	 if(s1.size()==s2.size()) flag1=true;
	 for(it1=s1.begin(),it2=s2.begin();it1!=s1.end(),it2!=s2.end();it1++,it2++)
	 {
	     if((*it1)!=(*it2)) {flag2=true;break;}
	 }
	 if(flag2) {printf("I'm confused!");system("pause");return 0;}
	 if(flag1) {printf("A equals B");system("pause");return 0;}
	 if(s1.size()>s2.size()) 
	 {
	   printf("B is a proper subset of A");
	 }
	 else printf("A is a proper subset of B");
	 system("pause");
	 return 0;
}
