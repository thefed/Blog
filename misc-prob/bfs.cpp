// impl BFS on a graph
#include <iostream>  
#include <queue>    
#include <list>          // list, store adjacenct nodes as a linked list
#include <vector>   
#include <cassert>   
using namespace std;
class Graph{
    int V;              // number of vertices
    list<int> *adj;     // adjacency list
public:
    Graph(int V): V(V){
        adj = new list<int>[V];
    }        
    
    // add an edge {v, w}, insert node w to v's adjacency list
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    vector<int> BFS(int s) {   // s: src node index
        vector<int> res;        // returned traversal list
        vector<char> visited(V, 0);
        // create a queue
        list<int> queue;
        visited[s] = 1; // mark as visited
        queue.push_back(s);

        // use i to get all neighbors of a node
        list<int>::iterator it;
        while (!queue.empty()) {
            s = queue.front();
            queue.pop_front();
            res.push_back(s);
            //cout << s << " ";
            // visit all unvisited neighbors
            for (it = adj[s].begin(); it != adj[s].end(); ++it) {
                if (!visited[*it]) {
                    visited[*it] = 1;
                    queue.push_back(*it);
                }
            }
        }
        return res;
    }
};

void print(const vector<int>& v, string msg="") {
    cout << msg;
    for (int i : v) printf("%d ", i);
    printf("\n");
}
int main() {
    /*
    * 0 - 1
    * |   |
    * 2 --+
    * |/\
    * 3-+
    */
    int numOfNodes = 4;
    vector<vector<int> > edges = {
        {0, 1}, {0, 2}, {1, 2}, 
        {2, 0}, {2, 3}, {3, 3}};
    Graph g(numOfNodes);
    for (auto &it : edges) g.addEdge(it[0], it[1]);
    // g.addEdge(0, 1);
    // g.addEdge(0, 2);
    // g.addEdge(1, 2);
    // g.addEdge(2, 0);
    // g.addEdge(2, 3);
    // g.addEdge(3, 3);
    cout << "BFS traversal\n";
    int src = 2;
    vector<int> res = g.BFS(src);
    print(res, "from node 2: ");
    assert(res == (vector<int> {2,0,3,1}));

    src = 0;
    res = g.BFS(src);
    print(res, "from node 0: ");
    assert(res == (vector<int> {0,1,2,3}));
    return 0;
}
