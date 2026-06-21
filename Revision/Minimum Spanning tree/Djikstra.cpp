#include <iostream>
#include <vector>
#include <queue>

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

void dijikstra(int src, vector<vector<Edge>> g, int v){
    vector<int> dist(v, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while(pq.size() > 0){
        int u = pq.top().second;
        pq.pop();

        for(Edge e: g[u]){   // each edge using the u that we have taken in the work
            if(dist[e.v] > dist[u] + e.wt){
                dist[e.v] = dist[u] + e.wt;
                pq.push({dist[e.v], e.v});
            }
        }
    }
    for(int i = 0; i < v; i++){
        cout<< dist[i];
    }
    cout<< endl;
}

int main() {
    int V = 5;

    vector<vector<Edge>> g(v);
    g[0].push_back(Edge(1,2));
    g[0].push_back(Edge(2,4));

    g[1].push_back(Edge(4,7));
    g[1].push_back(Edge(2,1));

    g[2].push_back(Edge(3, 3));

    g[3].push_back(Edge(4, 2));
    g[3].push_back(Edge(5, 5));

    g[4].push_back(Edge(5, 1));

    djikstra(0, g, V);

    return 0;
}
