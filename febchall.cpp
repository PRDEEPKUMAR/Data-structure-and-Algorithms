#include<iostream>
using namespace std;
long lcm(int a,int b)
{
    long k=1;
    int c=a>b?a:b;

    for(int i=1;i<=c;i++)
    {
        if(a%i==0&&b%i==0)
            k=i;
    }
    return (a*b)/k;
}

int main()
{
long int  t,n,a,b,g=0,k,i,r=0;
long int  a_c=0,b_c=0,l_c=0;
    cin>>t;
    while(t--)
    {
        g=0;
        cin>>n>>a>>b>>k;

      for(i=1;i<=n;i++)
      {
          if(i%a!=0&&i%b==0)
          {
             // cout<<i<<" ";
            g++;
          }
         else if(i%a==0&&i%b!=0)
            {
                //cout<<i<<" ";
                g++;
            }
      }



       //cout<<"g: "<<g<<endl;



        if(g>=k)
            cout<<"Win"<<endl;
        else
            cout<<"Loose"<<endl;

    }

 return 0;
}
