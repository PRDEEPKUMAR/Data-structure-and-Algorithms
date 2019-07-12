#include<iostream>
using namespace std;
int main()
{
    int t,n,c,m,sum=0,wrap,k;
    cin>>t;
    while(t--)
    {
    cin>>n>>c>>m;
    sum=n/c;
    wrap=n/c;
    while(wrap>=m)
    {
        k=wrap/m;
        sum=sum+k;
        wrap=wrap%m;
        wrap=wrap+k;
    }
    cout<<sum<<endl;
    }

    return 0;
}
