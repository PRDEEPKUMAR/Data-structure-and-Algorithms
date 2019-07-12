#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,k;
        map<int, int> mp;
        cin>>n;
        int A[n];
        int *B=(int*)calloc(201,sizeof(int));
        int *C=(int*)calloc(201,sizeof(int));

        for(i=0;i<n;i++)
        {
            cin>>A[i];
            mp.insert(pair<int , int>(A[i],i));

        }
        map<int, int>:: iterator it=mp.begin();
        while(it!=mp.end())
        {
            cout<<it->second<<" ";
            it++;
        }
        cout<<endl;

    }
    return 0;
}
