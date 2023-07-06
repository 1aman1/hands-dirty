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
    bool includes_recursive(node_t *, int);

public:
    bool includes_iterative(int);

    bool includes_recursive(int);
};

bool Solution::includes_iterative(int target)
{
    if (root == nullptr)
        return false;

    else if (root->data == target)
        return true;

    else
    {
        std::queue<node_t *> queue;
        queue.push(root);

        while (!queue.empty())
        {
            node_t *tmp = queue.front();
            queue.pop();

            if (tmp->left)
            {
                if (tmp->left->data == target)
                    return true;
                queue.push(tmp->left);
            }
            if (tmp->right)
            {
                if (tmp->right->data == target)
                    return true;
                queue.push(tmp->right);
            }
        }
    }

    return false;
}

bool Solution::includes_recursive(int target)
{
    return includes_recursive(root, target);
}

bool Solution::includes_recursive(node_t *currNodePtr, int target)
{
    if (currNodePtr == nullptr)
        return false;

    if (currNodePtr->data == target)
        return true;

    return (includes_recursive(currNodePtr->left, target) || includes_recursive(currNodePtr->right, target));
}

int main()
{
    std::cout << "Building " << __FILE__ << std::endl;

    Solution *tobj = new Solution();

    tobj->insert(7);
    tobj->insert(3);
    tobj->insert(5);
    tobj->insert(1);
    tobj->insert(9);
    tobj->insert(10);
    tobj->insert(11);

    if (tobj->includes_iterative(20))
        std::cout << "Found\n";
    else
        std::cout << "Not Found\n";

    if (tobj->includes_recursive(20))
        std::cout << "Found\n";
    else
        std::cout << "Not Found\n";

    return 0;
}
