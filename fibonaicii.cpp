#include<iostream>
using namespace std;
int main()
{
    int t,t2,n;

    cin>>t;
    while(t--)
    {
    cin>>n;
    unsigned long long int  A[n+1];
    A[0]=0;
    A[1]=1;
    A[2]=1;
    for(int i=3;i<=n;i++)
    {
        A[i]=A[i-1]+A[i-2];
    }
    cout<<A[n]<<endl;
    }
    return 0;
}
