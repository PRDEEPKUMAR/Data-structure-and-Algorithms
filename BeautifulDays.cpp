#include<iostream>
using namespace std;
int rev(int n)
{

    int s=0,g=0;
    while(n>0)
    {
        g=n%10;
        n=n/10;
        s=s*10+g;
    }
    return s;
}
int main()
{
    int i,j,k,d,count=0;
    cin>>i>>j>>k;
    for(int l=i;l<=j;l++)
    {
        d=l-rev(l);
        if(d<0)
            d=-d;
        if(d%k==0)
        {

        count++;
        }
    }
    cout<<count ;

    return 0;
}
