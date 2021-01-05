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
    cout<<"依次输入猴子数量m报数大小n:";
    cin>>m>>n;
    cout<<"按照"<<m<<"个猴子，每数到第"<<n<<"个数的方法，输出为大王的猴子是"<<SelectMonkey(m,n);
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
    p1->next=NULL;   //形成单向链表
    p=head;
    i=0;
    flag=0;
    while(i!=m-1)
    {
        if(flag==n-1)
        {
            if(p==head)   //当删除的节点位于节点头时
            {
                head=head->next;
                p=head;
            }
            else if(p->next==NULL) //当初节点位于节点尾时
            {
                temp->next=NULL;
                p=head;
            }
            else                   //位于中间
            {
                temp->next=p->next;
                p=p->next;
            }
            i++;
            flag=0;
        }
      //当指针到达链表尾部时，使其指向头指针。
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