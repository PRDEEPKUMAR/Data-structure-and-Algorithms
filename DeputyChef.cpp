#include<iostream>
using namespace std;
int  main()
{
    int t,n,i,db;
    cin>>t;
    while(t--)
    {
        db=-1;
        cin>>n;
        int A[n],B[n];
        for(i=0;i<n;i++)
        {
            cin>>A[i];
        }
        for(i=0;i<n;i++)
        {
            cin>>B[i];
        }
        if(A[n-1]+A[1]<B[0])
            db=B[0];
        if(A[n-2]+A[0]<B[n-1])
            db=B[n-1];
        for(i=1;i<n-1;i++)
        {
            if(A[i-1]+A[i+1]<B[i])
                db=B[i];

        }
        cout<<db<<endl;


    }

    return 0;
}
