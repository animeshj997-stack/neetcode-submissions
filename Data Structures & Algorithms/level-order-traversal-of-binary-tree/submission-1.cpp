/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(!root) return res;
        q.push(root);

    while(!q.empty()){
        int s = q.size();
        vector<int> temp;
        while(s){
            TreeNode* n=q.front();
            q.pop();
            if(n->left)
              q.push(n->left);
            if(n->right)
              q.push(n->right);
            s--;   
            temp.push_back(n->val); 
        }
          res.push_back(temp);
    }

    return res;
    }
};
