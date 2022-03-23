#include<bits/stdc++.h>
using namespace std;
bool breath_search(int first_value, int second_value, vector<int>*adj_node2, bool *visited2, int *previous2)
{
    queue<int>sourav;
    while(!sourav.empty())
    {
        sourav.pop();
    }
    sourav.push(first_value);
    visited2[first_value]=true;
    while(!sourav.empty())
    {
        int node = sourav.front();
        sourav.pop();
        int len = adj_node2[node].size();
        for(int k=0; k<len; k++)
        {
            int edge = adj_node2[node][k];
            if(node==edge&&edge==second_value)
            {
                return true;
            }
            if(visited2[edge]&&second_value==edge)
            {
                return true;
            }
            if(!visited2[edge])
            {
                visited2[edge]=true;
                previous2[edge]=node;
                if(edge==second_value)
                {
                    return true;
                }
                sourav.push(edge);
            }
        }
    }
    return false;
}
int main()
{
    int n1,i,k,l,m,n,first,last,total;
    for(int i=0;;i++)
    {
        cin>>n1;
        if(n1==0)
        {
            return 0;
        }
        vector<int>adj_node[1000];
        for(int i=0;;i++)
        {
            cin>>k;
            if(k==0)
            {
                break;
            }
            m=k;
            for(int i=0;;i++)
            {
                cin>>l;
                n=l;
                if(l==0)
                {
                    break;
                }
                adj_node[m].push_back(n);
            }
        }
        cin>>total;
        while(total--)
        {
            cin>>first;
            int count_var=0, j = 0;
            int second_value[1000]= {0};
            for(i=1; i<=n1; i++)
            {
                bool visited_node[1000]= {false};
                int previous_visit[1000]= {-1};
                if(!breath_search(first,i,adj_node,visited_node,previous_visit))
                {
                    count_var++;
                    second_value[j]=i;
                    j++;
                }
            }
            cout<<count_var;
            for(int s=0 ; s<count_var; s++)
            {
                cout<<" "<<second_value[s];
            }
            cout<<endl;
        }
    }
    return 0;
}
