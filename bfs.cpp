#include<iostream>  // cout
#include<queue>     // queue
#include<list>      // list
using namespace std;
class Graph{
    int V;
    list<int> *adj;    // adjacency list
public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }        
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }
    void BFS(int s) {
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++) {
            visited[i] = false;
        }
        // create a queue
        list<int> queue;
        visited[s] = true;
        queue.push_back(s);

        // use i to get all neighbors of a node
        list<int>::iterator it;
        while (!queue.empty()) {
            s = queue.front();
            cout << s << " ";
            queue.pop_front();
            // visit all unvisited neighbors
            for (it = adj[s].begin(); it != adj[s].end(); ++it) {
                if (!visited[*it]) {
                    visited[*it] = true;
                    queue.push_back(*it);
                }
            }
        }
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout << "BFS traversal\n";
    g.BFS(2);
    return 0;
}
