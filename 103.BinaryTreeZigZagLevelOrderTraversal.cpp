class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        int count=0;
        while(!q.empty()){
            int size=q.size();
            vector<int>currAns(size);
            int i=0;
            while(i<size){
                TreeNode* front=q.front();
                q.pop();
                int index=(count%2==0)?i:(size-1-i);
                currAns[index]=front->val;
                if(front->left!=NULL){
                  q.push(front->left);
                }
                if(front->right!=NULL){
                    q.push(front->right);
                }
                i++;
            }
            ans.push_back(currAns);
            count++;

        }
        return ans;
    }
};
