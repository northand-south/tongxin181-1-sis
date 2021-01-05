
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<Windows.h>
#include<stdio.h>
 
void main()
{
	int a[5][9] = { { O, O, O, O,O,P,O,O,O }, { O, O, O, O,O,P,O,O,O }, { O, O, O, X,O,P,O,O,O } {O,O,O,O,O,P,O,O,O},{O,O,X,O,O,P,O,O,O}};

	int i=0,j=0;
	for ( i = 0; i < 5;i++)//Ñ°ÕÒ×î´óÖµ
	{
		for(j=0;j < 9;j++)
		{
			if(a[i][j]=X)
			{	
				if(a[i][j+1]!=P)
					a[i][j+1]=X;
                if(a[i][j-1]!=P)
			        a[i][j-1]=X;
                if(a[i-1][j]!=P)
				    a[i-1][j]=X;
                if(a[i+1][j]!=P)
				    a[i+1][j]=x;
			}
		}
	}
	for(i=0;i<5;i++)
	{
     	for(j=0;j<9;j++)
		{
     	printf("%c",&a[i][j]);
		}
		printf("\n");
	}
}
