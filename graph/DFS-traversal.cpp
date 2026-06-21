#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph{
public:
    int v;
    list<int> *l;
    Graph(int v){
        this->v = v;
        l = new list<int> [v];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void dfshelper(int u, vector<bool>& vis){
        cout << u << " ";
        vis[u] = true;

        for( int v : l[u]){
            if(!vis[v]){
                dfshelper(v, vis);
            }
        }
    }

    void dfs(){
        int src = 0;
        vector<bool> vis(v, false);
        // call this function
        dfshelper(src, vis);


        // for disconnected graph
//        for( int i = 0; i < v; i++){
//            if(!vis[i]){
//                dfshelper(i, vis);
//            }
//        }
    }
};


int main() {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.dfs();
    return 0;
}