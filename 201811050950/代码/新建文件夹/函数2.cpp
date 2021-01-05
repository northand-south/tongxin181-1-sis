#include <stdio.h>
int fun(int &a,int &b)
{
int c=(b%10)+10*(a/10)+100*(b/10)+1000*(a%10);
return c;
}
int main() 
{
int a;
int b;
printf("请输入两位数a,b: ");
scanf("%d%d",&a,&b);
int c=fun(a,b);
printf("结果为:%d",c);
printf("\n");
return 0;
}