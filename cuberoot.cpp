/// This Program will find the cube root of any number n.
#include<iostream>
#include<math.h>
using namespace std;
double nrAlgorithm(double m,double n)
{
    if(n==0)
        return 0;
    double g=1,x=1;
    int i=0;
    while(true)
    {
        x=((m-1)*pow(x,m)+n)/(m*pow(x,m-1));
        if(x==g)
        {
            break;
        }
            g=x;
        i++;
    }
    return g;

}
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<nrAlgorithm(3,n)<<endl;
    }
}

