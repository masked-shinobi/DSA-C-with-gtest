queue<TreeNode*> q;
q.push(root);

int maxSum = INT_MIN;

while(!q.empty()) {

int size = q.size();      // nodes in current level
int levelSum = 0;

for(int i = 0; i < size; i++) {

TreeNode* curr = q.front();
q.pop();

levelSum += curr->value;

if(curr->left)
q.push(curr->left);

if(curr->right)
q.push(curr->right);
}

maxSum = max(maxSum, levelSum);
}

cout << "Max Level Sum : " << maxSum;