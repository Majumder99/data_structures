#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

vector<vector<pii> > adj;
vector<bool> mark;



//input:
//4 5
//1 2 7
//1 4 6
//4 2 9
//4 3 8
//2 3 6
//
//cutput:
//19


int Prims1(int src)
{
    priority_queue<pii> pq;
    int miniCost = 0;
    pq.push({0, src});

    while(!pq.empty())
    {
        int u = pq.top().second;
        int cost_uv = pq.top().first;
        pq.pop();

        if(mark[u])
            continue;
        miniCost += (-1*cost_uv);
        mark[u]=true;

        for(int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].second;
            int dis = adj[u][i].first;
            if(mark[v] == false){
                pq.push({-dis, v});
            }
        }
    }

    return miniCost;
}

int Prims2(int src)
{
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    int miniCost = 0;
    pq.push({0, src});

    while(!pq.empty())
    {
        int u = pq.top().second;
        int cost_uv = pq.top().first;
        pq.pop();

        if(mark[u])
            continue;
        miniCost += cost_uv;
        mark[u]=true;

        for(int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].second;
            int dis = adj[u][i].first;
            if(mark[v] == false){
                pq.push(adj[u][i]);
            }

        }
    }

    return miniCost;
}

int main()
{
    int n, m;
    cin >> n >> m;

    adj.resize(n+1);
    mark.resize(n+1, false);

    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
//    for(int i = 1; i < n+1; i++)
//    {
//        for(int j = 0; j < adj[i].size(); j++)
//        {
//            cout<<adj[i][j].first<<"  "<<adj[i][j].second<<endl;
//        }
//        cout<<endl;
//    }
    int minCost = Prims2(1);
    cout<<minCost<<endl;

}
