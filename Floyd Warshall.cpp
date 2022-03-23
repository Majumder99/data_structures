#include<bits/stdc++.h>
using namespace std;
#define INF 10000
int main()
{
    int graph[4][4] =
    {
        {0,3,INF,7},
        {8,0,2,INF},
        {5,INF,0,1},
        {2,INF,INF,0}
    };
    int k,i,j;
    for(k=0; k<4; k++)
    {
        for(i=0; i<4; i++)
        {
            for(j=0; j<4; j++)
            {
                graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
            }
        }
    }


//    for(i=0; i<4; i++)
//    {
//        for(k=0; k<4; k++)
//        {
//            for(j=0; j<4; j++)
//            {
//                graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
//            }
//        }
//
//    }

    for( i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
