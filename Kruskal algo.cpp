#include<bits/stdc++.h>
using namespace std;
#define edge pair<int,int>
class Graph
{
private:
    int *parent;
    vector< pair<int, edge> >g;///graph
    vector< pair<int, edge> >t;///mst
    int V;
public:
    Graph(int V);
    void AddWeightedEdge(int u, int v, int w);
    int find_set(int i);
    void union_set(int u, int v);
    void kruskal();
    void print();
};
Graph::Graph(int V)
{
    parent = new int[V];
    for(int i=0; i<V; i++)
    {
        parent[i] = i;
    }
    g.clear();
    t.clear();
}
void Graph::AddWeightedEdge(int u, int v, int w)
{
    g.push_back(make_pair(w,edge(u,v)));
}
int Graph::find_set(int i)
{
    if(i==parent[i])
        return i;
    else
        parent[i]=find_set(parent[i]);
        return parent[i];
}
///If we do not use union_set, edges will be repeated like if (1,5) is a minimum
///edge
///then (1,5)will be printed and also (5,1) will be printed.
void Graph::union_set(int u, int v)
{
    parent[u] = parent[v];
}
void Graph::kruskal()
{
    int i,uRep,vRep,total=0;
    sort(g.begin(),g.end());
    for(i=0; i<g.size(); i++)
    {
        uRep = find_set(g[i].second.first);
        vRep = find_set(g[i].second.second);
        if(uRep!=vRep)
        {
            t.push_back(g[i]);
            total+=g[i].first;
            union_set(uRep,vRep);
        }
    }
    cout << total << endl;
}
void Graph::print()
{
    cout << "Edge :"
         << " Weight" << endl;
    for (int i = 0; i < t.size(); i++)
    {
        cout << t[i].second.first << " - " << t[i].second.second << " : "
             << t[i].first;
        cout << endl;
    }
}
int main()
{
    Graph g(9);
    g.AddWeightedEdge(0, 1, 4);
    g.AddWeightedEdge(0, 7, 8);
    g.AddWeightedEdge(1, 2, 8);
    g.AddWeightedEdge(1, 7, 11);
    g.AddWeightedEdge(2, 3, 7);
    g.AddWeightedEdge(2, 5, 4);
    g.AddWeightedEdge(3, 4, 9);
    g.AddWeightedEdge(3, 5, 14);
    g.AddWeightedEdge(5, 4, 10);
    g.AddWeightedEdge(6, 5, 2);
    g.AddWeightedEdge(7, 8, 7);
    g.AddWeightedEdge(7, 6, 1);
    g.AddWeightedEdge(8, 2, 2);
    g.AddWeightedEdge(8, 6, 6);
    g.kruskal();
    g.print();
    return 0;
}
