#include <queue>
#include <iostream>
#include <vector>

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


void inorder(TreeNode* root, int& sum, int& count){
    if(root == nullptr) return;
    inorder(root->left, sum, count);
    cout << root->value << " ";
    count++;
    sum += root->value;
    inorder(root-> right, sum, count);
}

void preorder(TreeNode* root){
    if(root == nullptr) return;
    cout<< root->value << " ";
    preorder(root-> left);
    preorder(root-> right);
}

void postorder(TreeNode* root){
    if(root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout<< root->value << " ";
}

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

    int sum = 0, count = 0;
    inorder(root, sum, count);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;

    cout << "sum : " << sum << " " << "count"<<  count << endl;

    return 0;
}

// logic
// 1. Read all tokens into nodes

// 2. Create root using nodes[0]

// 3. Push root into queue

// 4. Start from i = 1

// 5. While queue not empty and i < nodes.size()
//
//      curr = q.front()
//      q.pop()
//
//      use nodes[i] as left child
//      i++
//
//      use nodes[i] as right child
//      i++