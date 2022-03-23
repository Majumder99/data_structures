#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<pair<ll,ll>>adj_node[6000];
ll first_short[6000];
ll second_short[6000];

void dijkstra(int s)
{
    second_short[s] = 0;
    priority_queue<pair<ll,ll>>sm;
    sm.push({0,s});
    while(!sm.empty())
    {
        int search_node = sm.top().second;
        sm.pop();
        for(int i = 0 ; i < adj_node[search_node].size() ; i++)
        {
            ll second_node = adj_node[search_node][i].second;
            ll second_cost = adj_node[search_node][i].first;
            if(second_short[second_node] > second_short[search_node]+second_cost)
            {
                second_short[second_node] = second_short[search_node]+second_cost;
                sm.push({-second_short[second_node], second_node});
            }
        }
    }
}

void result()
{
    ll total_node, total_edge,start_node,end_node,cost;
    for(int i = 0 ; i < 6000 ; i++)
    {
        second_short[i] = INT_MAX;
        adj_node[i].clear();
    }
    cin >> total_node >> total_edge;
    for(int i = 0 ; i < total_edge ; i++)
    {
        cin >> start_node >> end_node >> cost;
        adj_node[start_node].push_back({cost,end_node});
        adj_node[end_node].push_back({cost,start_node});
    }
    dijkstra(1);
    for(int i = 0 ; i < 6000 ; i++)
    {
        first_short[i] = second_short[i];
        second_short[i] = INT_MAX;
    }
    dijkstra(total_node);
    ll res_value = INT_MAX;
    for(int i = 1 ; i <= total_node ; i++)
    {
        for(auto sourav : adj_node[i])
        {
            ll t_result = first_short[i] + second_short[sourav.second] + sourav.first;
            if(t_result > first_short[total_node])
            {
                res_value = min(t_result, res_value);
            }
        }
    }
    cout << res_value << endl;
}
int main()
{
    ll t,f = 1;
    cin >> t;
    while(t--)
    {
        cout << "Case " << f << ": ";
        f++;
        result();
    }
}
