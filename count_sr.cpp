#include<iostream>
#include<math.h>
using namespace std;
float squareroot(float m,float n)
{
    if(n==0)
        return 0;
    float g=1,x=n/2;
    int i=0;
    while(true)
    {
        x=((m-1)*pow(x,m)+n)/(m*pow(x,m-1));
        if(x==g)
        {
           // cout<<"Emergency Break "<<endl;
            break;
        }

            g=x;
        i++;
    }
    return g;

}
int main()
{

   int t,i;
   int n,g;
   int count;
   cin>>t;
   while(t--)
   {
       count=0;
       cin>>n;
       g=squareroot(2,n);
       for(i=1;i<=g;i++)
       {
           if(i*i<n)
            count++;
       }
       cout<<count;
   }

  return 0;
}

