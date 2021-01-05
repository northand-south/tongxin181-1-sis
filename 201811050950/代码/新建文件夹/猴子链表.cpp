#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct Node//monkey
{
    int number;//保存编号
    struct Node *pNext;
}NODE,*PNODE;
/*创建循环链表，容纳m个猴子。返回指向链表头结点的指针*/
PNODE create_list(int m);
void function(PNODE p,int n);
int main()
{
    int m;//猴子的数目
    int n;//猴子报数的大小
    printf("请输入猴子的数目和报数:");
    scanf("%d%d",&m,&n);
    PNODE p=NULL;
    p=create_list(m);
    function(p,n);
}
PNODE create_list(int m)
{
    int i;
    PNODE pHead=(PNODE)malloc(sizeof(NODE));//创建头结点
    if(NULL==pHead)
    {
        printf("动态内存分配失败！");
        exit(-1);
    }
    pHead->pNext=NULL;
    PNODE pTail=pHead;//创建始终指向尾结点的指针
    for(i=0;i<m;++i)
    {
        PNODE p=(PNODE)malloc(sizeof(NODE));
        if(NULL==p)
        {
            printf("动态内存分配失败！");
            exit(-1);
        }
        p->number=i+1;
        pTail->pNext=p;
        p->pNext=NULL;
        pTail=p;
    }
    pTail->pNext=pHead->pNext;//尾结点指向首结点
    free(pHead);
    return pTail->pNext;//返回首结点的地址
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
    printf("最终获选的猴子大王编号为：%d\n",p->number);
    return;
}