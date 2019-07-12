#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int i,n,val;
        cin>>n;
        int A[2]={0};
        for(i=0;i<n;i++)
        {
            cin>>val;
            A[val]++;
        }
        cout<<A[0]<<endl;
    }
    return 0;
}
/*
3
3
2 10 14
4
-28 -21 -7 0
5
9 12 15 21 24
*/
