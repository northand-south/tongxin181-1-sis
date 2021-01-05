
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define maxsize 100

int main()
{
	int M,N,c;
	int i,j,m,n,k=0;
	char a[maxsize][maxsize]={0};
	char (*p)[4]=0;
	cout<<"输入行数和列数：";
	cin>>M>>N;
	printf("输入数据：\n");
	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
            cin>>a[i][j];  
        }
		
    }

	cout<<"输入周期数：";
	cin>>c;	
while(k<c)
{
	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
           if(a[i][j]=='X')
		   {	
			   {	if(a[i-1][j]='O')
						a[i-1][j]='A';
					if(a[i+1][j]='O')		
						a[i+1][j]='A';	   
					if(a[i][j+1]='O')
						a[i][j+1]='A';
					if(a[i][j-1]='O')
						a[i][j-1]='A';		
				 }		
		   }
        }
		
    }
	k++;
for(m=0; m<M; m++)
{
	for(n=0; n<N; n++)
	{
		if(a[m][n]=='A')
		a[m][n]='X';
	}
}	
}

	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
            cout<<a[i][j];  
        }
		cout<<endl;
	}

}
