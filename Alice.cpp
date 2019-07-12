#include<stdio.h>
int findPos(int *A,int n,int val)
{
    int beg,end,mid;
    beg=0;
    end=n-1;
    mid=(beg+end)/2;
    if(val>A[beg])
        return 1;
    if(val<A[end])
        return end+1;
    while(beg<end)
    {
        if(val>A[mid])
        {
            end=mid-1;
            mid=(beg+end)/2;
        }
        else if(val<A[mid])
        {
            beg=mid+1;
             mid=(beg+end)/2;

        }
    }
    if(beg==end&&val==A[beg])
    {
      printf("Hi ");
        return beg;
    }
    else if(beg==end)
    {
     printf("Bye ");
        return beg+1;
    }
}
int main()
{
  int B[10],k=0;
    int i,A[10]={100,90,90,80,75,60};
     for(i=0;i<6;i++)
    {
       if(A[i]!=A[i+1])
       {
          B[k]=A[i];
           k++;

       }
    }
    printf("%d",findPos(B,5,50)+1);
    return 0;
}
