#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge{
public:
    int u,v,wt;
    Edge(int u, int v, int wt){
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
    // add custom operator to make the sorting based in the wt
    bool operator<(const Edge &other) const {
        return this->wt < other.wt;
    }
};

class Graph{
public:
    int v;
    vector<Edge> edges;
    vector<int> par, rank;
    Graph(int v){
        this->v = v;
        for(int i = 0; i < v; i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }

    void addEdge(int u, int v, int wt){
        edges.push_back(u, v, w);
    }

    void unionbyrank(int a, int b){
        int parA = find(a);
        int parB = find(b);

        if(parA == parB){
            return;
        }
        // core logic
        if(rank[parA] == rank[parB]){
            par[parB] = parA;
            par[parA]++;
        }
        else if(rank[parA] > rank[parB]){
            par[parB] = parA;
        }
        else{
            par[parA] = parB;
        }
    }

    int find(int x){
        if(par[x] == x){
            return x;
        }
        return par[x] = find(x);
    }

    void kruskal(){
        sort(edges.begin(), edges.end());
        int mincost = 0;
        for( int i = 0; i < edges.size(), i++){
            Edge e = edges[i];
            int parU = find(e.u);
            int parV = find(e.v);
            if(parU != parV){
                unionbyrank(e.u, e.v);
                mincost += e.wt;
            }
        }
        cout << mincost << endl;
    }
};

// when we need edges:
// add - vector<Edge> MST;
// inside if add this line : add each e that satisfied all those

// optimisation loop running can be stoped after v-1 nodes added
// before loop : count = 0;
// inside loop condition add : (i = 0; i < edges.size() && count < v - 1; i++)
// inside if condition : count ++ that satisfies condition

int main() {
    Graph graph(4);
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 1, 10);

    return 0;
}