#include<iostream>
using namespace std;
int main()

{
    int i,j,k,l,n,val;
    int A[100000];
    cin>>n>>val;
    for(i=0,j=n-1,k=1,l=0;i<j;i++,j--,k=k+2,l=l+2)
    {
        A[i]=k;
        A[j]=l;

    }

    if(i==j&&n%2!=0)
    {
        A[i]=l;

    }
    for(i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    cout<<"Value :- "<<A[val];
    return 0;

}
