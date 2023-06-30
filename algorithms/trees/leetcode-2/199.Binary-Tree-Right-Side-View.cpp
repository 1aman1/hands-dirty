class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;

        if (root == nullptr)
            return result;

        queue<TreeNode *> myQueue;
        myQueue.push(root);

        while (!myQueue.empty())
        {
            int levelSize = myQueue.size();

            for (int i = 0; i < levelSize; ++i)
            {
                TreeNode *popFront = myQueue.front();
                myQueue.pop();

                if (i == levelSize - 1)
                {
                    result.push_back(popFront->val);
                }

                if (popFront->left != nullptr)
                {
                    myQueue.push(popFront->left);
                }
                if (popFront->right != nullptr)
                {
                    myQueue.push(popFront->right);
                }
            }
        }

        return result;
    }
};