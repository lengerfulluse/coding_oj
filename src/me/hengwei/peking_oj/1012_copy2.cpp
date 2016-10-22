#include <iostream>
using namespace std;

static int a[14];

int minM(int t)
{
 if(t==1) return 2;
 int n=t<<1;
 bool b=true;
 for(int m=t+1;;b?m++:m+=t,b=!b)//m mod (t+1) = 0 or 1
 {
  int index=0;
  for(int j=n;j>t;j--)
  {
   index=(index+m-1)%j;
   if(index<t) goto con;
  }
  return m;
con:continue;
 }
}

int main()
{
 int k;
 while(cin>>k,k)
 {
  if(!a[k])
  {
  a[k]=minM(k);
  }  
  cout<<a[k]<<endl; 
 }
return 0;
}

