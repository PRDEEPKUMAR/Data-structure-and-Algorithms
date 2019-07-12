#include<iostream>
using namespace std;
int main()
{
    int i;
    int sum=0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int A[n],B[n];
    for(i=0;i<n;i++)
    {
        cin>>A[i];
    }
    if(A[0]<A[1])
    {
        B[0]=1;
        B[1]=2;
    }
    else
    {
        B[1]=1;
        B[0]=2;
    }
    for(i=1;i<n-1;i++)
    {
        if(A[i]<A[i+1])
        {
            B[i+1]=B[i]+1;
        }
        else{
            B[i+1]=1;
        }

    }
    for(i=0;i<n;i++)
    {
        cout<<B[i]<<" ";
        sum=sum+B[i];
    }
    cout<<sum;

    return 0;

}
