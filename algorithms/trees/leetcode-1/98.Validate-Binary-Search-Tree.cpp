class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        return isValidBST(LONG_MIN, root, LONG_MAX);
    }

private:
    bool isValidBST(long MIN, TreeNode *root, long MAX)
    {
        if (root != nullptr)
        {
            if (MIN < root->val && root->val < MAX)
                return isValidBST(MIN, root->left, root->val) &&
                       isValidBST(root->val, root->right, MAX);

            return false;
        }

        return true;
    }
};