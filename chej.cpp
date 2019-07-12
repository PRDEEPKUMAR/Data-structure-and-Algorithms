#include<iostream>
#include<boost/math/common_factor.hpp>
using namespace std;
int main()
{
long long  t,n,a,b,g,k,i,r=0;
long long  a_c=0,b_c=0,l_c=0;
    cin>>t;
    while(t--)
    {
      cin>>n>>a>>b>>k;
      a_c=n/a;
      b_c=n/b;
      l_c=n/boost::math::lcm(a,b);
      g=(a_c+b_c)-2*l_c;
      //cout<<g;




        if(g>=k)
            cout<<"Win"<<endl;
        else
            cout<<"Loose"<<endl;

    }

 return 0;
}
