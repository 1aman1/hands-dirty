#include <iostream>
#include <queue>
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
    int tree_value_recursive(node_t *);

public:
    int tree_value_recursive();

    int tree_value_iterative();
};

int Solution::tree_value_iterative()
{
    if (root == nullptr)
        return 0;

    std::queue<node_t *> queue;
    int Sum = root->data;

    queue.push(root);

    while (!queue.empty())
    {
        node_t *tmp = queue.front();
        queue.pop();

        if (tmp->left)
        {
            Sum += tmp->left->data;
            queue.push(tmp->left);
        }
        if (tmp->right)
        {
            Sum += tmp->right->data;
            queue.push(tmp->right);
        }
    }

    return Sum;
}

int Solution::tree_value_recursive()
{
    return tree_value_recursive(root);
}

int Solution::tree_value_recursive(node_t *currNodePtr)
{
    if (currNodePtr == nullptr)
        return 0;

    return (currNodePtr->data +
            tree_value_recursive(currNodePtr->left) +
            tree_value_recursive(currNodePtr->right));
}

int main()
{
    std::cout << "Building " << __FILE__ << std::endl;

    Solution *tobj = new Solution();

    tobj->insert(7);
    tobj->insert(3);
    tobj->insert(10);
    tobj->insert(80);
    tobj->insert(100);

    std::cout << tobj->tree_value_recursive() << "\n";
    std::cout << tobj->tree_value_iterative() << "\n";

    return 0;
}
