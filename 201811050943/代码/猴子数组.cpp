#include<stdio.h>
void main()
{
	int a[10000];
	int m,n,x,b,i;
	printf("��������Ӹ���: ");
	scanf("%d",&m);
	printf("������Ҫɾ���ĺ��ӱ��: ");
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
				printf("���Ӵ������Ϊ:%d\n",i);
				}
