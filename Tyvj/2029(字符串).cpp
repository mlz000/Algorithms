#include<cstdio>//e出现次数最多，对应即可 
#include<iostream> 
#include<climits>
#include<queue> 
#include<cstring> 
#include<algorithm> 
#include<cmath> 
using namespace std;
const int N=50010;
char s[N]; 
long long a[30]; 
int main()
{ 
      int i,j,t,n,pos;
      char ch;
      j=0; 
      while((scanf("%c",&ch))!=EOF) 
      {
        s[++j]=ch; 
       if(ch>='a' && ch<='z') a[ch-'a'+1]++;
       else if(ch>='A' && ch<='Z') a[ch-'A'+1]++; 
      } 
      int MAX=0; 
      for(i=1;i<=26;++i)
       if(a[i]>MAX) {pos=i;MAX=a[i];} 
      t=5-pos; 
      for(i=1;i<=j;++i)
      {
        if(s[i]>='a' && s[i]<='z') 
        {
            if(s[i]+t>'z') s[i]=s[i]+t-26; 
            else if(s[i]+t<'a') s[i]=s[i]+t+26;  
            else s[i]=s[i]+t; 
            printf("%c",s[i]);
        }
        else if(s[i]>='A' && s[i]<='Z')
        {
          if(s[i]+t>'Z') s[i]=s[i]+t-26;
          else if(s[i]+t<'A') s[i]=s[i]+t+26; 
          else s[i]=s[i]+t;
          printf("%c",s[i]); 
        } 
        else printf("%c",s[i]); 
      }   
    //  system("pause"); 
      return 0;
}
