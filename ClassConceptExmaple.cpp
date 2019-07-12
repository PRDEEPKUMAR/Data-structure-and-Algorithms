#include<iostream>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        int sum1=0,sum2=0;
        int val;
        cin>>n;
        int A[n];
        for(int i=0;i<n-1;i++)
        {
            sum1=sum1+i+1;
            cin>>val;
            sum2=sum2+val;
        }
        cout<<(sum1+n)-sum2<<endl;
    }
    return 0;
}
