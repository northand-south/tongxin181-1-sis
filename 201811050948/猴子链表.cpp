#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct Node//monkey
{
    int number;//������
    struct Node *pNext;
}NODE,*PNODE;
/*����ѭ����������m�����ӡ�����ָ������ͷ����ָ��*/
PNODE create_list(int len);
void function(PNODE p,int baoshu);
int main()
{
    int len;//���ӵ���Ŀ
    int baoshu;//���ӱ����Ĵ�С
    printf("��������ӵ���Ŀ:");
    scanf("%d",&len);
    printf("�����뱨���Ĵ�С:");
    scanf("%d",&baoshu);
    PNODE p=NULL;
    p=create_list(len);
    function(p,baoshu);
}
PNODE create_list(int len)
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
    for(i=0;i<len;++i)
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
void function(PNODE p,int baoshu)
{
    int i=0;
    int j=0;
    for(p;p!=p->pNext;p=p->pNext)
    {
        i++;
        if(i==baoshu-1)
        {
            j++;
            PNODE q=p->pNext;
            p->pNext=q->pNext;
            printf("��%d���˳��ĺ��ӱ��Ϊ��%d\n",j,q->number);
            free(q);
            i=0;
        }
    }
    printf("���ջ�ѡ�ĺ��Ӵ������Ϊ��%d\n",p->number);
    return;
}