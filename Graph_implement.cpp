#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;
    cin>>n>>e;
    vector<pair<int,int>>adj[n+1];
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for(int i=1;i<=n;i++){
        cout<<"Node "<<i<<": ";
        for(auto neighbor : adj[i]){
            cout<<"("<<neighbor.first<<" "<<neighbor.second<<") ";
        }
        cout<<endl;
    }

    return 0;
}

/**

5 6
1 2 3
1 3 10
2 4 6
2 5 4
4 5 9
3 4 5

*/
