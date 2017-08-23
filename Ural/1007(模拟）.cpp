#include<algorithm>
#include<iostream> 
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
const int N=1005;
int n;
bool count(string S)
{
     int tmp=0;
     for(int i=1;i<=n;++i)
     if(S[i-1]=='1')      tmp+=i;
     return (tmp==0||(tmp%(n+1)==0));
}
int main()
{
    scanf("%d",&n);
    string s;
    while(cin>>s)
    {
       bool flag=false;
       if(s.length()==n && count(s)) flag=true;
       else 
       {
            if(s.length()==n)
            {
              for(int i=0;i<n;++i)
              {
                 if(s[i]=='1')
                 {
                    s[i]='0';
                    if(count(s)) {flag=true;break;}
                    s[i]='1';
                 }
              }
            }
            else if(s.length()==n+1)
            {
               for(int i=0;i<n;++i)
               {
                  char c=s[i]; 
                  s.erase(i,1);
                  if(count(s)) {flag=true;break;}
                  if(c=='0') s.insert(i,"0");
                  else s.insert(i,"1"); 
               }
            
            }
            else if(s.length()==n-1)
            {
               for(int i=0;i<n;++i)
               {
                  s.insert(i,"1");
                  if(count(s)) {flag=true;break;}
                  s.erase(i,1);
                  s.insert(i,"0");
                  if(count(s)) {flag=true;break;}
                  s.erase(i,1);
               }
            }
       }   
       cout<<s<<endl;
    }
    return 0;
} 
