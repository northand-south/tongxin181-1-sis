
#include <stdio.h>
int fun(int &a,int &b)
{
int c=(b%10)+10*(a/10)+100*(b/10)+1000*(a%10);
return c;
}
int main() 
{
int n;
int m;
printf("请输入两位数n,m: ");
scanf("%d%d",&n,&m);
int c=fun(n,m);
printf("结果为:%d",c);
printf("\n");
return 0;
}