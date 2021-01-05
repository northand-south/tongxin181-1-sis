#include <iostream>
using namespace std;
int fun1(int a,int b) //按值传递
{
  int m,n,p,q,c;
  m=a%10;  //a的个位
  n=a/10;  //a的十位
  p=b%10;  //b的个位
  q=b/10;  //b的十位
  c=q+n*10+100*p+1000*m;
  return c;
}
int fun3(int &a,int &b) //引用传递
{
  int m,n,p,q,c;
  m=a%10;  //a的个位
  n=a/10;  //a的十位
  p=b%10;  //b的个位
  q=b/10;  //b的十位
  c=q+n*10+100*p+1000*m;
  return c;
}
int fun2(int *a,int *b) //指针传递
{
  int m,n,p,q,c;
  m=*a%10;  //a的个位
  n=*a/10;  //a的十位
  p=*b%10;  //b的个位
  q=*b/10;  //b的十位
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
  cout<<"按值传递： n1="<<n1<<endl;
  n2=fun2(&a,&b);
  cout<<"引用传递： n2="<<n2<<endl;
  n3=fun3(a,b);
  cout<<"指针传递： n3="<<n3<<endl;
}