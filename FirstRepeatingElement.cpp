#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,min=999999999;
        cin>>n;
        map<int , int > mp;
        map<int , int> ::iterator it;
        int *A=(int*)malloc((n+10)*sizeof(int));
        for(i=1;i<=n;i++)
        {
            cin>>A[i];
            if(mp.find(A[i])==mp.end())
            mp.insert(pair<int,int>(A[i],i));
            else
            {
                if(min>mp.find(A[i])->second)
                    min=mp.find(A[i])->second;
            }

        }
        if(min==999999999)
            cout<<-1<<endl;
        else
            cout<<min<<endl;


    }
    return 0;
}
