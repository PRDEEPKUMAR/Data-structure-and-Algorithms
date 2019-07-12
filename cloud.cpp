#include<iostream>
using namespace std;
int main()
{
    int n,k,e=100,i;
    int A[1000];
    cin>>n>>k;
    for(i=0;i<n;i++)
        cin>>A[i];
    i=0;
    while(i<n)
    {
       // cout<<i+k<<endl;
        if(A[i+k]==1)
        {
            cout<<"one";
            e=e-3;
        }
        if(A[i+k]==0)
        {
            e=e-1;
        }
        i=i+k;

    }
    //cout<<i;
        if(A[i%n]==1)
            e=e-3;
        else
            e--;
    cout<<e;
    return 0;
}
