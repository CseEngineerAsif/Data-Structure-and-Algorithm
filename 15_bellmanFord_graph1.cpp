#include<bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int V,vector<vector<int>>& edges,int src)
{

    vector<int>distance(V, 1e8);

    distance[src] = 0;

    // Relax all edges V-1 times
    for(int i = 0; i < V-1; i++)
    {

        for(auto edge : edges)
        {

            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if(distance[u] != 1e8 &&
                    distance[u] + w < distance[v])
            {

                distance[v] = distance[u] + w;
            }
        }
    }

    // Negative cycle detection
    for(auto edge : edges)
    {

        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        if(distance[u] != 1e8 &&
                distance[u] + w < distance[v])
        {

            return {-1};
        }
    }

    return distance;
}

int main()
{

    int V, E;

    cout<<"Please Enter number of vertices and edges"<<endl;

    cin>>V>>E;

    vector<vector<int>>edges;

    int u, v, w;

    // Input edges
    for(int i = 0; i < E; i++)
    {

        cout<<"Enter edge (u v w): ";

        cin>>u>>v>>w;

        edges.push_back({u,v,w});
    }

    int src;

    cout<<"Enter source node: ";

    cin>>src;

    vector<int>ans = bellmanFord(V, edges, src);

    // Negative cycle exists
    if(ans.size() == 1 && ans[0] == -1)
    {

        cout<<"Negative Weight Cycle Detected"<<endl;
    }
    else
    {

        cout<<"Shortest Distances:"<<endl;

        for(int d : ans)
        {
            cout<<d<<" ";
        }
    }
}
