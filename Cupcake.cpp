#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;
int main()
{
    int n,i,sum=0,j;
  cin>>n;
  int A[n];
  for(i=0;i<n;i++)
    cin>>A[i];
    sort(A,A+n);
  for(i=0,j=n-1;j>=0;i++,j--)
  {
    sum=sum+(pow(2,i)*A[j]);
  }
  cout<<sum;

 return  0;
}
