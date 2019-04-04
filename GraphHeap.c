/// This program consist of the Kruskal's Algorithm Which is used to conver a Graph into Minimal Spanning Tree with the help
///of Auxilary data structure "Disjoints Set Data Structre".
#include<stdio.h>
#include<stdlib.h>
#define range(i,n) for(i=1;i<=n;i++)
struct Edge
{
    int u;
    int v;
    int cost;
};
typedef struct Edge Edge;
Edge* createEdge()
{
    Edge* temp=(Edge*)malloc(sizeof(Edge));
    printf("Enter the u,v & cost\n");
    scanf("%d %d %d",&temp->u,&temp->v,&temp->cost);
    return temp;
}
void heapify(Edge *A[],int i ,int n)
{
    Edge *t=NULL;
    int l=2*i;
    int r=2*i+1;
    int lar=i;
    if(l<=n)
    {
    if(A[lar]->cost>A[l]->cost)
    {
       lar=l;
    }
    }
    if(r<=n)
    {
        if(A[lar]->cost>A[r]->cost)
    {
        lar=r;
    }
    }
    if(lar!=i)
    {
        t=A[lar];
        A[lar]=A[i];
        A[i]=t;
        heapify(A,lar,n);
    }
}
void Build_Max_Heap(Edge *A[],int n)
{
     int i=0;
    for(i=n/2;i>0;i--)
    {
        heapify(A,i,n);
    }

}
Edge* DeleteHeap(Edge *A[],int *n)
{
    Edge *temp=NULL;
    temp=A[1];
    A[1]=A[*n];
    (*n)--;
    if(*n!=0)
    heapify(A,1,*n);
    return temp;

}
void display(Edge *A[],int n)
{
    int i;
    for(i=1;i<=n;i++)
        printf("\n%d--%d :%d\n",A[i]->u,A[i]->v,A[i]->cost);
}
void insert_heap(Edge *A[],int *n,Edge *item)
{
     (*n)++;

    int i=*n;
    if(i>1)
    {
    while(item->cost<A[i/2]->cost&&i>1)
    {
        A[i]=A[i/2];
        i=i/2;
        if(i==1)
            break;
    }
    }

    A[i]=item;

}
void generateArray(Edge *A[],int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        A[i]=createEdge();
    }
}
int find(int A[],int i,int n)
{
    while(A[i]>0)
    {
        A[i]=i;
    }
    return i;
}
void union_operation(int A[],int i,int j,int n)
{
    A[i]=j;
}
void Krushals(Edge *E[],Edge *Sol[],int A[],int n)
{
    int u,v,i=1,l=1,min_cost=0,k,j;
    Edge *temp=NULL;
    while(i<=n)
    {
        temp=DeleteHeap(E,&n);
        u=temp->u;
        v=temp->v;
        j=find(A,u,n);
        k=find(A,v,n);
        if(j!=k)
        {
            Sol[i]=temp;
            min_cost=min_cost+temp->cost;
            union_operation(A,j,k,n);
            i++;
        }
    }
    printf("Minimun cost %d ",min_cost);
}
int main()
{
    int n,i=1;
    printf("Enter the number of Edges :");
    scanf("%d",&n);
    Edge *E[100];
    Edge *Sol[100];
    int A[100]={-1};
    range(i,100)
    {
        A[i]=-1;
    }

    generateArray(E,n);
    display(E,n);
    Build_Max_Heap(E,n);
    display(E,n);
    Krushals(E,Sol,A,n);
    printf("\n");
    range(i,10)
    {
        printf("%d ",A[i]);
    }
    return 0;
}
