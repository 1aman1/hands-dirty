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
    bool isCompleteTree(TreeNode *root)
    {
        // base case where initially the root is empty
        if (!root)
            return true;

        queue<TreeNode *> myQueue;
        myQueue.push(root);

        bool foundNullNode = false;

        while (!myQueue.empty())
        {
            TreeNode *root = myQueue.front();
            myQueue.pop();

            if (root == nullptr)
            {
                foundNullNode = true;
            }
            else
            {
                if (foundNullNode == true)
                {
                    return false;
                }
                else
                {
                    myQueue.push(root->left);
                    myQueue.push(root->right);
                }
            }
        }

        return true;
    }
};