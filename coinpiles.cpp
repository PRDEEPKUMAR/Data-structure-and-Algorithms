#include<bits/stdc++.h>
using namespace std;
int main()
{

    int t,n,k,g;
    int val;
    cin>>t;
    while(t--)
    {
        g=0;
        int min=0;
        int i,j;
        vector<int> v;
        cin>>n>>k;
        int m=9999;
        for(i=0;i<n;i++)
        {
            cin>>val;
            v.insert(v.end(),val);
            if(m>val)
                m=val;
        }
        for(i=0;i<n;i++)
        {
            cout<<abs(m-v[i])<<" "<<endl;
            if(abs(m-v[i])>k)
            {
                min=min+abs(m-v[i])-k;
            }

        }
   // cout<<min<<endl;
    }
    return 0;
}
