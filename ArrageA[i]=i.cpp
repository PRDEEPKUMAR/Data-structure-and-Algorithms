#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,val;
        cin>>n;
        int A[n+1];
        for(i=0;i<n;i++)
            A[i]=-1;
        for(i=0;i<n;i++)
        {
            cin>>val;
            A[val]=val;
        }
        for(i=0;i<n;i++)
        {
            cout<<A[i]<<" ";
        }
    }
    return 0;
}
