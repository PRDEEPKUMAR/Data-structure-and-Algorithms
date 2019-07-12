#include<iostream>
using namespace std;
int findmin(int *A,int n)
{

    int i,min=999;
    for(i=0;i<n;i++)
        if(min>A[i])
        min=A[i];
    return min;
}
int countnonzeros(int *A,int n)
{
    int count=0,i,k=0,B[n];
    for(i=0,k=0;i<n;i++)
    {
        if(A[i]!=0)
           {
               B[k]=A[i];
               k++;
               count++;
           }
    }
    for(i=0;i<k;i++)
        A[i]=B[i];
    return count;
}
int main()
{
    int n,i,s,j;
    cin>>n;
    int A[n];
    for(i=0;i<n;i++)
        cin>>A[i];
        int k=n;
        cout<<k<<endl;
    for(i=0;k>1;i++)
    {
        //k=countnonzeros(A,k);
        s=findmin(A,k);
        //cout<<"min "<<s<<endl;
        for(j=0;j<k;j++)
        {
            A[j]=A[j]-s;
        }
        k=countnonzeros(A,k);
        cout<<k<<endl;
    }

    return 0;
}
