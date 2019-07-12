#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
void bfs(int s, vector<int> adj[], bool vis[]);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N, E;
        cin>>N>>E;
        vector<int> adj[N];
        bool vis[N];
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        bfs(0, adj, vis);
        cout<<endl;
    }
}


void bfs(int s, vector<int> adj[], bool vis[])
{
    queue<int> q;
    int i,t,j;
    q.push(s);
    for(i=0;i<(*adj).size();i++)
        vis[i]=false;
    while(!q.empty())
    {
        t=q.front();
        cout<<t<<" ";
        q.pop();
        vis[t]=true;
        for(i=0;i<adj[t].size();i++)
        {
            if(vis[adj[t][i]]==false)
            {
             vis[adj[t][i]]=true;
                q.push(adj[t][i]);
            }
        }
    }
}
