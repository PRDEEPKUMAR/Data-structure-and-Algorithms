#include<iostream>
using namespace std;
int main()
{

    int n,p,i,k=0,j,l=0;
    cin>>n>>p;
    if(p==1||p==n)
    {
        cout<<0;
        return 0;
    }
     if(p<=n/2)
     {
         cout<<p/2;
     }
     else if(p>n/2)
     {
            p=n-p;
         if(n%2!=0)
         {
         cout<<p/2;
         }
         else{cout<<p/2+1;}
     }



     return 0;
}
