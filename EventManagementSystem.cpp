///Creating the Priority Queue(Min Heap end_time Structure) using structure.
///This can be use as Auxiliary end_time Structure for other Algorithms
#include<stdio.h>
#include<stdlib.h>
struct PriorityQueue
{
    int start_time;
    int end_time;
};
typedef struct PriorityQueue PriorityQueue;
PriorityQueue* createPriorityQueue(int n)
{
    PriorityQueue *P=(PriorityQueue*)malloc(sizeof(PriorityQueue)*n);

    return P;
}
void heapify(PriorityQueue A[],int i ,int n)
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
void Build_Max_Heap(PriorityQueue A[],int n)
{
     int i=0;
    for(i=n/2+1;i>=0;i--)
        heapify(A,i,n);

}

void heap_sort(PriorityQueue A[],int n)
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
void DeleteHeap(PriorityQueue A[],int n,int item)
{
    int temp=A[0].end_time;
    A[0].end_time=A[n-1].end_time;
    n--;
    heapify(A,0,n);
}
void display(PriorityQueue A[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",A[i].start_time);

}
void generateArray(PriorityQueue A[],int n)
{
    int i;
    printf("Enter the start time and finish time of the activity :-");
    for(int i=0;i<n;i++)
        scanf("%d",)
    scanf("%d %d",&A[i].start_time,&A[i].end_time);
}
int main()
{
    PriorityQueue *A=createPriorityQueue(100);
    generateArray(A,10);
    display(A,10);
    printf("\nAfter Sorting :-");
    heap_sort(A,10);
    display(A,10);
    return 0;
}

