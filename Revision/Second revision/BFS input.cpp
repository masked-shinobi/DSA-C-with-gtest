#include <queue>
#include <iostream>
#include <string>
#include <algorithm>

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
    
};

int main() {

    // handle both case
    // 1 N 2
    //  4 2 6 1 3 5 7
    vector<string> a;
    string x;

    while(cin >> x){
        a.push_back(x);
    }

    // check whether the input exist
    if(a.empty()){
        return 0;
    }
    // create root and also make the element to int using stoi
    TreeNode* root = new TreeNode(stoi(a[0]));

    // queue creation
    queue<TreeNode*> q;
    q.push(root);

    // create curr pointer logic
    int i = 1; // as we have used 0 index for the root
    while(!q.empty() && i < a.size()){
        // added current and pointed to front
        TreeNode* curr = q.front();
        q.pop();
        // left node logic
        if(i < a.size() && a[i] != "N"){
            curr->left = new TreeNode(stoi(a[i]));
            q.push(curr->left);
        }
        i++;
        // right node logic
        if(i < a.size() && a[i] != "N"){
            curr->right = new TreeNode(stoi(a[i]));
            q.push(curr->right);
        }
        i++;
    }



    return 0;
}