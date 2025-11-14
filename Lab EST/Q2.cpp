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
    void dfs(vector<vector<int>> &nodes, int depth, int pos, TreeNode* n){
        if(!n) return;
        nodes.push_back({n->val, depth, pos});
        dfs(nodes, depth+1, pos-1, n->left);
        dfs(nodes, depth+1, pos+1, n->right);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> nodes;
        dfs(nodes, 0, 0, root);
        sort(nodes.begin(), nodes.end(), [](vector<int> &a, vector<int> &b){
            if(a[2] != b[2]) return a[2] < b[2];
            if(a[1] != b[1]) return a[1] < b[1];
            return a[0] < b[0];
        });
        int lastPos = -1e9;
        vector<vector<int>> ans;
        for(int i = 0; i < nodes.size(); i++){
            if(nodes[i][2] != lastPos){
                ans.push_back({nodes[i][0]});
            }else{
                ans.back().push_back(nodes[i][0]);
            }
            lastPos = nodes[i][2];
        }
        return ans;
    }
};
