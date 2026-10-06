#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <list>

using namespace std;

class TreeNode{
public:
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value){
        this->value = value;
        left = nullptr;
        right = nullptr;
    }

    void inorderTraversal(TreeNode* root){
        if(root == nullptr) return;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            cout << curr->value << " ";

            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }

    

};

// int main() {
//     vector<string> arr;
//     string x;

//     while(cin >> x){
//         arr.push_back(x);
//     }

//     if(!arr.empty()) return 0;

//     TreeNode* root = new TreeNode(stoi(arr[0]));

//     queue<TreeNode*> q;
//     q.push(root);

//     int i = 1;
//     while(i <= arr.size() && !q.empty()){
//         TreeNode* curr = q.front();
//         if(i <= arr.size() && arr[i] != "N"){
//             curr->left = new TreeNode(stoi(arr[i]));
//             q.push(curr->left);
//         }
//         i++;
//         if(i <= arr.size() && !q.empty()){
//             curr->right = new TreeNode(stoi(arr[i]));
//         }
//         i++;
//     }


    
}


class Graph{
public:
    int v;
    list<int> *l;
    Graph(int v){
        this->v = v;
        l = new list<int> [v];
    }

    void addEdge(int a, int b){
        l[a].push_back(b);
        l[b].push_back(a);
    }

    void dfshelper( int src, vector<bool> vis ){
        cout<< src << " ";
        vis[src] = true;
        for(int v: vis){
            dfshelper(v, vis);
        }
    }

    void dfs(){
        int src = 0;
        vector<bool> vis(v, false);

        dfshelper(src, vis);
    }

    void bfs(){
        vector<bool> vis(v, false);

        queue<int> q;

        q.push(0);
        vis[0] = true;

        while(!q.empty()){
            int src = q.front();
            q.pop();

            vis[src] = true;

            for(auto v : l[src]){
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }
}


int main() {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.dfs();
    return 0;
}