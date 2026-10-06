#include <vector>
#include <iostream>
#include <list>
#include <queue>

using namespace std;

class Graph{
public:
    int v;
    list<int>* l;
    Graph(int v){
        this->v = v;
        l = new list<int> [v];
    }

    void Edge(int a, int b){
        l[a].push_back(b);
        l[b].push_back(a);
    }

    void helper(int v, Graph g){
        vector<bool> vis(v, false);
        vector<bool> visbfs(v, false);
        // int src = 0;
        for(int i = 0; i < v; i++){
            if(!vis[i]){
               dfs(i, vis); 
            }
            if(!visbfs[i]){
               bfs(i, visbfs);
            }
            
        }
    }

    void dfs(int src, vector<bool>& vis){
        vis[src] = true;
        cout << src << " ";
        for(int e: l[src]){
            if(!vis[e]){
                dfs(e, vis);
            }
        }
    }

    void bfs(int src, vector<bool>& vis){
        queue<int> q;
        q.push(src);
        vis[src] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            cout << "node" << node << " ";

            for( auto e : l[node] ){
                if(!vis[e]){
                    vis[e] = true;
                    q.push(e);
                }
            }
        }
    }
};

int main(){
    int v = 3;
    Graph g(v);

    g.Edge(0,1);
    g.Edge(0,2);

    g.helper(v, g);
    
    return 0;
}