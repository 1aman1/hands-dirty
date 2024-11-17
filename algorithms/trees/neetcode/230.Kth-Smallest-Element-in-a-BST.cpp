/*
    Given root of BST & int k, return kth smallest value (1-indexed) of all values in tree
    Ex. root = [3,1,4,null,2] k = 1 -> 1, root = [5,3,6,2,4,null,null,1] k = 3 -> 3

    Inorder traversal, each visit decrement k, when k = 0 return, works because inOrder

    Time: O(n)
    Space: O(n)
*/

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
    int kthSmallest(TreeNode *root, int k)
    {
        int result = 0;
        inOrder(root, k, result);
        return result;
    }

private:
    void inOrder(TreeNode *root, int &k, int &result)
    {
        if (root != nullptr)
        {
            inOrder(root->left, k, result);
            if (--k == 0)
            {
                result = root->val;
                return;
            }
            inOrder(root->right, k, result);
        }
    }
};
