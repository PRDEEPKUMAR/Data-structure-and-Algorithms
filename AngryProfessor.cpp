#include<iostream>
using namespace std;
int main()
{

    int n,t,k,s=0,m=0;
    cin>>t;
    while(t--)
    {
        s=0,m=0;

        cin>>n>>k;
        int A[n];
      for(int i=0;i<n;i++)
      {
          cin>>A[i];
          if(A[i]<=0)
            m++;
          else
            s++;
      }
       if(m>=k)
       {

           cout<<"NO"<<endl;
       }
       else
       {
           cout<<"YES"<<endl;
       }

    }
}
