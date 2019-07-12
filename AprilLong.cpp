#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int A[200000];
    long min=999999999,max=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        if(min>A[i])
            min=A[i];
        if(max<A[i])
            max=A[i];
    }
    cout<<max-min;
}
