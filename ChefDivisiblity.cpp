#include<iostream>
using namespace std;
int main()
{
    long long t,n,a,b,k,i,count=0;
    cin>>t;
    while(t--)
    {
        count=0;
        cin>>n>>a>>b>>k;
        for(i=1;i<=n;i++)
        {
            if((i%a!=0&&i%b==0))
           {
               count++;
           }
            else if(i%a==0&&i%b!=0)
            count++;
        }
        cout<<"C :-"<<count<<" ";
        if(count>=k)
            cout<<"Win"<<endl;
        else
            cout<<"Loose"<<endl;
    }

    return 0;
}
