#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct TreeNode{
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        value = x;
        left = nullptr;
        right = nullptr;
    }
};

void inorder(TreeNode* root, int& count, int& sum){
    if(root == nullptr) return;

    inorder(root->left, count, sum);
    cout << root->value << " ";
    count++;
    sum += root->value;
    inorder(root->right, count, sum);
}

void preorder(TreeNode* root){

    if(root == nullptr) return;

    cout << root->value << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    // 1 N 2
    // 4 3 2 5 6 7 3 5
    vector<string> a;
    string x;
    while(cin >> x){
        a.push_back(x);
    }
    TreeNode* root = new TreeNode(stoi(a[0]));

    // queue
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while(!q.empty() && i < a.size()){
        TreeNode* curr = q.front();
        q.pop();

        //children
        if(i < a.size() && a[i] != "N"){
            curr->left = new TreeNode(stoi(a[i]));
            q.push(curr->left);
        }
        i++;

        if(i < a.size() && a[i] != "N")
        {
            curr->right = new TreeNode(stoi(a[i]));
            q.push(curr->right);
        }
        i++;

    }
    int count = 0;
    int sum = 0;
    inorder(root, count, sum);
    cout << endl;
    preorder(root);
    cout << "sum : " << sum << " " << "count"<<  count << endl;
    return 0;
}
