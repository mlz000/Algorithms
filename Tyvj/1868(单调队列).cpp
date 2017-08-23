#include<cstdio> //单调队列 
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=5100000;
char s[N];
int num[N],ans[N]; 
int q[N];
int main()
{
   int len,l,r,i,n;
   scanf("%s",s);  
   scanf("%d",&n);
   len=strlen(s);
   for(i=0;i<len;++i)
    num[i]=s[i]-'0';
   q[0]=num[0];l=0;r=0;
   for(i=1;i<n;++i)
   {
      while(num[i]<q[r]) r--;
      q[++r]=num[i];
   } 
   for(i=n;i<len;++i)
   {
     if(num[i]<q[r] && r>=l) r--;
     q[++r]=num[i];
     ans[i-n]=q[l++];
   }
   bool flag=false;
   for(i=0;i<len-n;++i) 
   {
    if(ans[i]!=0) flag=true;
	if((ans[i]==0 && flag)||ans[i]>0) printf("%d",ans[i]); 
   }  
   return 0;
}

