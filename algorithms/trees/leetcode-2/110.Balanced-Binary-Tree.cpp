class Solution
{

public:
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return true;

        return isBalanced(root->left) && isBalanced(root->right) && (abs(maxDepth(root->left) - maxDepth(root->right)) <= 1);
    }

private:
    int maxDepth(TreeNode *root)
    {
        return root == nullptr ? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
