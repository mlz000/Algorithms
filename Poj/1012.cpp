#include<iostream>
#include<cstdio> 
using namespace std;
int Joseph[14];
int main()
{
      int k;
      while(scanf("%d",&k)&&k)
      {
           if(Joseph[k])
           {
				printf("%d\n",Joseph[k]);
                 continue;
           }
           int n=2*k;  //������
           int ans[30]={0};  //��i��ɱ����Ӧ��ǰ�ֵı��Ϊans[i]����
           int m=1;    //��������ٵı���
           for(int i=1;i<=k;i++)  //����
           {
                 ans[i]=(ans[i-1]+m-1)%(n-i+1);   //n-iΪʣ�����
                 if(ans[i]<k)  //�Ѻ���ɱ����,mֵ��������
                 {
                      i=0;
                      m++;  //ö��mֵ
				 }
           }
           Joseph[k]=m;
           printf("%d\n",m);
      }
      //system("pause");
      return 0;
}

