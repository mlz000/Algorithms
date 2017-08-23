#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=300;
char s[N];
int a[N];
int main()
{
     int i,pos,j,l,t,n,m;
     scanf("%s",s);
     l=strlen(s);
     j=1;
     int l1=0;
	 for(i=l-1;i>=0;--i)
     {
	    if(s[i]!='+') {a[j]+=s[i]-'0';j++;l1++;a[0]=max(l1,a[0]);}
	    if(s[i]=='+') {j=1;l1=0;}
	    if()
	 }
     for(i=1;i<=a[0];++i)
     {
        t=a[i]/10;
        a[i]=a[i]%10;
        a[i+1]=a[i+1]+t;
	 }
     if(t!=0) printf("%d",t);
     for(i=a[0];i>=1;--i)
     printf("%d",a[i]);
    // system("pause");
     return 0;
} 
