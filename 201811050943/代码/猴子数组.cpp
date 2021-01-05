#include<stdio.h>
void main()
{
	int a[10000];
	int m,n,x,b,i;
	printf("请输入猴子个数: ");
	scanf("%d",&m);
	printf("请输入要删除的猴子编号: ");
	scanf("%d",&n);
	for(i=0;i<m;i++)
		a[i]=i+1;
	b=m;
	x=0;
	for(i=0;b!=1;i++)
	{
		if(a[i%m+1]!=-1)
		{
			x++;
		}
		
			if(x==n && a[i%m+1]!=-1)
			{
				a[i%m+1]=-1;
				b--;
				x=0;
			}
		}
		for(i=1;i<=m;i++)
			if(a[i]!=-1)
				printf("猴子大王编号为:%d\n",i);
				}
