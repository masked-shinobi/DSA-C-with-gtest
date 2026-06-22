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

void inorder(TreeNode* root){
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->value << " ";
    inorder(root-> right);
}

int height(TreeNode* root){
    // LOGIC
// height(root)
//    if root == nullptr
//        return -1
//
//    leftHeight = height(root->left)
//    rightHeight = height(root->right)
//
//    return 1 + max(leftHeight, rightHeight)
    if(root == nullptr) return -1;

    int leftheight = height(root->left);
    int rightheight = height(root->right);

    return 1 + max(leftheight, rightheight);
}
int leaves(TreeNode* root){

//     LOGIC

// if root == nullptr
//    return 0

// if root is leaf
//    return 1

// return leaf(left) + leaf(right)
    if(root == nullptr) return 0;

    if(root->left == nullptr && root->right == nullptr){
        return 1;
    }

    return leaves(root->left) + leaves(root->right);
}

int internalcount(TreeNode* root){
    // LOGIC
// internal(root)
//
//if root == nullptr
//    return 0
//
//if root is leaf
//    return 0
//
//return 1
//       + internal(left)
//       + internal(right)
    if(root == nullptr) return 0;

    if(root->left == nullptr && root->right == nullptr){
        return 0;
    }

    return 1 + internalcount(root->left) + internalcount(root->right);
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

    inorder(root);
    cout << endl;

    cout << "height : " << height(root) << endl;
    cout << "leaves" << leaves(root) << endl;
    cout << "internal count" << internalcount(root) << endl;

    return 0;
}
