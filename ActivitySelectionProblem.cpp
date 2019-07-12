///Creating the Priority Queue(Min Heap end_time Structure) using structure.
///This can be use as Auxiliary end_time Structure for other Algorithms
#include<stdio.h>
#include<stdlib.h>
struct Activity
{
    int start_time;
    int end_time;
};
typedef struct Activity Activity;
Activity* createActivity(int n)
{
    Activity *P=(Activity*)malloc(sizeof(Activity)*n);

    return P;
}
void heapify(Activity A[],int i ,int n)
{
    int t;
    int l=2*i+1;
    int r=2*i+2;
    int lar=i;
    if(A[lar].end_time<A[l].end_time&&l<n)
    {
        lar=l;
    }
        if(A[lar].end_time<A[r].end_time&&r<n)
    {
        lar=r;
    }
    if(lar!=i)
    {
        t=A[lar].end_time;
        A[lar].end_time=A[i].end_time;
        A[i].end_time=t;
        heapify(A,lar,n);
    }


}
void Build_Max_Heap(Activity A[],int n)
{
     int i=0;
    for(i=n/2+1;i>=0;i--)
        heapify(A,i,n);

}

void heap_sort(Activity A[],int n)
{
    int size=n-1;
    int i;
    int temp;

    Build_Max_Heap(A,n);

    for(i=0;i<n;i++)
    {
       temp=A[0].end_time;
       A[0].end_time=A[size].end_time;
       A[size].end_time=temp;
       Build_Max_Heap(A,size);
       size--;
    }
}
void DeleteHeap(Activity A[],int n,int item)
{
    int temp=A[0].end_time;
    A[0].end_time=A[n-1].end_time;
    n--;
    heapify(A,0,n);
}
void display(Activity A[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d              %d\n",A[i].start_time,A[i].end_time);

}
void generateArray(Activity A[],int n)
{
    int i;
    printf("Enter the start time and finish time of the activity :-");
    for(int i=0;i<n;i++)
    scanf("%d %d",&A[i].start_time,&A[i].end_time);
}
void selectActivityProblem(Activity P[],int n,Activity Sol[])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        Sol[i].start_time=0;
        Sol[i].end_time=0;
    }
    Sol[0].start_time=P[0].start_time;
    Sol[0].end_time=P[0].end_time;
    j=0;
    for(i=1;i<n;i++)
    {

        if(P[i].start_time>=P[j].end_time)
        {
            Sol[i].start_time=P[i].start_time;
            Sol[i].end_time=P[i].end_time;
            j=i;
        }

    }


}
int main()
{
    int n;
    Activity *A=createActivity(100);
    Activity *Sol=createActivity(100);
    printf("\nEnter the number of Bookings :");
    scanf("%d",&n);
    generateArray(A,n);
   // display(A,n);
    printf("\nAfter Sorting :-");
    heap_sort(A,n);
  //  display(A,n);
    selectActivityProblem(A,n,Sol);
    printf("\nSolution vector :- \n");
    printf("StartTime    EndTime\n");
    display(Sol,n);
    return 0;
}

