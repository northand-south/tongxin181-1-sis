#include<stdio.h>
void fun(int *a,int *b,int *c)
{
 *c =(*a%10)*1000+(*b%10)*100+(*a/10)*10+(*b/10); 
}

void main()
{
 int a,b,c;
 printf("请输入两位数a,b: ");
 scanf("%d%d",&a,&b);
 fun(&a,&b,&c);
 printf("%d",c);
}
