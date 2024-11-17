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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;

        if (root == nullptr)
            return result;

        queue<TreeNode *> myQueue;
        myQueue.push(root);

        while (!myQueue.empty())
        {
            int levelSize = myQueue.size();
            vector<int> levelResult;

            for (int i = 0; i < levelSize; ++i)
            {
                TreeNode *popFront = myQueue.front();
                myQueue.pop();

                levelResult.push_back(popFront->val);

                if (popFront->left != nullptr)
                {
                    myQueue.push(popFront->left);
                }
                if (popFront->right != nullptr)
                {
                    myQueue.push(popFront->right);
                }
            }

            result.push_back(levelResult);
        }

        return result;
    }
};