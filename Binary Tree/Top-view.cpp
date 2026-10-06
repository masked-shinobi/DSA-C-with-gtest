#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

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

    vector<int> topview(TreeNode* root){
        vector<int> ans;
        if(root == nullptr) return;

        map<int, int> mp;

        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});

        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            TreeNode* node = curr.first;
            int hd = curr.second;

            if(mp.count(hd) == 0){ // count is similar to find()
                mp[hd] = node->value;
            }
            if(node->left){
                q.push({node->left, hd - 1});
            }
            if(node->right){
                q.push({node->right, hd + 1});
            }
        }
        for( auto p : mp ){
            ans.push_back(p.second);
        }
        return ans;
    }

    
};