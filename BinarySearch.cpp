#include<iostream>
using namespace std;
int bin(int A[],int low,int high,int item)
{
    int mid=0;
    if(low==high)
    {
        if(A[low]==item)
            return low;
        else
            return -1;
    }
    else
    {
      mid=(low+high)/2;
      if(item<A[mid])
        {
                bin(A,low,mid-1,item);
         }
       else if(item>A[mid])
       {
          // cout<<"higher";
          bin(A,mid+1,high,item);
       }
       else
        {
          return mid;
        }
    }
}
int main()
{
    int item;
    int A[]={1,2,3,4,5,6,7,8,9};
    cin>>item;
    cout<<bin(A,0,8,item);
    return 0;

}

