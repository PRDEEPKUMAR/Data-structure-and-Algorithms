#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int  i,t,n;
    cin>>t;
    while(t--)
    {
        unsigned long long int x,y,z;
        vector<unsigned long long int> v;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            v.insert(v.end(),i);
        }
     for(i=1;i<n;i++)
     {
         x=v.front();
         v.erase(v.begin());
         y=v.front();
         v.erase(v.begin());
         z=x+y+(x*y);
         v.insert(v.end(),z);
     }
    // cout<<v.size();
     cout<<v.front()%1000000007<<endl;
    }
    return 0;
}
