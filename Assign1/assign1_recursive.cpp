#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int numVertices;
    list<int> *adjLists;
    bool *visited;

public:
    Graph(int vertex)
    {
        this->numVertices = vertex;
        this->adjLists = new list<int>[numVertices];
        this->visited = new bool[numVertices];
    }

    void addEdge(int vertex, int adjacent)
    {
        adjLists[vertex].push_front(adjacent);
    }

    void DFS(int vertex)
    {
        visited[vertex] = true;
        list<int> adjList = adjLists[vertex];

        if(adjList.empty()) {
            return;
        }
        cout << vertex << " ";

        list<int>::iterator i;
        for (i = adjList.begin(); i != adjList.end(); i++)
        {
            if (!visited[*i])
            {
                DFS(*i);
            }
        }
    }
};

int main()
{
    // int countOfVertices;
    // cout << "Enter the count of the vertices: ";
    // cin >> countOfVertices;

    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    // int initialVertice;
    // cout<<"Enter the initial vertice: ";
    // cin>>initialVertice;

    g.DFS(2);

    return 0;
}