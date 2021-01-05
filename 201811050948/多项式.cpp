#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STACK_INIT_SIZE 1000
typedef struct             //����һ����ջ
{
 char *base;
 char *top;
 int stacksize;
}SqStack;
int InitStack(SqStack *s)       //��ջ����ռ䣬��ʼ��ջ
{
    (*s).base=(char*)malloc(STACK_INIT_SIZE*sizeof(char));
    if(!((*s).base))
        exit(0);
    s->top=s->base;
    s->stacksize=STACK_INIT_SIZE;
    return 1;
}
int Push(SqStack *s,char *ch)    //�ѽ��յ��ĵ�һ��Ԫ��ѹ��ջ
{
  if(s->top-s->base>=STACK_INIT_SIZE)
    return 0;
     *((*s).top)=*ch;
    (*s).top++;
    return 1;
}
void  Pop(SqStack *s,char *ch){      //ɾ��ջ��Ԫ��
    s->top--;
*ch=*(s->top);
}
char* Gettop(SqStack *s)            //�õ�ջ��Ԫ��
{
 if(s->top!=s->base)


    return (*s).top-1;
}
int In(char *c)          //�ж����յ������ǲ����ַ�
{
    switch(*c)
    {
    case'+':
    case'-':
    case'*':
    case'/':
    case'(':
    case')':
    case'#':return 1;
    default:return 0;
    }
}
char *Operate(char *a,char *theta,char *b)   //����ջ��Ԫ�ؽ�������
{
   char *c;
   *a=*a-48;
   *b=*b-48;
   c=(char *)malloc(sizeof(char));
    switch(*theta)
    {
    case'+':
        *c=*a+*b+48;
        break;
    case'-':
        *c=*a-*b+48;
        break;
    case'*':
        *c=(*a)*(*b)+48;
        break;
    case'/':*c=(*a)/(*b)+48;break;
    }
    return c;
}
char Precede(char *ch1,char *ch2)     //�ж���������Ⱥ�˳��
{
     if(*ch1=='+')
     {
     if(*ch2=='+')return '>';
     if(*ch2=='-')return '>';
     if(*ch2=='*')return '<';
     if(*ch2=='/')return '<';
     if(*ch2=='(')return '<';
     if(*ch2==')')return '>';
     if(*ch2=='#')return '>';
     }
     if(*ch1=='-')
     {
     if(*ch2=='+')return '>';
     if(*ch2=='-')return '>';
     if(*ch2=='*')return '<';
     if(*ch2=='/')return '<';
     if(*ch2=='(')return '<';
     if(*ch2==')')return '>';
     if(*ch2=='#')return '>';
     }
     if(*ch1=='*')
     {
     if(*ch2=='+')return '>';
     if(*ch2=='-')return '>';
     if(*ch2=='*')return '>';
     if(*ch2=='/')return '>';
     if(*ch2=='(')return '<';
     if(*ch2==')')return '>';
     if(*ch2=='#')return '>';
     }
          if(*ch1=='/')
     {
     if(*ch2=='+')return '>';
     if(*ch2=='-')return '>';
     if(*ch2=='*')return '>';
     if(*ch2=='/')return '>';
     if(*ch2=='(')return '<';
     if(*ch2==')')return '>';
     if(*ch2=='#')return '>';
     }
          if(*ch1=='(')
     {
     if(*ch2=='+')return '<';
     if(*ch2=='-')return '<';
     if(*ch2=='*')return '<';
     if(*ch2=='/')return '<';
     if(*ch2=='(')return '<';
     if(*ch2==')')return '=';
     }
          if(*ch1==')')
     {
     if(*ch2=='+')return '>';
     if(*ch2=='-')return '>';
     if(*ch2=='*')return '>';
     if(*ch2=='/')return '>';
     if(*ch2==')')return '>';
     if(*ch2=='#')return '>';
     }
     if(*ch1=='#')
     {
     if(*ch2=='+')return '<';
     if(*ch2=='-')return '<';
     if(*ch2=='*')return '<';
     if(*ch2=='/')return '<';
     if(*ch2=='(')return '<';
     if(*ch2=='#')return '=';
     }
}
int main()
{
    char *theta,*ch,*x,*c;
    char *a,*b;
    SqStack OPND;
    SqStack OPTR;
    InitStack(&OPND);    //����һ�������ֵ�ջ
    InitStack(&OPTR);     //����һ��������������ŵ�ջ
    c=(char *)malloc(sizeof(char));   //�����ڴ�
    ch=(char *)malloc(sizeof(char));
    x=(char *)malloc(sizeof(char));
    theta=(char *)malloc(sizeof(char));
    a=(char *)malloc(sizeof(char));
    b=(char *)malloc(sizeof(char));
    *c='#';
    Push(&OPTR,c);
    printf("��������#��β�ı��ʽ\n");
    *ch=getchar();
    while((*ch)!='#'||(*(Gettop(&OPTR)))!='#'){  //�������ֹͣ����
        if(!In(ch)){
            Push(&OPND,ch);
            printf("ѹ��OPNDջ  %d\n",*ch);
            *ch=getchar();
        }
        else
            switch(Precede(Gettop(&OPTR),ch))     //ͨ���ȽϽ��յ��ַ�����������
        {
         case'<':
         Push(&OPTR,ch);
         printf("ѹ��OPTRջ   %c\n",*ch);
         *ch=getchar();
         break;
         case'>':
         Pop(&OPTR,theta);
         printf("ѹ��ǰ%d %d\n",*b,*a);
         Pop(&OPND,b);
         Pop(&OPND,a);
         printf("ɾ����OPND��ͷ%d %d\n",*b,*a);
         Push(&OPND,Operate(a,theta,b));
         printf("����� %d\n",*theta);
         break;
         case'=':
            Pop(&OPTR,x);
            *ch=getchar();
            break;}
    }
    printf("\n\n\n");
    printf("������= %d",(*Gettop(&OPND)-48));
}
