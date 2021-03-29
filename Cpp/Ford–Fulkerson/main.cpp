// C++ program for implementation of Ford Fulkerson algorithm 
#include<cstdio>
#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
#include<iostream>

using namespace std;

int capacities[10][10];
int flowPassed[10][10];
vector<int> graph[10];
int parentsList[10];
int currentPathCapacity[10];

int bfs(int startNode, int endNode)
{
    memset(parentsList, -1, sizeof(parentsList));
    memset(currentPathCapacity, 0, sizeof(currentPathCapacity));

    queue<int> q;
    q.push(startNode);

    parentsList[startNode] = -2;
    currentPathCapacity[startNode] = 999;

    while(!q.empty())
    {
        int currentNode = q.front();
        q.pop();

        for(int i=0; i<graph[currentNode].size(); i++)
        {
            int to = graph[currentNode][i];
            if(parentsList[to] == -1)
            {
                if(capacities[currentNode][to] - flowPassed[currentNode][to] > 0)
                {
                    parentsList[to] = currentNode;
                    currentPathCapacity[to] = min(currentPathCapacity[currentNode],
                                                  capacities[currentNode][to] - flowPassed[currentNode][to]);
                    if(to == endNode)
                    {
                        return currentPathCapacity[endNode];
                    }
                    q.push(to);
                }
            }
        }
    }
    return 0;
}

int edmondsKarp(int startNode, int endNode)
{
    int maxFlow = 0;
    while(true)
    {
        int flow = bfs(startNode, endNode);
        if (flow == 0)
        {
            break;
        }
        maxFlow += flow;
        int currentNode = endNode;
        while(currentNode != startNode)
        {
            int previousNode = parentsList[currentNode];
            flowPassed[previousNode][currentNode] += flow;
            flowPassed[currentNode][previousNode] -= flow;
            currentNode = previousNode;
        }
    }
    return maxFlow;
}
int main()
{

    int graphs[5][5] = { {0, 20, 30, 10, 0},
                        {0, 0, 40, 0, 30},
                        {0, 0, 0, 10, 20},
                        {0, 0, 0, 0, 20},
                        {0, 0, 0, 0, 0}
    };

    cout<<"enter the number of nodes and edges\n";

    int source, sink;
    cout<<"enter the source and sink\n";

    for(int i=0; i<5; ++i){
        for(int j=0; j<5; ++j){
            if(graphs[i][j]!=0) {

                capacities[i][j] = graphs[i][j];
                graph[i].push_back(j);
                graph[j].push_back(i);

            }
        }
    }
    sink = 4;
    source = 0;

    int maxFlow = edmondsKarp(source, sink);

    cout<<endl<<endl<<"Max Flow is:"<<maxFlow<<endl;


}
