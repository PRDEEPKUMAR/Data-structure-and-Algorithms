#include<iostream>
using namespace std;
int main()
{
    int t,x,y,z,yz,xz;
    cin>>t;
    while(t--)
    {

        cin>>x>>y>>z;
        xz=x-z;
        yz=y-z;
        if(xz<0)
        {
            xz=-xz;
        }
        if(yz<0)
        {
            yz=-yz;
        }
        if(xz==yz)
            cout<<"Mouse C"<<endl;
        else if(xz>yz)
        {
            cout<<"Cat B"<<endl;

        }
        else if(xz<yz)
        {

            cout<<"Cat A"<<endl;
        }

    }

    return 0;
}
