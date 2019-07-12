#include<iostream>
using namespace std;
int main()
{
    int n,d;
    cin>>n>>d;
    int j,i,A[n],B[n];
    for(i=0;i<n;i++)
    {
        cin>>A[i];
    }
    for(i=d,j=0;i<n;i++,j++)
    {
        B[j]=A[i];
    }
    for(i=0;i<d;i++,j++)
    {
        B[j]=A[i];

    }

    for(i=0;i<n;i++)
        cout<<B[i]<<" ";
    return 0;
}
