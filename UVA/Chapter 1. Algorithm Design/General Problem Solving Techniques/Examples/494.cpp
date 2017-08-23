#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
 char   s[1000];
 int i,res,len;
 while(fgets(s,sizeof(s),stdin))
 {
  len=strlen(s);
  res=0;
  for(i=0;i<len-1;i++)
  {
   if(isalpha(s[i])&&!(isalpha(s[i+1])))
    res++;
  }
  printf("%d\n",res);
 }
 return 0;
}
