#include <iostream>
#include <vector>

#define DEBUG false

struct TreeNode
{
    int node_data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int newdata) : node_data(newdata),
                            left(nullptr),
                            right(nullptr) {}
};

class tree
{
public:
    TreeNode *root;
    tree();
    void inOrder(TreeNode *);
};

tree::tree()
{
    root = nullptr;
}

void insertInSeq(tree &treeObj, int arr[], int left, int right)
{
    if (right >= left)
    {
        int mid = (right - left) / 2 + left;
        std::cout << arr[mid] << std::endl;

        insertInSeq(treeObj, arr, left, mid - 1);
        insertInSeq(treeObj, arr, mid + 1, right);
    }
    return;
}

TreeNode *sortedArrayToBSTHelper(const std::vector<int> &nums, int left, int right)
{
    if (left > right)
        return nullptr;

    int mid = left + (right - left) / 2;
    TreeNode *root = new TreeNode(nums[mid]);

    root->left = sortedArrayToBSTHelper(nums, left, mid - 1);
    root->right = sortedArrayToBSTHelper(nums, mid + 1, right);

    return root;
}

TreeNode *sortedArrayToBST(const std::vector<int> &nums)
{
    return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
}

void tree::inOrder(TreeNode *ptr)
{
    if (!ptr)
        return;

    inOrder(ptr->left);
    std::cout << ptr->node_data << std::endl;
    inOrder(ptr->right);
}

int main()
{
    tree treeObj;
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};

    // insertInSeq(treeObj, arr, 0, 6);
    treeObj.root = sortedArrayToBST(nums);
    treeObj.inOrder(treeObj.root);

    return 0;
}