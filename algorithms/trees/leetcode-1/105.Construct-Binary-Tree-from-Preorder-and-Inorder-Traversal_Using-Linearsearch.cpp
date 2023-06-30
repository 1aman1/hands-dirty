#include <iostream>
#include <unordered_map>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    int getIndex(const std::vector<int> &inOrder,
                 int left, int right,
                 int target)
    {
        for (int i = left; i <= right; ++i)
            if (inOrder[i] == target)
                return i;
                
        return -1;
    }

    TreeNode *buildTree(const std::vector<int> &preOrder, const std::vector<int> &inOrder,
                        int &fillerIndex,
                        int left, int right)
    {
        if (left > right)
            return nullptr;

        TreeNode *root = new TreeNode(preOrder[fillerIndex++]);

        int mid = getIndex(inOrder, left, right, root->val);

        root->left = buildTree(preOrder, inOrder, fillerIndex, left, mid - 1);
        root->right = buildTree(preOrder, inOrder, fillerIndex, mid + 1, right);

        return root;
    }

public:
    TreeNode *buildTree(std::vector<int> &preOrder, std::vector<int> &inOrder)
    {
        int fillerIndex = 0;

        return buildTree(preOrder, inOrder, fillerIndex, 0, inOrder.size() - 1);
    }
};

class tree : public Solution
{
public:
    TreeNode *root;

    // views
    void inOrderView(TreeNode *currPtr);
    void preOrderView(TreeNode *currPtr);
};

void tree::inOrderView(TreeNode *currPtr)
{
    if (!currPtr)
    {
        return;
    }

    inOrderView(currPtr->left);

    std::cout << currPtr->val << "\t";

    inOrderView(currPtr->right);
}

void tree::preOrderView(TreeNode *currPtr)
{
    if (!currPtr)
    {
        return;
    }
    std::cout << currPtr->val << "\t";

    preOrderView(currPtr->left);
    preOrderView(currPtr->right);
}

int main()
{
    std::cout << __FILE__ << std::endl;

    std::vector<int> inOrderSeq = {4, 2, 1, 7, 5, 8, 3, 6};
    std::vector<int> preOrderSeq = {1, 2, 4, 3, 5, 7, 8, 6};

    // tree obj;
    tree obj;

    obj.root = obj.buildTree(inOrderSeq, preOrderSeq);

    std::cout << std::endl;
    obj.inOrderView(obj.root);

    std::cout << std::endl;
    obj.preOrderView(obj.root);

    std::cout << std::endl;
    return 0;
}