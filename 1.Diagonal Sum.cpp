#include <bits/stdc++.h>
using namespace std;

int S, T;
int inf = INT_MAX;

vector<vector<int>> g, sourav;
vector<int> majumder;
vector<bool> majum;

void resize(int n, int m)
{
    int x = (n + m) * 2;
    g.resize(x);
    sourav.resize(x, vector<int>(x));
    majumder.resize(x);
    majum.resize(x);
}
bool bfs()
{
    for(int i=0;i<(int)majumder.size();i++)
    {
        majumder[i]=-1;
    }
    for(int i=0;i<(int)majum.size();i++)
    {
        majum[i]= false;
    }

    majumder[S] = -1;
    majum[S] = true;

    queue<int> q;
    q.push(S);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v : g[u])
        {
            if(majum[v] == false and sourav[u][v] > 0)
            {
                q.push(v);
                majumder[v] = u;
                majum[v] = true;
            }
        }
    }
    return majum[T] == true;
}

void ford_fulkerson_with_bfs()
{
    while( bfs() )
    {
        int minimum_path = inf;

        for(int v = T; v != S; v = majumder[v])
        {
            int u = majumder[v];
            minimum_path = min(minimum_path, sourav[u][v]);
        }

        for(int v = T; v != S; v = majumder[v])
        {
            int u = majumder[v];
            sourav[u][v] -= minimum_path;
            sourav[v][u] += minimum_path;
        }
    }
}

void give_result()
{
    int n, m;
    cin >> n >> m;
    resize(n, m);

    S = 0, T = (n + m) * 2 - 1;

    vector<int> L(n + m), R(n + m);

    for(int i = 1; i < n + m; ++i)
    {
        cin >> L[i];
        L[i] -= (min(n, i) - max(0, i - m));
    }

    for(int i = 1; i < n + m; ++i)
    {
        cin >> R[i];
        R[i] -= (min(n, i) - max(0, i - m));
    }

    for(int i = 1; i < n + m; ++i)
    {
        g[S].push_back(i);
        g[i].push_back(S);
        sourav[S][i] += L[i];
    }

    int x = n + m - 1;
    for(int i = 1; i < n + m; ++i)
    {
        g[i + x].push_back(T);
        g[T].push_back(i + x);

        sourav[i + x][T] += R[i];
    }

    vector<vector<int>> l(n + 1, vector<int>(m + 1));
    vector<vector<int>> r(n + 1, vector<int>(m + 1));

    for(int i = 1; i <= n; ++i)
    {
        l[i][0] = i - 1;
        for(int j = 1; j <= m; ++j)
        {
            l[i][j] = l[i][j - 1] + 1;
        }
        r[i][m] = i + x;
        for(int j = m - 1; j > 0; --j)
        {
            r[i][j] = r[i][j + 1] + 1;
        }
    }

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            int u = l[i][j], v = r[i][j], cost = 99;
            g[u].push_back(v);
            g[v].push_back(u);
            sourav[u][v] += cost;
        }
    }

    ford_fulkerson_with_bfs();

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {

            cout << sourav[r[i][j]][l[i][j]] + 1;

            if(j < m)
            {
                cout << ' ';
            }
        }
        cout << '\n';
    }
}

int main()
{
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i)
    {
        cout << "Case " << i << ":" << '\n';
        give_result();
        g.clear();
        sourav.clear();
    }
    return 0;
}

