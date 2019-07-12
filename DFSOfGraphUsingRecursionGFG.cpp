#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
void dfs(int s, vector<int> g[], bool vis[]);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N, E;
        cin>>N>>E;

        vector<int> g[N];
        bool vis[N];

        memset(vis, false, sizeof(vis));

        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0,g,vis);

        cout<<endl;
    }
}
void dfsutil(int start, bool vis[],vector<int> g[])
{
    int i=0;
    vis[start]=true;
    cout<<start<<" ";
    for(i=0;i<g[start].size();i++)
    {
        if(vis[g[start][i]]==false)
        {
            dfsutil(g[start][i],vis,g);
        }
    }
}


void dfs(int s, vector<int> g[], bool vis[])
{
    int i;
    for(i=0;i<g->size();i++)
    {
        vis[i]=false;
    }
    dfsutil(s,vis,g);
  /*stack<int> q;
    int i,t,j;
    cout<<s<<" ";
    q.push(s);
    for(i=0;i<(*g).size();i++)
        vis[i]=false;
    while(!q.empty())
    {
        t=q.top();
        q.pop();
        vis[t]=true;
        for(i=0;i<g[t].size();i++)
        {
            if(vis[g[t][i]]==false)
            {
                vis[g[t][i]]=true;
                q.push(g[t][i]);
                cout<<g[t][i]<<" ";
            }
        }
    }*/
}
