#include<bits/stdc++.h>
using namespace std;
#define edge pair<int,int>
class Graph
{
private:
    int *parent_of_node;
    vector< pair<int, edge> >g;
    int V;
public:
    Graph(int );
    void set_cost_of_edges_of_node_edge(int , int , int );
    int find_set_parent(int );
    void add_two_nodes(int , int );
    void algo_krus_kal(int, int, int);
    void change_again(int);
};
Graph::Graph(int V)
{
    parent_of_node = new int[V+1];
    g.clear();
}
void Graph::change_again(int n)
{
    for(int i=1; i<=n; i++)
    {
        parent_of_node[i] = i;
    }
}
void Graph::set_cost_of_edges_of_node_edge(int u, int v, int w)
{
    g.push_back(make_pair(w,edge(u,v)));
}
int Graph::find_set_parent(int i)
{
    if(i==parent_of_node[i])
        return i;
    else
        return find_set_parent(parent_of_node[i]);
}
void Graph::add_two_nodes(int u, int v)
{
    parent_of_node[u] = v;
}
void Graph::algo_krus_kal(int n,int m,int t)
{
    change_again(n);
    int i,uRep,vRep;
    sort(g.begin(),g.end());
    vector<int>sourav;
    for(i=0; i<m; i++)
    {
        uRep = find_set_parent(g[i].second.first);
        vRep = find_set_parent(g[i].second.second);
        if(uRep==vRep)
            continue;
        add_two_nodes(uRep,vRep);
        sourav.push_back(i);
    }
    cout << "Case #" << t << " : ";
    if(sourav.size() != n-1)
    {
        cout << "No way" << endl;
    }
    else
    {
        long long inf = INT_MAX;
        long long mn = inf;

        for(int i : sourav)
        {
            change_again(n);
            int edge_count = 0;
            long long cost_of_edges = 0;
            for(int j=0 ; j<m; j++)
            {
                if(j==i)
                    continue;
                uRep = find_set_parent(g[j].second.first);
                vRep = find_set_parent(g[j].second.second);
                if(uRep==vRep)
                    continue;
                add_two_nodes(uRep,vRep);
                cost_of_edges = cost_of_edges + g[j].first;
                edge_count++;
            }
            if(edge_count == n-1)
            {
                mn = min(mn,cost_of_edges);
            }
        }
        if(mn == inf)
        {
            cout << "No second way" << endl;
        }
        else
        {
            cout << mn << endl;
        }
    }
}
int main()
{
    int w,l,a,b,v,e,t,j,i;
    cin >> t;
    l = t;
    while(t--)
    {
        cin >> v >> e;
        Graph g(v);
        for(i=0; i<e; i++)
        {
            cin >> a >> b >> w;
            g.set_cost_of_edges_of_node_edge(a,b,w);
        }
        j = l - t;
        g.algo_krus_kal(v,e,j);
    }
    return 0;
}
