#include<bits/stdc++.h>
using namespace std;

static const int N=1e5+5;
vector<int>adj[N];
int visited[N];

void dfs(int src, vector<int>&v)
{
    visited[src]=1;
    v.push_back(src);
    for(int adj_node : adj[src]){
        if(visited[adj_node]==0)
            dfs(adj_node,v);
    }
}
vector<int> bfs(int src)
{
    visited[src]=1;
    queue<int>q;
    q.push(src);
    vector<int>v;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        v.push_back(node);
        for(int adj_node : adj[node]){
            if(visited[adj_node]==0){
                visited[adj_node]=1;
                q.push(adj_node);
            }
        }
    }
    return v;
}

int main()
{
    int V,E;
    cin>>V>>E;
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>v = bfs(1);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;

    for(int i=1;i<=V;i++)
        visited[i]=0;

    vector<int>k;
    dfs(1,k);
    for(int i=0;i<k.size();i++)
        cout<<k[i]<<" ";
    cout<<endl;

    return 0;
}

/**

5 6

1 2
1 3
2 4
2 5
4 5
3 4

*/
