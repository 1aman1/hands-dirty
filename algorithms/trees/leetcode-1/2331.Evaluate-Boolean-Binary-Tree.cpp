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
class Solution
{
public:
    bool evaluateTree(TreeNode *root)
    {
        /*
        Null, return
        otherwise
        check root value, based on that execute & or with left & right
        */
        int current_val = root->val;
        if (root->left == nullptr)
        {
            if (current_val == 0)
                return false;
            else
                return true;
        }
        else
        {
            bool result;
            if (current_val == 2)
            {
                return evaluateTree(root->left) || evaluateTree(root->right);
            }
            else // if (current_val == 3)
            {
                return evaluateTree(root->left) && evaluateTree(root->right);
            }
        }
    }
};