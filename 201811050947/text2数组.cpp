#include <iostream>
#include <stdlib.h>
using namespace std;

int SelectMonkey(int *p,int m,int n);
main()
{
    int *p;
    int m,n,flag,temp;
    cout<<"���������������m������Сn:";
	while(1){
    cin>>m;
	cin>>n;
    p=(int *)malloc(sizeof(int)*m); //Ϊָ������ڴ棬����m��int�ʹ�С���ڴ�ռ�
    for(int i=0;i<m;i++)  //Ϊmֻ���ӱ�� 
        p[i]=i+1;
    cout<<"����"<<m<<"�����ӣ�ÿ������"<<n<<"�����ķ��������Ϊ�����ĺ�����"<<SelectMonkey(p,m,n)<<"��";
    }
    free(p);  //��p����ַ��ָ��ĵ�Ԫ�Ժ���ڴ���ͷ�
}
int SelectMonkey(int *p,int m,int n)
{
    int temp,flag,count;
    temp=0;
    count=m;  //��ʱ���ӵ����� 
     while(count!=1)
    {
        flag=1;         //������
        while(flag<n)   //����Ҫɾ���ĺ��ӵı��
        {
            if(temp>=m)
                temp=0;
            if(p[temp]!=0)
            {
                flag++;
            }
            temp++;
        }
        if(temp>=m)
            temp=0;
        while(temp<m&&p[temp]==0)
            {
                   temp++;
                   if(temp>=m)
                       temp=0;
            }      //������ɾ�����ӵı��
        p[temp]=0;   //ɾ�����ӵı�� 
        count-=1;    //ʣ�º��ӵĸ���-1
    }
    for(int i=0;i<m;i++)
    {
        if(p[i]!=0)
        {
            return p[i];
        }
    }
}