#include <iostream>
#include <vector>

using namespace std;

class Edge{
public:
    int v;
    int wt;
    Edge(int v, int wt){
        this->v = v;
        this->wt = wt;
    }
};

void bellamford(int src, vector<vector<Edge>> g, int v){
    vector<int> dist(v, INT_MAX);

    dist[src] = 0;

    for( int i = 0; i < v - 1; i++){
        for( int u = 0; u < v; u++){
            for( Edge e : g[u]){
                if(dist[e.v] > (dist[u] + e.wt)){
                    dist[e.v] = dist[u] + e.wt;
                }
            }
        }
    }
    for(int i = 0; i < v; i++){
        cout << dist[i];
    }
    cout << endl;
}

int main() {
    int v = 5;
    vector<vector<Edge>> g(v);
    g[0].push_back(Edge(2, 3));
    bellamford(0, g, v);
    return 0;
}