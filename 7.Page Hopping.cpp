#include<bits/stdc++.h>
using namespace std;
#define N 120
#define inf 9999999
int sourav[N][N];
int main()
{
    int starting_node,ending_node,s,o,u,r=0,a,v,m,j,i;
    while(cin>>starting_node>>ending_node)
    {
        if(starting_node==0 && ending_node==0)
        {
            return 0;
        }
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                sourav[i][j]=inf;
            }
        }
        for(int i=0; i<N; i++)
        {
            sourav[i][i]=0;
        }
        set<int>majumder;
        sourav[starting_node-1][ending_node-1]=1;
        majumder.insert(starting_node);
        majumder.insert(ending_node);

        while(cin>>starting_node>>ending_node)
        {
            if(starting_node==0 && ending_node==0)
            {
                break;
            }
            sourav[starting_node-1][ending_node-1]=1;
            majumder.insert(starting_node);
            majumder.insert(ending_node);
        }
       for(s=0;s<N;s++)
       {
           for(o=0;o<N;o++)
           {
               for(u=0;u<N;u++)
               {
                   if(sourav[o][u]>sourav[o][s]+sourav[s][u])
                   {
                       sourav[o][u] = sourav[o][s]+sourav[s][u];
                   }
               }
           }
       }

       v=0;
       for(i=0;i<N;i++)
       {
           for(j=0;j<N;j++)
           {
               if( i != j && sourav[i][j] != inf)
               {
                   v+=sourav[i][j];
               }
           }
       }
       m=majumder.size();
       m=(m*(m-1));
       printf("Case %d: average length between pages = %.3f clicks\n",++r,(double)v/m);
    }
    return 0;
}
