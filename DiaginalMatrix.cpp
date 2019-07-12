#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j,l;
        cin>>n;
        int A[n][n];
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>A[i][j];
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0,l=i;j<=i;j++,l--)
            {
                cout<<A[j][l]<<" ";
            }
        }
        for(i=1;i<n;i++)
        {
            for(j=n-1,l=i;j>=i;j--,l++)
            {
                cout<<A[l][j]<<" ";
            }
        }
        cout<<endl;

    }
    return 0;
}
