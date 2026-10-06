#include <iostream>
#include <vector>
#include <queue>
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

    // boundary driver
    vector<int> boundarydriver(TreeNode* root){
        vector<int> ans;
        if(root== nullptr)  return ans;
        ans.push_back(root->value);
        leftboundary(root, ans);
        leaves(root->left, ans);
        leaves(root->right, ans);
        rightboundary(root, ans);
        return ans;
    }   

    // leaves
    void leaves(TreeNode* root, vector<int>& ans){
        if(root == nullptr) return;

        if(root->left == nullptr && root->right == nullptr){
            ans.push_back(root->value);
        }

        leaves(root->left, ans);
        leaves(root->right, ans);
    }

    // left boundary 
    void leftboundary(TreeNode* root, vector<int>& ans){
        TreeNode* curr = root -> left;
        while(curr){
            if(curr->left || curr->right){
                ans.push_back(curr->value);
            }
            if(curr->left){
                curr = curr->left;
            }
            else{
                curr = curr->right;
            }
        }
    }

    // right boundary
    void rightboundary(TreeNode* root, vector<int>& ans){
        TreeNode* curr = root -> right;
        vector<int> temp;
        while(curr){
            if(curr->left || curr->right){
                temp.push_back(curr->value);
            }
            if(curr->right){
                curr = curr->right;
            }
            else{
                curr = curr->left;
            }
        }
        reverse(temp.begin(), temp.end());
        for(int element : temp){
            ans.push_back(element);
        }
    }
};

#include <iostream>
#include <vector>
using namespace std;

int main() {

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> ans = root->boundarydriver(root);

    cout << "Boundary Traversal: ";
    for(int x : ans){
        cout << x << " ";
    }

    return 0;
}