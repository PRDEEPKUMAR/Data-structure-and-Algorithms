#include<iostream>
#include<algorithm>
#include<set>

using namespace std;
int  main()
{

    int n,m,b,max=-1;
    int A[10000],B[10000];
    cin>>b>>n>>m;
    for(int i=0;i<n;i++)
        cin>>A[i];
    for(int i=0;i<m;i++)
        cin>>B[i];

    for(int i=0;i<n;i++)
    {
        max=-1;

        for(int j=0;j<m;j++)
        {
            if(A[i]+B[j]<=b)
                max=A[i]+B[j];

        }
    }
    cout<<max;
    return 0;
}
