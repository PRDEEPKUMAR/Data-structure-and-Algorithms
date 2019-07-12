#include<iostream>
using namespace std;
int main()
{
     long int A[100],val;
     A[0]=2;
     A[1]=3;
     for(int i=1;i<=50;i++)
     {
         A[i+1]=A[i]+i;
     }
     for(int i=1;i<=50;i++)
        A[i]=A[i]+A[i-1];
     cin>>val;
     if(val==1)
        cout<<A[0];
     else
        {
            cout<<A[val-1];
        }

     return 0;
}
