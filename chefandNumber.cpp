#include<iostream>
using namespace std;
int main()
{
    int  t,n,val;
    cin>>t;
    while(t--)
    {
        int pos=0,neg=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>val;
            if(val>=0)
            {
                pos++;
            }
            else
            {
                neg++;
            }

        }
        if(pos==n || neg==n)
            cout<<n<<" "<<n<<endl;
        else if(pos>neg)
            cout<<pos<<" "<<neg<<endl;
        else
            cout<<neg<<" "<<pos<<endl;
    }
    return 0;
}
