#include<iostream>
using namespace std;
int main()
{
    int n,val;
    int A[101]={0};
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        A[val]++;
    }
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<A[i];j++)
        cout<<i<<" ";
    }
    return 0;
}
