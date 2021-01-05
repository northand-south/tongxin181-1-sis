#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct Node//monkey
{
    int number;//������
    struct Node *pNext;
}NODE,*PNODE;
/*����ѭ����������m�����ӡ�����ָ������ͷ����ָ��*/
PNODE create_list(int m);
void function(PNODE p,int n);
int main()
{
    int m;//���ӵ���Ŀ
    int n;//���ӱ����Ĵ�С
    printf("��������ӵ���Ŀ�ͱ���:");
    scanf("%d%d",&m,&n);
    PNODE p=NULL;
    p=create_list(m);
    function(p,n);
}
PNODE create_list(int m)
{
    int i;
    PNODE pHead=(PNODE)malloc(sizeof(NODE));//����ͷ���
    if(NULL==pHead)
    {
        printf("��̬�ڴ����ʧ�ܣ�");
        exit(-1);
    }
    pHead->pNext=NULL;
    PNODE pTail=pHead;//����ʼ��ָ��β����ָ��
    for(i=0;i<m;++i)
    {
        PNODE p=(PNODE)malloc(sizeof(NODE));
        if(NULL==p)
        {
            printf("��̬�ڴ����ʧ�ܣ�");
            exit(-1);
        }
        p->number=i+1;
        pTail->pNext=p;
        p->pNext=NULL;
        pTail=p;
    }
    pTail->pNext=pHead->pNext;//β���ָ���׽��
    free(pHead);
    return pTail->pNext;//�����׽��ĵ�ַ
}
void function(PNODE p,int n)
{
    int i=0;
    int j=0;
    for(p;p!=p->pNext;p=p->pNext)
    {
        i++;
        if(i==n-1)
        {
            j++;
            PNODE q=p->pNext;
            p->pNext=q->pNext;
            free(q);
            i=0;
        }
    }
    printf("���ջ�ѡ�ĺ��Ӵ������Ϊ��%d\n",p->number);
    return;
}