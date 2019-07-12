#include<iostream>
using namespace std;
int main()
{
    int n,max=0,val,i,A[1000]={0};
    for(i=0;i<200;i++)
    A[i]=0;

    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>val;
        A[val]++;

    }

    for(i=1;i<=100;i++)
    {
        if(max<A[i])
            max=A[i];
    }
    cout<<n-max;
    return 0;
}
/*8
96 96 45 52 73 44 51 96*/
