#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
int main()
{
     char s[101];
     int i,j,t;
    while(scanf("%s",s)!=EOF)
    {
         char dest[101]={'0'};
         int len=0;
         for(i=strlen(s)-1;i>1;i--)
         {
             int num=s[i]-'0';
             for(j=0;j<len||num;j++)                
             {
                t=num*10+(j<len?dest[j]-'0':0);
                dest[j]=t/8+'0';
                num=t%8;
             }
             len=j;
         }
         dest[j]='\0';
         printf("%s [8] = 0.%s [10]\n",s,dest);
    }
    return 0;
}


