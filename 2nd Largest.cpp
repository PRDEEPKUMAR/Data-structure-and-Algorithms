#include<iostream>
using namespace std;
int main()
{
   int t,a,b,c,d;
   cin>>t;
   while(t--)
   {
   cin>>a>>b>>c;
   d=a>b?a:b;
   if(d>c)
   cout<<c;
   else
   cout<<d;

   }
   return 0;
}
