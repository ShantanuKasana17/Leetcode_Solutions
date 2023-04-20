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
    int widthOfBinaryTree(TreeNode* root) {
    	size_t ans = 1;
    	if(root){
    		queue<pair<TreeNode*, size_t>> q;
    		q.push({root, 0});
    		
    		while(!q.empty()){
				ans = max(ans, q.back().second-q.front().second+1);
    			int size = q.size();
    			for(int i = 0; i<size; i++){
    				TreeNode* current = q.front().first;
    				size_t curInd = q.front().second;
    				q.pop();
    				if(current->left){
    					q.push({current->left, curInd*2});
    				}
    				if(current->right){
    					q.push({current->right, curInd*2+1});
    				}
    			}
    		}
    	}
    	return (int)ans;   
    }
};
