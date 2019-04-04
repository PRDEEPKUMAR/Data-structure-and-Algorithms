#include<stdio.h>
#include<stdlib.h>
struct Graph
{
    int row;
    int col;
    int **adj;
};
typedef struct Graph Graph;
Graph* createGraph(int r, int c)
{
    int i,j;
    Graph *G=(Graph*)malloc(sizeof(Graph));
    G->row=r;
    G->col=c;
    G->adj=(int **)malloc(G->row*sizeof(int*));
    for(i=0;i<G->row;i++)
        (G->adj[i])=(int*)malloc(G->col*sizeof(int*));
    for(i=1;i<G->row;i++)
    {
        for(j=1;j<G->col;j++)
        {

            G->adj[i][j]=0;
            //printf("%d",G->adj[i][j]);
        }
        //printf("\n");
    }
    return G;

}

void addEdge(Graph *G,int u, int v)
{
    //printf("addming Edge");
    G->adj[u][v]=1;
    G->adj[v][u]=1;

}
void addCostEdge(Graph *G,int u, int v,int cost)
{
    G->adj[u][v]=cost;
    G->adj[v][u]=cost;
}
void displayEdges(Graph *G)
{

    int i,j;
    for(i=1;i<G->row;i++)
    {

        for(j=1;j<G->col;j++)
        {
            if(G->adj[i][j]!=0)
            {
                printf("%d------%d\n",i,j);
            }
        }

    }
}
void displayAdjMatrix(Graph *G)
{
    int i,j;
    for(i=1;i<G->row;i++)
    {
        for(j=1;j<G->col;j++)
        {
            printf("%d ",G->adj[i][j]);
        }
        printf("\n");
    }printf("\n");
}
int main()
{
    int n,i,j,u,v,e,cost;
    printf("Enter the number of Vertex:-");
    scanf("%d",&n);
    printf("\n Enter the number of Edges  in the Graph :-");
    scanf("%d",&e);
    Graph *G=createGraph(n+1,n+1);
    for(i=1;i<=e;i++)
    {
        scanf("%d %d",&u,&v);
    addEdge(G,u,v);

    }
    displayAdjMatrix(G);

    return 0;
}
