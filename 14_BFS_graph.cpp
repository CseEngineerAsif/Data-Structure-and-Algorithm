#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<int, vector<int>>adj;
    int n, e;

    cout<<"Please Enter number of nodes and edges"<<endl;

    cin>>n>>e;

    int u,v;

    // Input edges
    for(int i = 0; i < e; i++){
        cout<<"Enter edges: ";
        cin>>u>>v;

        // Undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool>visited(n,false);
    queue<int>q;

    // Source node = 0
    visited[0] = true;
    q.push(0);

    while(!q.empty()){

        int u = q.front();
        q.pop();

        cout<<u<<" ";

        // Traverse adjacent nodes
        for(int v: adj[u]){

            if(visited[v]==false){

                visited[v] = true;
                q.push(v);
            }
        }
    }
}
