class Solution
{
public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr)
            return false;

        if (matchTrees(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

private:
    bool matchTrees(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr && subRoot == nullptr)
            return true;

        if (root == nullptr || subRoot == nullptr)
            return false;

        if (root->val != subRoot->val)
            return false;

        return matchTrees(root->left, subRoot->left) && matchTrees(root->right, subRoot->right);
    }
};