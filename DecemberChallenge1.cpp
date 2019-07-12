#include<iostream>
using namespace std;
int main()
{
    cin>>n>>r;
    for(i=1;i<=n;i++)
    {
        cin>>c;
        if(c<r)
            cout<<"Bad boi\n";
        else
            cout<<"Good boi\n";
    }
    return 0;
}
