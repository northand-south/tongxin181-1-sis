#include <iostream>
#include <stdlib.h>
using namespace std;
struct num
{
    int number;
    struct num *next;
};
int SelectMonkey(int m,int n);
int main()
{
    int m,n;
    cout<<"���������������m������Сn:";
    cin>>m>>n;
    cout<<"����"<<m<<"�����ӣ�ÿ������"<<n<<"�����ķ��������Ϊ�����ĺ�����"<<SelectMonkey(m,n);
    return 0;
}

int SelectMonkey(int m,int n)
{
    struct num *p,*p1,*head,*temp;
    int i=0,flag;
    p=(struct num*)malloc(sizeof(struct num));
    head=p;
    if(n==1)
        return m;
    while(i<m)
    {
        p1=p;
        p->number=i+1;
        p=(struct num*)malloc(sizeof(struct num));
        p1->next=p;
        i++;
    }
    p1->next=NULL;   //�γɵ�������
    p=head;
    i=0;
    flag=0;
    while(i!=m-1)
    {
        if(flag==n-1)
        {
            if(p==head)   //��ɾ���Ľڵ�λ�ڽڵ�ͷʱ
            {
                head=head->next;
                p=head;
            }
            else if(p->next==NULL) //�����ڵ�λ�ڽڵ�βʱ
            {
                temp->next=NULL;
                p=head;
            }
            else                   //λ���м�
            {
                temp->next=p->next;
                p=p->next;
            }
            i++;
            flag=0;
        }
      //��ָ�뵽������β��ʱ��ʹ��ָ��ͷָ�롣
        if(p->next==NULL)
        {
            p=head;
        }
        else
        {
            temp=p;
            p=p->next;
        }
        flag++;
    }
    return head->number;
}