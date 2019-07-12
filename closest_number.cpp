#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,val;
    int min=9999999;
    vector<int> V;
    vector<pair<int,int>> P;
    cin>>n;
    for( i=0;i<n;i++)
    {
        cin>>val;
        V.insert(V.end(),val);
    }
    sort(V.begin(),V.end());
    for(i=0;i<n-1;i++)
    {
        if(min>V[i+1]-V[i])
        min=V[i+1]-V[i];
    }
    for(i=0;i<n-1;i++)
    {
        if(min==V[i+1]-V[i])
            P.insert(P.end(),make_pair(V[i],V[i+1]));
    }

    for(i=0;i<P.size();i++)
    {
        cout<<P[i].first<<" "<<P[i].second<<" ";
    }

    return 0;
}
