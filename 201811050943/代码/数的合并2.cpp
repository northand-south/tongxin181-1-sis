#include <stdio.h>
void fun(int &a, int &b,int &c)
{	
	c=(b/10)+10*(a/10)+100*(b%10)+1000*(a%10);
}
void main() 
{
int a;
int b;
int c;
printf("请输入两位数a,b: ");
scanf("%d%d",&a,&b);
fun(a,b,c);
printf("结果为:%d",c);
}
