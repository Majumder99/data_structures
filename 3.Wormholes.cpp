#include<bits/stdc++.h>
using namespace std;
struct Edge
{
    int u;
    int v;
    int w;
};
struct New_Graph
{
    int V;
    int E;
    struct Edge *edge;
};
struct New_Graph* createNew_graph_for_bellman(int V,int E)
{
    struct New_Graph* graph = new New_Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
};
void Bellman_ford_algo(struct New_Graph* New_Graph,int u,int l,int m)
{
    int V = l;
    int E = m;
    int dist[V];

    for(int i=0; i<V; i++)
    {
        dist[i] = 99999999;
    }
    dist[u] = 0;
    for(int k = 1; k<V-1; k++)
    {
        for(int j=0; j<E; j++)
        {
            int u = New_Graph->edge[j].u;
            int v = New_Graph->edge[j].v;
            int w = New_Graph->edge[j].w;
            if (dist[u] != 99999999 && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }
    int sourav = 0;
    for(int j=0; j<E; j++)
    {
        int u = New_Graph->edge[j].u;
        int v = New_Graph->edge[j].v;
        int w = New_Graph->edge[j].w;
        if (dist[u] != 99999999 && dist[u] + w < dist[v])
        {
            sourav = 1;
            break;
        }
    }
    if(sourav == 1)
        cout << "possible" << endl;
    else
        cout << "not possible" << endl;
    return;
}
int main()
{
    int V,E,t;
    cin >> t;
    while(t--)
    {
        cin>>V>>E;
        struct New_Graph* New_Graph = createNew_graph_for_bellman(V,E);
        int starting_node_graph,ending_node_graph,cost_of_Edges;
        for(int i=0; i<E; i++)
        {
            cin>>starting_node_graph>>ending_node_graph>>cost_of_Edges;
            New_Graph->edge[i].u = starting_node_graph;
            New_Graph->edge[i].v = ending_node_graph;
            New_Graph->edge[i].w = cost_of_Edges;
        }

        Bellman_ford_algo(New_Graph,0,V,E);
    }
    return 0;
}
