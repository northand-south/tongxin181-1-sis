#include<stdio.h>
void fun(int*a,int*b,int*c)
{
* c=(*b%10)+10*(*a/10)+100*(*b/10)+1000*(*a%10);
}
void main()
{
int a,b,c;
printf("��������λ��a,b:");
scanf("%d%d",&a,&b);
fun(&a,&b,&c);
printf("%d\n",c);
}
