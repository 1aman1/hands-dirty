class Solution
{
public:
    int goodNodes(TreeNode *root)
    {
        int result = 0;
        searchGoodNodes(root, root->val, result);

        return result;
    }

    void searchGoodNodes(TreeNode *root, int maxSoFar, int &result)
    {
        if (root == nullptr)
            return;

        if (root->val >= maxSoFar)
            ++result;

        searchGoodNodes(root->left, max(maxSoFar, root->val), result);
        searchGoodNodes(root->right, max(maxSoFar, root->val), result);
    }
};