#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    // constructor
    TreeNode (int data){
        val = data;
        left = nullptr;
        right = nullptr;
    }
};

int main() {

    // Node creation
    TreeNode* root = new TreeNode(23);
    root->left = new TreeNode(12);
    root->right = new TreeNode(2);
    // queue that we use is only for the storing of node
    // exact purpose we use queue for adding nodes as waiting list so these nodes need their children to be assigned
    queue<TreeNode*> q;
    q.push(root);

    // making to point the first node
    TreeNode* curr = q.front();
    q.pop();



    return 0;
}