#include<cstdio>
#include<climits> 
#include<iostream>
#include<string> 
#include<cstring>
#include<algorithm>
using namespace std;
string s,l,w;
const int N=105;
char ch[N];
int num[N];
int cnt1[10],cnt2[10];//栈外 栈内 
int get(char a)
{
    if (a=='+') return 1;
    if (a=='-') return 2;
    if (a=='*') return 3;
    if (a=='/') return 4;
    if (a=='^') return 5;
    if (a=='(') return 6;
    if (a==')') return 0;
}
void solve()
{
     int i,j,t,in,out;
     char now;
     int t1,t2;
	 t1=t2=0;
     memset(ch,0,sizeof(ch));
     memset(num,0,sizeof(num));
     s=w;
     s+=")";
     ch[++t2]='(';
     int len=s.length();
     for(i=0;i<len;++i)
      if(s[i]>='0' && s[i]<='9')//数字入栈 
	  {
	     j=i;
		 t=0;
		 while(j<len && s[j]>='0' && s[j]<='9')
		 {
		   t=t*10;
		   t+=s[j]-'0';
		   j++;
		 } 
		 i=j-1;
		 num[++t1]=t;
	  }
	  else 
	  {
	      in=get(ch[t2]);
	      out=get(s[i]);
	      if(out==0)//右括号 
	      {
	         while(t2>0 && (ch[t2]!='(')) //寻找左括号
			 {
			    now=ch[t2--];
				int b=num[t1--];
				int a=num[t1--];
				if(now=='+') a+=b;
				if(now=='-') a-=b;
				if(now=='*') a*=b;
				if(now=='/') a/=b;
				if(now=='^') 
				{
				  t=1;
				  for(j=1;j<=b;++j)
				   t=t*a;
				  a=t;
				} 
				num[++t1]=a;
			 }
			 t2--; 
		  }  
	      else if(cnt1[out]<=cnt2[in])
	      {
			while(t2>0 && cnt1[out]<=cnt2[in]) //栈外比栈内优先级低 
			 {
			    now=ch[t2--];
				int b=num[t1--];
				int a=num[t1--];
				if(now=='+') a+=b;
				if(now=='-') a-=b;
				if(now=='*') a*=b;
				if(now=='/') a/=b;
				if(now=='^') 
				{
				  t=1;
				  for(j=1;j<=b;++j)
				   t=t*a;
				  a=t;
				} 
				num[++t1]=a;
				in=get(ch[t2]); 
			 }
		    ch[++t2]=s[i];
		  }
	      else if(cnt1[out]>cnt2[in]) ch[++t2]=s[i];//入栈 
	  }
      printf("%d",num[1]);
}
int main()
{ 
	 int i,len;
	 cin>>s;
	 l="0";//正负号前加前导0 
	 len=s.length();
	 for(i=0;i<len;++i)
	 {
	   if(((i==0)&&((s[i]=='+')||(s[i]=='-')))||((i>=1)&&(s[i-1]=='(')&&((s[i]=='+')||(s[i]=='-'))))
	   {
	      w+=l;
	      w+=s[i];
	   }
	   else w+=s[i];
	 } 
	 cnt1[1]=cnt2[1]=cnt1[2]=cnt2[2]=1;
	 cnt1[3]=cnt2[3]=cnt1[4]=cnt2[4]=2;
	 cnt1[5]=4;cnt2[5]=3;//^特殊，先算栈内 
	 cnt1[6]=5;cnt2[6]=0;//无条件加入左括号 
	 solve();
	// system("pause");
	 return 0; 
} 
