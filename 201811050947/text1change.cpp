#include <iostream>
using namespace std;
int fun1(int a,int b) //��ֵ����
{
  int m,n,p,q,c;
  m=a%10;  //a�ĸ�λ
  n=a/10;  //a��ʮλ
  p=b%10;  //b�ĸ�λ
  q=b/10;  //b��ʮλ
  c=q+n*10+100*p+1000*m;
  return c;
}
int fun3(int &a,int &b) //���ô���
{
  int m,n,p,q,c;
  m=a%10;  //a�ĸ�λ
  n=a/10;  //a��ʮλ
  p=b%10;  //b�ĸ�λ
  q=b/10;  //b��ʮλ
  c=q+n*10+100*p+1000*m;
  return c;
}
int fun2(int *a,int *b) //ָ�봫��
{
  int m,n,p,q,c;
  m=*a%10;  //a�ĸ�λ
  n=*a/10;  //a��ʮλ
  p=*b%10;  //b�ĸ�λ
  q=*b/10;  //b��ʮλ
  c=q+n*10+100*p+1000*m;
  return c;
}
main()
{
  int a,b,n1,n2,n3;
  cout<<"a=" ;
  cin>>a;
  cout<<"b=" ;
  cin>>b;
  n1=fun1(a,b);
  cout<<"��ֵ���ݣ� n1="<<n1<<endl;
  n2=fun2(&a,&b);
  cout<<"���ô��ݣ� n2="<<n2<<endl;
  n3=fun3(a,b);
  cout<<"ָ�봫�ݣ� n3="<<n3<<endl;
}