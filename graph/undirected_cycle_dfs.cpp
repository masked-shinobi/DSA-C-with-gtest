#include <vector>
#include <iostream>
#include <list>

using namespace std;

class Graph{
    int v;
    list<int> *l;
public:
    Graph(int v){
        this->v = v;
        l = new list<int>[v];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool iscycleundirdfs(int src, int par, vector<bool> &vis){
        vis[src] = true;

        for(int v: l[src]){
            if(!vis[v]){
                if(iscycleundirdfs(v, src, vis)){
                    return true;
                }
            }else if(v != par){
                return true;
            }
        }
        return false;
    }

    bool isCycle(){
        vector<bool> vis(v, false);

        for(int i = 0; i < v; i++){
            if(!vis[i]){
                if(iscycleundirdfs(i, -1, vis)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);

    if(g.isCycle()){
        cout << "Cycle detected\n";
    } else {
        cout << "No cycle\n";
    }

    return 0;
}