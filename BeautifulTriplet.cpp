#include<iostream>
using namespace std;
int main()
{
    long int  n,d,count=0;
    int A[10000];
    int i,k,j;
    cin>>n>>d;
    for(i=0;i<n;i++)
        cin>>A[i];

    for(i=0;i<n-2;i++)
    {

        for(j=i+1;j<n-1;j++)
        {

            for(k=j+1;k<n;k++)
            {

                if((A[j]-A[i])==d&&(A[k]-A[j])==d)
                    {count++;
                    }
            }

        }

    }
    cout<<count;


    return 0;
}
