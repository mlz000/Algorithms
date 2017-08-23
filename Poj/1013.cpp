#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=20;
char l1[N],r1[N],s[N];
int l[N],r[N],w[N];
bool t[N];
int main()
{
      int i,j,n,len;
      int cnt=0;
      scanf("%d",&n);
      while(n--)
     {
          for(j=1;j<=3;++j)
	   {
		  scanf("%s %s %s",l1,r1,s);
          len=strlen(l1);
	      for(i=0;i<len;++i)
	      {
		     l[i]=l1[i]-'A';
		     r[i]=r1[i]-'A';
		  }
	      if(s[0]=='e') 
		  {
				  for(i=0;i<len;++i) 
	                      {
						       t[l[i]]=true;
							   t[r[i]]=true; 
						  }
		  }
	      if(s[0]=='u')
	      {
			  cnt++;	
		      for(i=0;i<len;++i)
		      {
			      if(!t[l[i]]) w[l[i]]++;
			      if(!t[r[i]]) w[r[i]]--;
			  }
		  }
	     if(s[0]=='d')
	      {
			  cnt++;	
		      for(i=0;i<len;++i)
		      {
			      if(!t[l[i]]) w[l[i]]--;
			      if(!t[r[i]]) w[r[i]]++;
			  }
		  }
	  }
		  for(i=0;i<12;++i)
		  {
		     if(!t[i])
		     {
			    if(w[i]==cnt) printf("%c is the counterfeit coin and it is heavy.\n",i+'A');
			    if(w[i]==-cnt) printf("%c is the counterfeit coin and it is light.\n",i+'A');
			 }
		  } 
		  memset(w,0,sizeof(w));
		  memset(t,false,sizeof(t));
		  cnt=0;
	 }
	 //system("pause");
     return 0;
} 
