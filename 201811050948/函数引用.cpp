
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
printf("��������λ��n,m: ");
scanf("%d%d",&n,&m);
int c=fun(n,m);
printf("���Ϊ:%d",c);
printf("\n");
return 0;
}