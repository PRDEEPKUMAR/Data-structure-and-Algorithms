#include<iostream>
using namespace std;
int main()
{

    int i,c,n,s,res=0,m=0,y,l,h,coin=1000;
    cin>>n>>c;
    l=1;
    h=n;
    m=(l+h)/2;
    while(coin>0&&l<h)
    {
        y=m;
        cout<<1<<" "<<y;
        cin>>s;
        if(s==0)
        {

            res=m;
            l=m+1;
            m=(h+l)/2;
            coin--;

        }
        else if(s==1)
        {

            coin=coin-c-1;
            cout<<2<<endl;
            h=m-1;
            m=(l+h)/2;
        }

    }

    cout<<3<<" "<<m;
    return 0;
}
