#include <iostream>
#include <stack>
#include <list>

struct node_t
{
    int data;
    node_t *left;
    node_t *right;

    node_t() = delete;

    node_t(int newData) : data(newData),
                          left(nullptr),
                          right(nullptr) {}
};

class Tree
{
public:
    Tree();

    void
    insert(int);

protected:
    node_t *root;

    virtual node_t *
    _insertUtil(node_t *, int);
};

Tree::Tree() : root(nullptr) {}

void Tree::insert(int newData)
{
    root = _insertUtil(root, newData);
}

node_t *Tree::_insertUtil(node_t *currNodePtr, int newData)
{
    if (!currNodePtr)
        return new node_t(newData);

    if (newData < currNodePtr->data)
        currNodePtr->left = _insertUtil(currNodePtr->left, newData);

    else
        currNodePtr->right = _insertUtil(currNodePtr->right, newData);

    return currNodePtr;
}

//______SOLUTION_______//

class Solution : public Tree
{
    static constexpr int INFINITY_NEG = -99999999;

    int max_root_to_leaf_sum(node_t *);

public:
    int max_root_to_leaf_sum();
};

int Solution::max_root_to_leaf_sum()
{
    return max_root_to_leaf_sum(root);
}

int Solution::max_root_to_leaf_sum(node_t *currNodePtr)
{
    if (currNodePtr == nullptr)
        return INFINITY_NEG;

    if (currNodePtr->left == nullptr && currNodePtr->right == nullptr)
        return currNodePtr->data;

    int leftMax = INFINITY_NEG;
    int rightMax = INFINITY_NEG;

    if (currNodePtr->left)
        leftMax = max_root_to_leaf_sum(currNodePtr->left);
    if (currNodePtr->right)
        rightMax = max_root_to_leaf_sum(currNodePtr->right);

    return std::max(leftMax, rightMax) + currNodePtr->data;
}

int main()
{
    std::cout << "Building " << __FILE__ << std::endl;

    Solution *tobj = new Solution();

    tobj->insert(7);
    tobj->insert(3);
    tobj->insert(20);
    tobj->insert(80);
    tobj->insert(100);

    std::cout << tobj->max_root_to_leaf_sum() << "\n";

    return 0;
}
