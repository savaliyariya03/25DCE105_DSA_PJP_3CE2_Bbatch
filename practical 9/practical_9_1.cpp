#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> graph[10];
bool visited[10];
void DFS(int start)
{
    visited[start]=true;
    cout<<start<<" ";
    for(int i=0;i<graph[start].size();i++)
    {
        int next=graph[start][i];
        if(!visited[next])
            DFS(next);
    }
}
void BFS(int start)
{
    bool visit[10]={false};
    queue<int> q;
    visit[start] = true;
    q.push(start);
    while(!q.empty())
    {
        int current=q.front();
        q.pop();
        cout<<current<<" ";
        for(int i=0;i<graph[current].size();i++)
        {
            int next=graph[current][i];
            if(!visit[next])
            {
                visit[next]=true;
                q.push(next);
            }
        }
    }
}
int main()
{
    int vertices, edges;
    int u, v, start;
    cout<<"Enter number of vertices: ";
    cin>>vertices;
    cout<<"Enter number of edges: ";
    cin>>edges;
    cout<<"Enter edges:\n";
    for(int i=0;i<edges;i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout<<"Enter starting vertex: ";
    cin>>start;
    cout<<"DFS Traversal: ";
    DFS(start);
    cout<<"\n";
    cout<<"BFS Traversal: ";
    BFS(start);
    return 0;
}
