#include <iostream>
using namespace std;

static int a[15];

int minM(int t)
{
 int n=2*t;
 for(int m=t+1;;m++)
 {
  //cout<<m<<endl;
  int f=(m-1)%n;
  int tmp1=f%n+1;
  if(tmp1<=t) continue;
  if(1==t) return m;
  for(int i=2;i<=n;i++)
  {
   int g=(m-1)%(n-i+1);
   for(int j=2;j<=i;j++)
   {
   g=(g+m)%(n-i+j);
   }
   f=g;
   int tmp2=f%n+1;
   if(tmp2<=t) goto con;
   if(i==t) return m;
  }
con:continue;
 }
}

int main()
{
 int k;
 while(1)
 {
  cin>>k;
  if(!k) return 0;
  if(!a[k])
  {
  a[k]=minM(k);
  }  
  cout<<a[k]<<endl; 
 }
return 0;
}

