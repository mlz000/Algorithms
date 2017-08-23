#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=300;
char s[N];
int a[N],b[N];
int main()
{
     int i,j,k;
	 scanf("%s",s);
     int l1=strlen(s);
	 int l=0; 
	 int flag=-1;
	  k=1;
     for(i=0;i<l1;++i)
     {
	   if(s[i]=='+')
	   {
	     l=max(l,i-flag-1);
		 for(j=i-1;j>=flag+1;--j)
		  {
				a[k]+=s[j]-'0';
				if(a[k]>=10) {a[k+1]+=a[k]/10;a[k]=a[k]%10;}
				k++;
		  }
		  if(a[l+1]!=0) l++;
	     flag=i; 
	     k=1;
	   }
	   if(s[i]=='-')
	   {
	     for(j=i-1;i>=flag+1;--j)
	       {
				a[k]-=s[j]-'0';
		        while(a[k]<0) {a[k]=a[k]+10;a[k+1]=a[k+1]-1;} 
		   }
	     flag=i;
	     k=1;
	   }
	 }
	 printf("%d\n",flag); 
     if(s[flag]=='-')
      for(i=l1-1;i>flag;--i)
       {
			a[i]-=s[i]-'0';
			while(a[i]<0) {a[i]+=10;a[i+1]=a[i+1]-1;}
	   }
	else 
	  for(i=l1-1;i>flag;--i)
	   {
	      a[i]+=s[i]-'0';
	      while(a[i]>=10) {a[i]=a[i]%10;a[i+1]=a[i+1]+a[i]/10;}
	   }
	   flag=true;
	   for(i=l;i>=1;--i)
	    {
		  if(a[i]!=0) {j=i;printf("%d",a[i]);break;}
	    }
	    for(i=j-1;i>=1;--i)
	     printf("%d",a[i]);
	   system("pause"); 
	   return 0;
}
