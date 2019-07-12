#include<iostream>
#include <cstdlib>
#include<algorithm>
using namespace std;
int main()
{
    int n,min=999999;
    cin>>n;
    int alpha;
    int A[n];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    sort(A,A+n);
    for(int i=0;i<n-1;i++)
    {
        alpha=abs(A[i+1]-A[i]);
        if(min>alpha)
        min=alpha;

    }
    cout<<min;
  return 0;
}
