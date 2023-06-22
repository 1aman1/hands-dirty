class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        height(root);
        return diameter;
    }

private:
    int diameter = 0;

    int height(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int leftHeight = height(root->leftHeight);
        int rightHeight = height(root->rightHeight);
        if (diameter < leftHeight + rightHeight)
            diameter = leftHeight + rightHeight;

        return 1 + max(leftHeight, rightHeight);
    }
};