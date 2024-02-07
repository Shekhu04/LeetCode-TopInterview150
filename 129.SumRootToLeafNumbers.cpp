class Solution {
public:
    int sumNumbers(TreeNode* root, string number = "") {
        if (!root)
            return 0;

        number += std::to_string(root->val);

        if (!root->left && !root->right)
            return stoi(number);

        int result1 = sumNumbers(root->left, number);
        int result2 = sumNumbers(root->right, number);

        return result1 + result2;
    }
};
